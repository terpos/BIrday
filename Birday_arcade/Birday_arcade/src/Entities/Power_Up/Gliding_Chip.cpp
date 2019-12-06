#include "Gliding_Chip.h"



Gliding_Chip::Gliding_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(GLIDING_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Gliding_Chip::~Gliding_Chip()
{
}
