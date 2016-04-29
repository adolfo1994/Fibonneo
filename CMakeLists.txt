cmake_minimum_required(VERSION 3.5)
project(Fibonneo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Fibonneo.cpp Fibonneo.h
        Client.h
        TcpClient.cpp TcpClient.h
        UdpClient.cpp UdpClient.h
        Server.h
        TcpServer.cpp TcpServer.h
        UdpServer.cpp UdpServer.h
        Message.cpp Message.h
        Confirmation.cpp Confirmation.h)
add_executable(Fibonneo ${SOURCE_FILES})