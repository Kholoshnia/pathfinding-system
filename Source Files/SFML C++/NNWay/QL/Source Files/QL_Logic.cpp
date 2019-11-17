#include <QL/Header Files/QL_Logic.h>

void ql::check()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Check");

	window.setFramerateLimit(fps);

	std::vector<int> moves;

	int position, k = 0;
	bool done = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear();
		map->show(window);

		if (!done)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
			{
				position = map_size_y * (event.mouseMove.y / (width / map_size_y)) + event.mouseMove.x / (width / map_size_x);
				moves.emplace_back(position);
				if (std::find(initials.begin(), initials.end(), position) != initials.end())
				{
					moves.emplace_back(position);
					while (true)
					{
						int best_action = table->inference_best_action(position);
						moves.emplace_back(best_action);
						if (best_action == finish_state)
							break;
						else position = best_action;
					}
					done = true;
				}
			}
		}
		else
		{
			agent->show(window);
			agent->update(moves[k]);
			k++;

			if (k > moves.size() - 1)
			{
				moves.clear();
				k = 0;
				done = false;
			}
		}

		window.display();
	}
}

void ql::create_new_map()
{
	if (dimension == Dimensions::TWOD)
	{
		map.reset(new Map());
		bool space_pressed = false;
		sf::RectangleShape rects[2];

		sf::RenderWindow window(sf::VideoMode(800, 800), "Map creator");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();

			window.clear(sf::Color::White);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && map->wall_pos.size() > 0)
			{
				map->wall_pos.pop_back();
				map->update();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
			{
				map->map[(int)map->finish.getPosition().y / (width / map_size_y)][(int)map->finish.getPosition().x / (height / map_size_x)] = 'F';
				bool alreadyThere = false;
				sf::Vector2f mouse_pos((float)(event.mouseMove.x / (height / map_size_x)), (float)(event.mouseMove.y / (width / map_size_y)));
				for (auto& el : map->wall_pos)
					if (el == mouse_pos)
						alreadyThere = true;
				if (!alreadyThere)
					map->map[(int)mouse_pos.y][(int)mouse_pos.x] = 'W';
				map->update();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !space_pressed)
			{
				for (int y = 0; y < map_size_y; y++)
					for (int x = 0; x < map_size_x; x++)
					{
						if (x == 0 || x == map_size_x - 1 || y == 0 || y == map_size_y - 1)
							map->map[x][y] = 'W';
						space_pressed = true;
					}
				map->update();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
				map->finish.setPosition((float)(event.mouseMove.x / (height / map_size_x) * (height / map_size_x)), (float)(event.mouseMove.y / (width / map_size_y) * (height / map_size_y)));

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				map->map[(int)map->finish.getPosition().y / (width / map_size_y)][(int)map->finish.getPosition().x / (height / map_size_x)] = 'F';
				for (size_t y = 0; y < map_size_y; y++)
					map->map[y].emplace_back('B');

				std::vector<char> line;
				for (size_t x = 0; x < map_size_x + 1; x++)
					line.emplace_back('B');
				map->map.emplace_back(line);

				map_size_x += 1;
				map_size_y += 1;
				map->update();
				space_pressed = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && map_size_x >= 1 && map_size_y >=1)
			{
				if (map_size_x > 10 && map_size_y > 10)
				{
					map->map[(int)map->finish.getPosition().y / (width / map_size_y)][(int)map->finish.getPosition().x / (height / map_size_x)] = 'F';
					for (size_t y = 0; y < map_size_y; y++)
						map->map[y].pop_back();
					map->map.pop_back();
					map_size_x -= 1;
					map_size_y -= 1;
					map->update();
					space_pressed = false;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				map->map[(int)map->finish.getPosition().y / (width / map_size_y)][(int)map->finish.getPosition().x / (height / map_size_x)] = 'F';
				map->update();
				window.close();
			}

			map->show(window);
			window.display();
		}

		finish_reward = map_size_x * map_size_x * map_size_y * map_size_y;

		map_loaded = true;
	}
	else if (dimension == Dimensions::THREED)
		language == Languages::EN ? System::Windows::Forms::MessageBox::Show("Open \"Map Creator\" and start when you done creating new map and then load from file") : System::Windows::Forms::MessageBox::Show("Откройте \"Map Creator\" и запустите, когда закончите создание новой карты и затем загрузите из файла");
}

void ql::load_map_from_file()
{
	if (dimension == Dimensions::TWOD)
	{
		map.reset(new Map());

		System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
		if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
		std::string str;
		for (int i = (int)path.length() - 1; i >= 0; i--)
			if (path[i] != '.') str += path[i];
			else break;
		if (str == "gnp" || str == "gepj" || str == "fig") from_image = true;
		else from_image = false;
		str.clear();

		if (from_image)
			image_path = path;
		else
		{
			fin.open(path);
			if (fin.is_open())
			{
				fin >> map_size_x >> map_size_y;

				map->map.resize(map_size_y);
				for (int y = 0; y < map_size_y; y++)
					map->map[y].resize(map_size_x);

				for (int y = 0; y < map_size_y; y++)
					for (int x = 0; x < map_size_x; x++)
						fin >> map->map[y][x];

				fin.close();

				map_loaded = true;
			}
			else
			{
				std::string message;
				language == Languages::EN ? message = "Error opening file \"" + path + "\"" : message = "Ошибка открытия файла \"" + path + "\"";
				System::String^ str = gcnew System::String(message.c_str());
				System::Windows::Forms::MessageBox::Show(str);
			}
		}
		map->update();
		table.reset(new Table());
		finish_reward = map_size_x * map_size_x * map_size_y * map_size_y;
	}
	else if (dimension == Dimensions::THREED)
	{
		System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
		if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
	}
}

void ql::load_from_image()
{
	map->update_size();
	sf::Image map_image;
	map_image.loadFromFile(image_path);
	for (int y = 0; y < map_size_y; y++)
		for (int x = 0; x < map_size_x; x++)
		{
			if (map_image.getPixel(x * (height / map_size_x), y * (width / map_size_y)) == sf::Color::Red && !finish_loaded)
			{
				map->map[y][x] = 'F';
				finish_loaded = true;
			}
			else if (map_image.getPixel(x * (height / map_size_x), y * (width / map_size_y)) == sf::Color::Black)
				map->map[y][x] = 'W';
			else
				map->map[y][x] = 'B';
		}
	map->update();

	map_loaded = true;
}

void ql::check_from_file()
{
	table.reset(new Table());

	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
	fout.open(path);

	if (fout.is_open())
	{
		for (auto& row : table->R)
			for (auto& el : row)
				fout >> el;
		fout.close();
	}
	else
	{
		std::string message;
		language == Languages::EN ? message = "Error opening file \"" + path + "\"" : message = "Ошибка открытия файла \"" + path + "\"";
		System::String^ str = gcnew System::String(message.c_str());
		System::Windows::Forms::MessageBox::Show(str);
	}

	sf::RenderWindow window(sf::VideoMode(width, height), "Map");

	window.setFramerateLimit(fps);

	std::vector<int> moves;

	int position, k = 0;
	bool done = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear();
		map->show(window);

		if (!done)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
			{
				position = map_size_y * (event.mouseMove.y / (width / map_size_y)) + event.mouseMove.x / (width / map_size_x);
				moves.emplace_back(position);
				if (std::find(initials.begin(), initials.end(), position) != initials.end())
				{
					moves.emplace_back(position);
					while (true)
					{
						int best_action = table->inference_best_action(position);
						moves.emplace_back(best_action);
						if (best_action == finish_state) break;
						else position = best_action;
					}
					done = true;
				}
			}
		}
		else
		{
			agent->show(window);
			agent->update(moves[k]);
			k++;

			if (k > moves.size() - 1)
			{
				moves.clear();
				k = 0;
				done = false;
			}
		}

		window.display();
	}
}

void ql::with_visualization()
{
	table.reset(new Table());
	agent.reset(new Agent());

	sf::RenderWindow window(sf::VideoMode(width, height), "Map");

	window.setFramerateLimit(fps);

	int iterations_k = 0, initials_k = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		table->episode(initials[initials_k]);

		std::ostringstream initials_str;
		initials_str << initials[initials_k];
		text[1].setString(initials_str.str());

		std::ostringstream iterations_str;
		iterations_str << iterations_k;
		text[3].setString(iterations_str.str());

		initials_k++;

		if (initials_k > initials.size() - 1)
		{
			initials_k = 0;
			iterations_k++;
		}

		if (iterations_k > iterations)
		{
			fout.open("Resource Files/Data/QL/way.txt");
			if (fout.is_open())
			{
				for (size_t y = 0; y < map_size_x * map_size_y; y++)
				{
					for (size_t x = 0; x < map_size_x * map_size_y; x++)
						fout << table->Q[y][x] << ' ';
					fout << std::endl;
				}
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"way.txt\"");

			window.close();
		}

		window.clear();

		map->show(window);
		agent->show(window);

		for (int i = 0; i < 4; i++)
			window.draw(text[i]);

		window.display();
	}
}

void ql::without_visualization()
{
	table.reset(new Table());
	agent.reset(new Agent());

	for (size_t i = 0; i < iterations; i++)
		for (auto& el : initials)
			table->episode(el);

	fout.open("Resource Files/Data/QL/way.txt");
	if (fout.is_open())
	{
		for (size_t y = 0; y < map_size_x * map_size_y; y++)
		{
			for (size_t x = 0; x < map_size_x * map_size_y; x++)
				fout << table->Q[y][x] << ' ';
			fout << std::endl;
		}
		fout.close();
	}
	else System::Windows::Forms::MessageBox::Show("Error opening file \"way.txt\"");
}
