#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Options.h"

#pragma once
class Game_Materials
{
public:
	Game_Materials();
	~Game_Materials();

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Font font);

private:
	Image image;
	int page;
};

