#include "Needle_Blast_Wind_Chip.h"



Needle_Blast_Wind_Chip::Needle_Blast_Wind_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(HEALTH_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Needle_Blast_Wind_Chip::~Needle_Blast_Wind_Chip()
{
}
