#include "lcm_game.hpp"

#include <format>
#include <iostream>

namespace games {

bool LcmGame::PlayBatch() {
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

}  // namespace games
