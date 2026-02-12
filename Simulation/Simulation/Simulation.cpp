#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("cute_image.jpg");
    sf::Sprite sprite(texture);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color::Red);
    // 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class

// set the origin of the entity
    shape.setOrigin({ -200.f, -200.f });


    // retrieve the origin of the entity
    sf::Vector2f origin = shape.getOrigin();// = (10.f, 20.f)

    // Create a graphical text to display
    const sf::Font font("arial.ttf");
    sf::Text text(font, "fufu le gamer il est nul", 50);

    text.setRotation(sf::degrees(35));
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        window.draw(shape);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }
}