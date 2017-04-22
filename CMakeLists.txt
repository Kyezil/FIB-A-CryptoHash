cmake_minimum_required(VERSION 3.7.2)
set (CMAKE_CXX_STANDARD 11)
project(cryptohash)

include_directories(src/include)

file(GLOB SOURCES "src/*.cc")

#add_subdirectory(src/experiments)
#add_subdirectory(src/utils)
#add_subdirectory(src/test)
file(GLOB UTILS_SOURCES "src/utils/src/*.cc")
add_library(utils ${UTILS_SOURCES})
target_include_directories(utils PUBLIC src/utils/include)

file(GLOB EXP_SOURCES "src/experiments/src/*.cc")
add_library(experiments ${EXP_SOURCES})
target_include_directories(experiments PUBLIC src/experiments/include)
target_link_libraries(experiments utils)

add_executable(cryptohash.exe ${SOURCES})
target_link_libraries(cryptohash.exe experiments)

# compile test examples
add_executable(bf_example.exe src/test/bf_example.cc src/BloomFilter.cc src/DoubleHashingBF.cc)
target_link_libraries(bf_example.exe utils)

# hash example
add_executable(hashes.exe src/test/hashes.cc)
target_link_libraries(hashes.exe utils)

# execution example
add_executable(execution.exe src/test/execution.cc src/Execution.cc src/BloomFilter.cc src/DoubleHashingBF.cc)
target_link_libraries(execution.exe experiments)