add_library(  
    lField STATIC
    
    ##
    #   Graphics
    ##

    "graphics/ShapeBase.cpp"
    "graphics/ShapeCompound.cpp"
    # Graphics - Shape
    "graphics/Shapes/Arrow.cpp"
    
    ##
    #   Elements
    ##

    "Elements/ElementBase.cpp"
    "Elements/Text.cpp"

    ##
    #   Util
    ###

    "util/Singleton.cpp"
    "util/Vector2.cpp"
    "util/Font.cpp"

    ##
    #   Physics
    ##

    "Physics/Particle.cpp"

    ##
    #   Events
    ##
    
    "Events/EventHandler.cpp"

    ##
    #   Simulation
    ##

    "Simulation.cpp"
    "WrapperParticle.cpp"
    "HandlerParticle.cpp"
)

##
#   INCLUDE FILES
#   Put all in E-FIELD/include
#
#   ex: E-FIELD/include/foo.hpp
##
target_include_directories(lField PUBLIC "${PROJECT_SOURCE_DIR}\\include")

### Output lib file for <Project_DIR>/lib
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")