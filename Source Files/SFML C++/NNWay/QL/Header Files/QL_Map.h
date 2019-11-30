#pragma once

#include <SFML/Graphics.hpp>

#include <fstream>

extern std::string path;
extern int width, height;

namespace ql
{
	extern float thickness;
	extern sf::Vector2i map_size;
	extern std::vector<int> initials;

	struct Map
	{
		sf::RectangleShape space, wall, goal;
		std::vector<std::vector<char>> map_markup;
		std::vector<sf::Vector2f> pos_spaces, pos_walls;

		Map();
		void save();
		void update();
		void update_size();
		void fill_around();
		void inc_map_size();
		void dec_map_size();
		void pos_walls_pop_back();
		void set_goal_pos(sf::Event::MouseMoveEvent pos_mouse);
		void pos_walls_push_back(sf::Event::MouseMoveEvent pos_mouse);
		void show(sf::RenderWindow& window);
	};
}