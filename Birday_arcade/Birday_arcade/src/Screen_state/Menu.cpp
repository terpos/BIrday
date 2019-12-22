#include "Menu.h"



Menu::Menu()
{
	options = GAME_SCREEN;
	
}


Menu::~Menu()
{
}

void Menu::update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Image image, ALLEGRO_EVENT &e, int &screennum, bool &done)
{
	//waits until key is pressed (can be neglected since timer is on)
	al_wait_for_event(q, &e);

	//closes the window when escape key is pressed
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
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
			screennum = options;
		}

		std::cout << options << std::endl;

	}

	if (e.type == ALLEGRO_EVENT_TIMER)
	{

	}
}

void Menu::render(Image image, Font font)
{
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
