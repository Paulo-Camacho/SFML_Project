#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "text, world" << std::endl;
    
    const int windowWidth  = 640;
    const int windowHeight = 480;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "VIDGEOGAME");
    window.setFramerateLimit(60);

    sf::Font bitsrom;
        if (!bitsrom.loadFromFile("assets/BitstromWeraNerdFont-Regular.ttf")) 
    {
        std::cerr << "The font didn't load fam :( " << std::endl;
        return 1;
    }

    sf::Text text("Hello, world ", bitsrom, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, windowHeight - (float)text.getCharacterSize() - 1);
    // The float value substracts the height of the characters, such that it moves back
    // inside of the window ~
    
    
    sf::CircleShape greenCircle(25.0f, 1000);
    greenCircle.setFillColor(sf::Color(0, 255, 0));
    greenCircle.setPosition(320.0f, 240.0f);
    float circleMoveSpeedX = 5.0f; 
    float circleMoveSpeedY = 5.0f; 

    sf::CircleShape redTriangle(50.f, 3);
    redTriangle.setFillColor(sf::Color(255, 0, 0, 200));



       while (window.isOpen())
    {
        sf::Event initialize;
        while(window.pollEvent(initialize))
        {
            if(initialize.type == sf::Event::Closed)
                window.close();
        }

        greenCircle.setPosition(greenCircle.getPosition().x + circleMoveSpeedX, greenCircle.getPosition().y + circleMoveSpeedY);
            
            
        greenCircle.move(circleMoveSpeedX, circleMoveSpeedY);

        float circleRadius = greenCircle.getRadius();
        sf::Vector2f circlePos = greenCircle.getPosition();

        if (circlePos.x - circleRadius <= 0) {
            circleMoveSpeedX = std::abs(circleMoveSpeedX); 
        } else if (circlePos.x + circleRadius >= windowWidth) {
            circleMoveSpeedX = -std::abs(circleMoveSpeedX);
        }

        if (circlePos.y - circleRadius <= 0) {
            circleMoveSpeedY = std::abs(circleMoveSpeedY);
        } else if (circlePos.y + circleRadius >= windowHeight) {
            circleMoveSpeedY = -std::abs(circleMoveSpeedY);
        }

            window.clear(sf::Color(135, 206, 235));
            window.draw(text);
            window.draw(redTriangle);
            window.draw(greenCircle);
            window.display();
    }

    return 0;
}
