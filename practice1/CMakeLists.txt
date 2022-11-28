cmake_minimum_required(VERSION 2.6)
project (Tutorial)

# 判断当前平台
if (PLATFORM STREQUAL "Linux")
    add_definitions(-DLIN)
elseif(PLATFORM STREQUAL "Windows")
    add_definitions(-DWIN)
endif()

# 设置一个变量
# set(Tutorial_VERSION_MAJOR 1)

configure_file(
    "${PROJECT_SOURCE_DIR}/Tutorial.conf"
    "${PROJECT_BINARY_DIR}/Tutorial.h"
)

# 添加一个头文件包含路径
include_directories("${PROJECT_BINARY_DIR}")

# 设置一个选项开关
option(USE_MYMATH "Use tutorial math implementation" ON)

# 判断开关
if (USE_MYMATH)
    # 打印信息
    message("USE_MYMATH")

    # 内部添加一个预定义宏
    add_definitions(-DUSE_MYMATH)

    # 添加一个头文件包含路径
    include_directories("${PROJECT_BINARY_DIR}/MathFunctions/include/")

    # 添加一个子文件夹, 子文件夹可以是一个项目
    add_subdirectory(MathFunctions)

    # 设置子项目生成库的变量名
    set(EXTRA_LIB ${EXTRA_LIB} MathFunctions)
endif(USE_MYMATH)


# 指定依赖库的地址
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/MathFunctions/Debug/)

# 主项目依赖的文件
add_executable(Tutorial tutorial.cpp)

# 当前项目依赖子项目, 所以需要添加连接路径
target_link_libraries(Tutorial ${EXTRA_LIB})