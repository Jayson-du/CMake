message("PLATFORM is ${PLATFORM}")

if (${PLATFORM} STREQUAL "linux")
    configure_file(
        "${PROJECT_SOURCE_DIR}/MathFunctions/mysqrt_lin.conf"
        "${PROJECT_BINARY_DIR}/MathFunctions/platform.h"
    )

elseif(PLATFORM STREQUAL "Windows")
    configure_file(
        "${PROJECT_SOURCE_DIR}/MathFunctions/mysqrt_win.conf"
        "${PROJECT_BINARY_DIR}/MathFunctions/platform.h"
        )
endif()



add_library(MathFunctions SHARED mysqrt.cpp)