cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h MyTestClientHandler.cpp Solver.h CacheManager.h FileCacheManager.h FileCacheManager.cpp StringReverser.cpp StringReverser.h)