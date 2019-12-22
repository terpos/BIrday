#include "Game_Over.h"

Game_Over::Game_Over()
{
	Sel = al_map_rgb(255, 0, 0);
	notSel = al_map_rgb(0, 255, 0);
	options = 1;
}

Game_Over::~Game_Over()
{

}

void Game_Over::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, ALLEGRO_EVENT & e, int & screennum, bool & done)
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
				options = 3;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			options++;
			if (options > 3)
			{
				options = 1;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			switch (options)
			{
			case 1:
				screennum = GAME_SCREEN;
				break;
			case 2:
				screennum = MENU_SCREEN;
				break;
			case 3:
				screennum = QUIT_SCREEN;
				break;
			}
		}
	}
	
}

void Game_Over::render(Image image, Font font)
{
	//al_clear_to_color(al_map_rgb(25, 0, 0));

	al_draw_bitmap(image.Background_image(1).first, 0, 0, NULL);

	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 90), 400, 150, NULL, "GAME OVER");

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "PLAY AGAIN (1)");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "MAIN MENU (2)");
	al_draw_text(font.get_font(0), notSel, 500, 390, NULL, "QUIT (3)");
	


	switch (options)
	{
	case 1:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "PLAY AGAIN (1)");
		break;
	case 2:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "MAIN MENU (2)");
		break;
	case 3:
		al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "QUIT (3)");
		break;
	
	}
}
