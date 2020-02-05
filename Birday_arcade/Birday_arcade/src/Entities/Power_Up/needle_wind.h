#include "Asset_management/Image.h"
#include "global.h"

#pragma once
class needle_wind
{
public:
	needle_wind(Image image);
	~needle_wind();

	Image get_image();

	int get_x();
	int get_y();

	void set_image(Image image);

	void set_x(int x);
	void set_y(int y);

	void go_right();

	void render();

private:
	int x, y, seed;
	Image image;

	std::default_random_engine rand_y;
	
};

