#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"

#pragma once
class P_Weapon
{
public:
	//puts in initial value
	P_Weapon(Image &sprite_sheet, int x, int y, int vel, int direction);
	~P_Weapon();

	//gets x position, y position, speed, and direction of the player
	virtual int get_x();
	virtual int get_y();
	virtual int get_vel();
	virtual int get_direction();
	virtual int damage();

	virtual bool is_dead();

	//returns bitmap value
	std::pair <ALLEGRO_BITMAP*, int> get_bitmap();

	//sets the x position, y position, speed, and direction of the player 
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_direction(int direction);
	virtual void set_kill(bool kill);
	virtual void abilities(bool collide);

	virtual void change_direction();

	//sets the bitmap information
	virtual void set_bitmap(ALLEGRO_BITMAP* image, int entity_num);

	//update weapon info
	virtual void update();

	//displays the weapon
	virtual void render();

private:
	//integer variables
	int x, y, vel, direction, buttons[7], type;

	//boolean variable
	bool draw, kill;

	//bitmap instance variables
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;


	std::default_random_engine movement;

	//pair variable
	std::pair <ALLEGRO_BITMAP*, int> image;


};

