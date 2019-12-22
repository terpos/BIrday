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

void Pause::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

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
			if (options == 2)
			{

			}

			else
			{
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
	al_draw_text(font.get_font(0), notSel, 500, 420, NULL, "QUIT (ESC)");

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
		al_draw_text(font.get_font(0), Sel, 500, 420, NULL, "QUIT (ESC)");
		break;
	}
}
