#include "Simulation.hpp"

Simulation::Simulation(uint64_t width, uint64_t height)
{
    this->width = width;
    this->height = height;
    this->init();

    Particle p1(1), p2(0), p3(1), p4(0);
    p1.setPosition(hz::Vector2(900, 300));
    p2.setPosition(hz::Vector2(500, 300));
    p3.setPosition(hz::Vector2(800, 200));
    p4.setPosition(hz::Vector2(100, 456));

    particles.push_back(p1);
    particles.push_back(p2);
    particles.push_back(p3);
    particles.push_back(p4);
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
    this->window.create({1200, 600}, "has");


    window.setFramerateLimit(60);
}

void Simulation::clear() {
    this->shapes.clear();
    this->particles.clear();
}

void Simulation::run() {

    uint64_t i, particles_size = this->particles.size();
    
    Arrow arrow(sf::Vector2f(600, 300), 40.f, 1.5f);
    arrow.setOrign({20, 10});

    if(window.isOpen())
        this->running = true;
    printf("RUNNING: %d\n", this->running);
    while(this->running) {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                this->running = false;
            }
        }

        
        window.clear();
        
        for(i = 0; i < particles_size; i++) {
            std::vector<Particle> temp_particle = this->particles;
            temp_particle.erase(temp_particle.begin() + i);
            particles[i].move(temp_particle);
            // particles[0].move(particles[1]);


            window.draw(particles[i].getShape());
            
        }
        // hz::Vector2 f = particles[0].getForce(temp_particle);
        
        window.draw(arrow);
        window.display();
        // sf::sleep(sf::milliseconds(100));

    }
    printf("OUTTING\n");
}