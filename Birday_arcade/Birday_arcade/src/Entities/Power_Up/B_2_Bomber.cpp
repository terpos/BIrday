#include "B_2_Bomber.h"

B_2_Bomber::B_2_Bomber(Image image)
{
	set_x(0);
	set_y(1360);
	set_image(image);
}

B_2_Bomber::~B_2_Bomber()
{
}

Image B_2_Bomber::get_image()
{
	return Image(image);
}

int B_2_Bomber::get_x()
{
	return this->x;
}

int B_2_Bomber::get_y()
{
	return this->y;
}

void B_2_Bomber::set_image(Image image)
{
	this->image = image;
}

void B_2_Bomber::set_x(int x)
{
	this->x = x;
}

void B_2_Bomber::set_y(int y)
{
	this->y = y;
}

void B_2_Bomber::go_up()
{
	set_y(get_y() - 50);
}

void B_2_Bomber::render()
{
	al_draw_bitmap(get_image().misc_image(0).first, get_x(), get_y(), NULL);
}
