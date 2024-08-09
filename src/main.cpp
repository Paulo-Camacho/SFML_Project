#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{
    const int wWidth  = 640;
    const int wHeight = 480;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "VIDGEOGAME");
    window.setFramerateLimit(60);

    sf::CircleShape greenCircle(100);
    greenCircle.setFillColor(sf::Color::Green);
    greenCircle.setPosition(300.0f, 300.0f);	
    float greenCircleMoveSpeed = 128.0f;

    sf::Font bitstrom;
    if (!bitstrom.loadFromFile("BitstromWeraNerdFont-Regular.ttf")) {
        return 1;
    }

    sf::Text text;
    text.setFont(bitstrom);  // Set the loaded font here
    text.setString("Hello, SFML!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
                     window.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f);

    while(window.isOpen())
    {
        sf::Event initialize;
        while(window.pollEvent(initialize))
        {
            if(initialize.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}
