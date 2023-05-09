cmake_minimum_required(VERSION 3.23)
project(VKratseClient)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(${PROJECT_NAME} include)

add_executable(${PROJECT_NAME}
        src/main.cpp
        include/mainwindow.h
        src/mainwindow.cpp
        include/authorization_dialog.h
        src/authorization_dialog.cpp
        include/registration_dialog.h src/registration_dialog.cpp)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

