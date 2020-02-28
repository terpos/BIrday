#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Options.h"

#pragma once
class Quit
{
public:
	Quit();
	~Quit();

	//updates info
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	
	//renders assets
	void render(Image image, Font font);

private:
	//object variable
	Image image;

	//int variable
	int options;

	//allegro color variables
	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;
};

