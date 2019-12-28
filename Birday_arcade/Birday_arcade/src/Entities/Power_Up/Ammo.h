#include "Entities/Player/Player.h"
#include "global.h"
#include "Asset_management/Image.h"

#pragma once
class Ammo
{
public:
	Ammo(Image image, int ammotype, int x, int y);
	~Ammo();

	int get_x();
	int get_y();
	std::pair <ALLEGRO_BITMAP*, int> get_bitmap();

	//sets the x position, y position, and bitmap information/tags
	void set_x(int x);
	void set_y(int y);
	void set_bitmap(ALLEGRO_BITMAP *image, int entity_num);

	//functionality of the power up
	void ammo_reload(Sound sound, Player* &player);

	//displays the powerup
	void render();

private:
	//integer variables
	int x, y, ammo_type;

	//pair variables
	std::pair <ALLEGRO_BITMAP *, int> image;
};

