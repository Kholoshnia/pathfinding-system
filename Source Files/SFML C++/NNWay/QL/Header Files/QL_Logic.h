#pragma once

#include <SFML/Graphics.hpp>

#include <sstream>
#include <fstream>

#include <Enums.h>

#include <QL/Header Files/QL_Map.h>
#include <QL/Header Files/QL_Table.h>
#include <QL/Header Files/QL_Agent.h>

extern Languages language;
extern Dimentions dimention;

extern int fps;
extern bool from_image;
extern sf::Sprite loading;

namespace ql
{
	extern std::shared_ptr<Map> map;
	extern std::shared_ptr<Table> table;
	extern std::shared_ptr<Agent> agent;

	extern sf::Text text[4];
	extern std::string image_path;
	extern std::fstream fout, fin;
	extern std::vector<int> initials;
	extern long long int finish_reward;
	extern bool map_loaded, finish_loaded;
	extern int map_size_x, map_size_y, width, height, finish_state, iterations;

	void check();
	void load_from_file();
	void create_new_map();
	void load_from_image();
	void check_from_file();
	void with_visualization();
	void without_visualization();
}