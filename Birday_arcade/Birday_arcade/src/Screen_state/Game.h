#include "Asset_management/Sound.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"

#include "Screen_state/Options.h"
#include "Entities/Collision.h"
#include "Screen_state/Weapons_Unlocked_List.h"

#include "Entities/Power_Up/Power_Up.h"
#include "Entities/Power_Up/B_2_Bomber_Strike_Chip.h"
#include "Entities/Power_Up/Copy_Chip.h"
#include "Entities/Power_Up/Gliding_Chip.h"
#include "Entities/Power_Up/Health_Chip.h"
#include "Entities/Power_Up/Needle_Blast_Wind_Chip.h"
#include "Entities/Power_Up/Stop_Time_Chip.h"
#include "Entities/Power_Up/Ammo.h"

#include "Entities/Enemy/Ball.h"
#include "Entities/Enemy/Cannon_Slug.h"
#include "Entities/Enemy/Diamondo.h"
#include "Entities/Enemy/Magic_Mask.h"
#include "Entities/Enemy/Fisher.h"
#include "Entities/Enemy/Tripus.h"

#include "Entities/Power_Up/B_2_bomber.h"
#include "Entities/Power_Up/needle_wind.h"


#pragma once
class Game
{
public:
	Game();
	~Game();

	void init(Options option);
	void load(Image image);
	void enemies_spawn(Image image, int random_num, std::uniform_int_distribution <int> randomx, std::uniform_int_distribution <int> randomy);
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Tile_map &m, Weapons_Unlocked_List &weapons_unlocked, Options &option, Image image, Sound sound, ALLEGRO_EVENT &e, int & screennum, bool &done);
	void render(Weapons_Unlocked_List &weapons_unlocked, Options option, Image image, Sound sound, Tile_map &m, Font font);

	

	void reset(Weapons_Unlocked_List &weapons_unlocked);

private:
	//vector object variables
	std::vector <Enemy*> enemy;
	std::vector <Power_Up*> powerup;
	std::vector <P_Weapon*> pweapon;
	std::vector <E_Weapon*> eweapon;
	std::vector <Ammo*> ammo;

	//object variables
	Player *player;
	Collision collision;

	std::default_random_engine power_up_popup, ammo_popup, enemy_spawn, yposition, xposition;

	Animation healing[2];
	std::vector <B_2_Bomber*> b2;
	std::vector <needle_wind*> nw;


	bool unlock_weapon[12], levelup, initial, spreadout, increment_defense, increment_max_ammo, increase_bounce, destroyed_by_b2;

	int buttons[7], seed, duration1, duration2, num_of_kills, 
		num_of_weapon, level, score, notification_duration, level_duration, x1, x2, defense, num_of_notification, num_of_bounce[12], appear_duration1, appear_duration2;
	double healing_loading[2];
};

