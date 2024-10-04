#pragma once
#include "common_game.hpp"

namespace games {

class GeometricProgressionGame : public CommonGame {
 public:
  explicit GeometricProgressionGame(std::mt19937& gen)
      : CommonGame(gen) {
  }

 private:
  using IntDistrib = std::uniform_int_distribution<std::int64_t>;

  bool PlayBatch() override;

  const std::pair<std::int64_t, std::int64_t> k_min_max_len_{5, 10};
  const std::pair<std::int64_t, std::int64_t> k_min_max_param_value_{-10, 10};
  IntDistrib len_distrib_{k_min_max_len_.first, k_min_max_len_.second};
  IntDistrib param_distrib_{k_min_max_param_value_.first,
                            k_min_max_param_value_.second};
};

}  // namespace games
