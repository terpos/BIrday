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

	levelup = true;
	initial = true;
	
	healing_loading[0] = 0;
	healing_loading[1] = 0;

	seed = std::chrono::system_clock::now().time_since_epoch().count();

	power_up_popup.seed(seed);
	ammo_popup.seed(seed);
	enemy_spawn.seed(seed);
	yposition.seed(seed);

	num_of_kills = 0;
	duration1 = 200;
	duration2 = 250;
	num_of_weapon = 0;
	level = 1;
	score = 0;
	level_duration = 0;
	

	healing[0].set_frame(0);
	healing[1].set_frame(0);
}


Game::~Game()
{
	//destroys image and sound memory
	
	std::cout << "Memory Deallocated" << std::endl;
}

void Game::init(Options option)
{
	if (level_duration == 0 && initial)
	{
		this->level = option.get_level_for_difficulty();
		initial = false;
		x1 = x2 = 680;
	}
	
}

void Game::load(Image image)
{
	//vector variable assignment
	player = new Player(image, 8 *80, 80, 80, 0, buttons);

}

void Game::enemies_spawn(int random_num, std::uniform_int_distribution <int> randomy)
{
	switch (random_num)
	{
	case TRIPUS:
		enemy.push_back(new Tripus(image, 1, 0, randomy(yposition), 5, 0));
		break;
	case MAGIC_MASK:
		enemy.push_back(new Magic_Mask(image, 1, 0, randomy(yposition), 5, 0));
		break;
	case DIAMONDO:
		enemy.push_back(new Diamondo(image, 1, 0, randomy(yposition), 5, 0));
		break;
	case CANNON_SLUG:
		enemy.push_back(new Cannon_Slug(image, 1, 0, randomy(yposition), 5, 0));
		break;
	case FISHER:
		enemy.push_back(new Fisher(image, 1, 0, randomy(yposition), 5, 0));
		break;
	case BALL:
		enemy.push_back(new Ball(image, 1, 0, randomy(yposition), 5, 0));
		break;

	case TRIPUS2:														
		enemy.push_back(new Tripus(image, 2, 0, randomy(yposition), 5, 0));
		break;															
	case MAGIC_MASK2:													
		enemy.push_back(new Magic_Mask(image, 2, 0, randomy(yposition), 5, 0));
		break;															
	case DIAMONDO2:														
		enemy.push_back(new Diamondo(image, 2, 0, randomy(yposition), 5, 0));
		break;															
	case CANNON_SLUG2:													
		enemy.push_back(new Cannon_Slug(image, 2, 0, randomy(yposition), 5, 0));
		break;															
	case FISHER2:														
		enemy.push_back(new Fisher(image, 2, 0, randomy(yposition), 5, 0));
		break;
	case BALL2:
		enemy.push_back(new Ball(image, 2, 0, randomy(yposition), 5, 0));
		break;
	}
}

void Game::update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Tile_map &m, Weapons_Unlocked_List &weapons_unlocked, 
	Options &option, Image image, Sound sound, ALLEGRO_EVENT &e, int & screennum, bool &done)
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

			option.set_last_screen(GAME_SCREEN);
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

	if (x1 > 0 && x2 < 1360)
	{
		x1-=5;
		x2+=5;
	}

	else
	{
		if (level_duration == 1)
		{
			level_duration = 0;
			level++;
		}

		if (level_duration > 1)
		{
			std::cout << level_duration << std::endl;
			level_duration--;

		}

		if (enemy.size() <= 0 && !levelup)
		{
			levelup = true;
			level_duration = 150;
		}
	}
	

	//updates stuff
	if (e.type == ALLEGRO_EVENT_TIMER && x1 == 0 && x2 == 1360)
	{
		std::uniform_int_distribution <int> pwrup(0, 5);
		std::uniform_int_distribution <int> ammos(0, num_of_weapon);
		std::uniform_int_distribution <int> enemiesspawn(0, 11);
		std::uniform_int_distribution <int> ypos(1 * 80, 7 * 80);
		

		if (levelup && level_duration == 0)
		{

			if (level == 1)
			{
				enemy.push_back(new Tripus(image, 1, 0, 80, 5, 0));
				enemy.push_back(new Tripus(image, 1, 0, 240, 5, 0));
			
				
			}

			else if (level == 2)
			{
				    enemy.push_back(new Tripus(image, 1, 0, ypos(yposition), 5, 0));
				    enemy.push_back(new Tripus(image, 1, 0, ypos(yposition), 5, 0));
				    enemy.push_back(new Tripus(image, 1, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
			}

			else if (level == 3)
			{
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0,   ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0,   ypos(yposition), 10, 0));
			}

			else if (level == 4)
			{
				enemy.push_back(new Tripus(image, 1, 0,     ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,     ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,     ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus(image, 1, 0,     ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 1, 0,   ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,   ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,   ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,   ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1,0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1,0, ypos(yposition), 10, 0));
			}

			else if (level == 5)
			{
				enemy.push_back(new Tripus (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 6)
			{
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
			}

			else if (level == 7)
			{
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
			}

			else if (level == 8)
			{
				enemy.push_back(new Tripus    (image, 1, 0, ypos(yposition) , 5, 0));
				enemy.push_back(new Tripus    (image, 1, 0,   ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0,   ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 1, 0,     ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0,  ypos(yposition), 10, 0));
			}

			else if (level == 9)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 10)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			        enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
			        enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 11)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 12)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 13)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 14)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 15)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			        enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
				    enemy.push_back(new Fisher(image, 1, 0, ypos(yposition), 10, 0));
			}

			else if (level == 16)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
			}

			else if (level == 17)
			{
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo  (image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
			   enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher    (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball      (image, 1, 0, ypos(yposition), 8, 0));
			}

			else if (level == 18)
			{
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
			}

			else if (level == 19)
			{
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
			}

			else if (level == 20)
			{
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo   (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher     (image, 1, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball       (image, 1, 0, ypos(yposition), 8, 0));
			}

			

			if (level == 21)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
			}

			else if (level == 22)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level == 23)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 24)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 25)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 26)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 27)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 28)
			{
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Tripus(image, 2, 0, ypos(yposition), 5, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 29)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 30)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 31)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}									  

			else if (level == 32)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 33)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 34)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 35)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
			}

			else if (level == 36)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level == 37)
			{
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Magic_Mask(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level == 38)
			{
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level == 39)
			{
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level == 40)
			{
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Diamondo(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Cannon_Slug(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Fisher(image, 2, 0, ypos(yposition), 10, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
				enemy.push_back(new Ball(image, 2, 0, ypos(yposition), 8, 0));
			}

			else if (level > 40)
			{
				for (int i = 0; i < 16; i++)
				{
					enemies_spawn(enemiesspawn(enemy_spawn), ypos);
				}
			}

			levelup = false;

		}

		if (notification_duration > 0)
		{
			notification_duration--;
		}

		if (notification_duration < 0)
		{
			notification_duration = 0;
		}

		//levels up

		if (player->get_health() <= 0)
		{
			enemy.clear();
			level = option.get_level_for_difficulty();
			player->damage_col_tile_update();
			player->set_health(100);
			player->set_x(8);
			player->set_y(0);
			player->set_direction(0);
			initial = true;
			player->set_x(8 * 80);
			player->set_y(80);
			player->set_hit(false, 0);
			healing_loading[0] = 0;
			healing_loading[1] = 0;
			eweapon.clear();
			pweapon.clear();
			screennum = GAME_OVER_SCREEN;
		}

		if (player->get_health() > 100)
		{
			player->set_health(100);
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
			healing_loading[0] += .1;
		}

		if (healing_loading[0] == 80.00 && collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 0))
		{

			if (player->get_health() < 100.00)
			{
				player->set_vel(0);
				player->set_direction(0);
				player->set_health(player->get_health() + 1);
				player->set_healing(true);
			}

			else
			{
				player->set_healing(false);
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
			healing_loading[1] += .1;
		}

		if (healing_loading[1] == 80.00 && collision.collision_detect(player->get_x(), player->get_y(), 80 * 8, 80 * 8))
		{
			if (player->get_health() < 100.00)
			{
				player->set_healing(true);
				player->set_direction(0);
				player->set_vel(0);
				player->set_health(player->get_health() + 1);

			}

			else
			{
				player->set_healing(false);
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

			

			if (collision.collision_detect(player->get_x(), player->get_y(), enemy[i]->get_x(), enemy[i]->get_y()) && player->is_hit().second == 0)
			{
				player->set_hit(true, 1);
			}

			//enemy & tile collision 
			for (int j = 0; j < enemy.size(); j++)
			{
				if (i != j)
				{
					if (collision.collision_detect(enemy[i]->get_x(), enemy[i]->get_y(), enemy[j]->get_x(), enemy[j]->get_y()))
					{
						enemy[i]->set_move_duration(0);
						enemy[i]->change_direction();
					}
				}
			}

			for (int tile_y = 0; tile_y < m.get_length(); tile_y++)
			{
				for (int tile_x = 0; tile_x < m.get_width(); tile_x++)
				{
					//std::cout << m.get_tile_number(j);
					if (m.get_tile_number(tile_x, tile_y) == 1)
					{
						if (collision.collision_detect(enemy[i]->get_x(), enemy[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
						{
							enemy[i]->set_move_duration(0);
							enemy[i]->change_direction();
						}
					}

					if (m.get_tile_number(tile_x, tile_y) == 2)
					{
						if (collision.collision_detect(enemy[i]->get_x(), enemy[i]->get_y(), tile_x*al_get_bitmap_width(image.Tiles(6).first), tile_y*al_get_bitmap_width(image.Tiles(6).first)))
						{
							enemy[i]->set_move_duration(0);
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
						if (enemy[i]->get_health() <= 0 && pweapon[j]->is_hit().first)
						{
							if (option.get_sound_options())
							{
								al_play_sample_instance(sound.sound_effects(8));
							}
							pweapon[j]->set_hit(true, pweapon[j]->is_hit().second);
						}

						else if (enemy[i]->get_health() > 0 && !pweapon[j]->is_hit().first)
						{
							pweapon[j]->abilities();

							if (pweapon[j]->enemy_damaged())
							{
								enemy[i]->set_hit(true, pweapon[j]->enemy_status());
								enemy[i]->set_health(enemy[i]->get_health() - pweapon[j]->damage());
							}

							if (pweapon[j]->is_dead())
							{
								pweapon.erase(pweapon.begin() + j);
							}
						}

						
					}
				}
			}

			if (enemy[i]->is_dead())
			{
				score = score + enemy[i]->get_score();
				num_of_kills++;
				enemy.erase(enemy.begin() + i);
			}

			if (player->is_hit().first && player->is_hit().second)
			{
				player->set_health(player->get_health() - enemy[i]->Damage());
				player->set_hit(false, player->is_hit().second);
			}


			enemy[i]->react(image, sound, player, eweapon, option);
			enemy[i]->update(eweapon, option, pweapon, image, sound);
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

			if (collision.collision_detect(eweapon[i]->get_x(), eweapon[i]->get_y(), player->get_x(), player->get_y()) && player->is_hit().second == 0)
			{
				player->set_hit(true, 1);
				eweapon.erase(eweapon.begin() + i);
			}
		}

		

		//update power up's info
		for (int i = 0; i < powerup.size(); i++)
		{

			if (collision.collision_detect(player->get_x(), player->get_y(), powerup[i]->get_x(), powerup[i]->get_y()))
			{
				duration1 = 200;
				powerup[i]->power_up_abilities(sound, player, enemy, option);
				powerup.erase(powerup.begin() + i);
			}
		}

		//update ammo info
		for (int i = 0; i < ammo.size(); i++)
		{

			if (collision.collision_detect(player->get_x(), player->get_y(), ammo[i]->get_x(), ammo[i]->get_y()))
			{
				duration2 = 250;
				ammo[i]->ammo_reload(sound, player, option);


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
			notification_duration = 200;

		}
		if (num_of_kills == 2 && !unlock_weapon[STUNNER])
		{
			unlock_weapon[STUNNER] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("STUNNER");
			notification_duration = 200;

		}
		if (num_of_kills == 3 && !unlock_weapon[BOMBS])
		{
			unlock_weapon[BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("BOMBS");
			notification_duration = 200;

		}
		if (num_of_kills == 4 && !unlock_weapon[ICE_BOMBS])
		{
			unlock_weapon[ICE_BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ICE BOMBS");
			notification_duration = 200;
		}
		if (num_of_kills == 5 && !unlock_weapon[FIRE_BOMBS])
		{
			unlock_weapon[FIRE_BOMBS] = true;
			num_of_weapon++;

			weapons_unlocked.add_word_to_list("FIRE BOMBS");
			notification_duration = 200;

		}
		if (num_of_kills == 6 && !unlock_weapon[ATOMIC_BOMBS])
		{
			unlock_weapon[ATOMIC_BOMBS] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ATOMIC BOMBS");
			notification_duration = 200;

		}
		if (num_of_kills == 7 && !unlock_weapon[BI_NUKE])
		{
			unlock_weapon[BI_NUKE] = true;
			this->num_of_weapon++;


			weapons_unlocked.add_word_to_list("BI NUKE");
			notification_duration = 200;
		}
		if (num_of_kills == 8 && !unlock_weapon[TRI_NUKE])
		{
			unlock_weapon[TRI_NUKE] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("TRI NUKE");
			notification_duration = 200;

		}
		if (num_of_kills == 9 && !unlock_weapon[TRIANGULAR_MISSILE])
		{
			unlock_weapon[TRIANGULAR_MISSILE] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("TRIANGULAR MISSILE");
			notification_duration = 200;

		}
		if (num_of_kills == 10 && !unlock_weapon[ARROW])
		{
			unlock_weapon[ARROW] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("ARROW");
			notification_duration = 200;
		}
		if (num_of_kills == 11 && !unlock_weapon[SLICER])
		{
			unlock_weapon[SLICER] = true;
			this->num_of_weapon++;

			weapons_unlocked.add_word_to_list("SLICER");
			notification_duration = 200;
		}

	}
}

void Game::render(Weapons_Unlocked_List &weapons_unlocked, Options option, Image image, Sound sound, Tile_map &m, Font font)
{

	if (player->get_health() > 0 && x1 == 0 && x2 == 1360)
	{
		if (option.get_sound_options())
		{
			if (level >= 0 && level <= 4)
			{
				al_play_sample_instance(sound.bg_music(1));
			}

			else if (level >= 5 && level <= 14)
			{
				al_play_sample_instance(sound.bg_music(2));
				al_stop_sample_instance(sound.bg_music(1));
			}

			else if (level >= 15 && level <= 24)
			{
				al_play_sample_instance(sound.bg_music(3));
				al_stop_sample_instance(sound.bg_music(2));

			}

			else if (level >= 25 && level <= 40)
			{
				al_play_sample_instance(sound.bg_music(4));
				al_stop_sample_instance(sound.bg_music(3));

			}

			else
			{
				al_play_sample_instance(sound.bg_music(5));
				al_stop_sample_instance(sound.bg_music(4));

			}
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
				switch (option.get_tile_options())
				{
				case 1:
					al_draw_bitmap(image.Tiles(BLUE_SQUARE).first, j*al_get_bitmap_width(image.Tiles(BLUE_SQUARE).first), i*al_get_bitmap_height(image.Tiles(BLUE_SQUARE).first), NULL);
					break;
				case 2:
					al_draw_bitmap(image.Tiles(BLUE_CIRCLE).first, j*al_get_bitmap_width(image.Tiles(BLUE_CIRCLE).first), i*al_get_bitmap_height(image.Tiles(BLUE_CIRCLE).first), NULL);
					break;
				case 3:
					al_draw_bitmap(image.Tiles(SAND).first, j*al_get_bitmap_width(image.Tiles(SAND).first), i*al_get_bitmap_height(image.Tiles(SAND).first), NULL);
					al_draw_bitmap(image.Tiles(PALM_TREE).first, j*al_get_bitmap_width(image.Tiles(PALM_TREE).first), i*al_get_bitmap_height(image.Tiles(PALM_TREE).first), NULL);
					break;
				case 4:
					al_draw_bitmap(image.Tiles(BRICK_WALL).first, j*al_get_bitmap_width(image.Tiles(BRICK_WALL).first), i*al_get_bitmap_height(image.Tiles(BRICK_WALL).first), NULL);
					break;
				case 5:
					al_draw_bitmap(image.Tiles(GRASS).first, j*al_get_bitmap_width(image.Tiles(GRASS).first), i*al_get_bitmap_height(image.Tiles(GRASS).first), NULL);
					al_draw_bitmap(image.Tiles(FENCE).first, j*al_get_bitmap_width(image.Tiles(FENCE).first), i*al_get_bitmap_height(image.Tiles(FENCE).first), NULL);
					break;
				}
			}

			else if (m.get_tile_number(j, i) == 0)
			{
				switch (option.get_tile_options())
				{
				case 1:
					al_draw_bitmap(image.Tiles(GRAY_SQUARE).first, j*al_get_bitmap_width(image.Tiles(GRAY_SQUARE).first), i*al_get_bitmap_height(image.Tiles(GRAY_SQUARE).first), NULL);
					break;
				case 2:
					al_draw_bitmap(image.Tiles(WHITE_CIRCLE).first, j*al_get_bitmap_width(image.Tiles(WHITE_CIRCLE).first), i*al_get_bitmap_height(image.Tiles(WHITE_CIRCLE).first), NULL);
					break;
				case 3:
					al_draw_bitmap(image.Tiles(SAND).first, j*al_get_bitmap_width(image.Tiles(SAND).first), i*al_get_bitmap_height(image.Tiles(SAND).first), NULL);
					break;
				case 4:
					al_draw_bitmap(image.Tiles(GRAY_SQUARE).first, j*al_get_bitmap_width(image.Tiles(GRAY_SQUARE).first), i*al_get_bitmap_height(image.Tiles(GRAY_SQUARE).first), NULL);
					break;
				case 5:
					al_draw_bitmap(image.Tiles(GRASS).first, j*al_get_bitmap_width(image.Tiles(GRASS).first), i*al_get_bitmap_height(image.Tiles(GRASS).first), NULL);
					break;
				}
			}

			else if (m.get_tile_number(j, i) == 2)
			{
				switch (option.get_tile_options())
				{
				case 1:
					al_draw_bitmap(image.Tiles(PURPLE_SQUARE).first, j*al_get_bitmap_width(image.Tiles(PURPLE_SQUARE).first), i*al_get_bitmap_height(image.Tiles(PURPLE_SQUARE).first), NULL);
					break;
				case 2:
					al_draw_bitmap(image.Tiles(PURPLE_CIRCLE).first, j*al_get_bitmap_width(image.Tiles(PURPLE_CIRCLE).first), i*al_get_bitmap_height(image.Tiles(PURPLE_CIRCLE).first), NULL);
					break;
				case 3:
					al_draw_bitmap(image.Tiles(SAND).first, j*al_get_bitmap_width(image.Tiles(SAND).first), i*al_get_bitmap_height(image.Tiles(SAND).first), NULL);
					al_draw_bitmap(image.Tiles(ROCK).first, j*al_get_bitmap_width(image.Tiles(ROCK).first), i*al_get_bitmap_height(image.Tiles(ROCK).first), NULL);
					break;
				case 4:
					al_draw_bitmap(image.Tiles(GRAY_SQUARE).first, j*al_get_bitmap_width(image.Tiles(GRAY_SQUARE).first), i*al_get_bitmap_height(image.Tiles(GRAY_SQUARE).first), NULL);
					al_draw_bitmap(image.Tiles(PILLAR).first, j*al_get_bitmap_width(image.Tiles(PILLAR).first), i*al_get_bitmap_height(image.Tiles(PILLAR).first), NULL);
					break;
				case 5:
					al_draw_bitmap(image.Tiles(GRASS).first, j*al_get_bitmap_width(image.Tiles(GRASS).first), i*al_get_bitmap_height(image.Tiles(GRASS).first), NULL);
					al_draw_bitmap(image.Tiles(FLOWER).first, j*al_get_bitmap_width(image.Tiles(FLOWER).first), i*al_get_bitmap_height(image.Tiles(FLOWER).first), NULL);
					break;
				}
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
		pweapon[i]->render(image, sound, option.get_sound_options());
	}

	for (int i = 0; i < eweapon.size(); i++)
	{
		eweapon[i]->render();
	}

	if ( x1 == 0 && x2 == 1360)
	{
		player->render();
	}

		
	

	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->render(image);
	}

	if (level_duration != 0)
	{
		al_draw_filled_rectangle(0, 0, 400, 80, al_map_rgb(0, 0, 0));
		al_draw_text(font.get_font(1), al_map_rgb(255, 255, 255), 0, 0, NULL, "LEVEL ");
		al_draw_textf(font.get_font(1), al_map_rgb(255, 255, 255), 0 + al_get_text_width(font.get_font(1) , "LEVEL "), 0, NULL, "%i", level + 1);

	}

	al_draw_filled_rectangle(0, 720, 1360, 768, al_map_rgb(100, 1, 10));

	al_draw_text(font.get_font(3), al_map_rgb(255, 255, 255), 10, 732, NULL, "SCORE:");

	al_draw_textf(font.get_font(3), al_map_rgb(255, 255, 0), 10 + al_get_text_width(font.get_font(3), "SCORE:"), 732, NULL, "%i", score);

  	al_draw_text(font.get_font(3), al_map_rgb(255, 255, 255), 200, 732, NULL, "HEALTH:");

	al_draw_textf(font.get_font(3), al_map_rgb(255, 255, 0), 200 + al_get_text_width(font.get_font(3), "HEALTH:"), 732, NULL, "%i", player->get_health());

	al_draw_text(font.get_font(3), al_map_rgb(255, 255, 255), 1200, 732, NULL, "LEVEL ");

	al_draw_textf(font.get_font(3), al_map_rgb(255, 255, 0), 1200 + al_get_text_width(font.get_font(3), "LEVEL "), 732, NULL, "%i", level);

	al_draw_text(font.get_font(3), al_map_rgb(255, 255, 255), 600, 732, NULL, "WEAPON:");

	if (player->get_option_weapon() == 0)
	{
		al_draw_textf(font.get_font(3), al_map_rgb(255, 255, 0), 600 + al_get_text_width(font.get_font(3), "WEAPON: "), 732, NULL, "LAZER");
	}

	else
	{
		al_draw_textf(font.get_font(3), al_map_rgb(255, 255, 0), 600 + al_get_text_width(font.get_font(3), "WEAPON: "), 732, NULL, weapons_unlocked.get_list(player->get_option_weapon() - 1).c_str());
		al_draw_textf(font.get_font(3), al_map_rgb(200, 200, 255), 600 + al_get_text_width(font.get_font(3), weapons_unlocked.get_list(player->get_option_weapon() - 1).append("WEAPON:  ").c_str()), 732, NULL, "%d", player->get_num_of_ammo(player->get_option_weapon()));
	}

	if (num_of_weapon > 0 && notification_duration != 0)
	{
 		al_draw_textf(font.get_font(3), al_map_rgb(255, 175, 0), 850, 732, NULL, weapons_unlocked.get_list(num_of_weapon - 1).c_str());
 		al_draw_textf(font.get_font(3), al_map_rgb(255, 175, 0), 850 + al_get_text_width(font.get_font(3), weapons_unlocked.get_list(num_of_weapon - 1).c_str()), 732, NULL, " UNLOCKED");
	}

	al_draw_filled_rectangle(0, 0, x1, 720, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(x2, 0, 1360, 720, al_map_rgb(0, 0, 0));


}

void Game::reset()
{
	enemy.clear();
	level = option.get_level_for_difficulty();
	player->damage_col_tile_update();
	player->set_health(100);
	player->set_x(8);
	player->set_y(0);
	player->set_direction(0);
	initial = true;
	player->set_x(8 * 80);
	player->set_y(80);
	player->set_hit(false, 0);
	healing_loading[0] = 0;
	healing_loading[1] = 0;
	eweapon.clear();
	pweapon.clear();
}
