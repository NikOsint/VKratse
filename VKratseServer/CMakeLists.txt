cmake_minimum_required(VERSION 3.16)
project(VKratseServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS
        Core
        Network
        Sql
        REQUIRED)

include_directories(${PROJECT_NAME} include)

add_executable(VKratseServer
        src/main.cpp
        include/server.h
        src/server.cpp
        include/worker.h
        src/worker.cpp
        include/message_type.h)

target_link_libraries(VKratseServer
        Qt5::Core
        Qt5::Network
        Qt5::Sql)

