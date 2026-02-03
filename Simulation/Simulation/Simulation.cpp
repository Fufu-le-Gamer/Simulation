#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

    // Load a sprite to display
    const sf::Texture texture("cute_image.jpg");
    sf::Sprite sprite(texture);

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    // 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class
    // set the origin of the entity
    shape.setOrigin({ -375.f, -250.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_cercle = shape.getOrigin(); // = (10.f, 20.f)

    // define a 120x50 rectangle
    sf::RectangleShape rectx({ 120.f, 50.f });
    rectx.setFillColor(sf::Color::Gray);
    // change the size to 100x100
    rectx.setSize({ 1000.f, 50.f });
    rectx.setOrigin({ 0.f, -275.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_rectx = rectx.getOrigin();

    // define a 120x50 rectangle
    sf::RectangleShape recty({ 120.f, 50.f });
    recty.setFillColor(sf::Color::Gray);
    // change the size to 100x100
    recty.setSize({ 1000.f, 50.f });
    recty.setOrigin({ 0.f, 450.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_recty = recty.getOrigin();
    // set the absolute rotation of the entity
    recty.setRotation(sf::degrees(80));
    // rotate the entity relatively to its current orientation
    recty.rotate(sf::degrees(10));
    // retrieve the absolute rotation of the entity
    sf::Angle rotation = recty.getRotation(); // = 55 degrees

    // Create a graphical text to display
    const sf::Font font("arial.ttf");
    sf::Text text(font, "Abonnez vous à Fufu le Gamer", 50);

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

        window.draw(rectx);

        window.draw(recty);

        window.draw(shape);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }
}