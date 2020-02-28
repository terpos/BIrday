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

	//updates info
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	
	//renders assets
	void render(Image image, Sound sound, Font font, Options option);

private:
	//object variable
	Image image;

	//int variable
	int options;

	//boolean variable
	bool play;

	//allegro color variables
	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;
};

