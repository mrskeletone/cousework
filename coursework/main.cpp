#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    sf::CircleShape shape(200.f);
    shape.setRadius(100.f);
    shape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    shape.setOrigin(100, 100);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(3.f);
    shape.setOutlineColor(sf::Color::Red);
    sf::CircleShape circle(200.f);
    circle.setRadius(2.f);
    circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    circle.setOrigin(73.5, 73.5);
    circle.setFillColor(sf::Color::Green);
    double speed = 0.05,x= window.getSize().x / 2.f,y= window.getSize().y / 2.f,x_line[5],y_line[3];
    x_line[0] = x + 70; y_line[0] = y + 70;
    x_line[1] = x - 100; y_line[1] = y - 20;
    x_line[2] = x; y_line[2] = y - 100;
    x_line[3] = x + 100; 
    x_line[4] = x - 70; 
    sf::Texture texture;
    if (!texture.loadFromFile("art.png"))
    {
        // error...
    };
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(x_line[0], y_line[0])),
        sf::Vertex(sf::Vector2f(x_line[1], y_line[1])),
        sf::Vertex(sf::Vector2f(x_line[2], y_line[2])),
        sf::Vertex(sf::Vector2f(x_line[3], y_line[1])),
        sf::Vertex(sf::Vector2f(x_line[4], y_line[0])),
        sf::Vertex(sf::Vector2f(x_line[2], y_line[2])),
        sf::Vertex(sf::Vector2f(x_line[0], y_line[0])),
        sf::Vertex(sf::Vector2f(x_line[3], y_line[1])),
        sf::Vertex(sf::Vector2f(x_line[1], y_line[1])),
        sf::Vertex(sf::Vector2f(x_line[4], y_line[0])),
        sf::Vertex(sf::Vector2f(x_line[0], y_line[0])),

    };
    for (unsigned i = 0; i < 11; i++) {
        line[i].color = sf::Color::Red;
    }
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                shape.scale(0.5f, 0.5f);
                circle.scale(0.5f, 0.5f);
                
               
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {

                shape.scale(2.f, 2.f);
                circle.scale(2.f, 2.f);

            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            speed -= 0.001;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            speed += 0.001;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            speed = 0;
        circle.rotate(speed);
        window.clear();
        window.draw(shape);
        window.draw(circle);
        window.draw(line, 11, sf::LineStrip);
        texture.update(texture);
        window.display();
    }

}