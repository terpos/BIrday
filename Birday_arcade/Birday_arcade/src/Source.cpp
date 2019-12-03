#include <iostream>

#include "global.h"
#include "Asset_management/Image.h"
#include "Asset_management/Sound.h"
#include "Asset_management/Tile_map.h"

using namespace std;

int main()
{
	al_init();
	al_install_keyboard();
	al_init_image_addon();
	
	ALLEGRO_DISPLAY *display = al_create_display(1360, 768);
	//Image image;
	//image.Load_Images();
	ALLEGRO_BITMAP * bmp = al_load_bitmap("Mario.png");
	
	if (bmp == NULL)
	{
		std::cout << "CANNOT LOAD" << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	al_set_display_flag(display, ALLEGRO_NOFRAME, true);

	while (1)
	{
		al_draw_bitmap(bmp, 0, 0, NULL);
		al_clear_to_color(al_map_rgb(255, 0, 0));
		al_flip_display();
	}
	
	
	al_destroy_bitmap(bmp);
	al_destroy_display(display);
	system("pause");
	return 0;
}