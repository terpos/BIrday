#include "Ammo.h"



Ammo::Ammo(Image image, int ammotype, int x, int y)
{
	set_x(x);
	set_y(y);
	switch (ammotype)
	{
	case ROCKET_LAZER_AMMO:
		set_bitmap(image.Ammo_image(ROCKET_LAZER_AMMO).first, image.Ammo_image(ROCKET_LAZER_AMMO).second);
		break;
	case STUNNER_AMMO:
		set_bitmap(image.Ammo_image(STUNNER_AMMO).first, image.Ammo_image(STUNNER_AMMO).second);
		break;
	case BOMB_AMMO:
		set_bitmap(image.Ammo_image(BOMB_AMMO).first, image.Ammo_image(BOMB_AMMO).second);
		break;
	case ICE_BOMB_AMMO:
		set_bitmap(image.Ammo_image(ICE_BOMB_AMMO).first, image.Ammo_image(ICE_BOMB_AMMO).second);
		break;
	case FIRE_BOMB_AMMO:
		set_bitmap(image.Ammo_image(FIRE_BOMB_AMMO).first, image.Ammo_image(FIRE_BOMB_AMMO).second);
		break;
	case ATOMIC_BOMB_AMMO:
		set_bitmap(image.Ammo_image(ATOMIC_BOMB_AMMO).first, image.Ammo_image(ATOMIC_BOMB_AMMO).second);
		break;
	case BI_NUKE_AMMO:
		set_bitmap(image.Ammo_image(BI_NUKE_AMMO).first, image.Ammo_image(BI_NUKE_AMMO).second);
		break;
	case TRI_NUKE_AMMO:
		set_bitmap(image.Ammo_image(TRI_NUKE_AMMO).first, image.Ammo_image(TRI_NUKE_AMMO).second);
		break;
	case TRIANGULAR_MISSILE_AMMO:
		set_bitmap(image.Ammo_image(TRIANGULAR_MISSILE_AMMO).first, image.Ammo_image(TRIANGULAR_MISSILE_AMMO).second);
		break;
	case ARROW_AMMO:
		set_bitmap(image.Ammo_image(ARROW_AMMO).first, image.Ammo_image(ARROW_AMMO).second);
		break;
	case SLICER_AMMO:
		set_bitmap(image.Ammo_image(SLICER_AMMO).first, image.Ammo_image(SLICER_AMMO).second);
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

std::pair<ALLEGRO_BITMAP*, int> Ammo::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->image.first, this->image.second);
}

void Ammo::set_x(int x)
{
	this->x = x;
}

void Ammo::set_y(int y)
{
	this->y = y;
}

void Ammo::set_bitmap(ALLEGRO_BITMAP * image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void Ammo::power_up_abilities(Player* & player)
{
}

void Ammo::render()
{
	al_draw_bitmap(get_bitmap().first, get_x(), get_y(), NULL);
}
