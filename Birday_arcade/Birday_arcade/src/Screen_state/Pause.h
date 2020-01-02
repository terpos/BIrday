#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Options.h"

#pragma once
class Pause
{
public:
	Pause();
	~Pause();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Font font);

private:
	Image image;
	int options;

	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR notSel;
};

