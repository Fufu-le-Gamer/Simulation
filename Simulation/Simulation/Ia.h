#pragma once

#include <string>
#include <vector>

class Shop;

class Ia
{
public:
	int IaX;
	int IaY;

	int prix_demande;

	Ia();
	virtual ~Ia();
	/*int GetPositionX();
	int GetPositionY();*/
	void SetShop(Shop* NewShop);
	//void GoTo(int IaX, int IaY, int ObjectifX, int ObjectifY);
	void Setdemande();
public:
	Shop* IAShop;
};

