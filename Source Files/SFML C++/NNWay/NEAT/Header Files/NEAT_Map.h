#pragma once

#include <SFML\Graphics.hpp>

namespace neat
{
	extern sf::Vector2i map_size;
	extern std::string map_markup[80];
	extern float agent_radius, goal_radius;

	struct Map
	{
		int size;
		float goal_r;
		sf::CircleShape circle;
		sf::RectangleShape rect;
		sf::Vector2f pos_goal, pos_start;
		std::vector<sf::Vector2f> pos_rects, pos_additional_rewards;

		Map();
		float dist(sf::Vector2f& obj);
		bool touched_wall(sf::Vector2f& obj);
		bool touched_goal(sf::Vector2f& obj);
		bool touched_additional_reward(sf::Vector2f& obj);
		void show(sf::RenderWindow& window);
	};
}