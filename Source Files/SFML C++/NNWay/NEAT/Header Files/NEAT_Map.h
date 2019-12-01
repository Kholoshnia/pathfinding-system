#pragma once

#include <SFML/Graphics.hpp>

namespace neat
{
	extern sf::Vector2i map_size;
	extern float agent_radius, goal_radius;
	extern std::vector<std::string> map_markup;

	struct Map
	{
		int size;
		sf::RectangleShape rect;
		sf::Vector2i pos_goal, pos_agent;
		sf::CircleShape circle_goal, circle_agent;
		std::vector<sf::Vector2i> pos_rects, pos_additional_rewards;

		Map();

		void fill_around();
		void pos_walls_pop_back();
		void set_goal_pos(sf::Event::MouseMoveEvent pos_mouse);
		void pos_walls_push_back(sf::Event::MouseMoveEvent pos_mouse);

		void from_file();
		float dist(sf::Vector2f& obj);
		bool touched_wall(sf::Vector2f& obj);
		bool touched_goal(sf::Vector2f& obj);
		bool touched_additional_reward(sf::Vector2f& obj);
		void show(sf::RenderWindow& window);
	};
}