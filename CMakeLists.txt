# nLine
# 
# Copyright (c) 2024 Wahtari GmbH
# All rights reserved

# 3.21.1 is the minimum required version for static Qt builds.
cmake_minimum_required(VERSION 3.21.1)

# Define the projects and its version.
project(qmlImportTest VERSION 0.6.4 LANGUAGES CXX)

# Define custom vars.
set(QT_MIN_VERSION 6.5)
set(APP_TARGET ${CMAKE_PROJECT_NAME}-app)

# Set C++20 as minimum that must be supported by the compiler.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS Gui Qml Quick Charts LinguistTools)

qt_standard_project_setup(REQUIRES ${QT_MIN_VERSION})

qt_add_executable(${APP_TARGET} main.cpp)

qt_add_qml_module(${APP_TARGET}
    URI ${CMAKE_PROJECT_NAME}
    QML_FILES Main.qml
    RESOURCE_PREFIX /qt/qml
    NO_RESOURCE_TARGET_PATH # Prevents that the URI becomes part of the resource target path.
)

add_subdirectory(A)
add_subdirectory(B)

# Tell CMake which libraries our executable will use.
target_link_libraries(${APP_TARGET} PRIVATE 
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Charts
    Aplugin
    Bplugin
)
