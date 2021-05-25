add_library(  
    lField

    "util/Vector2.hpp"
    "util/Vector2.cpp"
    #"Charge.cpp"
    #"./Eforce.hpp"
    #"./Eforce.cpp"
    "graphics/IGraphics.hpp"
)

target_include_directories(lField PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")