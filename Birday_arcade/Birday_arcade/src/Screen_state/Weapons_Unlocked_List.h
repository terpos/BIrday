#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Font.h"
#include "Options.h"

#pragma once
class Weapons_Unlocked_List
{
public:

	Weapons_Unlocked_List();
	~Weapons_Unlocked_List();

	//adds words to game status screen
	void add_weapon_word_list(std::string word);

	//adds word to this screen
	void add_word_to_screen(std::string word);

	//gets the weapon list
	std::string get_weapon_list(int index);

	//gets all weapon and abilities list
	std::string get_screen_list(int index);

	//clears all the list
	void clear_all();

	//updates infos
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	
	//render assets
	void render(Image image, Font font);

private:
	//object variable
	Image image;

	//allegro color variables
	ALLEGRO_COLOR Sel = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR notSel = al_map_rgb(0, 255, 0);

	//string vector variables
	std::vector <std::string> listing, listing2;

	//int variables
	int move_over, move_down;
};

