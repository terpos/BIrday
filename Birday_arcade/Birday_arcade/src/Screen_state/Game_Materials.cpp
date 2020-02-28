#include "Game_Materials.h"



Game_Materials::Game_Materials()
{
	page = 1;
}


Game_Materials::~Game_Materials()
{
}

void Game_Materials::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Options &option, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		//goes to quit screen if escape key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			option.set_last_screen(GAME_MATERIAL_SCREEN);
			screennum = QUIT_SCREEN;
		}

		//goes to previous page if left key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			page--;
			if (page < 1)
			{
				page = 5;
			}
		}

		//goes to next page if right key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			page++;
			if (page > 5)
			{
				page = 1;
			}
		}

		//goes back to the menu screen if space key is pressed
		if (e.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			screennum = MENU_SCREEN;
		}
	}

	if (e.type == ALLEGRO_EVENT_TIMER)
	{

	}
}

void Game_Materials::render(Image image, Font font)
{
	//background
	al_clear_to_color(al_map_rgb(170, 170, 170));
	
	//image
	al_draw_bitmap(image.Background_image(8).first, 0, 0, NULL);

	//prompts user to press space if they want to go back to the main menu
	al_draw_text(font.get_font(2), al_map_rgb(0, 150, 0), 930, 700, NULL, "PRESS SPACEBAR ");
	al_draw_text(font.get_font(2), al_map_rgb(0, 150, 0), 880, 720, NULL, "TO RETURN TO THE MAIN MENU");

	//renders pics based on what page it is
	switch (page)
	{
	case 1:
		al_draw_bitmap(image.Background_image(4).first, 0, 0, NULL);
		break;
	case 2:
		al_draw_bitmap(image.Background_image(6).first, 0, 0, NULL);
		break;
	case 3:
		al_draw_bitmap(image.Background_image(5).first, 0, 0, NULL);
		break;
	case 4:
		al_draw_bitmap(image.Background_image(7).first, 0, 0, NULL);
		break;
	case 5:
		al_draw_bitmap(image.Background_image(3).first, 0, 0, NULL);
		break;
	}

}
