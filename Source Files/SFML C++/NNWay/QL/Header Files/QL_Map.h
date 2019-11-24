#pragma once

#include <SFML/Graphics.hpp>

#include <fstream>

extern std::string path;
extern int width, height;

namespace ql
{
	extern sf::Vector2i map_size;
	extern std::vector<int> initials;

	struct Map
	{
		std::vector<std::vector<char>> map;
		sf::RectangleShape background, wall, finish;
		std::vector<sf::Vector2f> background_pos, wall_pos;

		Map();
		void update();
		void update_size();
		void show(sf::RenderWindow& window);
	};
}