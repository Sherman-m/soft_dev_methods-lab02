#include "common_game.hpp"

#include <format>
#include <iostream>

namespace games {

bool CommonGame::Play() {
  for (int batch = 0; batch < k_max_batches_; ++batch) {
    if (!PlayBatch()) {
      return false;
    }
  }
  return true;
}

bool CommonGame::CheckResult(std::int64_t expected) {
  std::cout << "\nYour answer: ";
  std::int64_t actual;
  std::cin >> actual;

  if (actual == expected) {
    std::cout << "\nCorrect!\n";
  } else {
    std::cout << std::format(
        "'{}' is wrong answer ;(. Correct answer was '{}'.\n", actual,
        expected);
  }

  return actual == expected;
}

}  // namespace games
