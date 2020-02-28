#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Asset_management/Sound.h"
#include "key_strings_allegro.h"

#pragma once
class Options
{
public:
	Options();
	~Options();

	//control options for player
	int get_control_options(int index);
	void set_control_options(int buttons[7]);

	//whether sound is mute or not
	bool get_sound_options();
	void set_sound_options(bool sound);

	//gets the last screen after option
	int get_last_screen();
	void set_last_screen(int screennum);

	//last screen that goes to option
	int get_last_screen_to_option();
	void set_last_screen_to_option(int screennum);

	//whether it quits or not
	bool is_quitting();
	void set_quit(bool quit);

	//different tile style
	int get_tile_options();
	void set_tile_options(int tile_options);

	//different difficulty options
	int get_difficulty_options();
	void Set_difficulty_options(int difficulty_option);

	//levels appropiate for difficulty
	int get_level_for_difficulty();

	//updates info
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Sound sound, Image image, ALLEGRO_EVENT &e, int &screennum, bool &done);
	
	//renders assets
	void render(Image image, Font font);

private:
	//option variable
	Image image;

	//int variables
	int options, tile_options, difficulty_option, control_option[7], screennum, num_of_key_pressed, max_options, to_option;
	
	//boolean variables
	bool sound_options, press_any_key, quit;

	//allegro color variables
	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR SelOption;
	ALLEGRO_COLOR notSel;
	ALLEGRO_COLOR notSelOption;
};

