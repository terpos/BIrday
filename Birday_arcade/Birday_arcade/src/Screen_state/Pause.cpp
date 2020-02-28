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

void Pause::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Options &option, Game &game, Sound sound, ALLEGRO_EVENT & e, Weapons_Unlocked_List &weapons_unlocked, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		//goes to quit screen when escape key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			option.set_last_screen(PAUSE_SCREEN);
			screennum = QUIT_SCREEN;
		}

		//direction of choice go up if up arrow is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			al_set_sample_instance_position(sound.sound_effects(17), 0);
			al_play_sample_instance(sound.sound_effects(17));
			options--;
			if (options < 1)
			{
				options = 4;
			}
		}

		//direction of choice go down if down arrow is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			al_set_sample_instance_position(sound.sound_effects(17), 0);
			al_play_sample_instance(sound.sound_effects(17));
			options++;
			if (options > 4)
			{
				options = 1;
			}
		}

		//keyboard shortcuts (1, 2, 3, and 4)
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
			option.set_last_screen_to_option(PAUSE_SCREEN);
			option.set_last_screen(PAUSE_SCREEN);
			screennum = OPTION_SCREEN;
			break;

		case ALLEGRO_KEY_4:
			game.reset(weapons_unlocked);
			screennum = MENU_SCREEN;
			break;
		}


		//selection occurs when enter key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			if (options == 2)
			{
				screennum = WEAPONS_UNLOCKED_SCREEN;
			}

			else if (options == 3)
			{
				option.set_last_screen(PAUSE_SCREEN);
				option.set_last_screen_to_option(PAUSE_SCREEN);

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
	//background color
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//title
	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 90), 500, 150, NULL, "PAUSE");

	//renders all texts to the screen
	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "CONTINUE (1)");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "WEAPON UNLOCKED (2)");
	al_draw_text(font.get_font(0), notSel, 500, 390, NULL, "OPTION (3)");
	al_draw_text(font.get_font(0), notSel, 500, 420, NULL, "MAIN MENU (4)");

	//renders the text based on selection
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
