#include "Stunner.h"



Stunner::Stunner(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce):P_Weapon (sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(STUNNER);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	set_hit(false, num_of_bounce);

	


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
