#pragma once

#include <SFML\Graphics.hpp>

namespace neat
{
	extern float goal_radius;
	extern std::string map_markup[80];

	struct Map
	{
		float goal_r;
		sf::CircleShape circle;
		sf::RectangleShape rect;
		sf::Vector2f goal, dot_pos;
		std::vector<sf::Vector2f> pos_rect, pos_bonus;

		Map();
		float dist(sf::Vector2f& obj);
		bool bonus(sf::Vector2f& obj);
		bool touched(sf::Vector2f& obj);
		void show(sf::RenderWindow& window);
	};
}