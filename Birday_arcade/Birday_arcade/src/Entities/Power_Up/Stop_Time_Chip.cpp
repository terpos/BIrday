#include "Stop_Time_Chip.h"



Stop_Time_Chip::Stop_Time_Chip(Image image, int x, int y): Power_Up(image, x, y)
{
	set_bitmap(image.Power_Up_image(STOP_CHIP).first, image.Power_Up_image(0).second);
	set_x(x);
	set_y(y);
}


Stop_Time_Chip::~Stop_Time_Chip()
{
}
