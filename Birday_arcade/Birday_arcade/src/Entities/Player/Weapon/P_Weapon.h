#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Animation.h"

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
	virtual int enemy_status();
	virtual int get_id();

	virtual bool is_dead();
	virtual bool enemy_damaged();
	

	//returns bitmap value
	Image get_image();

	virtual std::pair <bool, int> is_hit();

	//sets the x position, y position, speed, and direction of the player 
	virtual void set_x(int x);
	virtual void set_y(int y);
	virtual void set_vel(int vel);
	virtual void set_direction(int direction);
	virtual void set_kill(bool kill);
	virtual void abilities();
	virtual void set_enemy_damage(bool damage);
	virtual void set_enemy_status(int status);
	virtual void set_id(int id);

	virtual void set_hit(bool hit, int hit_count);

	virtual void change_direction();

	//sets the bitmap information
	virtual void set_image(Image image);

	//update weapon info
	virtual void update();

	//displays the weapon
	virtual void render(Image expl, Sound sound, bool play_sound);


	Animation animation, weapon_explosion, bomb_detonate;
	ALLEGRO_BITMAP *cropping;
	ALLEGRO_BITMAP *cropping2;

private:
	//integer variables
	int x, y, vel, direction, buttons[7], type, seed, hit_count, temp_vel, status_enemy, id;

	//boolean variable
	bool draw, kill, hit, damage_enemy;

	//bitmap instance variables
	


	std::default_random_engine movement;

	//pair variable
	Image image;


};

