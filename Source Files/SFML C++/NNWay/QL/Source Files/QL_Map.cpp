#include <QL/Header Files/QL_Map.h>

ql::Map::Map()
{
	background.setOutlineThickness(2.5F);
	background.setFillColor(sf::Color::White);
	background.setOutlineColor(sf::Color::Black);
	background.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
	
	wall.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
	finish.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
	background.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));

	wall.setFillColor(sf::Color::Blue);
	finish.setFillColor(sf::Color::Red);

	update_size();
	update();
}

void ql::Map::update()
{
	initials.clear();
	wall_pos.clear();
	background_pos.clear();

	int k = 0;
	for (size_t y = 0; y < map_size_y; y++)
		for (size_t x = 0; x < map_size_x; x++)
		{
			if (map[y][x] == 'B')
			{
				background_pos.emplace_back((float)(x * (height / map_size_x)), (float)(y * (width / map_size_y)));
				initials.emplace_back(k);
				k++;
			}
			else if (map[y][x] == 'W')
			{
				wall_pos.emplace_back((float)(x * (height / map_size_x)), (float)(y * (width / map_size_y)));
				k++;
			}
			else if (map[y][x] == 'F')
			{
				finish.setPosition((float)(x * (height / map_size_x)), (float)(y * (width / map_size_y)));
				k++;
			}
		}
	
	wall.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
	finish.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
	background.setSize(sf::Vector2f((float)(width / map_size_x), (float)(height / map_size_y)));
}

void ql::Map::update_size()
{
	map.resize(map_size_y);
	for (auto& el : map)
		for (size_t i = 0; i < map_size_x; i++)
			el.emplace_back('B');
}

void ql::Map::show(sf::RenderWindow& window)
{
	for (auto& el : background_pos)
	{
		background.setPosition(el);
		window.draw(background);
	}

	for (auto& el : wall_pos)
	{
		wall.setPosition(el);
		window.draw(wall);
	}

	window.draw(finish);
}