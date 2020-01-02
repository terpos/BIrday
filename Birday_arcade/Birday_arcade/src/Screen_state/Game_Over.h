#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Asset_management/Sound.h"
#include "Options.h"

#pragma once
class Game_Over
{
public:
	Game_Over();
	~Game_Over();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Sound sound, Font font, Options option);

private:
	Image image;
	int options;
	bool play;

	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;
};

