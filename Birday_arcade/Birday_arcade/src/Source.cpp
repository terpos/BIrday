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
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);

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
	m.load("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Tile_map.txt");

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

	//loads images and sounds
	image.Load_Images();
	sound.Load_Sound();

	//object variable
	Player player(image, 8*80, 0, 80, 0, buttons);

	//vector object variables
	std::vector <Enemy*> enemy;
	std::vector <Power_Up*> powerup;
	std::vector <P_Weapon*> pweapon;
	std::vector <E_Weapon*> eweapon;

	//vector variable assignment
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Fisher(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Magic_Mask(image, 2, 300, 300, 5, 0));

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
			collision.Window_Collision(display, e, player);
			collision.Window_Collision(display, e, pweapon, eweapon);

			

			//updates enemies' info
			for (int i = 0; i < enemy.size(); i++)
			{
				enemy[i]->react(image, player, eweapon);
				enemy[i]->update(eweapon, image);

				collision.Window_Collision(display, e, enemy[i]);

				

				if (collision.collision_detect(player.get_x(), player.get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
				{
					player.set_health(player.get_health() - enemy[i]->Damage());
					player.damage_col_update();
				}

				//enemy & tile collision 
				for (int tile_y = 0; tile_y < m.get_length(); tile_y++)
				{
					for (int tile_x = 0; tile_x < m.get_width(); tile_x++)
					{
						//std::cout << m.get_tile_number(j);
						if (m.get_tile_number(tile_x, tile_y) == 1)
						{
							if (collision.collision_detect(enemy[i]->get_x(), enemy[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								enemy[i]->change_direction();
								
							}
						}


						if (m.get_tile_number(tile_x, tile_y) == 2)
						{
							if (collision.collision_detect(enemy[i]->get_x(), enemy[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								enemy[i]->change_direction();
							}
						}
					}
				}

				for (int j = 0; j < pweapon.size(); j++)
				{
					if (enemy.size() > 0)
					{
						if (collision.collision_detect(pweapon[j]->get_x(), pweapon[j]->get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
						{
							pweapon[j]->abilities(true);
							enemy[i]->set_health(enemy[i]->get_health() - pweapon[j]->damage());
							
							std::cout << pweapon[j]->is_dead() << std::endl;

							if (enemy[i]->get_health() <= 0)
							{
								powerup.push_back(new Health_Chip(image, enemy[i]->get_x(), enemy[i]->get_y()));
								enemy.erase(enemy.begin() + i);
							}

							
							if (pweapon[j]->is_dead())
							{
								pweapon.erase(pweapon.begin() + j);
							}
						}
					}
				}
			}
			
			//collision for tiles (player and enemy weapon)
			for (int tile_y = 0; tile_y < m.get_length(); tile_y++)
			{
				for (int tile_x = 0; tile_x < m.get_width(); tile_x++)
				{
					

					for (int i = 0; i < pweapon.size(); i++)
					{
						if (m.get_tile_number(tile_x, tile_y) == 1)
						{
							if (collision.collision_detect(pweapon[i]->get_x(), pweapon[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								pweapon[i]->abilities(true);

							}
						}


						if (m.get_tile_number(tile_x, tile_y) == 2)
						{
							if (collision.collision_detect(pweapon[i]->get_x(), pweapon[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								pweapon[i]->abilities(true);
							}
						}

						if (pweapon[i]->is_dead())
						{
							pweapon.erase(pweapon.begin() + i);
						}
					}

					for (int j = 0; j < eweapon.size(); j++)
					{
						if (m.get_tile_number(tile_x, tile_y) == 1)
						{
							if (collision.collision_detect(eweapon[j]->get_x(), eweapon[j]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								eweapon.erase(eweapon.begin() + j);

							}
						}


						if (m.get_tile_number(tile_x, tile_y) == 2)
						{
							if (collision.collision_detect(eweapon[j]->get_x(), eweapon[j]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
							{
								eweapon.erase(eweapon.begin() + j);
							}
						}
					}
					
					
				}
			}

			//collision for tiles (player)
			for (int i = 0; i < m.get_length(); i++)
			{
				for (int j = 0; j < m.get_width(); j++)
				{
					//std::cout << m.get_tile_number(j);
					if (m.get_tile_number(j, i) == 1)
					{
						if (collision.collision_detect(player.get_x(), player.get_y(), j*al_get_bitmap_width(image.Tiles(6).first), i*al_get_bitmap_width(image.Tiles(6).first)))
						{
							player.col_update();
						}
					}


					if (m.get_tile_number(j, i) == 2)
					{
						if (collision.collision_detect(player.get_x(), player.get_y(), j*al_get_bitmap_width(image.Tiles(6).first), i*al_get_bitmap_width(image.Tiles(6).first)))
						{
							player.col_update();
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
					player.set_health(player.get_health() - eweapon[i]->damage());
					eweapon.erase(eweapon.begin() + i);
				}
			}

			//update power up's info
			for (int i = 0; i < powerup.size(); i++)
			{

				if (collision.collision_detect(player.get_x(), player.get_y(), powerup[i]->get_x(), powerup[i]->get_y()))
				{
					powerup[i]->power_up_abilities(player, enemy);
					powerup.erase(powerup.begin() + i);
				}
			}
			
			//updates player weapon
			for (int i = 0; i < pweapon.size(); i++)
			{
				pweapon[i]->update();
			}

			//draw becomes true for the sake of cpu
			draw = true;
		}

		//if draw is true, display all assets
		if (draw)
		{
			for (int i = 0; i < m.get_length(); i++)
			{
				for (int j = 0; j < m.get_width(); j++)
				{
					//std::cout << m.get_tile_number(j);
					if (m.get_tile_number(j, i) == 1)
					{
						al_draw_bitmap(image.Tiles(1).first, j*al_get_bitmap_width(image.Tiles(1).first), i*al_get_bitmap_height(image.Tiles(1).first), NULL);
					}

					else if (m.get_tile_number(j, i) == 0)
					{
						al_draw_bitmap(image.Tiles(6).first, j*al_get_bitmap_width(image.Tiles(6).first), i*al_get_bitmap_height(image.Tiles(6).first), NULL);
					}

					else if (m.get_tile_number(j, i) == 2)
					{
						al_draw_bitmap(image.Tiles(10).first, j*al_get_bitmap_width(image.Tiles(10).first), i*al_get_bitmap_height(image.Tiles(10).first), NULL);
					}
				}
			}

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
	image.Deallocate_image(m);
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