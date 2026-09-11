# 1. Название проекта и стандарт языка.
cmake_minimum_required(VERSION 3.20)
project(laba1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. Используем GNU GCC. ASan включён для всех собираемых исходников.
if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "Use GNU GCC: configure with -DCMAKE_CXX_COMPILER=g++")
endif()
add_compile_options(-Wall -Wextra -Wpedantic -g -fsanitize=address -fno-omit-frame-pointer)
add_link_options(-fsanitize=address)

# 3. Ищем Google Test; если он не установлен — скачиваем фиксированную версию.
find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.15.2
    )
    FetchContent_MakeAvailable(googletest)
endif()

# 4. Собираем общую логику и указываем каталог заголовков.
add_library(laba1_lib src/array_ops.cpp)
target_include_directories(laba1_lib PUBLIC include)

# 5. Собираем программу и связываем её с общей логикой.
add_executable(laba1_main src/main.cpp)
target_link_libraries(laba1_main PRIVATE laba1_lib)

# 6. Собираем тесты и регистрируем их запуск в CTest.
add_executable(tests test/array_ops_test.cpp)
target_link_libraries(tests PRIVATE laba1_lib GTest::gtest_main)
enable_testing()
add_test(NAME Laba1Tests COMMAND tests)