#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Font.h"

#pragma once
class Weapons_Unlocked_List
{
public:

	Weapons_Unlocked_List();
	~Weapons_Unlocked_List();

	void add_word_to_list(std::string word);

	std::string get_list(int index);

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Font font);

private:
	Image image;

	ALLEGRO_COLOR Sel = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR notSel = al_map_rgb(0, 255, 0);


	std::vector <std::string> listing;

	int page;
};

