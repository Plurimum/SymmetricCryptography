cmake_minimum_required(VERSION 3.24)
project(SymmetricCryptography)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#add_executable(SymmetricCryptography test/test_aes128.cpp)
add_executable(SymmetricCryptography src/Random.h src/AES128.h src/main.cpp)
