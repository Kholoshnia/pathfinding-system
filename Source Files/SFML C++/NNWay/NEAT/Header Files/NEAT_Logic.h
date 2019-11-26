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

extern Dimensions dimension;

extern std::string path;
extern sf::Sprite loading;
extern int fps, width, height;
extern bool visualization, from_image, map_loaded, result_loaded, pause;

namespace neat
{
	extern std::shared_ptr<Map> map;
	extern std::shared_ptr<Layers> layers;
	extern std::shared_ptr<Population> population;

	extern std::fstream fout, fin;
	extern std::string map_markup[80];

	extern sf::RectangleShape rect;
	extern sf::Text text[4], controls[3];
	extern sf::Vector2i map_size, wall_size;

	extern bool auto_end, around;
	extern int population_quantity, layers_quantity, direction_array_size, auto_exit;

	void check_2d();
	void check_3d();
	void create_new_map_2d();
	void create_new_map_3d();
	void draw(sf::Event& event);
	void load_map_from_file_2d();
	void load_map_from_file_3d();
	void load_result_from_file_2d();
	void load_result_from_file_3d();
	void with_visualization_2d();
	void with_visualization_3d();
	void without_visualization_2d();
	void without_visualization_3d();
}