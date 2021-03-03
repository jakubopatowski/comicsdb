cmake_minimum_required(VERSION 3.14)

project(ComicsDB)

add_executable(main)

# Check what is the compiler
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # using regular Clang or AppleClang
  target_compile_options(main PRIVATE -Wpedantic -W -v)
  if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # using clang with clang-cl front end
  elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
    # using clang with regular front end
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  target_compile_options(main PRIVATE -Wpedantic -W -v)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  target_compile_options(main PRIVATE /permissive- /W4)
endif()

get_target_property(MAIN_CFLAGS main COMPILE_OPTIONS)
message("-- Target compiler flags are: ${MAIN_CFLAGS}")

include(FetchContent)

FetchContent_Declare(
  sqlite3
  URL "https://www.sqlite.org/2021/sqlite-amalgamation-3340100.zip")

if (NOT sqlite3_POPULATED)
  FetchContent_Populate(sqlite3)
endif()

target_include_directories(main
  PRIVATE
  $<BUILD_INTERFACE:${sqlite3_SOURCE_DIR}>
  "./app")

target_sources(main
  PRIVATE
  ${sqlite3_SOURCE_DIR}/sqlite3.c
  "./app/main.cpp"
  "./app/IDatabaseManager.hpp"
  "./app/Sqlite3Manager.hpp"
  "./app/Sqlite3Manager.cpp"
  "./app/Sqlite3ErrorCodes.hpp"
  "./app/Sqlite3ErrorCodes.cpp"
  )

# Tests
# https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top
FetchContent_Declare(
  Catch2 
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4)

FetchContent_MakeAvailable(Catch2)
# FetchContent_GetProperties(Catch2)
# if(NOT Catch2_POPULATED)
#   FetchContent_Populate(Catch2)
#   message(STATUS "Catch source dir: ${catch2_SOURCE_DIR}")
#   message(STATUS "Catch binary dir: ${catch2_BINARY_DIR}")
#   add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
# endif()

add_executable(app_tests 
app/tests/test.cpp
app/tests/Sqlite3ErrorCodesTests.hpp
app/Sqlite3ErrorCodes.cpp)

target_include_directories(app_tests
  PRIVATE
  app/tests
  app
)

target_link_libraries(app_tests Catch2::Catch2)
