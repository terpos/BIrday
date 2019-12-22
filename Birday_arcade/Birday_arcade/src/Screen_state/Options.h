#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "key_strings_allegro.h"

#pragma once
class Options
{
public:
	Options();
	~Options();

	int get_control_options(int index);
	void set_control_options(int buttons[7]);

	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, ALLEGRO_EVENT &e, int &screennum, bool &done);
	void render(Image image, Font font);

private:
	Image image;
	int options, sound_options, tile_options, difficulty_option, control_option[7];

	ALLEGRO_COLOR Sel;
	ALLEGRO_COLOR SelOption;
	ALLEGRO_COLOR notSel;
	ALLEGRO_COLOR notSelOption;
};

