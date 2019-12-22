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
}


Game::~Game()
{
	//destroys image and sound memory
	
	std::cout << "Memory Deallocated" << std::endl;
}

void Game::init()
{
	
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Fisher(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Magic_Mask(image, 2, 300, 300, 5, 0));
	
	//player->set_health(100);
}

void Game::load(Image image)
{

	

	//vector variable assignment
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Fisher(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Tripus(image, 1, 300, 300, 5, 0));
	enemy.push_back(new Magic_Mask(image, 2, 300, 300, 5, 0));

	player = new Player(image, 8 * 80, 0, 80, 0, buttons);

}

void Game::update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Tile_map &m, Options option, Image image, ALLEGRO_EVENT &e, int & screennum, bool &done)
{
	//waits until key is pressed (can be neglected since timer is on)
	al_wait_for_event(q, &e);

	//closes the window when escape key is pressed
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (e.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			screennum = QUIT_SCREEN;
		}

		if (e.keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			screennum = PAUSE_SCREEN;
		}
	}


	//controls player
	player->control(image, e, option, pweapon);

	//updates stuff
	if (e.type == ALLEGRO_EVENT_TIMER)
	{
		//clears the trails images has left over
		al_clear_to_color(al_map_rgb(0, 0, 0));

		//updates player's info
		player->update(pweapon);
		collision.Window_Collision(display, e, player);
		collision.Window_Collision(display, e, pweapon, eweapon);

		

		//updates enemies' info
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i]->react(image, player, eweapon);
			enemy[i]->update(eweapon, image);

			collision.Window_Collision(display, e, enemy[i]);



			if (collision.collision_detect(player->get_x(), player->get_y(), enemy[i]->get_x(), enemy[i]->get_y()))
			{
				if (player->get_health() <= 0)
				{
					player->damage_col_tile_update();
					player->set_health(100);
					player->set_x(8*80);
					player->set_y(0);
					player->set_direction(0);

					//enemy.clear();
					//init();
					screennum = GAME_OVER_SCREEN;
				}

				else
				{
					player->set_health(player->get_health() - enemy[i]->Damage());
					player->damage_col_update();
				}
			
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
							ammo.push_back(new Ammo(image, ROCKET_LAZER_AMMO, enemy[i]->get_x(), enemy[i]->get_y()));
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
				powerup[i]->power_up_abilities(player, enemy);
				powerup.erase(powerup.begin() + i);
			}
		}

		for (int i = 0; i < ammo.size(); i++)
		{

			if (collision.collision_detect(player->get_x(), player->get_y(), ammo[i]->get_x(), ammo[i]->get_y()))
			{
				ammo[i]->power_up_abilities(player);
				ammo.erase(ammo.begin() + i);
			}
		}

		//updates player weapon
		for (int i = 0; i < pweapon.size(); i++)
		{
			pweapon[i]->update();
		}

		
	}
}

void Game::render(Image image, Tile_map &m, Font font)
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

	for (int i = 0; i < ammo.size(); i++)
	{
		ammo[i]->render();
	}

	for (int i = 0; i < pweapon.size(); i++)
	{
		pweapon[i]->render();
	}

	for (int i = 0; i < eweapon.size(); i++)
	{
		eweapon[i]->render();
	}

	player->render();

	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->render();
	}
}

