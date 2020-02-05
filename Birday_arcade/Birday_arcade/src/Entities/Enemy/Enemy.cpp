#include "Enemy.h"



Enemy::Enemy(Image &sprite_sheet, int version, int x, int y, int vel, int direction)
{
	set_image(sprite_sheet);
	set_version(version);
	set_x(x);
	set_y(y);
	set_vel(vel);
	set_direction(direction);
	set_hit(false, NULL);
	set_health(5);

	tempvel = vel;
	seed = std::chrono::system_clock::now().time_since_epoch().count();
	movement.seed(seed);
	shooting_probability.seed(seed);
	random_duration.seed(seed);
	
	burn_duration = 0;
	freeze_duration = 0;
	stop_duration = 0;
	is_damage = 0;
	nochange = 25;
	reload_time = 25;
	cropping = al_create_bitmap(80, 80);
	dead.set_frame(0);
	damage.set_frame(0);
}


Enemy::~Enemy()
{
	std::cout << "ENEMY WEAPON CLEARED" << std::endl;
	al_destroy_bitmap(cropping);
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

int Enemy::get_id()
{
	return this->id;
}

int Enemy::Damage()
{
	return 1;
}

bool Enemy::is_dead()
{
	return this->enemy_dead;
}

std::pair<bool, int> Enemy::is_hit()
{
	return std::pair<bool, int>(this->hit.first, this->hit.second);
}

Image Enemy::get_image()
{
	return this->image;
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

void Enemy::set_id(int id)
{
	this->id = id;
}

void Enemy::set_direction(int direction)
{
	this->direction = direction;
}

void Enemy::set_move_duration(int duration)
{
	this->nochange = duration;
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

void Enemy::set_kill(bool kill)
{
	this->enemy_dead = kill;
}

void Enemy::set_image(Image image)
{
	this->image = image;
}

void Enemy::damage_col_update()
{
	if (get_health() > 0)
	{
		set_health(get_health() - 1);
	}
}

void Enemy::react(Image &image, Sound sound, Player* & player, std::vector<E_Weapon*>& eweapon, Options option)
{

}

void Enemy::change_direction()
{
	if (get_direction() == 0)
	{
		set_x(get_x() - get_vel());
	}

	else if (get_direction() == 1)
	{
		set_x(get_x() + get_vel());
	}

	else if (get_direction() == 2)
	{
		set_y(get_y() - get_vel());
	}

	else if (get_direction() == 3)
	{
		set_y(get_y() + get_vel());
	}

	if (this->nochange <= 0)
	{
		std::uniform_int_distribution<int > d(0, 3);

		if (get_direction() == 0 || get_direction() == 1)
		{
			set_direction((d(movement) % 2) + 2);
			set_move_duration(80*5);
		}

		else if (get_direction() == 2 || get_direction() == 3)
		{
			set_direction(d(movement) % 2);
			set_move_duration(80 * 5);
		}

		
	}
	//this->nochange = 50;
}

void Enemy::opposite_direction()
{

	if (get_direction() == 0)
	{
		set_direction(1);
		set_move_duration(80 * 5);
	}

	else if (get_direction() == 1)
	{
		set_direction(0);
		set_move_duration(80 * 5);
	}

	else if (get_direction() == 2)
	{
		set_direction(3);
		set_move_duration(80 * 5);
	}

	else if (get_direction() == 3)
	{
		set_direction(2);
		set_move_duration(80 * 5);
	}

}

void Enemy::shoot(std::vector <E_Weapon*> &eweapon, Options option, Sound sound, Image spritesheet)
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
			this->reload_time = 20;
		}

		else
		{
			reload_time = 20;
		}

	}
}

void Enemy::update(std::vector <E_Weapon*> &eweapon, Options option, std::vector <P_Weapon*> &pweapon, Image spritesheet, Sound sound)
{
	
	if (get_health() <= 0)
	{
		set_vel(0);
		dead.increment_frame();
	}

	if (is_hit().first && is_hit().second == 2)
	{
		set_vel(0);
		freeze_duration++;
		stop_duration = 300;
	}

	if (is_hit().first && is_hit().second == 3)
	{
		set_vel(0);
		burn_duration++;
		stop_duration = 300;
	}

	if (damage.get_frame() >= 100)
	{
		set_hit(false, 0);
		damage.reset_frame();
	}

	if (is_hit().first && is_hit().second == 1)
	{
		damage.increment_frame();
	}

	if (is_hit().first && is_hit().second == 4)
	{
		damage.increment_frame();
		set_vel(0);
		stop_duration++;
	}

	std::uniform_int_distribution<int> d(0, 3);
	std::uniform_int_distribution<int> duration(1, 7);
	if (get_vel() > 0)
	{

		if (nochange > 0)
		{
			this->nochange-=get_vel();
		}

		else if (nochange <= 0)
		{
			set_direction(d(movement));

			this->nochange = 80 * duration(random_duration);

		}

		if (animation.get_frame() == 100)
		{
			animation.reset_frame();
		}

		animation.increment_frame();

		shoot(eweapon, option, sound, spritesheet);

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

	else if (get_vel() == 0)
	{
		if (dead.get_frame() >= 20)
		{
			set_hit(false, 1);
			set_kill(true);
		}

		if (burn_duration == 600 || freeze_duration == 600)
		{
			burn_duration = 0;
			freeze_duration = 0;
			set_vel(tempvel);
			set_hit(false, 0);
		}

		if (is_hit().second == 0 || is_hit().second == 1)
		{
			stop_duration++;
		}

		if (stop_duration >= 300)
		{
			set_vel(tempvel);
			stop_duration = 0;
		}
	}
}

void Enemy::render(Image death)
{
	if (get_health() <= 0)
	{
		if (dead.get_frame_position(21) >= 0 && dead.get_frame_position(21) <= 10)
		{
			al_draw_bitmap_region(death.Destruction_image(0).first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}

		else
		{
			al_draw_bitmap_region(death.Destruction_image(0).first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
		}
	}

	else
	{
		if (is_hit().first && (is_hit().second == 1  || is_hit().second == 4))
		{
			if (damage.get_frame_position(11) >= 0 && damage.get_frame_position(11) <= 5)
			{
				is_damage = 1;
			}

			else if (damage.get_frame_position(11) > 5)
			{
				is_damage = 0;
			}
		}

		else
		{
			is_damage = 0;
		}

		if (al_get_bitmap_width(get_image().Enemy_image(get_id()).first) > 160)
		{
			switch (get_direction())
			{
			case 0:
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 0, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
				break;
			case 1:
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 80, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
				break;
			case 2:
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 160, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
				break;
			case 3:
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 240, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
				break;
			}
		}

		else if (al_get_bitmap_width(get_image().Enemy_image(get_id()).first) == 160)
		{
			if (animation.get_frame_position(51) >= 0 && animation.get_frame_position(51) <= 25)
			{
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 0, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			}

			else if (animation.get_frame_position(51) > 25)
			{
				al_draw_bitmap_region(get_image().Enemy_image(get_id()).first, 80, 80 * is_damage, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			}

		}

		if (is_hit().first && is_hit().second == 2)
		{
			al_draw_bitmap_region(death.status_image(0).first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);

		}

		if (is_hit().first && is_hit().second == 3)
		{
			if (burn_duration % 11 >= 0 && burn_duration % 11 <= 5)
			{
				al_draw_bitmap_region(death.status_image(1).first, 0, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			}

			else
			{
				al_draw_bitmap_region(death.status_image(1).first, 80, 0, al_get_bitmap_width(cropping), al_get_bitmap_height(cropping), get_x(), get_y(), NULL);
			}
		}
	}
}
