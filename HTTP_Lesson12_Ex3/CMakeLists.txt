cmake_minimum_required(VERSION 3.12)

project(HTTP_Lesson12_Ex3)

include(FetchContent)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8
)

FetchContent_MakeAvailable(cpr)

add_executable(HTTP_Lesson12_Ex3 "HTTP_Lesson12_Ex3.cpp")

target_link_libraries(HTTP_Lesson12_Ex3 PRIVATE cpr::cpr)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HTTP_Lesson12_Ex3 PROPERTY CXX_STANDARD 20)
endif()
