#include "Menu.h"



Menu::Menu()
{
	options = GAME_SCREEN;
	
}


Menu::~Menu()
{
}

void Menu::update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, Sound sound, Options &option, ALLEGRO_EVENT &e, int &screennum, bool &done)
{
	//waits until key is pressed (can be neglected since timer is on)
	al_wait_for_event(q, &e);

	//closes the window when escape key is pressed
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			option.set_last_screen(MENU_SCREEN);
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

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			if (options == OPTION_SCREEN)
			{
				option.set_last_screen(MENU_SCREEN);
				screennum = options;
			}

			else
			{
				option.set_last_screen(MENU_SCREEN);
				screennum = options;
			}
			
			al_stop_sample_instance(sound.bg_music(6));
		}


	}

	if (e.type == ALLEGRO_EVENT_TIMER)
	{

	}
}

void Menu::render(Image image, Sound sound, Font font)
{
	al_play_sample_instance(sound.bg_music(6));
	al_draw_bitmap(image.Background_image(MENU).first, 0, 0, NULL);
	al_draw_bitmap(image.Background_image(BANNER).first, -100, 0, NULL);

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "PLAY");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "MATERIALS IN THE GAME");
	al_draw_text(font.get_font(0), notSel, 500, 390, NULL, "OPTION");
	al_draw_text(font.get_font(0), notSel, 500, 420, NULL, "QUIT");

	switch (options)
	{
	case GAME_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "PLAY");
		break;
	case GAME_MATERIAL_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "MATERIALS IN THE GAME");
		break;
	case OPTION_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "OPTION");
		break;
	case QUIT_SCREEN:
		al_draw_text(font.get_font(0), Sel, 500, 420, NULL, "QUIT");
		break;
	}
}

void Menu::error_notify(Font font, int x)
{
	if (x == 101)
	{
		al_draw_text(font.get_font(0), al_map_rgb(0, 200, 100), 500, 720, NULL, "Player Image not found!");
	}
}