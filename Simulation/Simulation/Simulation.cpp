#include <SFML/Graphics.hpp>
#include "Buildings.h"

int main()
{
    // Create the main window
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

    
    sf::CircleShape Center(50.f);
    Center.setFillColor(sf::Color::Gray);
    Center.setOrigin({ -375.f, -250.f });

    // define a rectangle
    sf::RectangleShape Roadx({ 120.f, 50.f });
    Roadx.setFillColor(sf::Color::Gray);
    // change the size
    Roadx.setSize({ 1000.f, 50.f });
    Roadx.setOrigin({ 0.f, -275.f });

    // define a rectangle
    sf::RectangleShape Roady({ 120.f, 50.f });
    Roady.setFillColor(sf::Color::Gray);
    // change the size
    Roady.setSize({ 1000.f, 50.f });
    Roady.setOrigin({ 0.f, 450.f });
    Roady.setRotation(sf::degrees(80));
    Roady.rotate(sf::degrees(10));

    sf::Font font;
    font.openFromFile("arial.ttf");

    sf::Text text(font, "Abonnez vous à Fufu le Gamer", 10);

    Buildings bakery(
        font,
        "Bakery",
        { 130.f, 250.f },
        { -10.f, -20.f },
        {0.f, 0.f},
        sf::Color::Red,
        0.f
    );

    Buildings bank(
        font,
        "Bank",
        { 130.f, 250.f },
        { -150.f, -20.f },
        { 100.f, 0.f },
        sf::Color::Yellow,
        0.f
    );

    Buildings butcher(
        font,
        "Butcher",
        { 130.f, 250.f },
        { -300.f, -20.f },
        { 300.f, 0.f },
        sf::Color::Cyan,
        0.f
    );

    Buildings police_station(
        font,
        "Police Station",
        { 200.f, 250.f },
        { -50.f, -330.f },
        { 50.f, 0.f },
        sf::Color::Blue,
        0.f
    );

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
        bakery.draw(window);
        bank.draw(window);
        butcher.draw(window);
        police_station.draw(window);
        window.draw(Center);
        window.draw(text);

        window.display();
    }
}