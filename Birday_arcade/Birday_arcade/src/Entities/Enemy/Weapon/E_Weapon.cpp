#include "E_Weapon.h"



E_Weapon::E_Weapon(Image &sprite_sheet, int x, int y, int vel, int direction)
{
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
}


E_Weapon::~E_Weapon()
{
}

int E_Weapon::get_x()
{
	return this->x;
}

int E_Weapon::get_y()
{
	return this->y;
}

int E_Weapon::get_vel()
{
	return this->vel;
}

int E_Weapon::get_direction()
{
	return this->direction;
}

std::pair<ALLEGRO_BITMAP*, int> E_Weapon::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(image.first, image.second);
}

void E_Weapon::set_x(int x)
{
	this->x = x;
}

void E_Weapon::set_y(int y)
{
	this->y = y;
}

void E_Weapon::set_vel(int vel)
{
	this->vel = vel;
}

void E_Weapon::set_direction(int direction)
{
	this->direction = direction;
}

void E_Weapon::set_bitmap(ALLEGRO_BITMAP * image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void E_Weapon::update()
{
	switch (get_direction())
	{
	case 0:
		set_x(get_x() + get_vel());
		break;
	case 1:
		set_x(get_x() - get_vel());
		break;
	case 2:
		set_y(get_y() + get_vel());
		break;
	case 3:
		set_y(get_y() - get_vel());
		break;
	}
}

void E_Weapon::render()
{
	if (al_get_bitmap_width(get_bitmap().first) > 160)
	{
		switch (get_direction())
		{
		case 0:
			al_draw_bitmap_region(get_bitmap().first, 240, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 1:
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 2:
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 3:
			al_draw_bitmap_region(get_bitmap().first, 160, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		}
	}

	else if (al_get_bitmap_width(get_bitmap().first) == 160)
	{
		switch (get_direction())
		{
		case 0:
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 1:
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 2:
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 3:
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		}
	}

	else if (al_get_bitmap_width(get_bitmap().first) == 80)
	{
		al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
	}
}
