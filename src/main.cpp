#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);

    class EllipseShape : public sf::Shape
    {
    public:
        explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f)) : m_radius(radius)
        {
            update();
        }

        void setRadius(const sf::Vector2f& radius)
        {
            m_radius = radius;
            update();
        }

        const sf::Vector2f& getRadius() const
        {
            return m_radius;
        }

        virtual std::size_t getPointCount() const
        {
            return 30; // fixed, but could be an attribute of the class if needed
        }

        virtual sf::Vector2f getPoint(std::size_t index) const
        {
            static const float pi = 3.141592654f;

            float angle = index * 2 * pi / getPointCount() - pi / 2;
            float x = std::cos(angle) * m_radius.x;
            float y = std::sin(angle) * m_radius.y;

            return sf::Vector2f(m_radius.x + x, m_radius.y + y);
        }

    private:
        sf::Vector2f m_radius;
    };

    sf::CircleShape triangle(80.f, 3);
    sf::CircleShape shape(50);
    sf::CircleShape oct(100);
    EllipseShape ellipse(sf::Vector2f(100.f, 50.f));

    shape.setFillColor(sf::Color::Green);
    triangle.setFillColor(sf::Color::Red);
    oct.setFillColor(sf::Color::Blue);
    ellipse.setFillColor(sf::Color::Yellow);

    // Position the shapes
    shape.setPosition(100, 100);
    triangle.setPosition(300, 100);
    oct.setPosition(500, 100);
    ellipse.setPosition(300, 300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(triangle);
        window.draw(shape);
        window.draw(oct);
        window.display();
    }

    return 0;
}
