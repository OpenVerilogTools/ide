cmake_minimum_required(VERSION 3.29)
project(ide)

# Guide: https://doc.qt.io/qt-6/cmake-get-started.html

set(CMAKE_CXX_STANDARD 17) # Qt6 has abseil[cxx17] dependency
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR  ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE
    MACOSX_BUNDLE ON
)