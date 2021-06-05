cmake_minimum_required(VERSION 3.0.0)
project(Field VERSION 0.1.0)

# Library dir
add_subdirectory(src)   #lField

include(CTest)
enable_testing()

set (SFML_BIR_DIR C:\\MinGW\\bin)

add_executable(Field main.cpp)

# add all .a files in C:\\..\\lib in a object
file(GLOB libSrc "C:\\MinGW\\lib\\*.a")

#file(GLOB incBir "C:\\MinGW\\include\\SFML\\")

target_link_libraries(
    Field PUBLIC
    ${libScr}
    lField
    # SFML_dll
    # .dll files necessary
    "${CMAKE_SOURCE_DIR}\\sfml-graphics-2.dll"
    "${CMAKE_SOURCE_DIR}\\sfml-window-2.dll"
    "${CMAKE_SOURCE_DIR}\\sfml-system-2.dll"
    #"${CMAKE_SOURCE_DIR}\\lib/liblField.a"
    "opengl32.a"
)

target_include_directories(
    Field PUBLIC
    "C:\\MinGW\\include\\SFML\\"
    # "${incBir}"
)

# target_link_libraries(
#     SFML
#     "C:\\MinGW\\lib\\*"
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

set_target_properties(
    Field
    PROPERTIES
    CXX_STANDARD 17
)