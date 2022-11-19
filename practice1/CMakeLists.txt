cmake_minimum_required(VERSION 2.6)
project (Tutorial)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/Tutorial.conf"
    "${PROJECT_BINARY_DIR}/Tutorial.h"
)

include_directories("${PROJECT_BINARY_DIR}")

option(USE_MYMATH "Use tutorial math implementation" ON)

if (USE_MYMATH)
    message("USE_MYMATH")
    include_directories("${PROJECT_BINARY_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIB ${EXTRA_LIB} MathFunctions)
endif(USE_MYMATH)

add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIB})