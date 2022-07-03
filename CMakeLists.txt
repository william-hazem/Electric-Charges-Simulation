cmake_minimum_required(VERSION 3.0.0)
project(Field VERSION 0.1.0)

##
#   Enviroments
##

set(TESTS_ENABLE OFF)    #   Compile Tests files



include(CTest)
enable_testing()

add_executable(Field main.cpp)

find_package(SFML 2.5.1 COMPONENTS graphics window network audio system REQUIRED)
include_directories(PUBLIC_HEADER "D:\\willi\\lib\\mingw\\SFML-2.5.1\\include")

add_subdirectory(src)   # Library source dir
add_subdirectory(Tests) # Test dir


target_link_libraries(
    Field PUBLIC
    # ${libScr}
    #   My lib
    lField
    #   SFML - Dynamic libraries
    sfml-graphics
    sfml-window
    sfml-system
    #   Opengl
    "opengl32.a" 
)

# SFML include dir
target_include_directories(
    Field PUBLIC
    "D:\\willi\\lib\\mingw\\SFML-2.5.1\\include"
    # "${incBir}"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



set_target_properties(
    Field
    PROPERTIES
    CXX_STANDARD 17
)
target_compile_features(Field PRIVATE cxx_std_17)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})