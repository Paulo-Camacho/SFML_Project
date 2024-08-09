#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "text, world" << std::endl;
    
    const int wWidth  = 640;
    const int wHeight = 480;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "VIDGEOGAME");
    window.setFramerateLimit(60);

    sf::Font bitsrom;
        if (!bitsrom.loadFromFile("assets/BitstromWeraNerdFont-Regular.ttf")) 
    {
        std::cerr << "The font didn't load fam :( " << std::endl;
        return 1;
    }

    sf::Text text("Hello, world ", bitsrom, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, wHeight - (float)text.getCharacterSize());
    
    
    sf::CircleShape greenCircle(200.f, 1000);
    greenCircle.setFillColor(sf::Color(0, 255, 0));

    sf::CircleShape redTriangle(200.f, 3);
    redTriangle.setFillColor(sf::Color(255, 0, 0, 200));



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
        window.draw(greenCircle);
        window.draw(redTriangle);
        window.display();
    }

    return 0;
}
