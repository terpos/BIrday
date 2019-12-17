#include "Enemy.h"



Enemy::Enemy(Image &sprite_sheet, int version, int x, int y, int vel, int direction)
{
	set_version(version);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);
	set_health(5);

	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);

	nochange = 25;
	reload_time = 25;
	cropping = al_create_bitmap(80, 80);
}


Enemy::~Enemy()
{
	std::cout << "ENEMY WEAPON CLEARED" << std::endl;
}

int Enemy::get_x()
{
	return this->x;
}

int Enemy::get_y()
{
	return this->y;
}

int Enemy::get_vel()
{
	return this->vel;
}

int Enemy::get_direction()
{
	return this->direction;
}

int Enemy::get_version()
{
	return this->version;
}

signed int Enemy::get_health()
{
	return this->health;
}

int Enemy::Damage()
{
	return 1;
}

std::pair<bool, int> Enemy::is_hit()
{
	return std::pair<bool, int>(this->hit.first, this->hit.second);
}

std::pair<ALLEGRO_BITMAP*, int> Enemy::get_bitmap()
{
	return std::pair<ALLEGRO_BITMAP*, int>(this->image.first, this->image.second);
}

void Enemy::set_x(int x)
{
	this->x = x;
}

void Enemy::set_y(int y)
{
	this->y = y;
}

void Enemy::set_vel(int vel)
{
	this->vel = vel;
}

void Enemy::set_health(signed int health)
{
	this->health = health;
}

void Enemy::set_direction(int direction)
{
	this->direction = direction;
}

void Enemy::set_version(int version)
{
	this->version = version;
}

void Enemy::set_hit(bool ishit, int status)
{
	this->hit.first = ishit;
	this->hit.second = status;
}

void Enemy::set_bitmap(ALLEGRO_BITMAP * image, int entity_num)
{
	this->image.first = image;
	this->image.second = entity_num;
}

void Enemy::damage_col_update()
{
	if (get_health() > 0)
	{
		set_health(get_health() - 1);
		std::cout << "Enemy's Health: " << get_health() << std::endl;
	}

	
}

void Enemy::react(Image &image, Player & player, std::vector<E_Weapon*>& eweapon)
{

}

void Enemy::change_direction()
{
	if (get_direction() == 0)
	{
		set_x(get_x() - get_vel());
	}

	if (get_direction() == 1)
	{
		set_x(get_x() + get_vel());
	}

	if (get_direction() == 2)
	{
		set_y(get_y() - get_vel());
	}

	if (get_direction() == 3)
	{
		set_y(get_y() + get_vel());
	}

	std::uniform_int_distribution<int > d(0, 3);

	set_direction(d(movement));

	this->nochange = 50;
}

void Enemy::shoot(std::vector <E_Weapon*> &eweapon, Image spritesheet)
{
	std::uniform_int_distribution<int > shoot(0, 11);

	if (reload_time > 0)
	{
		this->reload_time--;
	}

	else if (reload_time == 0)
	{
		if (shoot(shooting_probability) > 5)
		{
			//eweapon.push_back(new Missile(spritesheet, get_x(), get_y(), 20, get_direction()));
			this->reload_time = 20;
		}

		else
		{
			reload_time = 20;
		}

	}
}

void Enemy::update(std::vector <E_Weapon*> &eweapon, Image spritesheet)
{
	//	std::cout << nochange << std::endl;
	std::uniform_int_distribution<int > d(0, 3);
	if (get_vel() > 0)
	{

		if (nochange > 0)
		{
			this->nochange--;
		}

		else if (nochange == 0)
		{
			set_direction(d(movement));

			this->nochange = 50;
			//std::cout << get_direction() << std::endl;

		}

		shoot(eweapon, spritesheet);



		if (get_direction() == 0)
		{
			set_x(get_x() + get_vel());
		}

		if (get_direction() == 1)
		{
			set_x(get_x() - get_vel());
		}

		if (get_direction() == 2)
		{
			set_y(get_y() + get_vel());
		}

		if (get_direction() == 3)
		{
			set_y(get_y() - get_vel());
		}
	}
}

void Enemy::render()
{


	if (al_get_bitmap_width(get_bitmap().first) > 160)
	{
		switch (get_direction())
		{
		case 0:
			al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 1:
			al_draw_bitmap_region(get_bitmap().first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 2:
			al_draw_bitmap_region(get_bitmap().first, 160, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		case 3:
			al_draw_bitmap_region(get_bitmap().first, 240, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			break;
		}
	}

	else if (al_get_bitmap_width(get_bitmap().first) == 160)
	{
		al_draw_bitmap_region(get_bitmap().first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

	}

}
