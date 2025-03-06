cmake_minimum_required(VERSION 3.10)
project(VK)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(include)

add_executable(VK src/main.cpp)
target_link_libraries(VK ${GTEST_LIBRARIES})


file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(VKTests ${TEST_SOURCES})

file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "src/main.cpp")

target_sources(VKTests PRIVATE ${SOURCES})
target_link_libraries(VKTests ${GTEST_LIBRARIES} Threads::Threads)

add_test(NAME VKTests COMMAND VKTests)
