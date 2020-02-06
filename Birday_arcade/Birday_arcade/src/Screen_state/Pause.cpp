#include "Pause.h"



Pause::Pause()
{
	Sel = al_map_rgb(255, 0, 0);
	notSel = al_map_rgb(0, 255, 0);
	options = 1;
}


Pause::~Pause()
{
}

void Pause::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Options &option, Game &game, ALLEGRO_EVENT & e, Weapons_Unlocked_List &weapons_unlocked, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{

		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			option.set_last_screen(PAUSE_SCREEN);
			screennum = QUIT_SCREEN;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			options--;
			if (options < 1)
			{
				options = 4;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			options++;
			if (options > 4)
			{
				options = 1;
			}
		}


		switch (e.keyboard.keycode)
		{
		case ALLEGRO_KEY_1:
			option.set_last_screen(PAUSE_SCREEN);
			screennum = GAME_SCREEN;
			break;

		case ALLEGRO_KEY_2:
			screennum = WEAPONS_UNLOCKED_SCREEN;
			break;

		case ALLEGRO_KEY_3:
			option.set_last_screen(PAUSE_SCREEN);
			screennum = OPTION_SCREEN;
			break;

		case ALLEGRO_KEY_4:
			game.reset(weapons_unlocked);
			screennum = MENU_SCREEN;
			break;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			if (options == 2)
			{
				screennum = WEAPONS_UNLOCKED_SCREEN;
			}

			else if (options == 3)
			{
				option.set_last_screen(PAUSE_SCREEN);
				screennum = options;
			}

			else if (options == 4)
			{
				game.reset(weapons_unlocked);
				screennum = MENU_SCREEN;
			}

			else
			{
				option.set_last_screen(PAUSE_SCREEN);
				screennum = options;
			}
		}
	}
}

void Pause::render(Image image, Font font)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 90), 500, 150, NULL, "PAUSE");

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "CONTINUE (1)");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "WEAPON UNLOCKED (2)");
	al_draw_text(font.get_font(0), notSel, 500, 390, NULL, "OPTION (3)");
	al_draw_text(font.get_font(0), notSel, 500, 420, NULL, "MAIN MENU (4)");

	switch (options)
	{
	case GAME_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "CONTINUE (1)");
		break;
	case GAME_MATERIAL_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "WEAPON UNLOCKED (2)");
		break;
	case OPTION_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "OPTION (3)");
		break;
	case QUIT_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 420, NULL, "MAIN MENU (4)");
		break;
	}
}
