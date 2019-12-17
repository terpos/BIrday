#include "global.h"

#pragma once
class Tile_map
{
public:
	Tile_map();
	~Tile_map();

	void load(std::string file_name);
	
	int get_width();
	int get_length();
	int get_x();
	int get_y();

	void set_x(int x);
	void set_y(int y);
	int get_tile_number(int indexx, int indexy);
	int get_tile_style();
	void set_tile_style(int style_num);
	
private:
	std::vector <std::vector<int>> tile_info;
	std::ifstream tile_file;
	int x, y, width, length, counter_x, counter_y, info, style;
};

