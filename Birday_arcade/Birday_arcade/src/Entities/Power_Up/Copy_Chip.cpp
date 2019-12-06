#include "Copy_Chip.h"



Copy_Chip::Copy_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(COPY_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Copy_Chip::~Copy_Chip()
{
}
