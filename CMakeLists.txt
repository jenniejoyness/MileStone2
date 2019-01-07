cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-pthread")

add_executable(MileStone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h MyTestClientHandler.cpp Solver.h CacheManager.h FileCacheManager.h FileCacheManager.cpp StringReverser.cpp StringReverser.h State.h Searchable.h Searcher.h BestFirstSearch.cpp BestFirstSearch.h Matrix.cpp Matrix.h Point.cpp Point.h)