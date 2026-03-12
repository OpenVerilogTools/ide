cmake_minimum_required(VERSION 3.21)
project(OpenVerilogIDE LANGUAGES CXX)

# Block common polluting prefixes on macOS (Homebrew, local installs)
# This prevents find_package from considering them at all
list(APPEND CMAKE_IGNORE_PREFIX_PATH
    "/opt/homebrew"
    "/usr/local"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy;-p=${CMAKE_BINARY_DIR})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Concurrent Widgets)
find_package(Eigen3 REQUIRED)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)