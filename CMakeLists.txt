cmake_minimum_required(VERSION 3.17)
project(Vision)

set(CMAKE_CXX_STANDARD 17)

include_directories(Vision "${PROJECT_SOURCE_DIR}/dependencies/headers/common" "src/")

add_executable(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/common/glad.c"
        src/vision/test/main.cpp
        src/vision/core/vision.h "src/vision/core/ext.h" "src/vision/ui/window.h" "src/vision/ui/window.cpp" "src/vision/util/logging.cpp" "src/vision/util/logging.h")

IF (WIN32)
    # Windows only
    # "${PROJECT_SOURCE_DIR}/dependencies/binaries/win/glfw3.dll" HUH?
    target_link_libraries(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/win/glfw3dll.lib")
ELSE()
    # Linux only
    target_link_libraries(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/linux/libglfw.so.3.4")
ENDIF()