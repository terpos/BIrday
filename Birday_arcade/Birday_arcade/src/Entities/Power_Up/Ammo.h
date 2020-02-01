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
	Image get_image();

	//sets the x position, y position, and bitmap information/tags
	void set_x(int x);
	void set_y(int y);
	void set_image(Image image);

	//functionality of the power up
	void ammo_reload(Sound sound, Player* &player, Options option);

	//displays the powerup
	void render();

private:
	//integer variables
	int x, y, ammo_type;

	//image variables
	Image image;
};

