#pragma once
#include <string>
class Shop
{
public:
	int ShopX;
	int ShopY;

	std::string article;

	int stock;
	int prix;

	Shop();
	virtual ~Shop();
	int GetPositionX();
	int GetPositionY();
	void setPrix();
	void setstock();
};

