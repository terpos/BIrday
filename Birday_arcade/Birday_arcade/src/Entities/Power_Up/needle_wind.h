#include "Asset_management/Image.h"
#include "global.h"

#pragma once
class needle_wind
{
public:
	//initial variable
	needle_wind(Image image);
	~needle_wind();

	//gets image info, x, and y
	Image get_image();
	int get_x();
	int get_y();

	//sets image info, x, and y
	void set_image(Image image);
	void set_x(int x);
	void set_y(int y);

	//goes right
	void go_right();

	//displays needle wind
	void render();

private:
	//int variables
	int x, y, seed;

	//object variables
	Image image;

	//random engine variables
	std::default_random_engine rand_y;
	
};

