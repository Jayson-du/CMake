cmake_minimum_required(VERSION 2.6)
project (Tutorial)

# 判断当前平台
if (PLATFORM STREQUAL "Linux")
    add_definitions(-DLIN)
elseif(PLATFORM STREQUAL "Windows")
    add_definitions(-DWIN)
endif()

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

if (PLATFORM STREQUAL "Windows")
    # Windows下是指当前启动项目
    set_property (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
endif()

# 指定依赖库的地址
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR})

# 主项目依赖的文件
add_executable(Tutorial tutorial.cpp)

# 当前项目依赖子项目, 所以需要添加连接路径
target_link_libraries(Tutorial ${EXTRA_LIB})


# 创建第三方依赖头文件目录
make_directory("${PROJECT_BINARY_DIR}/ThirdHeader")
# 遍历查找第三方库函数头文件
file(GLOB_RECURSE ThirdHeaderFile
     "${PROJECT_BINARY_DIR}/resource/HeaderFile/*.h"
     )
# 拷贝到指定目录
file(COPY "${ThirdHeaderFile}" DESTINATION  "${PROJECT_BINARY_DIR}/ThirdHeader")



# 拷贝第三方依赖库,
# 1、遍历寻找*.dll文件
file(GLOB_RECURSE ThirdLibFile
     "${PROJECT_BINARY_DIR}/resource/library/${PLATFORM}/*.dll"
     )
# 2、POST_BUILD: 编译结束后执行自定义命令拷贝
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${ThirdLibFile}" "${PROJECT_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES}"
)

