cmake_minimum_required(VERSION 3.10)
project(GraphProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исходные файлы
add_library(graph graph.cpp)

# Исполняемый файл для основной программы
add_executable(main main.cpp)
target_link_libraries(main graph)

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Тесты
add_executable(test_graph test_graph.cpp)
target_link_libraries(test_graph graph GTest::GTest GTest::Main)

# Добавляем команду для запуска тестов
add_test(NAME RunTests COMMAND test_graph)
