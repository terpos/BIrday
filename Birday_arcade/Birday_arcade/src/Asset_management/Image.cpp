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
	
	//player
	this->player.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Birday.png"), PLAYER));

	//Player weapon
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Lazer.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Rocket_Lazer.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Stunner.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Bombs.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Ice_Bombs.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Fire_Bombs.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Bi_Nuke.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Tri_Nuke.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Triangular_Missle.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Arrow.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Slicer.png"), PWEAPON));
	this->P_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Player/Weapon/Atomic_Bombs.png"), PWEAPON));


	//Enemy Version 1
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Tripus.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Magic_Mask.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Diamondo.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Cannon_Slug.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Fisher.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Ball.png"), ENEMY));

	//Enemy Version 2
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Tripus_2.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Magic_Mask_2.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Diamondo_2.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Cannon_Slug_2.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Fisher_2.png"), ENEMY));
	this->enemies.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Ball_2.png"), ENEMY));
	
	//Enemy Weapon
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Fire.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Lightning.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Diamond.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Star_Shot.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Ball_Shot.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Bubble_Shot.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Venom_Spit.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Missle.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Grapple.png"), EWEAPON));
	this->E_weapon.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy/Weapon/Gunk.png"), EWEAPON));

	//Power Up
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Gliding_Chip.png"), POWERUP));
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Health_Chip.png"), POWERUP));
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Needle_Wind_blast_Chip.png"), POWERUP));
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Stop_Chip.png"), POWERUP));
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/B_2_Bomber_Strike_Chip.png"), POWERUP));
	this->PowerUp.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Copy_Chip.png"), POWERUP));

	//Ammo
	this->Player_Weapon_Ammo.push_back(std::make_pair(nullptr, AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Rocket_Lazer_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Stunner_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Bomb_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Ice_Bomb_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Fire_Bomb_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Atomic_Bomb_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Bi_Nuke_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Tri_Nuke_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Triangular_Missile_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Arrow_Ammo.png"), AMMO));
	this->Player_Weapon_Ammo.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Power_Ups/Ammo/Slicer_Ammo.png"), AMMO));

	//Tiles
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Blue_Circle_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Blue_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Brick_Wall_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Fence_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Flower_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Grass_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Gray_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Palm_Tree_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Pillar_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Purple_Circle_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Purple_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Rock_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Sand_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Dark_Gray_Circle_Tile.png"), TILES));
	this->tile_piece.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Tiles/Dark_Gray_Tile.png"), TILES));

	//Background
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Menu.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Game_Over.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Birday_Title.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Ammo_Materials.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Character_Materials.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Enemy_Weapon_Materials.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Player_Weapon_Materials.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Power_Up_Materials.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Next_Prev.png"), BACKGROUND));
	this->Background.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Background/Terpos_Intro.png"), BACKGROUND));

	//Destruction
	this->Destruction.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Enemy_Destroyed.png"), DESTRUCTION));
	this->Destruction.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Explosion_From_Weapon.png"), DESTRUCTION));
	this->Destruction.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Explosion_From_Bombs.png"), DESTRUCTION));

	//Status
	this->status.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Freeze.png"), STATUS));
	this->status.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/Burn.png"), STATUS));

	//Misc
	this->misc.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/B_2_bomber.png"), MISC));
	this->misc.push_back(std::make_pair(al_load_bitmap("c:/Users/gebei/Documents/GitHub/Birday/Birday_arcade/Birday_arcade/Assets/Image/needle_wind.png"), MISC));


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
