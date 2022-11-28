# 通过从顶级CMakeLists.txt传递的${PLATFORM}, 判断当前平台
if (PLATFORM STREQUAL "Linux")
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/include/mysqrt_lin.conf"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/platform.h"
    )
elseif (PLATFORM STREQUAL "Windows")
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/include/mysqrt_win.conf"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/platform.h"
        )
endif()

# 在WIndows下开启项目组织
option(USE_SOLUTION_FOLDERS  ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# 通过CMake内置的file函数将.h文件与.cpp文件分离,
# ${CMAKE_CURRENT_SOURCE_DIR}为当前目录
# 递归查找当前项目include下的所有.h文件
file(GLOB_RECURSE HeaderFile
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
     )
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HeaderFile})

# 递归查找当前项目source目录下所有.cpp文件
file(GLOB_RECURSE SourceFile
     "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
     )
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SourceFile})

# 添加文件分类
add_library(MathFunctions SHARED
            ${HeaderFile}
            ${SourceFile}
            )