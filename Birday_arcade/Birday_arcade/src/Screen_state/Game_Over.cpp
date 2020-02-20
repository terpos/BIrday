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

void Game_Over::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, Sound sound, Options &option, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);
	

	if (al_get_sample_instance_position(sound.bg_music(0)) < 150000)
	{
		play = true;
	}

	else
	{
		play = false;
	}

	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			screennum = QUIT_SCREEN;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			al_set_sample_instance_position(sound.sound_effects(17), 0);
			al_play_sample_instance(sound.sound_effects(17));
			options--;
			if (options < 1)
			{
				options = 2;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			al_set_sample_instance_position(sound.sound_effects(17), 0);
			al_play_sample_instance(sound.sound_effects(17));
			options++;
			if (options > 2)
			{
				options = 1;
			}
		}

		switch (e.keyboard.keycode)
		{
		case ALLEGRO_KEY_1:
			screennum = GAME_SCREEN;
			break;

		case ALLEGRO_KEY_2:
			screennum = MENU_SCREEN;
			break;

		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			play = true;
			al_set_sample_instance_position(sound.bg_music(0), 0);
			al_stop_sample_instance(sound.bg_music(0));
			switch (options)
			{
			case 1:
				screennum = GAME_SCREEN;
				break;
			case 2:
				screennum = MENU_SCREEN;
				break;
			
			}
		}
	}
	
}

void Game_Over::render(Image image, Sound sound, Font font, Options option)
{
	//system("cls");
	if (option.get_sound_options())
	{
		if (play)
		{
			al_play_sample_instance(sound.bg_music(0));
		}

		else
		{
			al_set_sample_instance_position(sound.bg_music(0), 150000);
			al_play_sample_instance(sound.bg_music(0));
		}
	}

	al_draw_bitmap(image.Background_image(1).first, 0, 0, NULL);

	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 90), 400, 150, NULL, "GAME OVER");

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "PLAY AGAIN (1)");
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "MAIN MENU (2)");
	


	switch (options)
	{
	case 1:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "PLAY AGAIN (1)");
		break;
	case 2:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "MAIN MENU (2)");
		break;
	
	}
}
