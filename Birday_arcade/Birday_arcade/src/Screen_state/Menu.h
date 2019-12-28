#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Asset_management/Sound.h"

#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Sound sound, Font font);

private:
	Image image;

	int options;

	ALLEGRO_COLOR Sel = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR notSel = al_map_rgb(0, 255, 0);

};

