#include "Entities/Player/Player.h"
#include "Entities/Enemy/Enemy.h"
#include "Asset_management/Image.h"
#include "global.h"

#pragma once
class Power_Up
{
public:
	//puts in initial value
	Power_Up(Image image, int x, int y);
	~Power_Up();

	//gets the x position, y position, and bitmap information/tags
	virtual int get_x();
	virtual int get_y();
	virtual std::pair <ALLEGRO_BITMAP*, int> get_bitmap();

	//sets the x position, y position, and bitmap information/tags
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_bitmap(ALLEGRO_BITMAP *image, int entity_num);

	//functionality of the power up
	virtual void power_up_abilities(Player &player, std::vector <Enemy*> &enemy);

	//displays the powerup
	virtual void render();

private:
	//integer variables
	int x, y;
	
	//pair variables
	std::pair <ALLEGRO_BITMAP *, int> image;

	
};

