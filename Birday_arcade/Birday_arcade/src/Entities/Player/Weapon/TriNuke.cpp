#include "TriNuke.h"



TriNuke::TriNuke(Image &sprite_sheet, int x, int y, int vel, int direction, int num_of_bounce): P_Weapon (sprite_sheet, x, y, vel, direction, num_of_bounce)
{
	set_id(TRI_NUKE);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	
	set_hit(false, num_of_bounce);

	this->type = 1;
}


TriNuke::~TriNuke()
{
}

int TriNuke::damage()
{
	return 10;
}



void TriNuke::render(Image expl, Sound sound, bool play_sound)
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
		if (is_hit().second == 2)
		{
			if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}

		else if (is_hit().second == 1)
		{
			if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 0, 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 80, 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}

		else if (is_hit().second == 0)
		{
			if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 0, 160, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 80, 160, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}
	}
}
