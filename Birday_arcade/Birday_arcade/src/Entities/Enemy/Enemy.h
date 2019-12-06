#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Weapon/E_Weapon.h"
#include "Weapon/Bubble_Blast.h"
#include "Weapon/Diamond_Ice.h"
#include "Weapon/Fire.h"
#include "Weapon/Grapple.h"
#include "Weapon/Missile.h"
#include "Weapon/Star_Bomb.h"
#include "Weapon/Thunder.h"
#include "Weapon/Venom_Spit.h"

#pragma once
class Enemy
{
public:
	//puts in initial value
	Enemy(Image &sprite_sheet, int version, int x, int y, int vel, int direction);
	~Enemy();

	//gets x position, y position, speed, and direction of the player
	virtual int get_x();
	virtual int get_y();
	virtual int get_vel();
	virtual int get_direction();

	//gets the positive value of health
	virtual signed int get_health();

	//checks if the player is hit
	virtual std::pair <bool, int> is_hit();

	//gets the image information
	virtual std::pair <ALLEGRO_BITMAP*, int> get_bitmap();

	//sets the x position, y position, speed, and direction of the player 
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_direction(int direction);

	//sets the positive value of health
	virtual void set_health(signed int health);

	//sets whether the player is hit or not
	virtual void set_hit(bool ishit, int status);

	//sets the bitmap information
	virtual void set_bitmap(ALLEGRO_BITMAP* image, int entity_num);

	//updates the enemy's info when collided (player moves backward)
	virtual void col_update();

	//updates the enemies's info as well as the weapon's movement
	virtual void update(std::vector <E_Weapon*> &eweapon, Image spritesheet);

	//displays the enemies
	virtual void render();

private:
	//integer variables
	int x, y, vel, direction, nochange, reload_time;
	unsigned int health;

	//positive whole number variables
	unsigned seed;

	//boolean variables
	bool draw;
	
	//pair variables
	std::pair <bool, int> hit;
	std::pair <ALLEGRO_BITMAP*, int> image;

	//random engine instance variables
	std::default_random_engine movement;
	std::default_random_engine shooting_probability;

	//bitmap instance variables
	ALLEGRO_BITMAP* cropping;
};

