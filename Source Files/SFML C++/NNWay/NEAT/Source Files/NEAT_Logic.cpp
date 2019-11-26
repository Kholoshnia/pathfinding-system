#include <NEAT/Header Files/NEAT_Logic.h>

void neat::draw(sf::Event &event)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == event.MouseMoved)
	{
		if ([&]
		{
			for (auto& el : map->pos_rects)
				if (el == sf::Vector2i(event.mouseMove.x / 10 * 10, event.mouseMove.y / 10 * 10))
					return false;
				return true;
		}())
			map->pos_rects.emplace_back(event.mouseMove.x / 10 * 10, event.mouseMove.y / 10 * 10);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && event.type == event.MouseMoved)
	{
		if ([&]
		{
			for (auto& el : map->pos_additional_rewards)
				if (el == sf::Vector2i(event.mouseMove.x / 10 * 10, event.mouseMove.y / 10 * 10))
					return false;
				return true;
		}())
			map->pos_rects.emplace_back(event.mouseMove.x / 10 * 10, event.mouseMove.y / 10 * 10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && map->pos_rects.size() > 0)
		map->pos_rects.pop_back();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && map->pos_additional_rewards.size() > 0)
		map->pos_additional_rewards.pop_back();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		for (int y = 0; y < map_size.y; y++)
		{
			map->pos_rects.emplace_back(0, y * 10);
			map->pos_rects.emplace_back(map_size.x - 1, y * 10);
		}

		for (int x = 0; x < map_size.x; x++)
		{
			map->pos_rects.emplace_back(x * 10, 0);
			map->pos_rects.emplace_back(x * 10, map_size.y - 1);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && event.type == event.MouseMoved)
		map->pos_goal = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.type == event.MouseMoved)
		map->pos_agent = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) goal_radius += 0.1f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && goal_radius > 0) goal_radius -= 0.1f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) agent_radius += 0.1f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && agent_radius > 0) agent_radius -= 0.1f;
}

void neat::check_2d()
{
	std::vector<sf::Vector2f> check;

	sf::RenderWindow window(sf::VideoMode(width, height), "Check");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear(sf::Color::White);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		map->show(window);

		if (population->gen == 1)
			population->update();

		population->show(window);

		if (!population->reached_the_goal) check.emplace_back(population->agents[0].circle.getPosition());

		for (auto& el : check)
		{
			map->circle_agent.setPosition(el);
			window.draw(map->circle_agent);
		}

		window.draw(controls[0]);
		window.display();
	}
}

void neat::check_3d()
{
	system("OpenUnity.exe");
}

void neat::create_new_map_2d()
{
	map_size.x = 80;
	map_size.y = 80;
	map.reset(new Map());

	sf::RenderWindow window(sf::VideoMode(width, height), "Map creator");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		window.clear(sf::Color::White);

		draw(event);

		map->show(window);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			window.draw(loading);
			window.display();

			fout.open("Resource Files/Data/NEAT/input.csv");
			if (fout.is_open())
			{
				fout << "map-size-x:;" << map_size.x << std::endl;
				fout <<	"map-size-y:;" << map_size.y << std::endl;
				for (int y = 0; y < map_size.y; y++)
				{
					for (int x = 0; x < map_size.x; x++)
					{
						if (x == map->pos_agent.x / 10 && y == map->pos_agent.y / 10)
							fout << 'A';
						else if (x == map->pos_goal.x / 10  && y == map->pos_goal.y / 10)
							fout << 'G';
						else if ([&x, &y]
						{
							for (auto& el : map->pos_rects)
								if (x == el.x / 10 && y == el.y / 10)
									return true;
							return false;
						}())
							fout << 'W';
						else if ([&x, &y]
						{
							for (auto& el : map->pos_additional_rewards)
								if (x == el.x / 10 && y == el.y / 10)
									return true;
							return false;
						}())
							fout << 'B';
						else
							fout << 'S';
						fout << ';';
					}
					fout << std::endl;
				}
				fout << "agent-radius:;" << agent_radius << std::endl;
				fout << "goal-radius:;" << goal_radius << std::endl;
				fout.close();
				window.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"input.csv\"");
		}
		window.draw(controls[2]);
		window.display();
	}
}

void neat::create_new_map_3d()
{
	System::Windows::Forms::MessageBox::Show("Open \"Map Creator\" and start when you done creating new map and then load from file");
	map_loaded = true;
}

void neat::load_map_from_file_2d()
{
	map_size.x = 80;
	map_size.y = 80;
	map.reset(new Map);

	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	
	std::string str;
	for (int i = static_cast<int>(path.length()) - 1; i >= 0; i--)
		if (path[i] != '.') str += path[i];
		else break;

	if (str == "pmb" || str == "gnp" || str == "agt" || str == "gpj" ||
		str == "fig" || str == "dsp" || str == "rdh" || str == "cip") from_image = true;
	else from_image = false;

	str.clear();

	if (from_image)
	{
		sf::Image map_image;
		map_image.getSize();
		map_image.loadFromFile(path);

		for (int y = 0; y < map_size.y; y++)
		{
			map_markup[y].resize(map_size.x);
			for (int x = 0; x < map_size.x; x++)
			{
				if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Black)
					map_markup[y][x] = 'A';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Red)
					map_markup[y][x] = 'G';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Blue)
					map_markup[y][x] = 'W';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Yellow)
					map_markup[y][x] = 'B';
				else
					map_markup[y][x] = 'S';
			}
		}

		map->from_file();
		map_loaded = true;
	}
	else
	{
		fin.open(path);
		if (fin.is_open())
		{
			char ch = '\0';
			while (ch != ';') fin.get(ch);
			fin >> map_size.x;
			fin.get(ch);
			while (ch != ';') fin.get(ch);
			fin >> map_size.y;
			fin.get(ch);
			std::string line;
			for (int y = 0; y < map_size.y; y++)
			{
				std::getline(fin, line);
				line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
				map_markup[y] = line;
			}
			while (ch != ';') fin.get(ch);
			fin >> agent_radius;
			fin.get(ch);
			while (ch != ';') fin.get(ch);
			fin >> goal_radius;
			map->from_file();
			fin.close();
			map_loaded = true;
		}
		else
		{
			std::string message = "Error opening file \"" + path + "\"";
			System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
		}
	}
}

void neat::load_map_from_file_3d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	if (path != "")
		map_loaded = true;
}

void neat::load_result_from_file_2d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	
	fin.open(path);
	if (fin.is_open())
	{
		fin >> max_speed;
		fin >> direction_array_size;

		population_quantity = 1;
		population.reset(new Population());

		for (auto& el : population->agents[0].brain.directions)
		{
			fin >> el.x;
			fin.get();
			fin.get();
			fin >> el.y;
		}
		fout.close();

		result_loaded = true;
	}
	else
	{
		std::string message = "Error opening file \"" + path + "\"";
		System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
	}
}

void neat::load_result_from_file_3d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	if (path != "")
		result_loaded = true;
}

void neat::with_visualization_2d()
{
	neat::direction_array_size = neat::map_size.x * neat::map_size.y / static_cast<int>(neat::agent_radius);
	layers.reset(new Layers());

	sf::RenderWindow window(sf::VideoMode(width, height), "Learning");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (auto_end && layers->populations[layers->best_population].after_reach > auto_exit))
		{
			window.draw(loading);
			window.display();

			fout.open("Resource Files/Data/NEAT/output.csv");
			if (fout.is_open())
			{
				fout << max_speed << std::endl;
				fout << layers->populations[layers->best_population].min_step << std::endl;
				for (int i = 0; i < layers->populations[layers->best_population].min_step; ++i)
					fout << layers->populations[layers->best_population].agents[layers->populations[layers->best_population].best_agent].brain.directions[i].x << " ; " << layers->populations[layers->best_population].agents[layers->populations[layers->best_population].best_agent].brain.directions[i].y << std::endl;
				fout.close();
				window.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"output.csv\"");

			fout.open("Resource Files/Data/NEAT/new_map.csv");
			if (fout.is_open())
			{
				fout << "map-size-x:;" << map_size.x << std::endl;
				fout << "map-size-y:;" << map_size.y << std::endl;
				for (int y = 0; y < map_size.y; y++)
				{
					for (int x = 0; x < map_size.x; x++)
					{
						if (x == map->pos_agent.x / 10 && y == map->pos_agent.y / 10)
							fout << 'A';
						else if (x == map->pos_goal.x / 10 && y == map->pos_goal.y / 10)
							fout << 'G';
						else if ([&x, &y]
						{
							for (auto& el : map->pos_rects)
								if (x == el.x / 10 && y == el.y / 10)
									return true;
								return false;
						}())
							fout << 'W';
						else
							fout << 'S';
						fout << ';';
					}
					fout << std::endl;
				}
				fout << "agent-radius:;" << agent_radius << std::endl;
				fout << "goal-radius:;" << goal_radius << std::endl;
				fout.close();
				window.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"new_map.csv\"");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.clear(sf::Color::White);
		map->show(window);

		draw(event);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) pause = !pause;
		if (!pause) layers->update();

		layers->show(window);

		if (layers->best_population) text[1].setString(L"Yes");
		else text[1].setString(L"No");

		std::ostringstream str;
		str << layers->populations[layers->best_population].gen;
		text[3].setString(str.str());

		for (int i = 0; i < 4; i++)
			window.draw(text[i]);
		window.draw(controls[1]);
		window.display();
	}
}

void neat::with_visualization_3d()
{
	fout.open(path, std::fstream::app);
	if (fout.is_open())
	{
		fout << "info" << std::endl;
		fout << "visualization:;" << visualization << std::endl;
		fout << "direction-array-size:;" << direction_array_size << std::endl;
		fout << "population-quantity:;" << population_quantity << std::endl;
		fout << "layers-quantity:;" << layers_quantity << std::endl;
		fout << "auto-completion:;" << auto_end << ';' << auto_exit;
		fout << "speed:;" << 0.1f << ';' << max_speed;
		fout << "mutation-rate" << mutation_rate;
		fout.close();
	}
	else
	{
		std::string message = "Error opening file: \"" + path + "\"";
		System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
	}

	system("OpenUnity.exe");
}

void neat::without_visualization_2d()
{
	neat::direction_array_size = neat::map_size.x * neat::map_size.y / static_cast<int>(neat::agent_radius);
	layers.reset(new Layers());
	bool calculating = true;

	while (calculating)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (auto_end && layers->populations[layers->best_population].after_reach > auto_exit))
		{
			fout.open("Resource Files/Data/NEAT/output.csv");
			if (fout.is_open())
			{
				fout << max_speed << std::endl;
				fout << layers->populations[layers->best_population].min_step << std::endl;
				for (int i = 0; i < layers->populations[layers->best_population].min_step; ++i)
					fout << layers->populations[layers->best_population].agents[layers->populations[layers->best_population].best_agent].brain.directions[i].x << " ; " << layers->populations[layers->best_population].agents[layers->populations[layers->best_population].best_agent].brain.directions[i].y << std::endl;
				fout.close();
				calculating = false;
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"output.csv\"");
		}

		layers->update();
	}
}

void neat::without_visualization_3d()
{
	fout.open(path, std::fstream::app);

	if (fout.is_open())
	{
		fout << "info" << std::endl;
		fout << "visualization:;" << visualization << std::endl;
		fout << "direction-array-size:;" << direction_array_size << std::endl;
		fout << "population-quantity:;" << population_quantity << std::endl;
		fout << "layers-quantity:;" << layers_quantity << std::endl;
		fout << "auto-completion:;" << auto_end << ';' << auto_exit;
		fout << "speed:;" << 0.1f << ';' << max_speed;
		fout << "mutation-rate" << mutation_rate;
		fout.close();
	}
	else
	{
		std::string message = "Error opening file: \"" + path + "\"";
		System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
	}

	system("OpenUnity.exe");
}