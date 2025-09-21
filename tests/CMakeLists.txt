# Tests configuration for RPN calculator
include(FetchContent)

# Динамически подключаем библиотеку GoogleTest из интернета
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл для тестов
add_executable(rpn_tests test_rpn.cpp)

# Линкуем его с библиотекой rpn.lib
target_link_libraries(rpn_tests PRIVATE gtest_main rpn_lib)

# Подключаем наши заголовочные файлы
target_include_directories(rpn_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Добавляем тест в CTest
add_test(NAME rpn_tests COMMAND rpn_tests)
