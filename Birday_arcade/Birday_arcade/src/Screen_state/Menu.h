#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Asset_management/Sound.h"
#include "Options.h"
#include "Asset_management/Animation.h"

#pragma once
class Menu
{
public:
	Menu();
	~Menu();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Sound sound, Font font);

	void error_notify(Font font, int x);

private:
	Image image;

	int options;
	bool rect_out;

	Animation title, bg, choice, intro;

	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;

};

