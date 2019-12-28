#include "TriNuke.h"



TriNuke::TriNuke(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon (sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(TRI_NUKE).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	
	set_hit(false, 2);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);

	this->type = 1;
}


TriNuke::~TriNuke()
{
}

int TriNuke::damage()
{
	return 10;
}



void TriNuke::render(Image expl)
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
				al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}

		else if (is_hit().second == 1)
		{
			if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_bitmap().first, 0, 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_bitmap().first, 80, 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}

		else if (is_hit().second == 0)
		{
			if (animation.get_frame_position(11) >= 0 && animation.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_bitmap().first, 0, 160, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}

			else if (animation.get_frame_position(11) > 5)
			{
				al_draw_bitmap_region(get_bitmap().first, 80, 160, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

			}
		}
	}
}
