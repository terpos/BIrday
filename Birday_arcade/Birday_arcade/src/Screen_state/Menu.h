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

	//updates infos
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	
	//renders assets
	void render(Image image, Sound sound, Font font);

	void error_notify(Font font, int x);

private:
	//object variables
	Image image;
	Animation title, bg, choice, intro;

	//int variable
	int options;

	//boolean variable
	bool rect_out;
	
	//allegro color variables
	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;

};

