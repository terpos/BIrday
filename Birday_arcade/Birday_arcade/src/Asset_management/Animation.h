#pragma once
class Animation
{
public:
	Animation();
	~Animation();
	
	int get_frame_position(int speed);
	int get_frame();
	float get_alpha();
	int get_num_of_fades();


	void set_frame(int frame);
	void set_alpha(float alpha);

	void reset_frame();
	void increment_frame();
	
	void fade_in(float speed);
	void fade_in(float speed, float stop_at);
	void fade_out(float speed);
	void fade_transition();

	void enable_fade_in(bool enable);
	void enable_fade_out(bool enable);

private:
	int frame;

	float  alpha, number_of_fades;

	bool fade[2];

};

