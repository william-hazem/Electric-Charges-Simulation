cmake_minimum_required(VERSION 3.7.0)
project(Field VERSION 0.1.0)

##
#   Enviroments
##

set(TESTS_ENABLE OFF)    #   Compile Tests files

add_subdirectory(src)   # Library source dir
# add_subdirectory(Tests) # Test dir

include(CTest)
enable_testing()

# set (SFML_BIR_DIR C:\\MinGW\\bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Field main.cpp)

# add all .a files in C:\\..\\lib in a object
# file(GLOB libSrc "C:\\MinGW\\lib\\*.a")
# set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\lib\\lib\\cmake\\SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window network audio system REQUIRED)

#file(GLOB incBir "C:\\MinGW\\include\\SFML\\")

target_link_libraries(
    Field
    lField
    sfml-graphics
    sfml-window
    sfml-system
    # "sfml-graphics-2.dll"
    # "sfml-window-2.dll"
    # "sfml-system-2.dll"
    #   Opengl
    # "opengl32.a" 
)

# SFML include dir
# target_include_directories(
#     Field PUBLIC
#     # "C:\\MinGW\\include\\SFML\\"
#     # "${incBir}"
# )

# target_link_libraries(
#     SFML
#     "C:\\MinGW\\lib\\*"
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# set_target_properties(
#     Field
#     PROPERTIES
#     CXX_STANDARD 17
# )
target_compile_features(Field PRIVATE cxx_std_17)


