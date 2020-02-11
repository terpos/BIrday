#include "Image.h"



Image::Image()
{
}


Image::~Image()
{
	player.clear();
	P_weapon.clear();
	E_weapon.clear();
	enemies.clear();
	PowerUp.clear();
	Player_Weapon_Ammo.clear();
	tile_piece.clear();
	Background.clear();
	status.clear();
	Destruction.clear();
}

void Image::Load_Images()
{
	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "Assets");
	

	

	//player
	al_set_path_filename(path, "Image/Player/Birday.png");
	//al_insert_path_component(path, 10, "/Image/Player/Birday.png");
	this->player.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PLAYER));

	//Player weapon
	al_set_path_filename(path, "Image/Player/Weapon/Lazer.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Rocket_Lazer.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Stunner.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Bombs.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Ice_Bombs.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Fire_Bombs.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Bi_Nuke.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Tri_Nuke.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Triangular_Missle.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Arrow.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Slicer.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));
	al_set_path_filename(path, "Image/Player/Weapon/Atomic_Bombs.png");
	this->P_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), PWEAPON));


	//Enemy Version 1
	al_set_path_filename(path, "Image/Enemy/Tripus.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Magic_Mask.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Diamondo.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Cannon_Slug.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Fisher.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Ball.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));

	//Enemy Version 2
	al_set_path_filename(path, "Image/Enemy/Tripus_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Magic_Mask_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Diamondo_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Cannon_Slug_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Fisher_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	al_set_path_filename(path, "Image/Enemy/Ball_2.png");
	this->enemies.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), ENEMY));
	
	//Enemy Weapon
	al_set_path_filename(path, "Image/Enemy/Weapon/Fire.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Lightning.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Diamond.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Star_Shot.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Ball_Shot.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Bubble_Shot.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Venom_Spit.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Missle.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Grapple.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));
	al_set_path_filename(path, "Image/Enemy/Weapon/Gunk.png");
	this->E_weapon.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), EWEAPON));

	//Power Up
	al_set_path_filename(path, "Image/Power_Ups/Gliding_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));
	al_set_path_filename(path, "Image/Power_Ups/Health_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));
	al_set_path_filename(path, "Image/Power_Ups/Needle_Wind_blast_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));
	al_set_path_filename(path, "Image/Power_Ups/Stop_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));
	al_set_path_filename(path, "Image/Power_Ups/B_2_Bomber_Strike_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));
	al_set_path_filename(path, "Image/Power_Ups/Copy_Chip.png");
	this->PowerUp.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), POWERUP));

	//Ammo
	this->Player_Weapon_Ammo.push_back(std::make_pair(nullptr, AMMO));

	al_set_path_filename(path, "Image/Power_Ups/Ammo/Rocket_Lazer_Ammo.png");
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Stunner_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Bomb_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Ice_Bomb_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Fire_Bomb_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Atomic_Bomb_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Bi_Nuke_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Tri_Nuke_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Triangular_Missile_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Arrow_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));
	al_set_path_filename(path, "Image/Power_Ups/Ammo/Slicer_Ammo.png");

	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), AMMO));

	//Tiles
	al_set_path_filename(path, "Image/Tiles/Blue_Circle_Tile.png");
	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Blue_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Brick_Wall_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Fence_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Flower_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Grass_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Gray_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Palm_Tree_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Pillar_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Purple_Circle_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Purple_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Rock_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Sand_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Dark_Gray_Circle_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));
	al_set_path_filename(path, "Image/Tiles/Dark_Gray_Tile.png");

	this->tile_piece.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), TILES));

	//Background
	al_set_path_filename(path, "Image/Background/Menu.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Game_Over.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Birday_Title.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Ammo_Materials.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Character_Materials.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Enemy_Weapon_Materials.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Player_Weapon_Materials.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Power_Up_Materials.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Next_Prev.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));
	al_set_path_filename(path, "Image/Background/Terpos_Intro.png");
	this->Background.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), BACKGROUND));

	//Destruction
	al_set_path_filename(path, "Image/Enemy_Destroyed.png");
	this->Destruction.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), DESTRUCTION));
	al_set_path_filename(path, "Image/Explosion_From_Weapon.png");
	this->Destruction.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), DESTRUCTION));
	al_set_path_filename(path, "Image/Explosion_From_Bombs.png");
	this->Destruction.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), DESTRUCTION));

	//Status
	al_set_path_filename(path, "Image/Freeze.png");
	this->status.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), STATUS));
	al_set_path_filename(path, "Image/Burn.png");
	this->status.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), STATUS));

	//Misc
	al_set_path_filename(path, "Image/B_2_bomber.png");
	this->misc.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), MISC));
	al_set_path_filename(path, "Image/needle_wind.png");
	this->misc.push_back(std::make_pair(al_load_bitmap(al_path_cstr(path, '/')), MISC));


	for (int i = 0; i < player.size(); i++)
	{
		malloc(sizeof(player[i]));
	}

	for (int i = 0; i < P_weapon.size(); i++)
	{
		malloc(sizeof(P_weapon[i]));
	}

	for (int i = 0; i < E_weapon.size(); i++)
	{
		malloc(sizeof(E_weapon[i]));
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		malloc(sizeof(enemies[i]));
	}

	for (int i = 0; i < Background.size(); i++)
	{
		malloc(sizeof(Background[i]));
	}

	for (int i = 0; i < tile_piece.size(); i++)
	{
		malloc(sizeof(tile_piece[i]));
	}

	for (int i = 0; i < PowerUp.size(); i++)
	{
		malloc(sizeof(PowerUp[i]));
	}

	for (int i = 0; i < status.size(); i++)
	{
		malloc(sizeof(status[i]));
	}

	for (int i = 0; i < Player_Weapon_Ammo.size(); i++)
	{
		malloc(sizeof(Player_Weapon_Ammo[i]));
	}

	for (int i = 0; i < Destruction.size(); i++)
	{
		malloc(sizeof(Destruction[i]));
	}

	for (int i = 0; i < misc.size(); i++)
	{
		malloc(sizeof(misc[i]));
	}

}

void Image::Image_error_check()
{
	try
	{
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i].first == NULL)
			{
				
				throw 99;
				break;
			}
		}

		for (int i = 0; i < P_weapon.size(); i++)
		{
			if (P_weapon[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < E_weapon.size(); i++)
		{
			if (E_weapon[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < Background.size(); i++)
		{
			if (Background[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		
		for (int i = 0; i < tile_piece.size(); i++)
		{
			if (tile_piece[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < PowerUp.size(); i++)
		{
			if (PowerUp[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < status.size(); i++)
		{
			if (status[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < Player_Weapon_Ammo.size(); i++)
		{
			if (Player_Weapon_Ammo[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < Destruction.size(); i++)
		{
			if (Destruction[i].first == NULL)
			{
				break;
				throw 99;
			}
		}

		for (int i = 0; i < misc.size(); i++)
		{
			if (misc[i].first == NULL)
			{
				throw 99;
				break;
			}
		}
	}

	catch (int x)
	{
		al_destroy_path(path);
		system("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/src/Asset_management/Image.bat");
		exit(EXIT_FAILURE);
	}
}

void Image::Deallocate_image(Tile_map &tile_map_file)
{
	al_destroy_bitmap(player[0].first);

	for (int i = 0; i < enemies.size(); i++)
	{
		al_destroy_bitmap(enemies[i].first);
	}
	
	for (int i = 0; i < P_weapon.size(); i++)
	{
		al_destroy_bitmap(P_weapon[i].first);
	}

	for (int i = 0; i < E_weapon.size(); i++)
	{
		al_destroy_bitmap(E_weapon[i].first);
	}

	for (int i = 0; i < PowerUp.size(); i++)
	{
		al_destroy_bitmap(PowerUp[i].first);
	}

	for (int i = 0; i < Player_Weapon_Ammo.size(); i++)
	{
		al_destroy_bitmap(Player_Weapon_Ammo[i].first);
	}

	for (int i = 0; i < tile_piece.size(); i++)
	{
		al_destroy_bitmap(tile_piece[i].first);
	}

	for (int i = 0; i < Background.size(); i++)
	{
		al_destroy_bitmap(Background[i].first);
	}

	for (int i = 0; i < Destruction.size(); i++)
	{
		al_destroy_bitmap(Destruction[i].first);
	}

	for (int i = 0; i < status.size(); i++)
	{
		al_destroy_bitmap(status[i].first);
	}

	

}

std::pair<ALLEGRO_BITMAP*, int> Image::Enemy_image(int enemy_num)
{
	return std::make_pair(this->enemies[enemy_num].first, this->enemies[enemy_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Player_image()
{
	return std::make_pair(this->player[0].first, this->player[0].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Player_Weapon_image(int pweapon_num)
{
	return std::make_pair(this->P_weapon[pweapon_num].first, this->P_weapon[pweapon_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Power_Up_image(int power_up_num)
{
	return std::make_pair(this->PowerUp[power_up_num].first, this->PowerUp[power_up_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Ammo_image(int ammo_num)
{
	return std::make_pair(this->Player_Weapon_Ammo[ammo_num].first, this->Player_Weapon_Ammo[ammo_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Enemy_Weapon_image(int eweapon_num)
{
	return std::make_pair(this->E_weapon[eweapon_num].first, this->E_weapon[eweapon_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Tiles(int tile_piece_num)
{
	return std::make_pair(this->tile_piece[tile_piece_num].first, this->tile_piece[tile_piece_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Background_image(int background_num)
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->Background[background_num].first, this->Background[background_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Destruction_image(int destruction_num)
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->Destruction[destruction_num].first, this->Destruction[destruction_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::status_image(int status_num)
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->status[status_num].first, this->status[status_num].second);
}

std::pair<ALLEGRO_BITMAP*, int> Image::misc_image(int misc_num)
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->misc[misc_num].first, this->misc[misc_num].second);
}
