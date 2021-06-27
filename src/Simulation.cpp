#include <Hazem/Simulation.hpp>

#include <cmath>
#include <iostream>

Arrow Simulation::defaultArrow = Arrow(sf::Vector2f(0, 0), 30.f, 2.5f);
Arrow Simulation::defaultFieldArrow = Arrow(sf::Vector2f(0, 0), 30.f, 12.f);

Simulation::Simulation(uint32_t width, uint32_t height)
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
    this->pause = false;
    this->stopParticle = true;

    EFIELD_OFFSET = 55;
    arrowStyle = arrowDrawType::NONE;
    // INITIALIZE FONT
    if (Hz::loadDefaultFont(&font) ) {
        printf("[INIT] Font Loaded \n");
    }
    else 
        printf("[ERROR] FAILED TO INIT FONT\n");
  
    sf::View view;
    // view.zoom(1.5f);
    // this->window.setView(view);

    window.setFramerateLimit(60);
    particleSystem.bindRender(&window);

    // INITIALIZE COMPONENTS
    initEField();
    initText();
    
    printf("[INIT] Sucefully initialized\n");
}

bool Simulation::initEField() {
    float x, y;
    EFIELD_VECTOR.clear();
    for(x = EFIELD_OFFSET; x < width; x += EFIELD_OFFSET)
        for(y = EFIELD_OFFSET; y < height; y += EFIELD_OFFSET)
            EFIELD_VECTOR.push_back(sf::Vector2f(x, y));
    return true;
}

bool Simulation::initText() {
    sf::Color cDefaultText(sf::Color::White),
        cWarningText(sf::Color::Red);
    
    Text newText;
    newText.setFillColor(cDefaultText);
    Text WarningText;
    WarningText.setFillColor(cWarningText);

    newText.setFont(font);
    WarningText.setFont(font);

    WarningText.setOpacity(0);

    //Particle_Count
    newText.setElement_Name("particle_count");
    mText.emplace(newText.getElement_Name(), newText);

    //Paused?
    Text pause = newText;
    pause.setString("PAUSED");
    pause.setElement_Name("paused");
    pause.setPosition((width - pause.getCharacterSize()*pause.getString().getSize()/2)/2, height - 50);
    mText.emplace(pause.getElement_Name(), pause);

    //Mode changed
    WarningText.setElement_Name("warning_mode");
    mText.emplace(WarningText.getElement_Name(), WarningText);


    
    return true;
}

void Simulation::clear() {
    this->shapes.clear();
    this->particles.clear();
}

void Simulation::run() {

    //Setting up Threads
    sf::Thread thread1(&Simulation::drawField, &*this);
    int drawFieldCount(0);
    int opacityFallout = 255;

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
                else if(event.key.code == sf::Keyboard::F) {
                    Text& t = mText.at("warning_mode");
                    t.setOpacity(255);
                    switch (arrowStyle)
                    {
                    case arrowDrawType::NONE:
                        arrowStyle = arrowDrawType::ACELERAION;
                        t.setString("MODE: Aceleration Vectors");
                        break;
                    case arrowDrawType::ACELERAION:
                        arrowStyle = arrowDrawType::EFIELD;
                        t.setString("MODE: Field Vectors");
                        break;
                    case arrowDrawType::EFIELD:
                        arrowStyle = arrowDrawType::NONE;
                        t.setString("MODE: NONE");
                        break;

                    default:
                        break;
                    }
                    printf("[MODE CHANGED] stopParticle: %b\n", stopParticle);
                }
            }
        }

        window.clear();
        // UPDATE
        if(!stopParticle) particleSystem.update();
        

        //DRAWING
        
        if(arrowStyle == 2) drawField();

        particleSystem.draw();
        drawTextInfo();
        opacityFallout--;

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
    Text text;

    // Box Size
    float w = 300.f, marginx = 20.f;
    float h = 200.f, marginy = 25.f;
    float x = this->width - w;
    float y = this->height - h;
    float cx(0), cy(0);

    /// Box def
    sf::RectangleShape rec(sf::Vector2f{w, h});
    rec.setPosition(sf::Vector2f{x, y});
    rec.setFillColor(sf::Color(255, 255, 255, 128));
    window.draw(rec);

    /// Particle count - i0
    text.setFont(this->font);
    text.setPosition({x + marginx, y + marginy});
    text.setFillColor(fontColor);
    text.setString("Particles: " + std::to_string(particleSystem.size()));
    window.draw(text);

    if(stopParticle) 
        window.draw(mText.at("paused"));

    ///  Warning Drawing Mode
    Text &t = mText.at("warning_mode");
    if(t.getOpacity() > 0) {
        static sf::Clock warningDuration, warningDurationFall;
        t.setPosition((width - t.getString().getSize()*t.getCharacterSize()/2)/2, 75);
        //Fallout animation
        if(t.getOpacity() > 0 &&  warningDuration.getElapsedTime() > sf::seconds(2)) {
            if(t.getOpacity() == 255)
                warningDuration.restart();
            if(warningDurationFall.getElapsedTime() > sf::seconds(7/255)) {
                t.setOpacity(t.getOpacity()-1);  
                warningDurationFall.restart();
            }
        }
        window.draw(t);
    }
    

}

void Simulation::drawField() {
    Particle q0;
    hz::Vector2 f;

    size_t i, size = EFIELD_VECTOR.size();
    for(i = 0; i < size; i++) {
        defaultFieldArrow.setPosition(EFIELD_VECTOR[i]);
        q0.setPosition(hz::Vector2(EFIELD_VECTOR[i].x, EFIELD_VECTOR[i].y));
        f = particleSystem.calcE_Force(q0);
        defaultFieldArrow.setAngle(90 - f.angle());
        window.draw(defaultFieldArrow);     
    }
}