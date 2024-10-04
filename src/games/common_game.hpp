#pragma once

#include <random>

class CommonGame {
 public:
  explicit CommonGame(std::mt19937& gen)
      : gen_(gen) {
  }

  bool Play();

  bool CheckResult(std::int64_t actual, std::int64_t expected);

  virtual ~CommonGame() = default;

 protected:
  std::mt19937& gen_;

 private:
  using IntDistrib = std::uniform_int_distribution<std::int32_t>;

  virtual bool PlayBatch() = 0;

  const int k_max_batches_{3};
};
