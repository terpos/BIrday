#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Screen_state/Options.h"
#include "Entities/Player/Weapon/P_Weapon.h"
#include "Entities/Player/Weapon/Arrow.h"
#include "Entities/Player/Weapon/Atom_Bomb.h"
#include "Entities/Player/Weapon/BiNuke.h"
#include "Entities/Player/Weapon/Bomb.h"
#include "Entities/Player/Weapon/Fire_bomb.h"
#include "Entities/Player/Weapon/Ice_Bomb.h"
#include "Entities/Player/Weapon/Lazer.h"
#include "Entities/Player/Weapon/Rocket_lazer.h"
#include "Entities/Player/Weapon/Slicer.h"
#include "Entities/Player/Weapon/Stunner.h"
#include "Entities/Player/Weapon/Triangular_Missle.h"
#include "Entities/Player/Weapon/TriNuke.h"

#pragma once
class Player
{
public:
	//puts in initial value
	Player(Image &sprite_sheet, int x, int y, int vel, int direction, int buttons[7]);
	~Player();

	//gets x position, y position, speed, and direction of the player
	int get_x();
	int get_y();
	int get_vel();
	int get_direction();

	bool is_gliding();
	
	//gets the positive value of health
	signed int get_health();

	//controls the player when a key is hit
	void control(Image spritesheet, ALLEGRO_EVENT e, std::vector <P_Weapon*> &pweapon);
	
	//checks if the player is hit
	std::pair <bool, int> is_hit();

	//gets the image information
	std::pair <ALLEGRO_BITMAP*, int> get_bitmap();

	//returns the buttons
	int get_buttons(int index);

	int get_delay_movement();

	//sets the x position, y position, speed, and direction of the player 
	void set_x(int x);
	void set_y(int y);
	void set_vel(int vel);
	void set_direction(int direction);

	//sets the positive value of health
	void set_health(signed int health);

	//sets whether the player is hit or not
	void set_hit(bool ishit, int status);

	//sets the bitmap information
	void set_bitmap(ALLEGRO_BITMAP* image, int entity_num);

	//sets the button configurations
	void set_buttons(int buttons[7]);

	//updates the player's movement when collided (player moves backward)
	void damage_col_update();
	
	void set_delay_movemement(int delay);

	void damage_col_tile_update();

	void col_update();

	void set_glide(bool glide);

	//updates the player's movement as well as the weapon's movement
	void update(Options &option, std::vector <P_Weapon*> &pweapon);

	//displays the player
	void render();

private:
	//integer variables
	int x, y, vel, direction, buttons[7], delay_movement, recover, option_weapon;
	unsigned int health;

	//boolean variables and boolean variables array
	bool draw, glide;
	bool key[4];

	//pair variables
	std::pair <bool, int> hit;
	std::pair <ALLEGRO_BITMAP*, int> image;

	//bitmap instance variable
	ALLEGRO_BITMAP* cropping;	
};

