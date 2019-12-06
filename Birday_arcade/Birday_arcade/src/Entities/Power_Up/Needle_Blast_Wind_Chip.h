#include "Power_Up.h"

#pragma once
class Needle_Blast_Wind_Chip: public Power_Up
{
public:
	Needle_Blast_Wind_Chip(Image image, int x, int y);
	~Needle_Blast_Wind_Chip();

private:
	int x, y;

	std::pair <ALLEGRO_BITMAP *, int> image;
};

