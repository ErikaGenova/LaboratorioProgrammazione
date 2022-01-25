cmake_minimum_required(VERSION 3.5)

add_subdirectory(./googletest)
set(gtest_SOURCE_DIR, ./googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES mainTest.cpp ListTest.cpp MemoTest.cpp CollectionTest.cpp DateTest.cpp)
add_executable(LabProgrammazioneTest ${TEST_SOURCE_FILES})
target_link_libraries(LabProgrammazioneTest gtest gtest_main newlib)