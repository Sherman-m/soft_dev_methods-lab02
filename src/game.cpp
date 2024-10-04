#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <format>
#include <unordered_map>

class CommonGame {
 public:
  explicit CommonGame(std::mt19937& gen)
      : gen_(gen) {
  }

  bool Play() {
    for (int batch = 0; batch < k_max_batches_; ++batch) {
      if (!PlayBatch()) {
        return false;
      }
    }
    return true;
  }

  bool CheckResult(int64_t actual, int64_t expected) {
    if (actual == expected) {
      std::cout << "\nCorrect!\n";
    } else {
      std::cout << std::format(
          "'{}' is wrong answer ;(. Correct answer was '{}'.\n", actual,
          expected);
    }

    return actual == expected;
  }

  virtual ~CommonGame() = default;

 protected:
  std::mt19937& gen_;

 private:
  using IntDistrib = std::uniform_int_distribution<std::int32_t>;

  virtual bool PlayBatch() = 0;

  const int k_max_batches_{3};
};

// LCM Game
class LcmGame : public CommonGame {
 public:
  explicit LcmGame(std::mt19937& gen)
      : CommonGame(gen) {
  }

 private:
  using IntDistrib = std::uniform_int_distribution<std::int64_t>;

  std::int64_t Gcd(std::int64_t a, std::int64_t b) const {
    while (b > 0) {
      a %= b;
      std::swap(a, b);
    }
    return a;
  }

  template <typename... Args>
  std::int64_t Lcm(std::int64_t a, Args... args) const {
    return ((a = Lcm(a, args)), ...);
  }

  std::int64_t Lcm(std::int64_t a, std::int64_t b) const {
    return (a * b) / Gcd(a, b);
  }

  bool PlayBatch() override {
    std::int64_t a = value_distrib_(gen_);
    std::int64_t b = value_distrib_(gen_);
    std::int64_t c = value_distrib_(gen_);

    std::int64_t expected = Lcm(a, b, c);

    std::cout << std::format(
                     "Find the smallest common multiple of given "
                     "numbers.\nQuestion: {} {} {}\n",
                     a, b, c)
              << "Your answer: ";
    std::int64_t actual;
    std::cin >> actual;

    return CheckResult(actual, expected);
  }

  IntDistrib value_distrib_{0, 2500};
};

// Geometric Progression Game
class GeometricProgressionGame : public CommonGame {
 public:
  explicit GeometricProgressionGame(std::mt19937& gen)
      : CommonGame(gen) {
  }

 private:
  using IntDistrib = std::uniform_int_distribution<std::int64_t>;

  bool PlayBatch() override {
    std::int64_t len = len_distrib_(gen_);
    std::int64_t b = param_distrib_(gen_);
    std::int64_t q = param_distrib_(gen_);
    std::int64_t pass = IntDistrib{0, len - 1}(gen_);

    std::int64_t expected = 0;

    std::cout << "What number is missing in the progression?\nQuestion: ";
    for (std::int64_t i = 0; i < len; ++i) {
      if (pass == i) {
        expected = b;
        std::cout << ".. ";
      } else {
        std::cout << b << ' ';
      }
      b *= q;
    }

    std::cout << "\nYour answer: ";
    std::int64_t actual;
    std::cin >> actual;

    return CheckResult(actual, expected);
  }

  const std::pair<std::int64_t, std::int64_t> k_min_max_len_{5, 10};
  const std::pair<std::int64_t, std::int64_t> k_min_max_param_value_{-10, 10};
  IntDistrib len_distrib_{k_min_max_len_.first, k_min_max_len_.second};
  IntDistrib param_distrib_{k_min_max_param_value_.first,
                            k_min_max_param_value_.second};
};

// Engine
class GameEngine {
 public:
  explicit GameEngine(std::string game_code)
      : game_code_(std::move(game_code)) {
  }

  void Start() {
    std::cout << "Welcome to the Brain Games!\nMay I have your name? ";
    std::cin >> player_name_;
    std::cout << std::format("\nHello, {}!\n", player_name_);

    if (k_code_to_game_.find(game_code_) == k_code_to_game_.end()) {
      std::cout << std::format("The game_code={} does not exist.\n",
                               game_code_);
      return;
    }

    auto game_ptr = k_code_to_game_.at(game_code_);
    std::string answer_to_player =
        (game_ptr->Play()) ? "Congratulations" : "Let's try again";
    std::cout << std::format("{}, {}!\n", answer_to_player, player_name_);
  }

 private:
  using CodeToGame =
      std::unordered_map<std::string, std::shared_ptr<CommonGame>>;

  const CodeToGame k_code_to_game_{
      {"LCM", std::make_shared<LcmGame>(gen_)},
      {"GEOMPROG", std::make_shared<GeometricProgressionGame>(gen_)}};

  std::string player_name_;
  std::string game_code_;
  std::mt19937 gen_{std::random_device{}()};
};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "The game cannot be started.\nYou need to enter the command: "
                 "make start -- <LCM|GEOMPROG>\n";
    return EXIT_FAILURE;
  }
  GameEngine engine{argv[1]};
  engine.Start();
  return EXIT_SUCCESS;
}
