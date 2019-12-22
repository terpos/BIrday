#include "Asset_management/Sound.h"
#include "Asset_management/Image.h"
#include "Asset_management/Font.h"
#include "Screen_state/Options.h"
#include "Entities/Collision.h"

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


#pragma once
class Game
{
public:
	Game();
	~Game();

	void init();
	void load(Image image);
	void update(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE* q, Tile_map &m, Options option, Image image, ALLEGRO_EVENT &e, int & screennum, bool &done);
	void render(Image image, Tile_map &m, Font font);


private:
	//vector object variables
	std::vector <Enemy*> enemy;
	std::vector <Power_Up*> powerup;
	std::vector <P_Weapon*> pweapon;
	std::vector <E_Weapon*> eweapon;
	std::vector <Ammo*> ammo;

	//object variables
	Player *player;

	Image image;
	Sound sound;
	Collision collision;
	Options option;

	int buttons[7];
};

