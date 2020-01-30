#include "Tile_map.h"



Tile_map::Tile_map()
{
	counter_x = counter_y = 0;
}


Tile_map::~Tile_map()
{
}

void Tile_map::load(std::string file_name)
{
	tile_file.open(file_name.c_str());

	tile_file >> width >> length;

	if (tile_file.is_open())
	{
		tile_info.push_back(std::vector <int> ());
		while (!tile_file.eof())
		{
			tile_file >> info;
			tile_info[counter_y].push_back(info);
			counter_x++;
			
			if (counter_x >= width)
			{
				counter_x = 0;
				counter_y++;
				tile_info.push_back(std::vector <int>());
			}
		}
	}
	tile_file.close();

}

int Tile_map::get_width()
{
	return this->width;
}

int Tile_map::get_length()
{
	return this->length;
}

int Tile_map::get_x()
{
	return this->x;
}

int Tile_map::get_y()
{
	return this->y;
}

void Tile_map::set_x(int x)
{
	this->x = x;
}

void Tile_map::set_y(int y)
{
	this->y = y;
}

int Tile_map::get_tile_number(int indexx, int indexy)
{
	return this->tile_info[indexy][indexx];
}

int Tile_map::get_tile_style()
{
	return this->style;
}

void Tile_map::set_tile_style(int style_num)
{
	this->style = style_num;
}

