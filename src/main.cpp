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

	 sf::Font font;
    if (!font.loadFromFile("home/ubuntulaptop/SFML_Project/assets/Regular.ttf")) {
	std::cout << "This failed, unc " << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Hello, SFML!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 300);

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
