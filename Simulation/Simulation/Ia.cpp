#include "Ia.h"
#include "Shop.h"
#include <iostream>

Ia::Ia() {

}

Ia::~Ia() {
	delete IAShop;
}

void Ia::SetShop(Shop* NewShop)
{
	IAShop = NewShop;
}

void Ia::Setdemande() {
	prix_demande = rand() % 5 + 1;
}

