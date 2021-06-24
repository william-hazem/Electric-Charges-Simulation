#include <Hazem/Simulation.hpp>

#include <cmath>
#include <exception>

const float Simulation::Q0 = 1.f;

Arrow Simulation::defaultArrow = Arrow(sf::Vector2f(0, 0), 40.f, 1.5f);

Simulation::Simulation() {}

Simulation::Simulation(uint32_t width, uint32_t height)
{
    this->width = width;
    this->height = height;

    

    this->init();

    size_t size = 1;
    
    srand(std::time(0));
    for(size_t i = 0; i < size; i++) {
        hz::Vector2 position; 
        position.x = rand() % (width - 100) + 100;
        position.y = rand() % (height - 100) + 100;
        if((int) rand() % 2) {
            this->addParticle(true, position);
        }
        else {
            this->addParticle(false, position);
        }
    }

    this->window.create({width, height}, "Simulation");
}

Simulation::~Simulation()
{
    this->clear();
}

void Simulation::init() {
    // INITIALIZE VAR
    this->running = false;
    this->showForces = false;
    this->showEField = false;
    this->pause = false;
    this->stopParticle = false;

    EFIELD_OFFSET = 150;

    // INITIALIZE FONT
    if (Hz::loadDefaultFont(&font) ) {
        printf("[INIT] Font Loaded \n");
    }
  
    sf::View view;
    // view.zoom(1.5f);
    // this->window.setView(view);

    window.setFramerateLimit(30);
    particleSystem.bindRender(&window);

    // INITIALIZE COMPONENTS
    initEField();
    
}

bool Simulation::initEField() {
    float x, y;
    EFIELD_VECTOR.clear();
    for(x = EFIELD_OFFSET; x < width; x += EFIELD_OFFSET)
        for(y = EFIELD_OFFSET; y < height; y += EFIELD_OFFSET)
            EFIELD_VECTOR.push_back(sf::Vector2f(x, y));
    return true;
}


void Simulation::clear() {
    this->shapes.clear();
    this->particles.clear();
}

void Simulation::run() {
    sf::CircleShape c(10);
    c.setPosition({900, 300});
    c.setOrigin({10, 10});

    size_t i, particles_size = this->particles.size();

    Arrow arrow(sf::Vector2f(600, 300), 40.f, 1.5f);
    arrow.setOrign({20, 10});

    if(window.isOpen())
        this->running = true;
    
    
    while(this->running) {
        particles_size = this->particles.size();
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                this->running = false;
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mouse = sf::Mouse::getPosition() - window.getPosition();
                hz::Vector2 position;
                position.x = mouse.x;
                position.y = mouse.y;
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    this->addParticle(true, position);
                    printf("Mx, My = %d, %d\n", mouse.x, mouse.y);
                    printf("Mx, My = %d, %d\n", mouse.x - 600, mouse.y - 300);
                    printf("------------------\n");
                } else
                if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    this->addParticle(false, position);
                    printf("Mx, My = %d, %d\n", mouse.x, mouse.y);
                    printf("Mx, My = %d, %d\n", mouse.x - 600, mouse.y - 300);
                    printf("------------------\n");
                }
            

            } //!Mouuse
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space) {
                    stopParticle = !stopParticle;
                    printf("[MODE CHANGED] stopParticle: %b\n", stopParticle);
                }
            }
        }

        window.clear();
        // UPDATE
        if(!stopParticle) particleSystem.update();


        //DRAWING
        drawField();
        particleSystem.draw();
        drawTextInfo();
        
        

        window.display();
        
    }
    this->clear();
}
// !RUN

void Simulation::addParticle(bool proton, const hz::Vector2& position) {
    size_t size = particles.size();
    
    Particle newParticle(proton);
    WrapperParticle newWrapper;

    newParticle.setPosition(position);

    newWrapper.bind(newParticle, new Arrow(defaultArrow));
    
    particleSystem.addParticle(newWrapper);
}

void Simulation::drawTextInfo() {
    const sf::Color fontColor = sf::Color::Black;

    // Box Size
    float w = 300.f, marginx = 20.f;
    float h = 200.f, marginy = 25.f;
    float x = this->width - w;
    float y = this->height - h;

    // Box def
    sf::RectangleShape rec(sf::Vector2f{w, h});
    rec.setPosition(sf::Vector2f{x, y});
    rec.setFillColor(sf::Color(255, 255, 255, 128));
    window.draw(rec);

    //Particle count
    Text text;
    text.setFont(this->font);
    text.setPosition({x + marginx, y + marginy});
    text.setFillColor(fontColor);
    text.setString("Particles: " + std::to_string(particleSystem.size()));
    window.draw(text);
}

void Simulation::drawField() {
    Particle q0;
    hz::Vector2 f;

    Arrow arrow({0, 0}, 20, 5);
    arrow.setColor(sf::Color::White);

    size_t i, size = EFIELD_VECTOR.size();
    for(i = 0; i < size; i++) {
        arrow.setPosition(EFIELD_VECTOR[i]);
        q0.setPosition(hz::Vector2(EFIELD_VECTOR[i].x, EFIELD_VECTOR[i].y));
        f = particleSystem.calcE_Force(q0);
        arrow.setAngle(90 - f.angle());
        window.draw(arrow);     
    }
}