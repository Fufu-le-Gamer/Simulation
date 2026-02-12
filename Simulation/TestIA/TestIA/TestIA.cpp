// TestIA.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <chrono>
#include <iostream>
#include <vector>
#include <thread>

#include "BehaviorTree.h"
#include "Node.h"
#include "Ia.h"
#include "Shop.h"

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


int main(int argc, char* argv[]) {

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

    while (continu) {
       
        nombre_client = rand() % 20 +1;
        /*Shop1->setstock();
        Shop1->setPrix();*/
        /*std::this_thread::sleep_for(dura);*/
        //std::cout << "\n\nnouveau jour\njour n" << compte_jour +1 << "\nnombre client:" << nombre_client << "\nprix :" << Shop1->prix << "\n\n";
    

        for (int i = 0; i < nombre_client; i++) {
            
            std::this_thread::sleep_for(dura);
            std::cout << Shop1->stock << "\n";
            MonIA->Setdemande();

            if (Shop1->stock <= 0)
            {
                std::cout << "y'en a plus\n";
            }
            else
            {
                if (Shop1->prix < MonIA->prix_demande - 1) {
                    Shop1->stock -= 1;
                }
                else {
                    std::cout << "trop cher\n";
                }

            }
        }
    }













    /*EnnemiBlackBoard* MyBlackBoard = new EnnemiBlackBoard();
    BehaviorTree* MyBt = new EnnemyBehaviorTree(MyBlackBoard);
    MyBt->BuildTree();
    MyBt->BeginExecute();

    while (BTClock.TimeSinceStart() < 10000.0f) {
        float DeltaTime = BTClock.GetElapsedTime();
        MyBt->Tick(DeltaTime);
    }
    return 0;*/
//}
