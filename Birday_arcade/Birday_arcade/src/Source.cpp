#include "global.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Image.h"
#include "Screen_state/Options.h"
#include "Entities/Collision.h"

#include "Entities/Power_Up/Power_Up.h"
#include "Entities/Power_Up/B_2_Bomber_Strike_Chip.h"
#include "Entities/Power_Up/Copy_Chip.h"
#include "Entities/Power_Up/Gliding_Chip.h"
#include "Entities/Power_Up/Health_Chip.h"
#include "Entities/Power_Up/Needle_Blast_Wind_Chip.h"
#include "Entities/Power_Up/Stop_Time_Chip.h"

#include "Entities/Enemy/Ball.h"
#include "Entities/Enemy/Cannon_Slug.h"
#include "Entities/Enemy/Diamondo.h"
#include "Entities/Enemy/Magic_Mask.h"
#include "Entities/Enemy/Fisher.h"
#include "Entities/Enemy/Tripus.h"


using namespace std;

int main()
{
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

	//sets the new display flags
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	//initializes and creates display
	ALLEGRO_DISPLAY *display = al_create_display(1360, 768);

	//al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
	
	//sets the screen to no frame
	al_set_display_flag(display, ALLEGRO_NOFRAME, true);

	//std::cout << al_get_display_width(display) << ", " << al_get_display_height(display) << std::endl;
	//double variable
	double fps = 60.0;
	
	

	//object variables
	Image image,image2;
	Sound sound;
	Collision collision;
	Options option;
	Tile_map m;

	//event variables
	ALLEGRO_EVENT e;
	ALLEGRO_EVENT_QUEUE *q = al_create_event_queue();
	
	//timer variable
	ALLEGRO_TIMER *timer = al_create_timer(1 / fps);

	//integer array variable
	int buttons[7] = {
		ALLEGRO_KEY_DOWN,
		ALLEGRO_KEY_UP,
		ALLEGRO_KEY_RIGHT,
		ALLEGRO_KEY_LEFT,
		ALLEGRO_KEY_SPACE,
		ALLEGRO_KEY_A,
		ALLEGRO_KEY_S
	};

	//object variable
	Player player(image, 0, 0, 5, 0, buttons);

	//vector object variables
	std::vector <Enemy*> enemy;
	std::vector <Power_Up*> powerup;
	std::vector <P_Weapon*> pweapon;
	std::vector <E_Weapon*> eweapon;

	//loads images and sounds
	image.Load_Images();
	sound.Load_Sound();

	//vector variable assignment
	enemy.push_back(new Cannon_Slug(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Fisher(image, 1, 300, 300, 5, 0));
	
	


	//registers different kinds of events
	al_register_event_source(q, al_get_keyboard_event_source());
	al_register_event_source(q, al_get_display_event_source(display));
	al_register_event_source(q, al_get_timer_event_source(timer));

	//starts the timer
	al_start_timer(timer);

	//game loop
	while (1)
	{
		//waits until key is pressed (can be neglected since timer is on)
		al_wait_for_event(q, &e);
		
		//closes the window when escape key is pressed
		if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				break;
			}
		}

		//controls player
		player.control(image, e, pweapon);

		//updates stuff
		if (e.type == ALLEGRO_EVENT_TIMER)
		{
			//clears the trails images has left over
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//updates player's info
			player.update(option, pweapon);
			
			//updates enemies' info
			for (int i = 0; i < enemy.size(); i++)
			{
				enemy[i]->update(eweapon, image);

				collision.Window_Collision(display, e, player, enemy[i]);

				if (collision.collision_detect(player.get_x(), player.get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
				{
					player.col_update();
				}

				for (int j = 0; j < pweapon.size(); j++)
				{
					if (enemy.size() > 0)
					{
						if (collision.collision_detect(pweapon[j]->get_x(), pweapon[j]->get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
						{
							powerup.push_back(new Health_Chip(image, enemy[i]->get_x(), enemy[i]->get_y()));
							enemy.erase(enemy.begin() + i);
							pweapon.erase(pweapon.begin() + j);

						}
					}
				}
			}

			//updates enemy weapons' info
			for (int i = 0; i < eweapon.size(); i++)
			{
				eweapon[i]->update();

				if (collision.collision_detect(eweapon[i]->get_x(), eweapon[i]->get_y(), player.get_x(), player.get_y()))
				{
					player.col_update();
					eweapon.erase(eweapon.begin() + i);
				}
			}


			//update power up's info
			for (int i = 0; i < powerup.size(); i++)
			{

				if (collision.collision_detect(player.get_x(), player.get_y(), powerup[i]->get_x(), powerup[i]->get_y()))
				{
					powerup.erase(powerup.begin() + i);
				}
			}
			
			//draw becomes true for the sake of cpu
			draw = true;
		}

		//if draw is true, display all assets
		if (draw)
		{
			for (int i = 0; i < powerup.size(); i++)
			{
				powerup[i]->render();
			}
			for (int i = 0; i < pweapon.size(); i++)
			{
				pweapon[i]->render();
			}

			for (int i = 0; i < eweapon.size(); i++)
			{
				eweapon[i]->render();
			}

			player.render();
			for (int i = 0; i < enemy.size(); i++)
			{
				enemy[i]->render();
			}
			draw = false;
		}

		al_flip_display();
	}
	
	//stops the timer
	al_stop_timer(timer);

	//destroys image and sound memory
	image.Deallocate_image();
	sound.Deallocate_sound();

	//uninstall audio and keyboard
	al_uninstall_audio();
	al_uninstall_keyboard();

	//destroys display, timer and event memory
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(q);
	
	system("pause");
	return 0;
}