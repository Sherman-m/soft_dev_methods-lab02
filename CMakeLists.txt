cmake_minimum_required(VERSION 3.12)
project(lab02 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_objs OBJECT
  src/games/common_game.hpp
  src/games/common_game.cpp
  src/games/engine.hpp
  src/games/engine.cpp
  src/games/geom_prog_game.hpp
  src/games/geom_prog_game.cpp
  src/games/lcm_game.hpp
  src/games/lcm_game.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objs)
