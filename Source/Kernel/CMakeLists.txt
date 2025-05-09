enable_testing()

set(KERNEL_HEADERS
  Log.h
  Result.h
  task/Task.h
  task/TaskManager.h
  task/TaskListener.h
)

set(KERNEL_SOURCES
  task/Task.cc
  task/TaskManager.cc
)

set(KERNEL_TEST_SOURCES
  task/TaskTest.cc
  task/TaskManagerTest.cc
)

add_library(Kernel ${KERNEL_HEADERS} ${KERNEL_SOURCES})
target_link_libraries(Kernel PUBLIC TX)

add_executable(Kernel_Test ${KERNEL_TEST_SOURCES})
target_link_libraries(Kernel_Test Kernel GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(Kernel_Test)
