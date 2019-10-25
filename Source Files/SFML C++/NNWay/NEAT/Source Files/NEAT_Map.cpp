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
				pos_rect.emplace_back((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == '0')
				goal = sf::Vector2f((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == '*')
				dot_pos = sf::Vector2f((float)j * 10.0f, (float)i * 10.0f);
			else if (map_markup[i][j] == 'b')
				pos_bonus.emplace_back((float)j * 10.0f, (float)i * 10.0f);
}

float neat::Map::dist(sf::Vector2f& obj) { return sqrt((goal.x - obj.x) * (goal.x - obj.x) + (goal.y - obj.y) * (goal.y - obj.y)); }

bool neat::Map::bonus(sf::Vector2f& obj)
{
	for (auto& pos_bonus : pos_bonus)
		if (obj.x >= pos_bonus.x && obj.x <= pos_bonus.x + 10 && obj.y >= pos_bonus.y && obj.y <= pos_bonus.y + 10) return true;
	return false;
}

bool neat::Map::touched(sf::Vector2f& obj)
{
	for (auto& pos_rect : pos_rect)
		if (obj.x >= pos_rect.x && obj.x <= pos_rect.x + 10 && obj.y >= pos_rect.y && obj.y <= pos_rect.y + 10) return true;
	return false;
}

void neat::Map::show(sf::RenderWindow& window)
{
	rect.setFillColor(sf::Color::Blue);
	for (auto& pos_rect : pos_rect)
	{
		rect.setPosition(pos_rect.x, pos_rect.y);
		window.draw(rect);
	}
	rect.setFillColor(sf::Color::Yellow);
	for (auto& pos_bonus : pos_bonus)
	{
		rect.setPosition(pos_bonus.x, pos_bonus.y);
		window.draw(rect);
	}
	circle.setPosition(goal);
	window.draw(circle);
}