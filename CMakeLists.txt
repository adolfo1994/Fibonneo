cmake_minimum_required(VERSION 3.3)
project(Fibonneo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads REQUIRED)

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
target_link_libraries(Fibonneo ${CMAKE_THREAD_LIBS_INIT})