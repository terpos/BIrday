#include "Font.h"

Font::Font()
{
}

Font::~Font()
{
	text.clear();
}

void Font::load()
{

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Assets");

	al_set_path_filename(path, "Font/pixelmix.ttf");

	text.push_back(al_load_font(al_path_cstr(path, '/'), 24, NULL));

	al_set_path_filename(path, "Font/pixelmix_bold.ttf");
	text.push_back(al_load_font(al_path_cstr(path, '/'), 72, NULL));
	text.push_back(al_load_font(al_path_cstr(path, '/'), 12, NULL));
	text.push_back(al_load_font(al_path_cstr(path, '/'), 16, NULL));


	for (int i = 0; i < text.size(); i++)
	{
		malloc(sizeof(text[i]));
	}

}

void Font::Font_error_check()
{
	try {
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == NULL)
			{
				throw 98;
			}
		}
	}

	catch (int x) {
		system("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/src/Asset_management/Font.bat");
		exit(EXIT_FAILURE);
	}
}

ALLEGRO_FONT * Font::get_font(int textnum)
{
	return text[textnum];
}

void Font::deallocate()
{
	for (int i = 0; i < text.size(); i++)
	{
		al_destroy_font(text[i]);
	}
}
