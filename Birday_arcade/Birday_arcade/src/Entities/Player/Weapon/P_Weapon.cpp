#include "P_Weapon.h"



P_Weapon::P_Weapon(Image &sprite_sheet, int x, int y, int vel, int direction)
{
	//set_bitmap(sprite_sheet.Player_Weapon_image(0).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_kill(false);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);

	
	type = 0;
	

}


P_Weapon::~P_Weapon()
{
	
}

int P_Weapon::get_x()
{
	return this->x;
}

int P_Weapon::get_y()
{
	return this->y;
}

int P_Weapon::get_vel()
{
	return this->vel;
}

int P_Weapon::get_direction()
{
	return this->direction;
}

int P_Weapon::damage()
{
	return 0;
}

bool P_Weapon::is_dead()
{
	return this->kill;
}

std::pair<ALLEGRO_BITMAP*, int> P_Weapon::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->image.first, this->image.second);
}

void P_Weapon::set_x(int x)
{
	this->x = x;
}

void P_Weapon::set_y(int y)
{
	this->y = y;
}

void P_Weapon::set_vel(int vel)
{
	this->vel = vel;
}

void P_Weapon::set_direction(int direction)
{
	this->direction = direction;
}

void P_Weapon::set_kill(bool kill)
{
	this->kill = kill;
}

void P_Weapon::abilities(bool collide)
{
	
}

void P_Weapon::change_direction()
{
	std::uniform_int_distribution<int > d(0, 3);

	set_direction(d(movement));
}



void P_Weapon::set_bitmap(ALLEGRO_BITMAP * image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void P_Weapon::update()
{
	if (type == 0)
	{
		switch (get_direction())
		{
		case 0:
			set_y(get_y() + get_vel());
			break;
		case 1:
			set_y(get_y() - get_vel());
			break;
		case 2:
			set_x(get_x() + get_vel());
			break;
		case 3:
			set_x(get_x() - get_vel());
			break;
		}
	}

	else
	{
		set_x(get_x());
		set_y(get_y());
	}
	
}

void P_Weapon::render()
{
	if (al_get_bitmap_width(get_bitmap().first) > 160)
	{
		switch (get_direction())
		{
		case 0:
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 1:
			al_draw_bitmap_region(get_bitmap().first, 160, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 2:
			al_draw_bitmap_region(get_bitmap().first, 240, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 3:
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
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

	
}


