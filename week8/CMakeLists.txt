cmake_minimum_required(VERSION 3.27)
project(Application)
set(EXECUTABLE_OUTPUT_PATH bin)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


add_executable(task03a.exe src/task03a.cpp)
add_executable(task03b.exe src/task03b.cpp)
add_executable(task03c.exe src/task03c.cpp)


add_executable(testA src/tests/testA.cpp)
add_executable(testB src/tests/testB.cpp)
add_executable(testC src/tests/testC.cpp)
target_link_libraries(testA GTest::gtest_main)
target_link_libraries(testB GTest::gtest_main)
target_link_libraries(testC GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(testA)
gtest_discover_tests(testB)
gtest_discover_tests(testC)

add_custom_command(
     TARGET task03a.exe
     COMMENT "Run tests"
     PRE_BUILD
     COMMAND testA
)
add_custom_command(
     TARGET task03b.exe
     COMMENT "Run tests"
     PRE_BUILD
     COMMAND testB
)
add_custom_command(
     TARGET task03c.exe
     COMMENT "Run tests"
     PRE_BUILD
     COMMAND testC
)
