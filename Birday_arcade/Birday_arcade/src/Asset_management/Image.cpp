#include "Image.h"



Image::Image()
{
}


Image::~Image()
{
}

void Image::Load_Images()
{
	//path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	//al_set_path_filename(path, "Birday.png");
	//this->player.push_back(std::make_pair(al_load_bitmap("C:\Users\gebei\Documents\GitHub\Birday\Birday_arcade\Birday_arcade\Assets\Image\Player\Birday.png"), PLAYER));
	p = al_load_bitmap("glass.jpg");
}

void Image::Image_error_check()
{
	//std::cout << "HELLO" << std::endl;
	al_draw_bitmap(p, 0, 0, NULL);
}

void Image::Deallocate_image()
{
	al_destroy_bitmap(this->p);
	//al_destroy_bitmap(this->player[0].first);
	al_destroy_path(this->path);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Enemy_image(int enemies)
{
	return std::pair<ALLEGRO_BITMAP*, int>();
}

std::pair<ALLEGRO_BITMAP*, int> Image::Player_image()
{
	return std::make_pair(this->p, PLAYER);
}

std::pair<ALLEGRO_BITMAP*, int> Image::Player_weapon_image(int pweapon)
{
	return std::pair<ALLEGRO_BITMAP*, int>();
}

std::pair<ALLEGRO_BITMAP*, int> Image::power_up_image(int power_up)
{
	return std::pair<ALLEGRO_BITMAP*, int>();
}

std::pair<ALLEGRO_BITMAP*, int> Image::Enemy_weapon_image(int eweapon)
{
	return std::pair<ALLEGRO_BITMAP*, int>();
}

std::pair<ALLEGRO_BITMAP*, int> Image::Tiles(Tile_map tiles, int number)
{
	return std::pair<ALLEGRO_BITMAP*, int>();
}
