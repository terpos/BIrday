#include "Animation.h"



Animation::Animation()
{
	set_frame(0);
}


Animation::~Animation()
{
}

int Animation::get_frame_position(int speed)
{
	return get_frame() % speed;
}

int Animation::get_frame()
{
	return this->frame;
}

void Animation::set_frame(int frame)
{
	this->frame = frame;
}

void Animation::reset_frame()
{
	set_frame(0);
}

void Animation::increment_frame()
{
	this->frame++;
}
