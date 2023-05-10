cmake_minimum_required(VERSION 3.16)
project(VKratseClient)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

include_directories(${PROJECT_NAME} include)

add_executable(${PROJECT_NAME}
        src/main.cpp
        include/client.h
        src/client.cpp
        include/authorization_dialog.h
        src/authorization_dialog.cpp
        include/registration_dialog.h
        src/registration_dialog.cpp
        include/settings_widget.h
        src/settings_widget.cpp
        include/chats_widget.h
        src/chats_widget.cpp
        include/new_chat_dialog.h
        src/new_chat_dialog.cpp
        include/user.h
        src/user.cpp
        include/message_type.h)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network)
