#include "Power_Up.h"



Power_Up::Power_Up(Image image, int x, int y)
{
	set_bitmap(image.Power_Up_image(0).first, image.Power_Up_image(0).second);
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

std::pair<ALLEGRO_BITMAP*, int> Power_Up::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(image.first, image.second);
}

void Power_Up::set_x(int x)
{
	this->x = x;
}

void Power_Up::set_y(int y)
{
	this->y = y;
}

void Power_Up::set_bitmap(ALLEGRO_BITMAP * image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void Power_Up::power_up_abilities(Player* &player, std::vector <Enemy*> &enemy)
{
}

void Power_Up::render()
{
	al_draw_bitmap(get_bitmap().first, get_x(), get_y(), NULL);
}
