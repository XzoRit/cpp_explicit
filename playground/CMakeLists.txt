cmake_minimum_required(VERSION 3.0)

project(explicit_playground)

add_executable(explicit_playground
  main_test.cpp
  not_null.cpp
  only_when.cpp
  out_param.cpp
  tagged_bool.cpp
  )

target_compile_features(explicit_playground
  PRIVATE
    cxx_std_17
  )

target_include_directories(explicit_playground
  PRIVATE
    ${explicit_playground_SOURCE_DIR}
    ${cpp_explicit_SOURCE_DIR}/explicit/include
  )

target_link_libraries(explicit_playground doctest)
