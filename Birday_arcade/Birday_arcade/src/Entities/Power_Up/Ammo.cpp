#include "Ammo.h"



Ammo::Ammo(Image image, int ammotype, int x, int y)
{
	set_x(x);
	set_y(y);
	set_image(image);

	switch (ammotype)
	{
	case ROCKET_LAZER_AMMO:
		ammo_type = ROCKET_LAZER_AMMO;
		break;
	case STUNNER_AMMO:
		ammo_type = STUNNER_AMMO;
		break;
	case BOMB_AMMO:
		ammo_type = BOMB_AMMO;
		break;
	case ICE_BOMB_AMMO:
		ammo_type = ICE_BOMB_AMMO;
		break;
	case FIRE_BOMB_AMMO:
		ammo_type = FIRE_BOMB_AMMO;
		break;
	case ATOMIC_BOMB_AMMO:
		ammo_type = ATOMIC_BOMB_AMMO;
		break;
	case BI_NUKE_AMMO:
		ammo_type = BI_NUKE_AMMO;
		break;
	case TRI_NUKE_AMMO:
		ammo_type = TRI_NUKE_AMMO;
		break;
	case TRIANGULAR_MISSILE_AMMO:
		ammo_type = TRIANGULAR_MISSILE_AMMO;
		break;
	case ARROW_AMMO:
		ammo_type = ARROW_AMMO;
		break;
	case SLICER_AMMO:
		ammo_type = SLICER_AMMO;
		break;
	}

}


Ammo::~Ammo()
{

}

int Ammo::get_x()
{
	return this->x;
}

int Ammo::get_y()
{
	return this->y;
}

Image Ammo::get_image()
{
	return this->image;
}

void Ammo::set_x(int x)
{
	this->x = x;
}

void Ammo::set_y(int y)
{
	this->y = y;
}

void Ammo::set_image(Image image)
{
	this->image = image;
}

void Ammo::ammo_reload(Sound sound, Player* & player, Options option)
{
	player->set_num_of_ammo(player->get_num_of_ammo(ammo_type) + 1, ammo_type);

	if (option.get_sound_options())
	{
		al_play_sample_instance(sound.sound_effects(16));
	}
}

void Ammo::render()
{
	al_draw_bitmap(get_image().Ammo_image(ammo_type).first, get_x(), get_y(), NULL);
}
