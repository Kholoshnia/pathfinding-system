#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include <Enums.h>

#include <NEAT/Header Files/NEAT_Map.h>
#include <NEAT/Header Files/NEAT_Brain.h>
#include <NEAT/Header Files/NEAT_Layers.h>
#include <NEAT/Header Files/NEAT_Population.h>

extern Languages language;
extern Dimensions dimension;

extern std::string path;
extern sf::Sprite loading;
extern int fps;
extern bool from_image;

namespace neat
{
	extern std::shared_ptr<Map> map;
	extern std::shared_ptr<Layers> layers;
	extern std::shared_ptr<Population> population;

	extern std::fstream fout;
	extern std::string map_markup[80];
	extern std::vector<sf::Vector2f> pos;

	extern sf::RectangleShape rect;
	extern sf::CircleShape circle[2];
	extern sf::Text text[4], controls[3];
	extern sf::Vector2f goal_pos, pos_goal;

	extern bool map_loaded, auto_end;
	extern int map_size_x, map_size_y, population_quantity, layers_quantity, direction_array_size, auto_exit;

	void check_2d();
	void check_3d();
	void create_new_map_2d();
	void create_new_map_3d();
	void load_map_from_file_2d();
	void load_map_from_file_3d();
	void load_result_from_file_2d();
	void load_result_from_file_3d();
	void with_visualization_2d();
	void with_visualization_3d();
	void without_visualization_2d();
	void without_visualization_3d();
}