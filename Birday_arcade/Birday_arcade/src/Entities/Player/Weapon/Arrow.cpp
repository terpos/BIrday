#include "Arrow.h"



Arrow::Arrow(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon (sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(ARROW).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);

	kill_count = 0;
	type = 0;
}


Arrow::~Arrow()
{
}

int Arrow::damage()
{
	return 12;
}

void Arrow::abilities(bool collide)
{
	if (collide && kill_count == 3)
	{
		set_kill(true);
	}

	else
	{
		kill_count++;
	}
}
