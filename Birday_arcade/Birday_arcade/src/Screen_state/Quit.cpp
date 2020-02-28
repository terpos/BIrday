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
		//goes to the quit screen when escape key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			done = true;
		}

		//direction of choice go up if up arrow is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			options--;
			if (options < 1)
			{
				options = 2;
			}
		}

		//direction of choice go down if down arrow is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			options++;
			if (options > 2)
			{
				options = 1;
			}
		}

		//selection occurs when enter key is pressed
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
	//background
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//title
	al_draw_text(font.get_font(1), al_map_rgb(255, 255, 255), 400, 150, NULL, "ARE YOU SURE");

	//renders all texts to the screen
	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "YES");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "NO");

	//renders the text based on selection
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
