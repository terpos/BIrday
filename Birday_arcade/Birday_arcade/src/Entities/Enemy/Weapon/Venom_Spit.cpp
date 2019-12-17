#include "Venom_Spit.h"



Venom_Spit::Venom_Spit(Image &sprite_sheet, int x, int y, int vel, int direction): E_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Enemy_Weapon_image(VENOM_SPIT).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
}


Venom_Spit::~Venom_Spit()
{
}

int Venom_Spit::damage()
{
	return 15;
}
