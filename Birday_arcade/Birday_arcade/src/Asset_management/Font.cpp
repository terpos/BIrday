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
	text.push_back(al_load_font("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Font/pixelmix.ttf", 24, NULL));
	text.push_back(al_load_font("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Font/pixelmix_bold.ttf", 72, NULL));
	text.push_back(al_load_font("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Font/pixelmix_bold.ttf", 12, NULL));
	text.push_back(al_load_font("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Font/pixelmix_bold.ttf", 16, NULL));


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
		system("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/src/Asset_management/Font.bat");
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
