#include "Power_Up.h"



Power_Up::Power_Up(Image image, int x, int y)
{
	set_image(image);
	set_x(x);
	set_y(y);
}


Power_Up::~Power_Up()
{
}

int Power_Up::get_x()
{
	return this->x;
}

int Power_Up::get_y()
{
	return this->y;
}

Image Power_Up::get_image()
{
	return this->image;
}

int Power_Up::get_id()
{
	return this->id;
}

void Power_Up::set_x(int x)
{
	this->x = x;
}

void Power_Up::set_y(int y)
{
	this->y = y;
}

void Power_Up::set_image(Image image)
{
	this->image = image;
}

void Power_Up::set_id(int id)
{
	this->id = id;
}

void Power_Up::power_up_abilities(Sound sound, Player* &player, std::vector <Enemy*> &enemy, Options option)
{
}

void Power_Up::render()
{
	al_draw_bitmap(get_image().Power_Up_image(get_id()).first, get_x(), get_y(), NULL);
}
