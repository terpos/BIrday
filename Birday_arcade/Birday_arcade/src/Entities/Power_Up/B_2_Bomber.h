#include "asset_management/image.h"
#include "global.h"

#pragma once


class B_2_Bomber
{
public:
	//intial value
	B_2_Bomber(Image image);
	~B_2_Bomber();

	//gets the image info, x, and y
	Image get_image();

	int get_x();
	int get_y();

	//sets the image info, x and y
	void set_image(Image image);

	void set_x(int x);
	void set_y(int y);

	//b2 bomber goes up
	void go_up();

	//renders the assets
	void render();

private:
	//int variables
	int x, y;

	//object variable
	Image image;
	
};

