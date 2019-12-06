#include "Power_Up.h"

#pragma once
class Copy_Chip:public Power_Up
{
public:
	Copy_Chip(Image image, int x, int y);
	~Copy_Chip();

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;


};

