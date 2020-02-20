#include "Quit.h"



Quit::Quit()
{
	Sel = al_map_rgb(255, 0, 0);
	notSel = al_map_rgb(0, 255, 0);
	options = 1;
}

Quit::~Quit()
{
}

void Quit::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Options &option, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			done = true;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			options--;
			if (options < 1)
			{
				options = 2;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			options++;
			if (options > 2)
			{
				options = 1;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			switch (options)
			{
			case 1:
				done = true;
				break;
			case 2:
				screennum = option.get_last_screen();
				option.set_quit(false);
				break;
			}
		}
	}
	
}

void Quit::render(Image image, Font font)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(font.get_font(1), al_map_rgb(255, 255, 255), 400, 150, NULL, "ARE YOU SURE");

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "YES");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "NO");

	switch (options)
	{
	case 1:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "YES");
		break;
	case 2:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "NO");
		break;
	}
}
