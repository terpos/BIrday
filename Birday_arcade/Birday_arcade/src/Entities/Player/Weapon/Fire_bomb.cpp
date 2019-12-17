#include "Fire_bomb.h"



Fire_bomb::Fire_bomb(Image &sprite_sheet, int x, int y, int vel, int direction): P_Weapon(sprite_sheet, x, y, vel, direction)
{
	set_bitmap(sprite_sheet.Player_Weapon_image(FIRE_BOMBS).first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);

	cropping = al_create_bitmap(80, 80);
	cropping2 = al_create_bitmap(40, 40);


	type = 0;
}


Fire_bomb::~Fire_bomb()
{
}

void Fire_bomb::render()
{
	al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping2), al_get_bitmap_height(cropping2), get_x(), get_y(), NULL);
}
