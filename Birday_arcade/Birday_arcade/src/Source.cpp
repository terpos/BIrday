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
	int screennum = MENU_SCREEN;
	int count_down_to_close = 600;

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
	
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Assets");
	al_set_path_filename(path, "Image/birday_icon.png");


	ALLEGRO_BITMAP * icon = al_load_bitmap(al_path_cstr(path, '/'));
	//initializes and creates display
	ALLEGRO_DISPLAY *display = al_create_display(1360, 768);

	malloc(sizeof(display));
	al_set_display_icon(display, icon);

	Animation fade;

	int alpha = 0;
	int speed = 5;

	

	Tile_map m;

	//sets the screen to no frame
	al_set_display_flag(display, ALLEGRO_NOFRAME, true);

	//double variable
	double fps = 60.0;
	double fps2 = 60.0;

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

	al_set_path_filename(path, "Tile_map.txt");

	m.load(al_path_cstr(path, '/'));
	image.Load_Images();
	font.load();
	sound.Load_Sound();

	image.Image_error_check();
	font.Font_error_check();

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
			menu.update(display, q, image, sound, option, ev, screennum, done);
			break;
		case GAME_SCREEN:
			game.init(option);
			game.update(display, q, m, weapon_unlock, option, image, sound, ev, screennum, done);
			break;
		case OPTION_SCREEN:
			option.update(display, q, sound, image, ev, screennum, done);
			break;
		case GAME_MATERIAL_SCREEN:
			game_materials.update(display, q, image, option, ev, screennum, done);
			break;
		case QUIT_SCREEN:
			quit.update(display, q, image, option, ev, screennum, done);
			break;
		case PAUSE_SCREEN:
			pause.update(display, q, image, option, game, sound, ev, weapon_unlock, screennum, done);
			break;
		case GAME_OVER_SCREEN:
			game_over.update(display, q, image, sound, option, ev, screennum, done);
			break;
		case WEAPONS_UNLOCKED_SCREEN:
			weapon_unlock.update(display, q, image, option, ev, screennum, done);
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
				game.render(weapon_unlock, option, image, sound, m, font);	
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
				game_over.render(image, sound, font, option);
				break;
			case WEAPONS_UNLOCKED_SCREEN:
				weapon_unlock.render(image, font);
				break;
			}
			
			draw = false;
		}

		al_flip_display();
	}

	
	
	weapon_unlock.clear_all();

	//destroys display, timer and event memory
	al_destroy_display(display);

	al_destroy_timer(timer);
	al_destroy_event_queue(q);
	al_destroy_path(path);
	font.deallocate();
	image.Deallocate_image(m);
	sound.Deallocate_sound();
	al_destroy_bitmap(icon);

	std::cout << "Assets Deallocated" << std::endl;

	//uninstall audio and keyboard
	al_uninstall_audio();
	al_uninstall_keyboard();





	return 0;
}