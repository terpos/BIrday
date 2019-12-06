#include "Player.h"



Player::Player(Image &sprite_sheet, int x, int y, int vel, int direction, int buttons[7])
{
	set_bitmap(sprite_sheet.Player_image().first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);
	set_health(10);
	set_buttons(buttons);
	cropping = al_create_bitmap(80, 80);
	key[0] = false;
	key[1] = false;
	key[2] = false;
	key[3] = false;


}


Player::~Player()
{
	//pweapon.clear();
	std::cout << "PLAYER WEAPON CLEARED" << std::endl;
}

int Player::get_x()
{
	return this->x;
}

int Player::get_y()
{
	return this->y;
}

int Player::get_vel()
{
	return this->vel;
}


std::pair<bool, int> Player::is_hit()
{
	return std::make_pair(this->hit.first, this->hit.second);
}

std::pair<ALLEGRO_BITMAP*, int> Player::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->image.first, this->image.second);
}

int Player::get_direction()
{
	return this->direction;
}

int Player::get_buttons(int index)
{
	return this->buttons[index];
}

void Player::set_x(int x)
{
	this->x = x;
}

void Player::set_y(int y)
{
	this->y = y;
}

void Player::set_vel(int vel)
{
	this->vel = vel;
}

void Player::set_health(signed int health)
{
	this->health = health;
}

void Player::set_direction(int direction)
{
	this->direction = direction;
}

void Player::set_hit(bool ishit, int status)
{
	this->hit.first = ishit;
	this->hit.second = status;
}

void Player::set_bitmap(ALLEGRO_BITMAP* image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void Player::set_buttons(int buttons[7])
{
	for (int i = 0; i < 7; i++)
	{
		this->buttons[i] = buttons[i];
	}
}

unsigned int Player::get_health()
{
	return this->health;
}

void Player::control(Image spritesheet, ALLEGRO_EVENT e, std::vector <P_Weapon*> &pweapon)
{
	//if you press a key, 
	//if the key is directional, player moves
	//if the key is space, player shoots
	//if the key is a or s, player switch weapon
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{

		if (e.keyboard.keycode == get_buttons(0))
		{
			key[get_direction()] = false;
			set_direction(0);
			key[0] = true;
		}

		if (e.keyboard.keycode == get_buttons(1))
		{
			key[get_direction()] = false;
			set_direction(1);
			key[1] = true;
		}

		if (e.keyboard.keycode == get_buttons(2))
		{
			key[get_direction()] = false;
			set_direction(2);
			key[2] = true;
		}

		if (e.keyboard.keycode == get_buttons(3))
		{
			key[get_direction()] = false;
			set_direction(3);
			key[3] = true;
		}

		if (e.keyboard.keycode == get_buttons(4))
		{
			pweapon.push_back(new Lazer(spritesheet, get_x(), get_y(), 20, get_direction()));
		}

		if (e.keyboard.keycode == get_buttons(5))
		{
			std::cout << get_buttons(5) << std::endl;
		}

		if (e.keyboard.keycode == get_buttons(6))
		{
			std::cout << get_buttons(6) << std::endl;
		}

	}

	//if you stop pressing the key
	if (e.type == ALLEGRO_EVENT_KEY_UP)
	{
		if (e.keyboard.keycode == get_buttons(0))
		{
			key[0] = false;
		}

		if (e.keyboard.keycode == get_buttons(1))
		{
			key[1] = false;
		}

		if (e.keyboard.keycode == get_buttons(2))
		{
			key[2] = false;
		}

		if (e.keyboard.keycode == get_buttons(3))
		{
			key[3] = false;
		}


	}
}

void Player::col_update()
{
	if (get_direction() == 0)
	{
		set_y(get_y() - 80);
	}

	if (get_direction() == 1)
	{
		set_y(get_y() + 80);
	}

	if (get_direction() == 2)
	{
		set_x(get_x() - 80);
	}

	if (get_direction() == 3)
	{
		set_x(get_x() + 80);
	}
}

void Player::update(Options &option, std::vector <P_Weapon*> &pweapon)
{
	set_y(get_y() + get_vel()*key[0]);
	set_y(get_y() - get_vel()*key[1]);
	set_x(get_x() + get_vel()*key[2]);
	set_x(get_x() - get_vel()*key[3]);

	//updates player weapon
	for (int i = 0; i < pweapon.size(); i++)
	{
		pweapon[i]->update();
	}

}

void Player::render()
{
	al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
}