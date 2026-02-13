#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <vector>
#include <thread>

#include "BehaviorTree.h"
#include "Node.h"
#include "Ia.h"
#include "Shop.h"
#include "Buildings.h"
#include "Clients.h"

class Clock {
public:
    Clock() = default;
    Clock(bool StartImmediatly) {
        if (StartImmediatly) {
            Start();
        }
    }

    void Start() {
        Restart();
    }
    float Restart() {
        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
        std::chrono::duration<float> Duration = Actual - TimeStart;

        TimeStart = Actual;
        LastCallElpased = Actual;

        return Duration.count();
    }
    float GetElapsedTime() {
        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
        std::chrono::duration<float> Duration = Actual - LastCallElpased;

        LastCallElpased = Actual;
        return Duration.count();
    }
    float TimeSinceStart() {
        std::chrono::time_point<std::chrono::steady_clock> Actual = std::chrono::steady_clock::now();
        std::chrono::duration<float> Duration = Actual - TimeStart;
        return Duration.count();
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> TimeStart;
    std::chrono::time_point<std::chrono::steady_clock> LastCallElpased;
};


int main()
{

    srand(time(0));

    std::chrono::milliseconds dura(1000);

    Clock BTClock = Clock(true);
    const float Duration = 20.0f;

    Ia* MonIA = new Ia();
    MonIA->SetShop(new Shop());
    bool continu = true;
    int a;
    int nombre_client;
    int compte_jour = 0;

    EnnemiBlackBoard* MyBlackBoard = new EnnemiBlackBoard();
    BehaviorTree* MyBt = new EnnemyBehaviorTree(MyBlackBoard);
    MyBt->BuildTree();
    MyBt->BeginExecute();

    while (BTClock.TimeSinceStart() < 10000.0f) {
        float DeltaTime = BTClock.GetElapsedTime();
        MyBt->Tick(DeltaTime);
    }








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