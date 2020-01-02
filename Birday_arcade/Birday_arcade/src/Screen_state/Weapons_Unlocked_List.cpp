#include "Weapons_Unlocked_List.h"

Weapons_Unlocked_List::Weapons_Unlocked_List()
{
	page = 0;
}

Weapons_Unlocked_List::~Weapons_Unlocked_List()
{
}

void Weapons_Unlocked_List::add_word_to_list(std::string word)
{
	listing.push_back(word);
}

std::string Weapons_Unlocked_List::get_list(int index)
{
	return listing[index];
}

void Weapons_Unlocked_List::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Options &option, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			screennum = PAUSE_SCREEN;
		}

		else if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			option.set_last_screen(WEAPONS_UNLOCKED_SCREEN);

			screennum = QUIT_SCREEN;
		}
	}


	if (e.type == ALLEGRO_EVENT_TIMER)
	{

	}
}

void Weapons_Unlocked_List::render(Image image, Font font)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 0), 225, 50, NULL, "WEAPONS UNLOCKED");

	for (int i = 0; i < listing.size(); i++)
	{
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 400, 250 + 30*i, NULL, get_list(i).c_str());
	}

	al_draw_text(font.get_font(0), al_map_rgb(255, 255, 255), 300, 720, NULL, "PRESS [SPACE] TO RETURN TO THE PAUSE SCREEN");

}
