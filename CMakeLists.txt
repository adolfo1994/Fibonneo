cmake_minimum_required(VERSION 3.5)
project(Fibonneo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Synthesizer.cpp Synthesizer.h Message.cpp Message.h Fibonneo.cpp Fibonneo.h Client.cpp Client.h TcpServer.cpp TcpServer.h Histogram.cpp Histogram.h Confirmation.cpp Confirmation.h Server.h UDPClient.cpp UDPClient.h TCPClient.cpp TCPClient.h)
add_executable(Fibonneo ${SOURCE_FILES})