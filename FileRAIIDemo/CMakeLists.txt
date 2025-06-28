cmake_minimum_required(VERSION 3.10)
project(FileRAII LANGUAGES CXX)

# Требуем C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаём библиотеку
add_library(file_raii
    File.cpp
)
target_include_directories(file_raii PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
# Создаём исполняемый файл demo
add_executable(FileRAIIDemo
    main.cpp
)
# Линкуем библиотеку
target_link_libraries(FileRAIIDemo PRIVATE file_raii)

# Пример теста (необязательно)
add_test(NAME DemoRun COMMAND FileRAIIDemo)
