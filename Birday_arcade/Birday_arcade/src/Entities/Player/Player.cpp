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

	Num_of_Bullet[ROCKET_LAZER] = 10;
	Num_of_Bullet[STUNNER] = 10;
	Num_of_Bullet[BOMBS] = 10;
	Num_of_Bullet[ICE_BOMBS] = 5;
	Num_of_Bullet[FIRE_BOMBS] = 5;
	Num_of_Bullet[ATOMIC_BOMBS] = 2;
	Num_of_Bullet[BI_NUKE] = 4;
	Num_of_Bullet[TRI_NUKE] = 4;
	Num_of_Bullet[TRIANGULAR_MISSILE] = 3;
	Num_of_Bullet[ARROW] = 3;
	Num_of_Bullet[SLICER] = 2;

	Poisoned_duration = 0;

	Damage.set_frame(0);
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

int Player::get_num_of_ammo(int index)
{
	return this->Num_of_Bullet[index];
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

int Player::get_option_weapon()
{
	return this->option_weapon;
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

void Player::set_health(float health)
{
	this->health = health;
}

void Player::set_num_of_ammo(int number_of_ammo, int index)
{
	this->Num_of_Bullet[index] = number_of_ammo;
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

int Player::get_health()
{
	return this->health;
}

void Player::control(Image spritesheet, Sound sound, ALLEGRO_EVENT e, Options &option, std::vector <P_Weapon*> &pweapon, bool unlock_weapon[12], int num_of_weapon)
{

	//if you press a key, 
	//if the key is directional, player moves
	//if the key is space, player shoots
	//if the key is a or s, player switch weapon
	if (e.type == ALLEGRO_EVENT_KEY_DOWN)
	{
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
			switch (this->option_weapon)
			{
			case LAZER:
				
				pweapon.push_back(new Lazer(spritesheet, get_x(), get_y(), 20, get_direction()));
				if (option.get_sound_options())
				{
					al_set_sample_instance_position(sound.sound_effects(13), 0);
					al_play_sample_instance(sound.sound_effects(13));
				}
				break;

			case ROCKET_LAZER:
				if (get_num_of_ammo(ROCKET_LAZER) != 0 && unlock_weapon[ROCKET_LAZER])
				{
					pweapon.push_back(new Rocket_lazer(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[ROCKET_LAZER] - 1, ROCKET_LAZER);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(13), 0);
						al_play_sample_instance(sound.sound_effects(13));
					}
				}
				break;

			case STUNNER:
				if (get_num_of_ammo(STUNNER) != 0 && unlock_weapon[STUNNER])
				{
					pweapon.push_back(new Stunner(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[STUNNER] - 1, STUNNER);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(13), 0);
						al_play_sample_instance(sound.sound_effects(13));
					}
				}
				break;

			case BOMBS:
				if (get_num_of_ammo(BOMBS) != 0 && unlock_weapon[BOMBS])
				{
					pweapon.push_back(new Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
					set_num_of_ammo(Num_of_Bullet[BOMBS] - 1, BOMBS);
				}
				break;

			case ICE_BOMBS:
				if (get_num_of_ammo(ICE_BOMBS) != 0 && unlock_weapon[ICE_BOMBS])
				{
					pweapon.push_back(new Ice_Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
					set_num_of_ammo(Num_of_Bullet[ICE_BOMBS] - 1, ICE_BOMBS);
				}
				break;

			case FIRE_BOMBS:
				if (get_num_of_ammo(FIRE_BOMBS) != 0 && unlock_weapon[FIRE_BOMBS])
				{
					pweapon.push_back(new Fire_bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
					set_num_of_ammo(Num_of_Bullet[FIRE_BOMBS] - 1, FIRE_BOMBS);
				}
				break;

			case ATOMIC_BOMBS:
				if (get_num_of_ammo(ATOMIC_BOMBS) != 0 && unlock_weapon[ATOMIC_BOMBS])
				{
					pweapon.push_back(new Atom_Bomb(spritesheet, get_x(), get_y(), 0, get_direction()));
					set_num_of_ammo(Num_of_Bullet[ATOMIC_BOMBS] - 1, ATOMIC_BOMBS);
				}
				break;

			case BI_NUKE:
				if (get_num_of_ammo(BI_NUKE) != 0 && unlock_weapon[BI_NUKE])
				{
					pweapon.push_back(new BiNuke(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[BI_NUKE] - 1, BI_NUKE);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(15), 0);
						al_play_sample_instance(sound.sound_effects(15));
					}
				}
				break;

			case TRI_NUKE:
				if (get_num_of_ammo(TRI_NUKE) != 0 && unlock_weapon[TRI_NUKE])
				{
					pweapon.push_back(new TriNuke(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[TRI_NUKE] - 1, TRI_NUKE);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(15), 0);
						al_play_sample_instance(sound.sound_effects(15));
					}
				}
				break;

			case TRIANGULAR_MISSILE:
				if (get_num_of_ammo(TRIANGULAR_MISSILE) != 0 && unlock_weapon[TRIANGULAR_MISSILE])
				{
					pweapon.push_back(new Triangular_Missle(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[TRIANGULAR_MISSILE] - 1, TRIANGULAR_MISSILE);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(15), 0);
						al_play_sample_instance(sound.sound_effects(15));
					}
				}
				break;

			case SLICER:
				if (get_num_of_ammo(SLICER) != 0 && unlock_weapon[SLICER])
				{
					pweapon.push_back(new Slicer(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[SLICER] - 1, SLICER);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(18), 0);
						al_play_sample_instance(sound.sound_effects(18));
					}
				}
				break;

			case ARROW:
				if (get_num_of_ammo(ARROW) != 0 && unlock_weapon[ARROW])
				{
					pweapon.push_back(new Arrow(spritesheet, get_x(), get_y(), 20, get_direction()));
					set_num_of_ammo(Num_of_Bullet[ARROW] - 1, ARROW);
					if (option.get_sound_options())
					{
						al_set_sample_instance_position(sound.sound_effects(0), 0);
						al_play_sample_instance(sound.sound_effects(0));
					}
				}
				break;
			}
		}

		if (e.keyboard.keycode == option.get_control_options(5))
		{
			this->option_weapon--;
			if (option_weapon < 0)
			{
				option_weapon = num_of_weapon;
			}
		}

		if (e.keyboard.keycode == option.get_control_options(6))
		{
			this->option_weapon++;
			if (option_weapon > num_of_weapon)
			{
				option_weapon = 0;
			}
			
		}
		std::cout << "Weapon Num: " << option_weapon << std::endl;
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
		
		//recover = 50;
	
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
	
	for (int i = 0; i < sizeof(Num_of_Bullet); i++)
	{
		if (Num_of_Bullet[i] < 0)
		{
			Num_of_Bullet[i] = 0;
		}
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

	if (is_hit().second == 1)
	{
		Damage.increment_frame();
	}

	if (Damage.get_frame() >= 100)
	{
		Damage.set_frame(0);
		set_hit(false, 0);
	}

	if (is_hit().second == 2)
	{
		Poisoned_duration++;
	}

	if (Poisoned_duration == 50)
	{
		Poisoned_duration = 0;
		set_hit(false, 0);
	}
}

void Player::render()
{
	if (is_hit().second == 1)
	{
		if (Damage.get_frame_position(11) >= 0 && Damage.get_frame_position(11) <= 5)
		{
			al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 80, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}

		else
		{
			al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}
	}

	if (is_hit().second == 2)
	{
		al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 160, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
	}

	else if (is_hit().second == 0)
	{
		al_draw_bitmap_region(get_bitmap().first, get_direction()*al_get_bitmap_width(cropping), 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
	}
}