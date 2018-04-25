set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories("../include")

add_executable(testy tests.cpp)

target_link_libraries(testy ${GTEST_BOTH_LIBRARIES})