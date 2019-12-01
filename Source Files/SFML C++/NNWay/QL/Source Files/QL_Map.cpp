#include <QL/Header Files/QL_Map.h>

ql::Map::Map()
{
	space.setOutlineThickness(thickness);
	space.setFillColor(sf::Color::White);
	space.setOutlineColor(sf::Color::Black);
	space.setSize(sf::Vector2f(static_cast<float>(width / map_size.x) - thickness, static_cast<float>(height / map_size.y) - thickness));

	wall.setOutlineThickness(thickness);
	wall.setFillColor(sf::Color::Blue);
	wall.setOutlineColor(sf::Color::Black);
	wall.setSize(sf::Vector2f(static_cast<float>(width / map_size.x) - thickness, static_cast<float>(height / map_size.y) - thickness));

	goal.setOutlineThickness(thickness);
	goal.setFillColor(sf::Color::Red);
	goal.setOutlineColor(sf::Color::Black);
	goal.setSize(sf::Vector2f(static_cast<float>(width / map_size.x) - thickness, static_cast<float>(height / map_size.y) - thickness));

	update_size();
	update();
}

void ql::Map::save()
{
	map_markup[static_cast<int>(goal.getPosition().y) / (width / map_size.y)][static_cast<int>(goal.getPosition().x) / (height / map_size.x)] = 'G';
	update();
}

void ql::Map::pos_walls_pop_back()
{
	if (pos_walls.size() > 0)
	{
		map_markup[pos_walls[pos_walls.size() - 1].y / (height / map_size.y)][pos_walls[pos_walls.size() - 1].x / (width / map_size.x)] = 'S';
		update();
	}
}

void ql::Map::fill_around()
{
	for (int y = 0; y < map_size.y; y++)
		for (int x = 0; x < map_size.x; x++)
			if (x == 0 || x == map_size.x - 1 || y == 0 || y == map_size.y - 1)
				map_markup[y][x] = 'W';

	update();
}

void ql::Map::inc_map_size()
{
	map_markup[static_cast<int>(goal.getPosition().y) / (height / map_size.y)][static_cast<int>(goal.getPosition().x) / (width / map_size.x)] = 'G';

	for (int y = 0; y < map_size.y; y++)
		map_markup[y].emplace_back('S');

	std::vector<char> line;
	for (int x = 0; x < map_size.x + 1; x++)
		line.emplace_back('S');
	map_markup.emplace_back(line);

	map_size.x += 1;
	map_size.y += 1;
	update();
}

void ql::Map::dec_map_size()
{
	if (map_size.x > 2 && map_size.y > 2)
	{
		map_markup[static_cast<int>(goal.getPosition().y) / (height / map_size.y)][static_cast<int>(goal.getPosition().x) / (width / map_size.x)] = 'G';

		for (int y = 0; y < map_size.y; y++)
			map_markup[y].pop_back();
		map_markup.pop_back();
		map_size.x -= 1;
		map_size.y -= 1;
		update();
	}
}

void ql::Map::pos_walls_push_back(sf::Event::MouseMoveEvent pos_mouse)
{
	if (pos_mouse.x < (width / map_size.x) * map_size.x && pos_mouse.y < (height / map_size.y) * map_size.y)
	{
		map_markup[static_cast<int>(goal.getPosition().y) / (height / map_size.y)][static_cast<int>(goal.getPosition().x) / (width / map_size.x)] = 'G';

		if ([&]()
		{
			for (auto& el : pos_walls)
				if (el == sf::Vector2f(static_cast<float>(pos_mouse.x / (height / map_size.x)), static_cast<float>(pos_mouse.y / (width / map_size.y))))
					return false;
				return true;
		}())
			map_markup[pos_mouse.y / (height / map_size.y)][pos_mouse.x / (width / map_size.x)] = 'W';
				update();
	}
}

void ql::Map::set_goal_pos(sf::Event::MouseMoveEvent pos_mouse)
{
	if (pos_mouse.x < (width / map_size.x) * map_size.x && pos_mouse.y < (height / map_size.y) * map_size.y)
	{
		map_markup[static_cast<int>(goal.getPosition().y) / (height / map_size.y)][static_cast<int>(goal.getPosition().x) / (width / map_size.x)] = 'S';
		goal.setPosition(static_cast<float>(pos_mouse.x / (width / map_size.x) * (width / map_size.x)), static_cast<float>(pos_mouse.y / (height / map_size.y) * (height / map_size.y)));
		update();
	}
}

void ql::Map::update()
{
	initials.clear();
	pos_walls.clear();
	pos_spaces.clear();

	int k = 0;
	for (int y = 0; y < map_size.y; y++)
		for (int x = 0; x < map_size.x; x++)
		{
			if (map_markup[y][x] == 'S')
			{
				pos_spaces.emplace_back(static_cast<float>(x * (height / map_size.x)), static_cast<float>(y * (width / map_size.y)));
				initials.emplace_back(k);
			}
			else if (map_markup[y][x] == 'W')
				pos_walls.emplace_back(static_cast<float>(x * (height / map_size.x)), static_cast<float>(y * (width / map_size.y)));
			else if (map_markup[y][x] == 'G')
				goal.setPosition(static_cast<float>(x * (height / map_size.x)), static_cast<float>(y * (width / map_size.y)));

			k++;
		}

	wall.setSize(sf::Vector2f(static_cast<float>(width / map_size.x), static_cast<float>(height / map_size.y)));
	goal.setSize(sf::Vector2f(static_cast<float>(width / map_size.x), static_cast<float>(height / map_size.y)));
	space.setSize(sf::Vector2f(static_cast<float>(width / map_size.x), static_cast<float>(height / map_size.y)));
}

void ql::Map::update_size()
{
	map_markup.resize(map_size.y);
	for (auto& el : map_markup)
		for (int i = 0; i < map_size.x; i++)
			el.emplace_back('S');
}

void ql::Map::show(sf::RenderWindow& window)
{
	for (auto& el : pos_spaces)
	{
		space.setPosition(el);
		window.draw(space);
	}

	for (auto& el : pos_walls)
	{
		wall.setPosition(el);
		window.draw(wall);
	}

	window.draw(goal);
}