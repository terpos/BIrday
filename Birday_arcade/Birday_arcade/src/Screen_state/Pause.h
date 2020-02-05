#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Options.h"
#include "Game.h"

#pragma once
class Pause
{
public:
	Pause();
	~Pause();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Options &option, Game &game, ALLEGRO_EVENT &e, Weapons_Unlocked_List &weapons_unlocked, int &screennum, bool &done);
	void render(Image image, Font font);

private:
	Image image;
	int options;

	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;
};

