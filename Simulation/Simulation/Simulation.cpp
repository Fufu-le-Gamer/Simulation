#include <SFML/Graphics.hpp>
#include "Buildings.h"
#include "Clients.h"

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

    Buildings bakery1(
        font,
        "Bakery 1",
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
        { -100.f, -20.f },
        { 100.f, 0.f },
        sf::Color::Yellow,
        0.f
    );

    Buildings butcher1(
        font,
        "Butcher 1",
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

    Buildings bakery2(
        font,
        "Bakery 2",
        { 130.f, 250.f },
        { -270.f, -330.f },
        { 200.f, 0.f },
        sf::Color::Magenta,
        0.f
    );

    Buildings butcher2(
        font,
        "Butcher 2",
        { 130.f, 250.f },
        { -350.f, -330.f },
        { 300.f, 0.f },
        sf::Color::Purpule,
        0.f
    );

    Clients clients( 20.f, 300.f, 200.f); //taille, position, vitesse
    sf::Clock clock;

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

        float deltaTime = clock.restart().asSeconds();

        clients.update(deltaTime);

        window.clear();

        window.draw(Roadx);
        window.draw(Roady);
        window.draw(Center);
        clients.draw(window);
        bakery1.draw(window);
        bakery2.draw(window);
        bank.draw(window);
        butcher1.draw(window);
        butcher2.draw(window);
        police_station.draw(window);
        window.draw(text);

        window.display();
    }
}