#include "Animation.h"



Animation::Animation()
{
	set_frame(0);
	fade[0] = true;
	fade[1] = true;
	number_of_fades = 0;
	
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

float Animation::get_alpha()
{
	return this->alpha;
}

int Animation::get_num_of_fades()
{
	return this->number_of_fades;
}

void Animation::set_frame(int frame)
{
	this->frame = frame;
}

void Animation::set_alpha(float alpha)
{
	this->alpha = alpha;
}

void Animation::reset_frame()
{
	set_frame(0);
}

void Animation::increment_frame()
{
	this->frame++;
}

void Animation::fade_in(float speed)
{
	if (alpha < 255 && fade[0])
	{
		set_alpha(get_alpha() + speed);
	}
}

void Animation::fade_in(float speed, float stop_at)
{
	if (alpha < stop_at && fade[0])
	{
		set_alpha(get_alpha() + speed);
	}
}

void Animation::fade_out(float speed)
{
	if (get_alpha() > 0 && fade[1])
	{
		set_alpha(get_alpha() - speed);
	}
}

void Animation::fade_transition()
{
	if (get_alpha() >= 255)
	{
		number_of_fades++;
		enable_fade_in(false);
		enable_fade_out(true);
	}

	
}

void Animation::enable_fade_in(bool enable)
{
	this->fade[0] = enable;
}

void Animation::enable_fade_out(bool enable)
{
	this->fade[1] = enable;
}
