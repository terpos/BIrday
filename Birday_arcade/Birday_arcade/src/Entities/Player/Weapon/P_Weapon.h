/*
Classes that inherit this class will use the same functions
*/

#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Animation.h"

#pragma once
class P_Weapon
{
public:
	//puts in initial value
	P_Weapon(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce);
	~P_Weapon();

	//gets x position, y position, speed, direction, damage, effect on the enemy, and id of the weapon
	virtual int get_x();
	virtual int get_y();
	virtual int get_vel();
	virtual int get_direction();
	virtual int damage();
	virtual int enemy_status();
	virtual int get_id();

	//gets whether the weapon is dead and/or enemy is damaged or not
	virtual bool is_dead();
	virtual bool enemy_damaged();
	
	//returns bitmap value
	Image get_image();

	//gets the amount of hit and whether the weapon is hit or not
	virtual std::pair <bool, int> is_hit();

	//sets x position, y position, speed, direction, damage, effect on the enemy, and id of the weapon
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_direction(int direction);
	virtual void set_enemy_status(int status);
	virtual void set_id(int id);

	//sets the amount of hit and whether the weapon is hit or not
	virtual void set_hit(bool hit, int hit_count);

	//gets whether the weapon is dead and/or enemy is damaged or not
	virtual void set_kill(bool kill);
	virtual void set_enemy_damage(bool damage);

	//weapon's abilities
	virtual void abilities();

	//change direction of the weapon
	virtual void change_direction();

	//sets the bitmap information
	virtual void set_image(Image image);

	//update weapon info
	virtual void update();

	//displays the weapon
	virtual void render(Image expl, Sound sound, bool play_sound);

	//object variables
	Animation animation, weapon_explosion, bomb_detonate;
	
	//allegro bitmap varaiables
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

private:
	//integer variables
	int x, y, vel, direction, buttons[7], type, seed, hit_count, temp_vel, status_enemy, id;

	//boolean variable
	bool draw, kill, hit, damage_enemy;

	//random engine variables
	std::default_random_engine movement;

	//pair variable
	Image image;


};

