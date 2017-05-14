#include <SFML/Graphics.hpp>

#define PHYSICS_TIMESTEP 0.04

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time prev_time = clock.getElapsedTime();
    double accumulator = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // step physics engine
        sf::Time curr_time = clock.getElapsedTime();
        accumulator += (double)(curr_time - prev_time).asSeconds();
        prev_time = curr_time;

        while (accumulator >= PHYSICS_TIMESTEP)
        {
            //eng->step();
            accumulator -= PHYSICS_TIMESTEP;
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

