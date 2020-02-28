/*
Classes that inherit this class will use the same functions
*/

#include "Entities/Player/Player.h"
#include "Entities/Enemy/Enemy.h"
#include "Asset_management/Image.h"
#include "B_2_Bomber.h"
#include "needle_wind.h"
#include "global.h"

#pragma once
class Power_Up
{
public:
	//puts in initial value
	Power_Up(Image image, int x, int y);
	~Power_Up();

	//gets the x position, y position, image information/tags, and class id
	virtual int get_x();
	virtual int get_y();
	virtual Image get_image();
	virtual int get_id();

	//sets the x position, y position, and image information/tags
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_image(Image image);

	//gets random power up
	virtual int get_random_powerup();

	//sets the id of the power up
	virtual void set_id(int id);

	//functionality of the power up
	virtual void power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, std::vector <B_2_Bomber*> &b2, std::vector <needle_wind*> &nw, Options option);

	//displays the powerup
	virtual void render();

private:
	//integer variables
	int x, y, id, image_x, image_y;
	
	//pair variables
	Image image;

	
};

