#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"

#pragma once
class E_Weapon
{
public:
	//puts in initial value
	E_Weapon(Image &sprite_sheet, int x, int y, int vel, int direction);
	~E_Weapon();

	//gets x position, y position, speed, and direction of the player
	virtual int get_x();
	virtual int get_y();
	virtual int get_vel();
	virtual int get_direction();
	virtual int get_id();

	//returns bitmap value
	virtual Image get_image();

	//sets the x position, y position, speed, and direction of the player 
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_direction(int direction);
	virtual void set_id(int id);

	virtual int damage() = 0;

	//sets the bitmap information
	virtual void set_image(Image image);

	//update weapon info
	virtual void update();

	//displays the weapon
	virtual void render();

private:
	//integer variables
	int x, y, vel, direction, buttons[7], type, id;

	//boolean variable
	bool draw;

	//bitmap instance variables
	ALLEGRO_BITMAP *cropping;

	//pair variable
	Image image;

};

