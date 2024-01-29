cmake_minimum_required(VERSION 3.27)
project(Vision)

set(CMAKE_CXX_STANDARD 17)

include_directories(Vision "${PROJECT_SOURCE_DIR}/dependencies/headers/common" "src/")

add_executable(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/common/glad.c"
        src/test/main.cpp
        src/core/vision.h
        src/core/project.h
        src/ui/cwindow.h
        src/core/project.cpp
        src/ui/cwindow.cpp
        src/util/common.h)

IF (WIN32)
    # Windows only
    target_link_libraries(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/win/glfw3.dll")
ELSE()
    # Linux only
    target_link_libraries(Vision "${PROJECT_SOURCE_DIR}/dependencies/binaries/linux/libglfw.so.3.4")
ENDIF()