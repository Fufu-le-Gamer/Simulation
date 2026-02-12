#include "Shop.h"
#include <iostream>
#include <random>


Shop::Shop() {

}

Shop::~Shop() {

}

void Shop::setPrix() {
	prix = rand() % 3 + 1;
}

void Shop::setstock() {
	stock = rand() % 20 + 1;
}

