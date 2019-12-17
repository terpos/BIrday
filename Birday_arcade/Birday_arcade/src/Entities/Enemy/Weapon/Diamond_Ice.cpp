#include "Diamond_Ice.h"



Diamond_Ice::Diamond_Ice(Image &sprite_sheet, int x, int y, int vel, int direction): E_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Enemy_Weapon_image(DIAMOND_ICE).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
}


Diamond_Ice::~Diamond_Ice()
{
}

int Diamond_Ice::damage()
{
	return 20;
}
