#include "Options.h"



Options::Options()
{
	Sel = al_map_rgb(255, 0, 0);
	SelOption = al_map_rgb(0, 0, 255);
	notSel = al_map_rgb(0, 255, 0);
	notSelOption = al_map_rgb(5, 50, 50);
	options = 1;
	sound_options = 1;
	tile_options = 1;
	difficulty_option = 1;
	control_option[0] = ALLEGRO_KEY_DOWN;
	control_option[1] = ALLEGRO_KEY_UP;
	control_option[2] = ALLEGRO_KEY_RIGHT;
	control_option[3] = ALLEGRO_KEY_LEFT;
	control_option[4] = ALLEGRO_KEY_SPACE;
	control_option[5] = ALLEGRO_KEY_A;
	control_option[6] = ALLEGRO_KEY_S;
}


Options::~Options()
{
}

int Options::get_control_options(int index)
{
	return this->control_option[index];
}

void Options::set_control_options(int buttons[7])
{
	for (int i = 0; i < 7; i++)
	{
		this->control_option[i] = buttons[i];
	}
}

void Options::update(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * q, Image image, ALLEGRO_EVENT & e, int & screennum, bool & done)
{
	al_wait_for_event(q, &e);



	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (options)
		{
		case 4:
			control_option[0] = e.keyboard.keycode;
			options++;
			break;
		case 5:
			control_option[1] = e.keyboard.keycode;
			options++;
			break;
		case 6:
			control_option[2] = e.keyboard.keycode;
			options++;
			break;
		case 7:
			control_option[3] = e.keyboard.keycode;
			options++;
			break;
		case 8:
			control_option[4] = e.keyboard.keycode;
			options++;
			break;
		case 9:
			control_option[5] = e.keyboard.keycode;
			options++;
			break;
		case 10:
			control_option[6] = e.keyboard.keycode;
			options++;
			break;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			screennum = QUIT_SCREEN;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			if (options == 11 || options < 4)
			{
				options--;
				if (options < 1)
				{
					options = 11;
				}
			}

			
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			if (options == 11 || options < 4)
			{
				options++;
				if (options > 11)
				{
					options = 1;
				}
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			switch (options)
			{
			case 1:
				//al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "SOUND:");
				sound_options--;
				break;
			case 2:
				//al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "TILE STYLE:");
				tile_options--;
				break;
			case 3:
				//al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "DIFFICULTY:");
				difficulty_option--;
				break;
		
			}

			if (sound_options < 1)
			{
				sound_options = 2;
			}

			if (difficulty_option < 1)
			{
				difficulty_option = 3;
			}

			if (tile_options < 1)
			{
				tile_options = 5;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			switch (options)
			{
			case 1:
				//al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "SOUND:");
				sound_options++;
				break;
			case 2:
				//al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "TILE STYLE:");
				tile_options++;
				break;
			case 3:
				//al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "DIFFICULTY:");
				difficulty_option++;
				break;
			
			}

			if (sound_options > 2)
			{
				sound_options = 1;
			}

			if (difficulty_option > 3)
			{
				difficulty_option = 1;
			}

			if (tile_options > 5)
			{
				tile_options = 1;
			}
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			if (options == 11)
			{
				screennum = MENU_SCREEN;
			}

		}

		if (e.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			if (options == 11 || options < 4)
			{
				screennum = MENU_SCREEN;
			}
		}
	}
}

void Options::render(Image image, Font font)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(font.get_font(1), al_map_rgb(255, 25, 90), 500, 150, NULL, "OPTION");

	al_draw_text(font.get_font(0), notSel, 500, 330, NULL, "SOUND:");
	
	al_draw_text(font.get_font(0), notSel, 500, 360, NULL, "TILE STYLE:");
	al_draw_text(font.get_font(0), notSel, 500, 390, NULL, "DIFFICULTY:");
	
	al_draw_text(font.get_font(0), al_map_rgb(0, 200, 200), 500, 450, NULL, "CONTROLS:");
	al_draw_text(font.get_font(0), notSel, 500, 480, NULL, "MOVE DOWN:");
	al_draw_text(font.get_font(0), notSel, 500, 510, NULL, "MOVE UP:");
	al_draw_text(font.get_font(0), notSel, 500, 540, NULL, "MOVE RIGHT:");
	al_draw_text(font.get_font(0), notSel, 500, 570, NULL, "MOVE LEFT:");
	al_draw_text(font.get_font(0), notSel, 500, 600, NULL, "SHOOT:");
	al_draw_text(font.get_font(0), notSel, 500, 630, NULL, "PREV WEAPON:");
	al_draw_text(font.get_font(0), notSel, 500, 660, NULL, "NEXT WEAPON:");

	if (sound_options == 1)
	{
		al_draw_text(font.get_font(0), SelOption, 625, 330, NULL, "ON");
	}

	else if (sound_options == 2)
	{
		al_draw_text(font.get_font(0), SelOption, 625, 330, NULL, "OFF");
	}

	if (difficulty_option == 1)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 390, NULL, "EASY");
	}

	else if (difficulty_option == 2)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 390, NULL, "MEDIUM");
	}

	else if (difficulty_option == 3)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 390, NULL, "HARD");
	}

	if (tile_options == 1)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 360, NULL, "NORMAL");
	}

	if (tile_options == 2)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 360, NULL, "CIRCULAR");
	}

	if (tile_options == 3)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 360, NULL, "TROPICAL");
	}

	if (tile_options == 4)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 360, NULL, "PILLAR");
	}

	if (tile_options == 5)
	{
		al_draw_text(font.get_font(0), SelOption, 700, 360, NULL, "FIELD");
	}

	al_draw_text(font.get_font(0), notSel, 500, 720, NULL, "BACK TO MAIN MENU (SPACEBAR)");

	al_draw_text(font.get_font(0), SelOption, 750, 480, NULL, key_display[control_option[0]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 510, NULL, key_display[control_option[1]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 540, NULL, key_display[control_option[2]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 570, NULL, key_display[control_option[3]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 600, NULL, key_display[control_option[4]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 630, NULL, key_display[control_option[5]].c_str());
	al_draw_text(font.get_font(0), SelOption, 750, 660, NULL, key_display[control_option[6]].c_str());

	switch (options)
	{
	case 1:
		al_draw_text(font.get_font(0), Sel, 500, 330, NULL, "SOUND:");
		break;
	case 2:
		al_draw_text(font.get_font(0), Sel, 500, 360, NULL, "TILE STYLE:");
		break;
	case 3:
		al_draw_text(font.get_font(0), Sel, 500, 390, NULL, "DIFFICULTY:");
		break;
	case 4:
		al_draw_text(font.get_font(0), Sel, 500, 480, NULL, "MOVE DOWN:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 480, NULL, "(Press Any Key)");
		break;
	case 5:
		al_draw_text(font.get_font(0), Sel, 500, 510, NULL, "MOVE UP:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 510, NULL, "(Press Any Key)");
		break;
	case 6:
		al_draw_text(font.get_font(0), Sel, 500, 540, NULL, "MOVE RIGHT:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 540, NULL, "(Press Any Key)");
		break;
	case 7:
		al_draw_text(font.get_font(0), Sel, 500, 570, NULL, "MOVE LEFT:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 570, NULL, "(Press Any Key)");
		break;
	case 8:
		al_draw_text(font.get_font(0), Sel, 500, 600, NULL, "SHOOT:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 600, NULL, "(Press Any Key)");
		break;
	case 9:
		al_draw_text(font.get_font(0), Sel, 500, 630, NULL, "PREV WEAPON:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 630, NULL, "(Press Any Key)");
		break;
	case 10:
		al_draw_text(font.get_font(0), Sel, 500, 660, NULL, "NEXT WEAPON:");
		al_draw_text(font.get_font(0), al_map_rgb(255, 255, 0), 1050, 660, NULL, "(Press Any Key)");
		break;
	case 11:
		al_draw_text(font.get_font(0), Sel, 500, 720, NULL, "BACK TO MAIN MENU (SPACEBAR)");
		break;
	}
}
