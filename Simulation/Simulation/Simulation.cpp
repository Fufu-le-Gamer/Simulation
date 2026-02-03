#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

    
    sf::CircleShape Center(50.f);
    Center.setFillColor(sf::Color::Gray);
    // 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class
    // set the origin of the entity
    Center.setOrigin({ -375.f, -250.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_cercle = Center.getOrigin();

    // define a rectangle
    sf::RectangleShape Roadx({ 120.f, 50.f });
    Roadx.setFillColor(sf::Color::Gray);
    // change the size
    Roadx.setSize({ 1000.f, 50.f });
    Roadx.setOrigin({ 0.f, -275.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_Roadx = Roadx.getOrigin();

    // define a rectangle
    sf::RectangleShape Roady({ 120.f, 50.f });
    Roady.setFillColor(sf::Color::Gray);
    // change the size
    Roady.setSize({ 1000.f, 50.f });
    Roady.setOrigin({ 0.f, 450.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_Roady = Roady.getOrigin();
    // set the absolute rotation of the entity
    Roady.setRotation(sf::degrees(80));
    // rotate the entity relatively to its current orientation
    Roady.rotate(sf::degrees(10));
    // retrieve the absolute rotation of the entity
    sf::Angle rotation_Roady = Roady.getRotation();

    // Create a graphical text to display
    const sf::Font font("arial.ttf");
    sf::Text text(font, "Abonnez vous à Fufu le Gamer", 10);

    sf::RectangleShape Bat1({ 120.f, 50.f });
    Bat1.setFillColor(sf::Color::Red);
    // change the size
    Bat1.setSize({ 250.f, 130.f });
    Bat1.setOrigin({ -20.f, 137.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_Bat1 = Bat1.getOrigin();
    // set the absolute rotation of the entity
    Bat1.setRotation(sf::degrees(80));
    // rotate the entity relatively to its current orientation
    Bat1.rotate(sf::degrees(10));
    // retrieve the absolute rotation of the entity
    sf::Angle rotation_Bat1 = Bat1.getRotation();
   
    sf::Text Baker(font, "Bakery", 30);
    Baker.setOrigin({ -20.f, -100.f });
    Baker.setFillColor(sf::Color::Black);


    sf::RectangleShape Bat2({ 120.f, 50.f });
    Bat2.setFillColor(sf::Color::Yellow);
    // change the size
    Bat2.setSize({ 250.f, 130.f });
    Bat2.setOrigin({ -20.f, 268.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_Bat2 = Bat2.getOrigin();
    // set the absolute rotation of the entity
    Bat2.setRotation(sf::degrees(80));
    // rotate the entity relatively to its current orientation
    Bat2.rotate(sf::degrees(10));
    // retrieve the absolute rotation of the entity
    sf::Angle rotation_Bat2 = Bat2.getRotation();

    sf::Text Bank(font, "Bank", 30);
    Bank.setOrigin({ -170.f, -100.f });
    Bank.setFillColor(sf::Color::Black);


    sf::RectangleShape Bat3({ 120.f, 50.f });
    Bat3.setFillColor(sf::Color::Cyan);
    // change the size
    Bat3.setSize({ 250.f, 130.f });
    Bat3.setOrigin({ -20.f, 399.f });
    // retrieve the origin of the entity
    sf::Vector2f origin_Bat3 = Bat3.getOrigin();
    // set the absolute rotation of the entity
    Bat3.setRotation(sf::degrees(80));
    // rotate the entity relatively to its current orientation
    Bat3.rotate(sf::degrees(10));
    // retrieve the absolute rotation of the entity
    sf::Angle rotation_Bat3 = Bat3.getRotation();

    sf::Text Butcher(font, "Butcher", 30);
    Butcher.setOrigin({ -280.f, -100.f });
    Butcher.setFillColor(sf::Color::Black);

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

        window.clear();

        window.draw(Roadx);

        window.draw(Roady);

        window.draw(Bat1);

        window.draw(Bat2);

        window.draw(Bat3);

        window.draw(Bank);

        window.draw(Baker);

        window.draw(Butcher);

        window.draw(Center);

        window.draw(text);

        window.display();
    }
}