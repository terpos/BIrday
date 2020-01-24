#include "Stunner.h"



Stunner::Stunner(Image &sprite_sheet, int x, int y, int vel, int direction):P_Weapon (sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(STUNNER).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	set_hit(false, 0);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);


	type = 1;
}


Stunner::~Stunner()
{
}

int Stunner::damage()
{
	return 3;
}

void Stunner::abilities()
{
	set_enemy_status(4);
	set_hit(true, is_hit().second);
	set_enemy_damage(true);
}
