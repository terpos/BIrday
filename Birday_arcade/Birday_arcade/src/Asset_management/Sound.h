#include "global.h"

#pragma once
class Sound
{
public:
	Sound();
	~Sound();
	//loads the sound files (.ogg)
	void Load_Sound();

	//throws error if the sound files are not loaded correctly
	void Sound_error_check();

	//returns the background music
	ALLEGRO_SAMPLE_INSTANCE* bg_music(int bgmusic);

	//returns sound effects	
	ALLEGRO_SAMPLE_INSTANCE* sound_effects(int soundeffects);
		
	//destroys sound memory
	void Deallocate_sound();



private:
	//sample variable
	std::vector <ALLEGRO_SAMPLE *> sample;

	//sample instance variables
	std::vector <ALLEGRO_SAMPLE_INSTANCE *> bg, sound_fx;



};

