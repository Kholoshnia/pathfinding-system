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
	extern sf::Vector2f goal_pos, dot_pos;

	extern bool map_loaded, auto_end;
	extern int population_quantity, layers_quantity, auto_exit;

	void check();
	void create_new_map();
	void load_map_from_file();
	void check_from_file();
	void with_visualization();
	void without_visualization();
}