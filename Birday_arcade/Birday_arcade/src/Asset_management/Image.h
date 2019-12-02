#include "global.h"
#include "Tile_map.h"

#pragma once
class Image
{
public:
	Image();
	~Image();

	void Load_Images();
	void Image_error_check();
	void Deallocate_image();
		
	std::pair <ALLEGRO_BITMAP*, int> Enemy_image(int enemies);
	std::pair <ALLEGRO_BITMAP*, int> Player_image();
	std::pair <ALLEGRO_BITMAP*, int> Player_weapon_image(int pweapon);
	std::pair <ALLEGRO_BITMAP*, int> power_up_image(int power_up);
	std::pair <ALLEGRO_BITMAP*, int> Enemy_weapon_image(int eweapon);
	std::pair <ALLEGRO_BITMAP*, int> Tiles(Tile_map tiles, int number);

private:
	std::vector < std::pair <ALLEGRO_BITMAP*, int> > tiles, enemies, player, p_weapon, E_weapon, PowerUp;
	ALLEGRO_PATH *path;
	ALLEGRO_BITMAP * p;
	
};

