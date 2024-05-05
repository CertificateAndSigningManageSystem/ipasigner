cmake_minimum_required(VERSION 3.25)
set(VERSION "0.1.0")
project(ipasigner LANGUAGES C CXX VERSION ${VERSION})

string(TIMESTAMP BUILT_TIME "%Y%m%d%H%M%S")
add_definitions(-DVERSION="${VERSION}" -DBUILT_TIME="${BUILT_TIME}")

set(CMAKE_CXX_STANDARD 20)
add_executable(ipasigner main.cpp)

include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)
target_link_libraries(ipasigner argparse)
