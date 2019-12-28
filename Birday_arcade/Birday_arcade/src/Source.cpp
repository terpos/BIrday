#include "Screen_state/Game.h"
#include "Screen_state/Menu.h"
#include "Screen_state/Game_Materials.h"
#include "Screen_state/Options.h"
#include "Screen_state/Pause.h"
#include "Screen_state/Quit.h"
#include "Screen_state/Game_Over.h"
#include "Screen_state/Weapons_Unlocked_List.h"

using namespace std;

int main()
{
	int screennum = 0;

	//boolean variable
	bool draw = false;
	
	//initializes allegro 5
	al_init();

	//initializes computer components
	al_install_keyboard();
	al_install_audio();

	//initializes addon
	al_init_image_addon();
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//sets the new display flags
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	//initializes and creates display
	ALLEGRO_DISPLAY *display = al_create_display(1360, 768);

	Tile_map m;

	//sets the screen to no frame
	al_set_display_flag(display, ALLEGRO_NOFRAME, true);

	//double variable
	double fps = 60.0;
	Image image;
	Font font;
	Sound sound;

	Game game;
	Menu menu;
	Options option;
	Pause pause;
	Game_Materials game_materials;
	Quit quit;
	Game_Over game_over;
	Weapons_Unlocked_List weapon_unlock;

	bool done = false;
	

	//event variables
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE *q = al_create_event_queue();
	
	//timer variable
	ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

	m.load("c:/Users/Kamal/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Tile_map.txt");
	image.Load_Images();
	font.load();
	sound.Load_Sound();

	game.load(image);
	

	//registers different kinds of events
	al_register_event_source(q, al_get_keyboard_event_source());
	al_register_event_source(q, al_get_display_event_source(display));
	al_register_event_source(q, al_get_timer_event_source(timer));

	//starts the timer
	al_start_timer(timer);

	//game loop
	while (!done)
	{

		switch (screennum)
		{
		case MENU_SCREEN:
			menu.update(display, q, image, sound, ev, screennum, done);
			break;
		case GAME_SCREEN:
			game.update(display, q, m, weapon_unlock, option, image, sound, ev, screennum, done);
			break;
		case OPTION_SCREEN:
			option.update(display, q, image, ev, screennum, done);
			break;
		case GAME_MATERIAL_SCREEN:
			game_materials.update(display, q, image, ev, screennum, done);
			break;
		case QUIT_SCREEN:
			quit.update(display, q, image, ev, screennum, done);
			break;
		case PAUSE_SCREEN:
			pause.update(display, q, image, ev, screennum, done);
			break;
		case GAME_OVER_SCREEN:
			game_over.update(display, q, image, sound, ev, screennum, done);
			break;
		case WEAPONS_UNLOCKED_SCREEN:
			weapon_unlock.update(display, q, image, ev, screennum, done);
			break;

		}

		//draw becomes true for the sake of cpu
		draw = true;
		
		//if draw is true, display all assets
		if (draw)
		{
			switch (screennum)
			{
			case MENU_SCREEN:
				menu.render(image, sound, font);
				break;
			case GAME_SCREEN:
				game.render(image, sound, m, font);
				break;
			case OPTION_SCREEN:
				option.render(image, font);
				break;
			case GAME_MATERIAL_SCREEN:
				game_materials.render(image, font);
				break;
			case QUIT_SCREEN:
				quit.render(image, font);
				break;
			case PAUSE_SCREEN:
				pause.render(image, font);
				break;
			case GAME_OVER_SCREEN:
				game_over.render(image, sound, font);
				break;
			case WEAPONS_UNLOCKED_SCREEN:
				weapon_unlock.render(image, font);
				break;
			}
			

			draw = false;
		}

		al_flip_display();
	}
	
	
	image.Deallocate_image(m);
	font.deallocate();
	sound.Deallocate_sound();

	//stops the timer
	al_stop_timer(timer);

	//uninstall audio and keyboard
	al_uninstall_audio();
	al_uninstall_keyboard();

	//destroys display, timer and event memory
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(q);
	
	std::cout << "Press [Enter] To Continue" << std::endl;

	std::cin.get();


	return 0;
}