#include "global.h"

#pragma once
class Font
{
public:
	Font();
	~Font();

	void load();
	void Font_error_check();

	ALLEGRO_FONT *get_font(int textnum);

	void deallocate();

private:
	std::vector <ALLEGRO_FONT *> text;
	ALLEGRO_PATH *path;
};

