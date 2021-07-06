cmake_minimum_required(VERSION 3.7.0)
project(Field VERSION 0.1.0)

##
#   Enviroments
##

set(TESTS_ENABLE OFF)    #   Compile Tests files

add_subdirectory(src)   # Library source dir

if(TESTS_ENABLE)
    add_subdirectory(Tests) # Test dir
endif()


include(CTest)
enable_testing()

# set (SFML_BIR_DIR C:\\MinGW\\bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Field main.cpp)

# set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:\\lib\\SFML-2.5.1\\lib\\cmake\\SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window network audio system REQUIRED)

target_link_libraries(
    Field
    lField
    sfml-graphics
    sfml-window
    sfml-system
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})