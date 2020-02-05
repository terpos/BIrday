#include "needle_wind.h"

needle_wind::needle_wind(Image image)
{
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	rand_y.seed(seed);
	
	std::uniform_int_distribution <int> randomy(1, 7);

	set_image(image);
	
	set_x(0);
	set_y(randomy(rand_y)*80);

}

needle_wind::~needle_wind()
{
}

Image needle_wind::get_image()
{
	return Image(image);
}

int needle_wind::get_x()
{
	return this->x;
}

int needle_wind::get_y()
{
	return this->y;
}

void needle_wind::set_image(Image image)
{
	this->image = image;
}

void needle_wind::set_x(int x)
{
	this->x = x;
}

void needle_wind::set_y(int y)
{
	this->y = y;
}

void needle_wind::go_right()
{
	x += 20;
}

void needle_wind::render()
{
	al_draw_bitmap(get_image().misc_image(1).first, get_x(), get_y(), NULL);
}
