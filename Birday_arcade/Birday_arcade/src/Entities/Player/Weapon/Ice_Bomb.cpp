#include "Ice_Bomb.h"



Ice_Bomb::Ice_Bomb(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_id(ICE_BOMBS);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	type = 0;
}


Ice_Bomb::~Ice_Bomb()
{
}

void Ice_Bomb::abilities()
{
	if (weapon_explosion.get_frame() > 0)
	{
		set_enemy_status(2);
		set_hit(true, is_hit().second);
		set_enemy_damage(true);
	}
}


void Ice_Bomb::render(Image expl, Sound sound, bool play_sound)
{
	if (weapon_explosion.get_frame() > 0)
	{
		if (play_sound)
		{
			al_set_sample_instance_position(sound.sound_effects(1), 0);
			al_play_sample_instance(sound.sound_effects(1));
		}
	}
	if (bomb_detonate.get_frame() < 200)
	{
		if (bomb_detonate.get_frame() <= 100)
		{
			if (bomb_detonate.get_frame_position(21) >= 0 && bomb_detonate.get_frame_position(21) <= 10)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 0, 0, al_get_bitmap_width(cropping2), al_get_bitmap_height(cropping2), get_x(), get_y(), NULL);
			}

			else
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 40, 0, al_get_bitmap_width(cropping2), al_get_bitmap_height(cropping2), get_x(), get_y(), NULL);
			}
		}

		else if (bomb_detonate.get_frame() > 100)
		{
			if (bomb_detonate.get_frame_position(11) >= 0 && bomb_detonate.get_frame_position(11) <= 5)
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 0, 0, al_get_bitmap_width(cropping2), al_get_bitmap_height(cropping2), get_x(), get_y(), NULL);
			}

			else
			{
				al_draw_bitmap_region(get_image().Player_Weapon_image(get_id()).first, 40, 0, al_get_bitmap_width(cropping2), al_get_bitmap_height(cropping2), get_x(), get_y(), NULL);
			}
		}
	}

	else
	{
		if (weapon_explosion.get_frame_position(11) >= 0 && weapon_explosion.get_frame_position(11) <= 5)
		{
			al_draw_bitmap_region(expl.Destruction_image(2).first, 160, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

		}

		else
		{
			al_draw_bitmap_region(expl.Destruction_image(2).first, 160, 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}
	}
}
