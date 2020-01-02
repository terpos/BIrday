#include "Sound.h"



Sound::Sound()
{
}


Sound::~Sound()
{
}

void Sound::Load_Sound()
{
	al_reserve_samples(30);
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Game_over.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Level_1-4.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Level_5-14.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Level_15-24.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Level_25-44.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Level_45-UP.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Background_Music/Menu.ogg"));

	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Arrow.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Blast.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Blasters.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Boing.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Bubble.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Clang.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Damage.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Enemy_Damage.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Enemy_Destroy.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Fast_Sparkling_Whoosh.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Flame_Arrow.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Gunk.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Health.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Laser_shot_scilenced.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Liquid_Ice.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Missile_Launcher_Explosion.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Power_up.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Select.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Slicer.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Spit_splat.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Tape_Slow_Down.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Wind.ogg"));
	sample.push_back(al_load_sample("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Sound/Sound_Effects/Zap.ogg"));

	for (int i = 0; i < 7; i++)
	{
		bg.push_back(al_create_sample_instance(sample[i]));
		al_attach_sample_instance_to_mixer(bg[i], al_get_default_mixer());
	}

	for (int i = 7; i < sample.size(); i++)
	{
		sound_fx.push_back(al_create_sample_instance(sample[i]));
		
	}
	
	for (int i = 0; i < sound_fx.size(); i++)
	{
		al_attach_sample_instance_to_mixer(sound_fx[i], al_get_default_mixer());
		al_set_sample_instance_playmode(sound_fx[i], ALLEGRO_PLAYMODE_ONCE);
		al_set_sample_instance_gain(sound_fx[i], .5f);
	}
}

void Sound::Sound_error_check()
{
}

ALLEGRO_SAMPLE_INSTANCE* Sound::bg_music(int bgmusic)
{
	return this->bg[bgmusic];
}

ALLEGRO_SAMPLE_INSTANCE* Sound::sound_effects(int soundeffects)
{
	
	return this->sound_fx[soundeffects];
	

	return 0;
}

void Sound::Deallocate_sound()
{
	for (int i = 0; i < bg.size(); i++)
	{
		al_destroy_sample_instance(this->bg[i]);
	}
	
	for (int i = 0; i < sound_fx.size(); i++)
	{
		al_destroy_sample_instance(this->sound_fx[i]);
	}

	for (int i = 0; i < sample.size(); i++)
	{
		al_destroy_sample(this->sample[i]);
	}
}
