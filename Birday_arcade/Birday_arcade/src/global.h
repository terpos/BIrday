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


// screen size
#define winx 1360
#define winy 768

enum {PLAYER, ENEMY, PWEAPON, EWEAPON, TILES, POWERUP};

enum {LAZER, ROCKET_LAZER, STUNNER, BOMBS, BI_NUKE, TRI_NUKE, TRIANGULAR_MISSILE, SLICER, ARROW};

enum {TRIPUS, MAGIC_MASK, DIAMONDO, CANNON_SLUG, FISHER, BALL, TRIPUS2, MAGIC_MASK2, DIAMONDO2, CANNON_SLUG2, FISHER2, BALL2};

enum {FIRE, LIGHTNING, DIAMOND_ICE, STAR_SHOT, BALL_SHOT, BUBBLE_SHOT, VENOM_SPIT, MISSILE, GRAPPLE};

enum {GLIDING_CHIP, HEALTH_CHIP, COPY_CHIP, NEEDLE_WIND_BLAST_CHIP, STOP_CHIP, B_2_BOMBER_STRIKE_CHIP};

enum {BLUE_CIRCLE, BLUE_SQUARE, BRICK_WALL, FENCE, FLOWER, GRASS, GRAY_SQUARE, 
	PALM_TREE, PILLAR, PURPLE_CIRCLE, PURPLE_SQUARE, ROCK, SAND, WHITE_CIRCLE, WHITE_SQUARE};
