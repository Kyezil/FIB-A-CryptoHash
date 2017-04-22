cmake_minimum_required(VERSION 3.7.2)
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

