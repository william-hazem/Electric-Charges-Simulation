#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include <map>
#include <thread>

#include <Hazem/graphics.hpp>
#include <Hazem/physics.hpp>
#include <Hazem/HandlerParticle.hpp>
#include <Hazem/Util/Singleton.hpp>
#include <Hazem/Elements/Elements.hpp>

// #include "Events/EventHandler.hpp"


class Simulation
{
    static Simulation* instance;        //Singleton Instance
    static std::mutex mutex;            //Mutex safety

    enum arrowDrawType {
        NONE = 0,
        ACCELERATION,
        EFIELD
    };

    const arrowDrawType ARROW_NONE = arrowDrawType::NONE;
    const arrowDrawType ARROW_ACCELERATION  = arrowDrawType::ACCELERATION;
    const arrowDrawType ARROW_EFIELD = arrowDrawType::EFIELD;

    uint32_t width, height;
    static Arrow defaultArrow;
    static Arrow defaultFieldArrow;
    
    bool running;               // running
    bool pause;                 // pause simulation
    bool stopParticle;          // Stop particle drawing system
    bool hasUpdated;            // has Something changed and need update
    
    arrowDrawType arrowStyle;   // Select the drawing mode
    int EFIELD_OFFSET;          // Offset between each vector on eletric field
    
    sf::Font font;              // Default font 
    std::map<const char*, Text> mText;  // Map to text elements 
    std::vector<ShapeBase*> shapes;
    HandlerParticle particleSystem;
    
    // INITIALIZE FUNCTIONS
    void init();
    bool initText();
    void initElement();

    void drawTextInfo();
    void drawBorder();
    /// \brief Add a new Particle
    /// \param set true for a proton
    /// and false for eletron, and set initial position
    void addParticle(bool, const hz::Vector2&);
    /// \brief Add a new Particle in a random position and random type
    void addParticle();
public:
    static Simulation* getInstance();
    
    sf::RenderWindow window;
    Simulation() {};
    Simulation(Simulation&) = delete;           //Singleton Logic 
    Simulation(const Simulation&) = delete;     //Singleton Logic
    Simulation(uint32_t, uint32_t);
    ~Simulation();

    bool start();
    void clear();
    /// \brief Reset the particles system
    void reset();
    void run();

    
};

#endif //!HAZEM_SIMULATION