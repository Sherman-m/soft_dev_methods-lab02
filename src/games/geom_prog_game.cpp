#include "geom_prog_game.hpp"

#include <iostream>

bool GeometricProgressionGame::PlayBatch() {
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
