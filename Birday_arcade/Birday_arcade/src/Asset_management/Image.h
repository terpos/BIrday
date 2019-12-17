#include "Tile_map.h"

#pragma once
class Image
{
public:
	Image();
	~Image();

	//loads sprites (.png)
	void Load_Images();

	//throws error if the sound files are not loaded correctly
	void Image_error_check();

	//destroys image memory
	void Deallocate_image(Tile_map &tile_map_file);
		
	//returns enemy image depending on which enemy
	std::pair <ALLEGRO_BITMAP*, int> Enemy_image(int enemy_num);
	
	//returns player image
	std::pair <ALLEGRO_BITMAP*, int> Player_image();
	
	//returns player weapon image depending on which player weapon
	std::pair <ALLEGRO_BITMAP*, int> Player_Weapon_image(int pweapon_num);
	
	//returns power up image depending on which power up
	std::pair <ALLEGRO_BITMAP*, int> Power_Up_image(int power_up_num);
	
	//returns enemy weapon image depending on which enemy weapon
	std::pair <ALLEGRO_BITMAP*, int> Enemy_Weapon_image(int eweapon_num);

	//returns tile image depending on which tile number and tile
	std::pair <ALLEGRO_BITMAP*, int> Tiles(int tile_piece_num);

private:
	//vector pair variables
	std::vector < std::pair <ALLEGRO_BITMAP*, int> > tile_piece, enemies, player, P_weapon, E_weapon, PowerUp;
	
};

