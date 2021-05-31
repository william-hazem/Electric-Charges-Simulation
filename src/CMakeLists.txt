file(GLOB src_util "util\\*.cpp")

add_library(  
    lField
    ${src_util}
    # ${src_graphics}
    # "util/Vector2.hpp"
    # "util/Vector2.cpp"
    # "Charge.cpp"
    "./Eforce.hpp"
    "./Eforce.cpp"
    "graphics/ShapeBase.cpp"
    "graphics/ShapeCompound.hpp"
    "graphics/ShapeCompound.cpp"
    "graphics/Arrow.hpp"
    "graphics/Arrow.cpp"
)

target_include_directories(lField PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")