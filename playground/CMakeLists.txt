cmake_minimum_required(VERSION 3.0)

project(explicit_playground)

add_executable(explicit_playground
  main_test.cpp
  tagged_bool.cpp)

target_include_directories(explicit_playground
  PRIVATE ${cpp_explicit_SOURCE_DIR}/explicit/include)

target_link_libraries(explicit_playground doctest)

