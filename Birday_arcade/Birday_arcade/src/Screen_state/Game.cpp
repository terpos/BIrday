#include "Game.h"



Game::Game()
{
	//integer array variable
	buttons[0] = ALLEGRO_KEY_DOWN;
	buttons[1] = ALLEGRO_KEY_UP;
	buttons[2] = ALLEGRO_KEY_RIGHT;
	buttons[3] = ALLEGRO_KEY_LEFT;
	buttons[4] = ALLEGRO_KEY_SPACE;
	buttons[5] = ALLEGRO_KEY_A;
	buttons[6] = ALLEGRO_KEY_S;

	unlock_weapon[LAZER] = true;
	unlock_weapon[ROCKET_LAZER] = false;
	unlock_weapon[STUNNER] = false;
	unlock_weapon[BOMBS] = false;
	unlock_weapon[ICE_BOMBS] = false;
	unlock_weapon[FIRE_BOMBS] = false;
	unlock_weapon[ATOMIC_BOMBS] = false;
	unlock_weapon[BI_NUKE] = false;
	unlock_weapon[TRI_NUKE] = false;
	unlock_weapon[TRIANGULAR_MISSILE] = false;
	unlock_weapon[ARROW] = false;
	unlock_weapon[SLICER] = false;

	levelup = false;

	healing_loading[0] = 0;
	healing_loading[1] = 0;

	seed = std::chrono::system_clock::now().time_since_epoch().count();

	power_up_popup.seed(seed);
	ammo_popup.seed(seed);

	num_of_kills = 0;
	duration1 = 200;
	duration2 = 250;
	num_of_weapon = 0;
	level = 1;

	healing[0].set_frame(0);
	healing[1].set_frame(0);
}


Game::~Game()
{
	//destroys image and sound memory
	
	std::cout << "Memory Deallocated" << std::endl;
}

void Game::init()
{
	
	
}

void Game::load(Image image)
{
	//vector variable assignment
	
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));

	player = new Player(image, 8 * 80, 0, 80, 0, buttons);

}

void Game::update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Tile_map &m, Weapons_Unlocked_List &weapons_unlocked, Options option, Image image, Sound sound, ALLEGRO_EVENT &e, int & screennum, bool &done)
{
	//waits until key is pressed 
	al_wait_for_event(q, &e);

	//closes the window when escape key is pressed
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			al_stop_sample_instance(sound.bg_music(1));
			al_stop_sample_instance(sound.bg_music(2));
			al_stop_sample_instance(sound.bg_music(3));
			al_stop_sample_instance(sound.bg_music(4));
			al_stop_sample_instance(sound.bg_music(5));
			screennum = QUIT_SCREEN;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			al_stop_sample_instance(sound.bg_music(1));
			al_stop_sample_instance(sound.bg_music(2));
			al_stop_sample_instance(sound.bg_music(3));
			al_stop_sample_instance(sound.bg_music(4));
			al_stop_sample_instance(sound.bg_music(5));
			screennum = PAUSE_SCREEN;
		}
	}

	//controls player
	player->control(image, sound, e, option, pweapon, unlock_weapon, num_of_weapon);


	//updates stuff
	if (e.type == ALLEGRO_EVENT_TIMER)
	{
		std::uniform_int_distribution <int> pwrup(0, 5);
		std::uniform_int_distribution <int> ammos(0, num_of_weapon);

		//std::cout << "Player's Health: " << player->get_health() << std::endl;

		//levels up

		if (player->get_health() <= 0)
		{
			player->damage_col_tile_update();
			player->set_health(100);
			player->set_x(8 * 80);
			player->set_y(0);
			player->set_direction(0);

			screennum = GAME_OVER_SCREEN;
		}

		if (enemy.size() <= 0 && !levelup)
		{
			levelup = true;
		}


		if (player->get_health() > 100)
		{
			player->set_health(100);
		}

		if (levelup)
		{
			level++;
			std::cout << "LEVEL " << level << std::endl;
			
			enemy.push_back(new Tripus(image, 1, 0, 80, 5, 0));
			enemy.push_back(new Magic_Mask(image, 1, 0, 80, 5, 0));
			enemy.push_back(new Magic_Mask(image, 1, 0, 80, 5, 0));
			enemy.push_back(new Tripus(image, 1, 0, 80, 5, 0));
			levelup = false;
			
		}

		//std::cout << healing_loading[0] << std::endl;

		if (healing_loading[0] > 80)
		{
			healing_loading[0] = 80.00;
		}

		if (healing_loading[0] == 80.00 && !collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 0))
		{
			healing[0].increment_frame();
		}

		if (healing_loading[0] < 80.00 && !collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 0))
		{
			healing_loading[0]+=.1;
		}

		if (healing_loading[0] == 80.00 && collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 0))
		{

			if (player->get_health() < 100.00)
			{
				player->set_vel(0);
				player->set_health(player->get_health() + 1);

			}

			else
			{
				player->set_vel(80);
				healing_loading[0] = 0;
				healing_loading[1] = 0;
			}
		}



		if (healing_loading[1] > 80)
		{
			healing_loading[1] = 80.00;
		}

		if (healing_loading[1] == 80.00 && !collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 80 * 8))
		{
			healing[1].increment_frame();
		}

		if (healing_loading[1] < 80.00 && !collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 80 * 8))
		{
			healing_loading[1]+=.1;
		}

		if (healing_loading[1] == 80.00 && collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 80 * 8))
		{
			if (player->get_health() < 100.00)
			{
				player->set_vel(0);
				player->set_health(player->get_health() + 1);

			}

			else
			{
				player->set_vel(80);
				healing_loading[0] = 0;
				healing_loading[1] = 0;
			}
		}

		//clears the trails images has left over
		al_clear_to_color(al_map_rgb(0, 0, 0));

		//updates player's info
		player->update(pweapon);

		collision.Window_Collision(display, e, player);
		collision.Window_Collision(display, e, pweapon, eweapon);

		//updates enemies' info
		for (int i = 0; i < enemy.size(); i++)
		{

			

			collision.Window_Collision(display, e, enemy[i]);

			enemy[i]->react(image, player, eweapon);
			enemy[i]->update(eweapon, pweapon, image);

			if (collision.collision_detect(player->get_x(), player->get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
			{
				player->set_health(player->get_health() - enemy[i]->Damage());
				player->damage_col_update();
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
						if (enemy[i]->get_health() > 0 && !pweapon[j]->is_hit().first)
						{
							
							
							pweapon[j]->abilities();
							

							if (pweapon[j]->enemy_damaged())
							{
								enemy[i]->set_hit(true, 0);
								enemy[i]->set_health(enemy[i]->get_health() - pweapon[j]->damage());
							}

							if (pweapon[j]->is_dead())
							{
								pweapon.erase(pweapon.begin() + j);
							}
						}

						if (enemy[i]->get_health() <= 0 && pweapon[j]->is_hit().first)
						{
							al_set_sample_instance_position(sound.sound_effects(1), 0);
							al_play_sample_instance(sound.sound_effects(1));
							pweapon[j]->set_hit(false, 0);
							pweapon[j]->set_kill(true);
						}
					}

				}
			}

			

			if (enemy[i]->is_hit().second == 1)
			{
				
				num_of_kills++;
				enemy.erase(enemy.begin() + i);
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
							pweapon[i]->set_hit(true, pweapon[i]->is_hit().second);
							pweapon[i]->abilities();
						}
					}


					if (m.get_tile_number(tile_x, tile_y) == 2)
					{
						if (collision.collision_detect(pweapon[i]->get_x(), pweapon[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
						{
							pweapon[i]->set_hit(true, pweapon[i]->is_hit().second);
							pweapon[i]->abilities();
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
				if (m.get_tile_number(j, i) == 1)
				{
					if (collision.collision_detect(player->get_x(), player->get_y(), j*al_get_bitmap_width(image.Tiles(6).first), i*al_get_bitmap_width(image.Tiles(6).first)))
					{
						player->col_update();
					}
				}


				if (m.get_tile_number(j, i) == 2)
				{
					if (collision.collision_detect(player->get_x(), player->get_y(), j*al_get_bitmap_width(image.Tiles(6).first), i*al_get_bitmap_width(image.Tiles(6).first)))
					{
						player->col_update();
					}
				}
			}
		}

		//updates enemy weapons' info
		for (int i = 0; i < eweapon.size(); i++)
		{
			eweapon[i]->update();

			if (collision.collision_detect(eweapon[i]->get_x(), eweapon[i]->get_y(), player->get_x(), player->get_y()))
			{
				player->set_health(player->get_health() - eweapon[i]->damage());
				eweapon.erase(eweapon.begin() + i);
			}
		}

		//update power up's info
		for (int i = 0; i < powerup.size(); i++)
		{

			if (collision.collision_detect(player->get_x(), player->get_y(), powerup[i]->get_x(), powerup[i]->get_y()))
			{
				duration1 = 200;
				powerup[i]->power_up_abilities(player, enemy);
				powerup.erase(powerup.begin() + i);
			}
		}

		//update ammo info
		for (int i = 0; i < ammo.size(); i++)
		{

			if (collision.collision_detect(player->get_x(), player->get_y(), ammo[i]->get_x(), ammo[i]->get_y()))
			{
				duration2 = 250;
				ammo[i]->ammo_reload(player);


				ammo.erase(ammo.begin() + i);
			}
		}

		//updates player weapon
		for (int i = 0; i < pweapon.size(); i++)
		{
			pweapon[i]->update();
		}


		if (duration1 == 1)
		{
			switch (pwrup(power_up_popup))
			{
			case GLIDING_CHIP:
				powerup.push_back(new Gliding_Chip(image, 320, 320));
				break;
			case HEALTH_CHIP:
				powerup.push_back(new Health_Chip(image, 320, 320));
				break;
			case NEEDLE_WIND_BLAST_CHIP:
				powerup.push_back(new Needle_Blast_Wind_Chip(image, 320, 320));
				break;
			case STOP_CHIP:
				powerup.push_back(new Stop_Time_Chip(image, 320, 320));
				break;
			case B_2_BOMBER_STRIKE_CHIP:
				powerup.push_back(new B_2_Bomber_Strike_Chip(image, 320, 320));
				break;
			case COPY_CHIP:
				powerup.push_back(new Copy_Chip(image, 320, 320));
				break;

			}

			duration1--;
		}

		else if (duration1 > 1)
		{
			duration1--;
		}


		if (duration2 == 1)
		{
		
			switch (ammos(ammo_popup))
			{
			case 0:
				duration2 = 250;
				break;
			case ROCKET_LAZER_AMMO:
				ammo.push_back(new Ammo(image, ROCKET_LAZER_AMMO, 960, 320));
				break;
			case STUNNER_AMMO:
				ammo.push_back(new Ammo(image, STUNNER_AMMO, 960, 320));
				break;
			case BOMB_AMMO:
				ammo.push_back(new Ammo(image, BOMB_AMMO, 960, 320));
				break;
			case ICE_BOMB_AMMO:
				ammo.push_back(new Ammo(image, ICE_BOMB_AMMO, 960, 320));
				break;
			case FIRE_BOMB_AMMO:
				ammo.push_back(new Ammo(image, FIRE_BOMB_AMMO, 960, 320));
				break;
			case ATOMIC_BOMB_AMMO:
				ammo.push_back(new Ammo(image, ATOMIC_BOMB_AMMO, 960, 320));
				break;
			case BI_NUKE_AMMO:
				ammo.push_back(new Ammo(image, BI_NUKE_AMMO, 960, 320));
				break;
			case TRI_NUKE_AMMO:
				ammo.push_back(new Ammo(image, TRI_NUKE_AMMO, 960, 320));
				break;
			case TRIANGULAR_MISSILE_AMMO:
				ammo.push_back(new Ammo(image, TRIANGULAR_MISSILE_AMMO, 960, 320));
				break;
			case ARROW_AMMO:
				ammo.push_back(new Ammo(image, ARROW_AMMO, 960, 320));
				break;
			case SLICER_AMMO:
				ammo.push_back(new Ammo(image, SLICER_AMMO, 960, 320));
				break;
			}

			std::cout << "AMMO: " << ammos(ammo_popup) << std::endl;

			duration2--;
		}

		else if (duration2 > 1)
		{
			duration2--;
		}

	

		if (num_of_kills == 1 && !unlock_weapon[ROCKET_LAZER])
		{
			unlock_weapon[ROCKET_LAZER] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ROCKET LAZER");

		}
		if (num_of_kills == 2 && !unlock_weapon[STUNNER])
		{
			unlock_weapon[STUNNER] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("STUNNER");


		}
		if (num_of_kills == 3 && !unlock_weapon[BOMBS])
		{
			unlock_weapon[BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("BOMBS");


		}
		if (num_of_kills == 4 && !unlock_weapon[ICE_BOMBS])
		{
			unlock_weapon[ICE_BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ICE BOMBS");

		}
		if (num_of_kills == 5 && !unlock_weapon[FIRE_BOMBS])
		{
			unlock_weapon[FIRE_BOMBS] = true;
			num_of_weapon++;

			weapons_unlocked.add_word_to_list("FIRE BOMBS");


		}
		if (num_of_kills == 6 && !unlock_weapon[ATOMIC_BOMBS])
		{
			unlock_weapon[ATOMIC_BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ATOMIC BOMBS");


		}
		if (num_of_kills == 7 && !unlock_weapon[BI_NUKE])
		{
			unlock_weapon[BI_NUKE] = true;
			this->num_of_weapon++;


			weapons_unlocked.add_word_to_list("BI NUKE");

		}
		if (num_of_kills == 8 && !unlock_weapon[TRI_NUKE])
		{
			unlock_weapon[TRI_NUKE] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("TRI NUKE");


		}
		if (num_of_kills == 9 && !unlock_weapon[TRIANGULAR_MISSILE])
		{
			unlock_weapon[TRIANGULAR_MISSILE] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("TRIANGULAR MISSILE");


		}
		if (num_of_kills == 10 && !unlock_weapon[ARROW])
		{
			unlock_weapon[ARROW] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ARROW");

		}
		if (num_of_kills == 11 && !unlock_weapon[SLICER])
		{
			unlock_weapon[SLICER] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("SLICER");

		}

	}
}

void Game::render(Image image, Sound sound, Tile_map &m, Font font)
{
	if (player->get_health() > 0)
	{
		if (level >= 1 && level <= 4)
		{
			al_play_sample_instance(sound.bg_music(1));
		}

		else if (level >= 5 && level <= 14)
		{
			al_play_sample_instance(sound.bg_music(2));
		}

		else if (level >= 15 && level <= 24)
		{
			al_play_sample_instance(sound.bg_music(3));
		}

		else if (level >= 25 && level <= 44)
		{
			al_play_sample_instance(sound.bg_music(4));
		}

		else
		{
			al_play_sample_instance(sound.bg_music(5));
		}
	}
	
	else
	{
		al_stop_sample_instance(sound.bg_music(1));
		al_stop_sample_instance(sound.bg_music(2));
		al_stop_sample_instance(sound.bg_music(3));
		al_stop_sample_instance(sound.bg_music(4));
		al_stop_sample_instance(sound.bg_music(5));
	}

	for (int i = 0; i < m.get_length(); i++)
	{
		for (int j = 0; j < m.get_width(); j++)
		{
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

	
	if (healing_loading[0] < 80)
	{
		al_draw_filled_rectangle(80 * 8, 0, (80 * 8) + healing_loading[0], 80, al_map_rgb(0, 150, 255));
	}
	
	else
	{
		if (healing[0].get_frame_position(7) == 2)
		{
			al_draw_filled_rectangle(80 * 8, 0, (80 * 8) + healing_loading[0], 80, al_map_rgb(0, 0, 255));
		}

		else if (healing[0].get_frame_position(7) == 4)
		{
			al_draw_filled_rectangle(80 * 8, 0, (80 * 8) + healing_loading[0], 80, al_map_rgb(0, 255, 0));
		}

		else
		{
			al_draw_filled_rectangle(80 * 8, 0, (80 * 8) + healing_loading[0], 80, al_map_rgb(255, 0, 0));
		}

	}
	
	if (healing_loading[1] < 80)
	{
		al_draw_filled_rectangle(80 * 8, 80 * 8, (80 * 8) + healing_loading[1], (80 * 8) + 80, al_map_rgb(0, 150, 255));
	}

	else
	{
		if (healing[1].get_frame_position(7) == 2)
		{
			al_draw_filled_rectangle(80 * 8, 80 * 8, (80 * 8) + healing_loading[1], (80 * 8) + 80, al_map_rgb(0, 0, 255));
		}

		else if (healing[1].get_frame_position(7) == 4)
		{
			al_draw_filled_rectangle(80 * 8, 80 * 8, (80 * 8) + healing_loading[1], (80 * 8) + 80, al_map_rgb(0, 255, 0));
		}

		else
		{
			al_draw_filled_rectangle(80 * 8, 80 * 8, (80 * 8) + healing_loading[1], (80 * 8) + 80, al_map_rgb(255, 0, 0));
		}

	}

	for (int i = 0; i < powerup.size(); i++)
	{
		powerup[i]->render();
	}

	for (int i = 0; i < ammo.size(); i++)
	{
		ammo[i]->render();
	}

	for (int i = 0; i < pweapon.size(); i++)
	{
		pweapon[i]->render(image);
	}

	for (int i = 0; i < eweapon.size(); i++)
	{
		eweapon[i]->render();
	}

	player->render();

	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->render(image);
	}
}

