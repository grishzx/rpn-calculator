cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Создаем БИБЛИОТЕКУ с нашей логикой
add_library(rpn_lib src/rpn.cpp)
target_include_directories(rpn_lib PUBLIC include)

# Создаем исполняемый файл калькулятора и линкуем его с библиотекой
add_executable(rpn_calculator src/main.cpp)
target_link_libraries(rpn_calculator PRIVATE rpn_lib)

# Включаем тестирование и добавляем папку с тестами
enable_testing()
add_subdirectory(tests)
