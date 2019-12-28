#pragma once
class Animation
{
public:
	Animation();
	~Animation();
	
	int get_frame_position(int speed);
	int get_frame();

	void set_frame(int frame);
	void reset_frame();
	void increment_frame();

private:
	int frame;

};

