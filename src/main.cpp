#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setVerticalSyncEnabled(true);
	

	sf::CircleShape greenCircle(100, 100);
	greenCircle.setFillColor(sf::Color(255, 0, 50));
	greenCircle.setPosition(10.f, 50.f);
	greenCircle.move(5.f, 5.f);
	sf::Vector2f posititon = greenCircle.getPosition();

	sf::CircleShape blueCircle(200, 200);
	blueCircle.setFillColor(sf::Color(0, 255, 100));	

	sf::CircleShape purpleCircle(300, 300);
	purpleCircle.setFillColor(sf::Color(0, 255, 70));

	sf::RectangleShape redRectangle(sf::Vector2f(200, 200));
	

	while(window.isOpen())
	{
		sf::Event initialize;
		while(window.pollEvent(initialize))
		{
			if(initialize.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);

		window.draw(greenCircle);
		window.display();
	}

	return 0;
}
