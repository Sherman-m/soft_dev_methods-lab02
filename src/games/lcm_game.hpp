#pragma once

#include "common_game.hpp"

namespace games {

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

  bool PlayBatch() override;

  IntDistrib value_distrib_{0, 2500};
};

}  // namespace games
