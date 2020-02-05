#include "asset_management/image.h"
#include "global.h"

#pragma once


class B_2_Bomber
{
public:
	B_2_Bomber(Image image);
	~B_2_Bomber();

	Image get_image();

	int get_x();
	int get_y();

	void set_image(Image image);

	void set_x(int x);
	void set_y(int y);

	void go_up();
	void render();

private:
	int x, y;
	Image image;
	
};

