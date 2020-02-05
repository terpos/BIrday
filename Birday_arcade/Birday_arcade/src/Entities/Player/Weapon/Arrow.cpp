#include "Arrow.h"



Arrow::Arrow(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce): P_Weapon (sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(ARROW);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	set_hit(false, num_of_bounce);
	set_kill(false);


	type = 0;
}


Arrow::~Arrow()
{
}

int Arrow::damage()
{
	return 12;
}
