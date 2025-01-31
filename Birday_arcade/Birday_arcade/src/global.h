#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <math.h>
#include <utility>
#include <chrono>
#include <fstream>
#include <tuple>


// screen size
#define winx 1360
#define winy 768

enum {PLAYER, ENEMY, PWEAPON, EWEAPON, TILES, POWERUP, AMMO, BACKGROUND, DESTRUCTION, STATUS, MISC};

enum {LAZER, ROCKET_LAZER, STUNNER, BOMBS, ICE_BOMBS, FIRE_BOMBS, BI_NUKE, TRI_NUKE, TRIANGULAR_MISSILE,
	ARROW, SLICER, ATOMIC_BOMBS};

enum {TRIPUS, MAGIC_MASK, DIAMONDO, CANNON_SLUG, FISHER, BALL, TRIPUS2, MAGIC_MASK2, DIAMONDO2, CANNON_SLUG2, FISHER2, 
	BALL2};

enum {FIRE, LIGHTNING, DIAMOND_ICE, STAR_SHOT, BALL_SHOT, BUBBLE_SHOT, VENOM_SPIT, MISSILE, GRAPPLE, GUNK};

enum {GLIDING_CHIP, HEALTH_CHIP, NEEDLE_WIND_BLAST_CHIP, STOP_CHIP, B_2_BOMBER_STRIKE_CHIP, COPY_CHIP
};

enum {NONE, ROCKET_LAZER_AMMO, STUNNER_AMMO, BOMB_AMMO, ICE_BOMB_AMMO, FIRE_BOMB_AMMO, ATOMIC_BOMB_AMMO, BI_NUKE_AMMO, TRI_NUKE_AMMO, 
	TRIANGULAR_MISSILE_AMMO, ARROW_AMMO, SLICER_AMMO};

enum {BLUE_CIRCLE, BLUE_SQUARE, BRICK_WALL, FENCE, FLOWER, GRASS, GRAY_SQUARE, 
	PALM_TREE, PILLAR, PURPLE_CIRCLE, PURPLE_SQUARE, ROCK, SAND, DARK_GRAY_CIRCLE, DARK_GRAY_SQUARE};

enum {MENU, GAME_OVER, BANNER};

enum {ENEMY_DESTROYED, WEAPON_DESTROYED};

enum {MENU_SCREEN, GAME_SCREEN, GAME_MATERIAL_SCREEN, OPTION_SCREEN, QUIT_SCREEN, PAUSE_SCREEN, GAME_OVER_SCREEN, WEAPONS_UNLOCKED_SCREEN};

enum {FREEZE = 1, BURN};

