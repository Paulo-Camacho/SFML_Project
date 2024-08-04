#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test Win", sf::Style::Default, settings);
    sf::RectangleShape pipe(sf::Vector2f(50.f, 100.f));
    pipe.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event vnt;
        while (window.pollEvent(vnt))
        {
            if (vnt.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pipe);
        window.display();
    }

    return 0;
}
