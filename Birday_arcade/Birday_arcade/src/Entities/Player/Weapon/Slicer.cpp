#include "Slicer.h"



Slicer::Slicer(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(SLICER).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	set_hit(false, 0);
	animation.set_frame(0);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);
	set_kill(false);

	type = 1;
}


Slicer::~Slicer()
{
}

int Slicer::damage()
{
	return 20;
}

void Slicer::abilities()
{
	if (get_x() < 0 || get_x() + 80 > 1360 || get_y() < 0 || get_y() + 80 > 720)
	{
		set_hit(true, is_hit().second);
	}

	else
	{
		set_hit(false, is_hit().second);
		set_enemy_damage(true);
	}
}

void Slicer::render(Image expl, Sound sound)
{
	if (is_hit().first)
	{
		if (weapon_explosion.get_frame_position(11) >= 0 && weapon_explosion.get_frame_position(11) <= 5)
		{
			al_draw_bitmap_region(expl.Destruction_image(1).first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

		}

		else
		{
			al_draw_bitmap_region(expl.Destruction_image(1).first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}
	}

	else
	{
		if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
		{
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

		}

		else if (animation.get_frame_position(11) > 5)
		{
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

		}
	}
	
	
}


