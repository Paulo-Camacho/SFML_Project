#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test Win", sf::Style::Default, settings);
    sf::RectangleShape pipe(sf::Vector2f(50.f, 100.f));
    pipe.setFillColor(sf::Color::Green);
    pipe.setPosition(1280.f, 360.f - pipe.getSize().y / 2);
    
    float speed = 200.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event vnt;
        while (window.pollEvent(vnt))
        {
            if (vnt.type == sf::Event::Closed)
                window.close();
        }
        
        sf::Time deltaTime = clock.restart();
        
        
float distance = speed * deltaTime.asSeconds();
        pipe.move(-distance, 0); // Move left

        // If the rectangle goes off-screen, reposition it to the right
        if (pipe.getPosition().x + pipe.getSize().x < 0)
        {
            pipe.setPosition(1280.f, 360.f - pipe.getSize().y / 2);
        }

        window.clear();
        window.draw(pipe);
        window.display();
    }

    return 0;
}
