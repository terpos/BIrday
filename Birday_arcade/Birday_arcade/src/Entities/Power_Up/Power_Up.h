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
	virtual Image get_image();
	virtual int get_id();

	//sets the x position, y position, and bitmap information/tags
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_image(Image image);
	virtual void set_id(int id);

	//functionality of the power up
	virtual void power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, Options option);

	//displays the powerup
	virtual void render();

private:
	//integer variables
	int x, y, id;
	
	//pair variables
	Image image;

	
};

