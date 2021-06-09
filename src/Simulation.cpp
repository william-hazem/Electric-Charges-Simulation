#include <Hazem/Simulation.hpp>

#include <cmath>

Arrow Simulation::defaultArrow = Arrow(sf::Vector2f(0, 0), 40.f, 1.5f);

Simulation::Simulation() {}

Simulation::Simulation(uint64_t width, uint64_t height)
{
    this->width = width;
    this->height = height;
    this->init();

    size_t size = 5;
    

    srand(std::time(0));
    for(size_t i = 0; i < size; i++) {
        hz::Vector2 position; 
        position.x = rand() % (width - 100) + 100;
        position.y = rand() % (height - 100) + 100;
        printf("[i] Force: %f,%f\n", position.x,position.y);
        if((int) rand() % 2) {
            this->addParticle(true, position);
        }
        else {
            this->addParticle(false, position);
        }
    }
    printf("\n\n");

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


    if (Hz::loadDefaultFont(&font) ) {
        printf("[INIT] Font Loaded \n");
    }
  
    sf::View view;
    // view.zoom(1.5f);
    // this->window.setView(view);

    window.setFramerateLimit(30);
    particleSystem.bindRender(&window);
    
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
    
    Arrow defaultArrow(sf::Vector2f(0, 0), 40.f, 3.5f);
    
    // std::vector<WrapperParticle> wAceleration(particles_size);

    // for(i = 0; i < particles_size; i++) { 
    //     wAceleration[i].bind( particles.data() + i, &(defaultArrow));
    //     wAceleration[i].setId(i);
    // }

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

            }
        }

        window.clear();
        
        

        // this->particleSystem.draw();
        // for(i = 0; i < particles_size; i++) {
        //     std::vector<Particle> temp_particle = this->particles;
        //     temp_particle.erase(temp_particle.begin() + i);
        //     particles[i].move(temp_particle);

        //     // wAceleration[i].update();

        //     // window.draw(*wAceleration[i].getShape());
        //     window.draw(particles[i].getShape());
        // }
        

    // printf("size: %d\n", particleSystem.size());
    for(size_t i = 0; i < particleSystem.size(); i++) {
        const WrapperParticle &p = particleSystem.getWrapper(i);
        printf("[i] Force: %f,%f\n", p.getParticle()->getPosition().x,p.getParticle()->getPosition().y);
        // sf::CircleShape c = p->getShape();
        
    }
    char c;
    scanf("%c", &c);
    printf("\n\n");

        this->drawTextInfo();
        // window.draw(c);

        window.display();
        

    }
    printf("OUTTING\n");
    this->clear();
}
// !RUN

void Simulation::addParticle(bool proton, const hz::Vector2& position) {
    Particle newParticle(proton);
    newParticle.setPosition(position);
    particles.push_back(newParticle);
    
    Particle p = particles.back();
    WrapperParticle newWrapper;
    newWrapper.bind(&particles.back(), &(defaultArrow));
    wp.push_back(newWrapper);
    WrapperParticle w = wp.back();
    particleSystem.addParticle(wp.back());
}



void Simulation::drawTextInfo() {
    float w = 300.f, marginx = 20.f;
    float h = 200.f, marginy = 25.f;
    float x = this->width - w;
    float y = this->height - h;

    sf::RectangleShape rec(sf::Vector2f{w, h});
    rec.setPosition(sf::Vector2f{x, y});
    rec.setFillColor(sf::Color(255, 255, 255, 128));
    window.draw(rec);

    Text text;
    text.setFont(this->font);
    text.setPosition({x + marginx, y + marginy});
    text.setFillColor(sf::Color::Black);
    text.setString("Particles: " + std::to_string(particles.size()));
    window.draw(text);

}