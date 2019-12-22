#include "Player.h"



Player::Player(Image &sprite_sheet, int x, int y, int vel, int direction, int buttons[7])
{
	set_bitmap(sprite_sheet.Player_image().first, sprite_sheet.Player_image().second);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);
	set_health(100);
	set_buttons(buttons);
	cropping = al_create_bitmap(80, 80);
	key[0] = false;
	key[1] = false;
	key[2] = false;
	key[3] = false;
	this->glide = false;
	set_glide(this->glide);
	this->delay_movement = 3;
	set_delay_movemement(this->delay_movement);
	this->option_weapon = 0;
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

bool Player::is_gliding()
{
	return this->glide;
}

int Player::get_buttons(int index)
{
	return this->buttons[index];
}

int Player::get_delay_movement()
{
	return this->delay_movement;
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

signed int Player::get_health()
{
	return this->health;
}

void Player::control(Image spritesheet, ALLEGRO_EVENT e, Options &option, std::vector <P_Weapon*> &pweapon)
{
	//if you press a key, 
	//if the key is directional, player moves
	//if the key is space, player shoots
	//if the key is a or s, player switch weapon
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		std::cout << e.keyboard.keycode << std::endl;
		if (e.keyboard.keycode == option.get_control_options(0))
		{
			key[get_direction()] = false;
			set_direction(0);
			key[0] = true;
		}

		if (e.keyboard.keycode == option.get_control_options(1))
		{
			key[get_direction()] = false;
			set_direction(1);
			key[1] = true;
		}

		if (e.keyboard.keycode == option.get_control_options(2))
		{
			key[get_direction()] = false;
			set_direction(2);
			key[2] = true;
		}

		if (e.keyboard.keycode == option.get_control_options(3))
		{
			key[get_direction()] = false;
			set_direction(3);
			key[3] = true;
		}

		if (e.keyboard.keycode == option.get_control_options(4))
		{
			switch (option_weapon)
			{
			case LAZER:
				pweapon.push_back(new Lazer(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case ROCKET_LAZER:
				pweapon.push_back(new Rocket_lazer(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case STUNNER:
				pweapon.push_back(new Stunner(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case BOMBS:
				pweapon.push_back(new Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
				break;
			case ICE_BOMBS:
				pweapon.push_back(new Ice_Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
				break;
			case FIRE_BOMBS:
				pweapon.push_back(new Fire_bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
				break;
			case ATOMIC_BOMBS:
				pweapon.push_back(new Atom_Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
				break;
			case BI_NUKE:
				pweapon.push_back(new BiNuke(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case TRI_NUKE:
				pweapon.push_back(new TriNuke(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case TRIANGULAR_MISSILE:
				pweapon.push_back(new Triangular_Missle(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case SLICER:
				pweapon.push_back(new Slicer(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			case ARROW:
				pweapon.push_back(new Arrow(spritesheet, get_x(), get_y(), 40, get_direction()));
				break;
			}
		}

		if (e.keyboard.keycode == option.get_control_options(5))
		{
			option_weapon--;
			if (option_weapon < 0)
			{
				option_weapon = 11;
			}
		}

		if (e.keyboard.keycode == option.get_control_options(6))
		{
			option_weapon++;
			if (option_weapon > 11)
			{
				option_weapon = 0;
			}
			
		}

	}

	//if you stop pressing the key
	if (e.type == ALLEGRO_EVENT_KEY_UP)
	{
		if (e.keyboard.keycode == option.get_control_options(0))
		{
			key[0] = false;
		}

		if (e.keyboard.keycode == option.get_control_options(1))
		{
			key[1] = false;
		}

		if (e.keyboard.keycode == option.get_control_options(2))
		{
			key[2] = false;
		}

		if (e.keyboard.keycode == option.get_control_options(3))
		{
			key[3] = false;
		}


	}
}

void Player::damage_col_update()
{
	//if player's health is greater than 0 and hit is false
	if (get_health() > 0 && !is_hit().first)
	{
		set_hit(true, 1);
		
		std::cout << "Player's Health: " << get_health() << std::endl;
		recover = 50;
	
		if (get_direction() == 0)
		{
			set_y(get_y() - get_vel());
		}

		if (get_direction() == 1)
		{
			set_y(get_y() + get_vel());
		}

		if (get_direction() == 2)
		{
			set_x(get_x() - get_vel());
		}

		if (get_direction() == 3)
		{
			set_x(get_x() + get_vel());
		}
	}


}

void Player::set_delay_movemement(int delay)
{
	this->delay_movement = delay;
}

void Player::damage_col_tile_update()
{
	if (get_health() > 0)
	{
		set_health(get_health() - 1);
		std::cout << "Player's Health: " << get_health() << std::endl;
	}


	else if (get_health() <= 0)
	{
		key[0] = false;
		key[1] = false;
		key[2] = false;
		key[3] = false;
	}

	if (get_direction() == 0)
	{
		set_y(get_y() - get_vel());
	}

	if (get_direction() == 1)
	{
		set_y(get_y() + get_vel());
	}

	if (get_direction() == 2)
	{
		set_x(get_x() - get_vel());
	}

	if (get_direction() == 3)
	{
		set_x(get_x() + get_vel());
	}
}

void Player::col_update()
{
	if (get_direction() == 0)
	{
		set_y(get_y() - get_vel());
	}

	if (get_direction() == 1)
	{
		set_y(get_y() + get_vel());
	}

	if (get_direction() == 2)
	{
		set_x(get_x() - get_vel());
	}

	if (get_direction() == 3)
	{
		set_x(get_x() + get_vel());
	}
}

void Player::set_glide(bool glide)
{
	this->glide = glide;
}

void Player::update(std::vector <P_Weapon*> &pweapon)
{
	if (recover != 0)
	{
		recover--;
	}

	else if (recover == 0)
	{
		set_hit(false, 0);
	}

	if (get_delay_movement() == 0 && !is_gliding())
	{
		set_y(get_y() + get_vel()*key[0]);
		set_y(get_y() - get_vel()*key[1]);
		set_x(get_x() + get_vel()*key[2]);
		set_x(get_x() - get_vel()*key[3]);
		set_delay_movemement(3);
	}
	
	if (is_gliding() && get_delay_movement() > 0)
	{
		set_y(get_y() + get_vel()*key[0]);
		set_y(get_y() - get_vel()*key[1]);
		set_x(get_x() + get_vel()*key[2]);
		set_x(get_x() - get_vel()*key[3]);
	}

	if (get_delay_movement() == 0 && is_gliding())
	{
		set_x(get_x() % 80 + (80 - get_x() % 80));
		set_y(get_y() % 80 + (80 - get_y() % 80));
		set_vel(80);
		set_glide(false);
		set_delay_movemement(3);
	}

	else
	{
		set_delay_movemement(get_delay_movement() - 1);
	}

	

}

void Player::render()
{
	al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
}