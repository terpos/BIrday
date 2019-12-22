#include "global.h"

#pragma once
class Font
{
public:
	Font();
	~Font();

	void load();

	ALLEGRO_FONT *get_font(int textnum);

	void deallocate();

private:
	std::vector <ALLEGRO_FONT *> text;
};

