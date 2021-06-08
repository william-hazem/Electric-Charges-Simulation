#include <Hazem/Simulation.hpp>

#include <cmath>

Simulation::Simulation() {}

Simulation::Simulation(uint64_t width, uint64_t height)
{
    this->width = width;
    this->height = height;
    this->init();

    Particle p1(1), p2(0);
    size_t size = 2;
    srand(std::time(0));

    for(size_t i = 0; i < size; i++) {
        hz::Vector2 position;
        position.x = rand() % (width - 100) + 100;
        position.y = rand() % (height - 100) + 100;
        if((int) rand() % 2) {
            p1.setPosition(position);
            particles.push_back(p1);
        }
        else {
            p2.setPosition(position);
            particles.push_back(p2);

        }
    }


    this->window.create({width, height}, "Simulation");
}

Simulation::~Simulation()
{
    this->clear();
}

void Simulation::init() {
    this->running = false;
    this->showForces = false;
    this->showEField = false;
    // const sf::Vector2u size(this->width, this->height);
    // this->window.setSize(size);
    // this->window.setTitle("Hellow");
  
    sf::View view;
    view.zoom(1.5f);
    this->window.setView(view);

    window.setFramerateLimit(30);
}

void Simulation::clear() {
    this->shapes.clear();
    this->particles.clear();
}

void Simulation::run() {
    sf::CircleShape c(10);
    c.setPosition({900, 300});
    c.setOrigin({10, 10});

    printf("RUNNIG...\b");
    size_t i, particles_size = this->particles.size();
    
    Arrow defaultArrow(sf::Vector2f(0, 0), 40.f, 3.5f);
    
    std::vector<WrapperParticle> wAceleration(particles_size);

    printf("PREPARING RESOURCES...\n");

    for(i = 0; i < particles_size; i++) { 
        wAceleration[i].bind( particles.data() + i, &(defaultArrow));
        wAceleration[i].setId(i);
    }
    // if(particles_size)
        // wAceleration[0].bindRender(&this->window);
    

    printf("ReFinalized...\n");
    Arrow arrow(sf::Vector2f(600, 300), 40.f, 1.5f);
    arrow.setOrign({20, 10});

    if(window.isOpen())
        this->running = true;
    printf("RUNNING: %d\n", this->running);
    while(this->running) {
        printf("EVENT SETTING: %d\n", this->running);
        Simulation *s = this;
        printf("EVENT OUT: %d\n", this->running);
        window.clear();
        
        for(i = 0; i < particles_size; i++) {
            // printf("--PARTICLE %d --\n", i); 
            std::vector<Particle> temp_particle = this->particles;
            temp_particle.erase(temp_particle.begin() + i);
            particles[i].move(temp_particle);
            wAceleration[i].update();
            // particles[0].move(particles[1]);

            window.draw(*wAceleration[i].getShape());
            window.draw(particles[i].getShape());
             printf("---------------\n"); 
        }
        // hz::Vector2 f = particles[0].getForce(temp_particle);
        
        window.draw(c);
        window.display();
        // sf::sleep(sf::milliseconds(100));

    }
    printf("OUTTING\n");
    this->clear();
}