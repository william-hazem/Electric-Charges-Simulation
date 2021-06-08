file(GLOB src_util "util\\*.cpp")


add_library(  
    lField
    
    ##
    #   Graphics
    ##

    "graphics/ShapeBase.cpp"
    "graphics/ShapeCompound.hpp"
    "graphics/ShapeCompound.cpp"
    # Graphics - Shape
    "graphics/Shapes/Arrow.hpp"
    "graphics/Shapes/Arrow.cpp"
    
    ##
    #   Util
    ###

    "util/Singleton.cpp"
    "util/Vector2.cpp"

    ##
    #   Physics
    ##

    "Physics/Particle.cpp"

    ##
    #   Events
    ##
    
    "Events/EventHandler.hpp"
    "Events/EventHandler.cpp"

    ##
    #   Simulation
    ##

    "Simulation.cpp"
    "WrapperParticle.cpp"
)

target_include_directories(lField PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")