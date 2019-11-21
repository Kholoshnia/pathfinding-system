#include <NEAT/Header Files/NEAT_Map.h>

neat::Map::Map()
{
	goal_r = goal_radius;
	circle.setOrigin(goal_radius, goal_radius);
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(goal_radius);
	rect.setSize(sf::Vector2f(10.0f, 10.0f));
	for (int i = 0; i < 80; i++)
		for (int j = 0; j < 80; j++)
			if (map_markup[i][j] == '#')
				pos_rects.emplace_back((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == '0')
				pos_goal = sf::Vector2f((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == '*')
				pos_start = sf::Vector2f((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == 'b')
				pos_additional_rewards.emplace_back((float)j * 10.0f, (float)i * 10.0f);
}

float neat::Map::dist(sf::Vector2f& obj) { return sqrt((pos_goal.x - obj.x) * (pos_goal.x - obj.x) + (pos_goal.y - obj.y) * (pos_goal.y - obj.y)); }

bool neat::Map::bonus(sf::Vector2f& obj)
{
	for (auto& pos_additional_rewards : pos_additional_rewards)
		if (obj.x >= pos_additional_rewards.x && obj.x <= pos_additional_rewards.x + 10 && obj.y >= pos_additional_rewards.y && obj.y <= pos_additional_rewards.y + 10) return true;
	return false;
}

bool neat::Map::touched_wall(sf::Vector2f& obj)
{
	for (auto& pos_rects : pos_rects)
		if (obj.x >= pos_rects.x && obj.x <= pos_rects.x + 10 && obj.y >= pos_rects.y && obj.y <= pos_rects.y + 10) return true;
	return false;
}

bool neat::Map::touched_goal(sf::Vector2f& obj) { return dist(obj) < goal_r; }

void neat::Map::show(sf::RenderWindow& window)
{
	rect.setFillColor(sf::Color::Blue);
	for (auto& pos_rects : pos_rects)
	{
		rect.setPosition(pos_rects.x, pos_rects.y);
		window.draw(rect);
	}
	rect.setFillColor(sf::Color::Yellow);
	for (auto& pos_additional_rewards : pos_additional_rewards)
	{
		rect.setPosition(pos_additional_rewards.x, pos_additional_rewards.y);
		window.draw(rect);
	}
	circle.setPosition(pos_goal);
	window.draw(circle);
}