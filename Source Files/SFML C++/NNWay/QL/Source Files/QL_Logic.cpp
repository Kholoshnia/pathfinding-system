#include <QL/Header Files/QL_Logic.h>

void ql::draw(sf::Event& event)
{
	if (event.type == event.KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			map->pos_walls_pop_back();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && !around)
		{
			around = true;
			map->fill_around();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			around = false;
			map->inc_map_size();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			around = false;
			map->dec_map_size();
		}
	}

	if (event.type == event.MouseMoved)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			if (event.mouseMove.x < (height / map_size.x) * map_size.x && event.mouseMove.y < (width / map_size.y) * map_size.y)
				map->pos_walls_push_back(event.mouseMove);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			map->set_goal_pos(event.mouseMove);
	}
}

void ql::check_2d()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Map");

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
				position = map_size.y * (event.mouseMove.y / (width / map_size.y)) + event.mouseMove.x / (width / map_size.x);
				moves.emplace_back(position);
				if (std::find(initials.begin(), initials.end(), position) != initials.end())
				{
					moves.emplace_back(position);
					while (true)
					{
						int best_action = table->inference_best_action(position);
						moves.emplace_back(best_action);
						if (best_action == goal_state) break;
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

void ql::check_3d()
{

}

void ql::create_new_map_2d()
{
	map.reset(new Map());

	sf::RenderWindow window(sf::VideoMode(width, height), "Map creator");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			draw(event);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				window.draw(loading);
				window.display();

				map->save();

				fout.open("Resource Files/Data/QL/input.csv");
				if (fout.is_open())
				{
					fout << "map-size:;" << map_size.x << ';' << map_size.y << std::endl;

					for (int y = 0; y < map_size.y; y++)
					{
						for (int x = 0; x < map_size.x; x++)
							fout << map->map_markup[y][x] << ';';
						fout << std::endl;
					}

					fout.close();

					map_loaded = true;
				}
				else
				{
					std::string message = "Error opening file: \"input.csv\"";
					System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
				}

				window.close();
			}
		}

		window.clear(sf::Color::White);

		map->show(window);
		window.display();
	}

	goal_reward = map_size.x * map_size.x * map_size.y * map_size.y;

	map_loaded = true;
}

void ql::create_new_map_3d()
{
	System::Windows::Forms::MessageBox::Show("Open \"Map Creator\" and start when you done creating new map and then load from file");
}

void ql::load_map_from_file_2d()
{
	map.reset(new Map());

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

	if (from_image)
	{
		sf::Image map_image;
		map_image.loadFromFile(image_path);
		for (int y = 0; y < map_size.y; y++)
			for (int x = 0; x < map_size.x; x++)
			{
				if (map_image.getPixel(x * (height / map_size.x), y * (width / map_size.y)) == sf::Color::Red && !goal_loaded)
				{
					map->map_markup[y][x] = 'G';
					goal_loaded = true;
				}
				else if (map_image.getPixel(x * (height / map_size.x), y * (width / map_size.y)) == sf::Color::Black)
					map->map_markup[y][x] = 'W';
				else
					map->map_markup[y][x] = 'S';
			}

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
			fin >> map_size.y;
			fin.get(ch);

			map->map_markup.resize(map_size.y);
			for (int y = 0; y < map_size.y; y++)
				map->map_markup[y].resize(map_size.x);

			std::string line;
			for (int y = 0; y < map_size.y; y++)
			{
				std::getline(fin, line);
				line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
				for (int x = 0; x < map_size.x; x++)
					map->map_markup[y][x] = line[x];
			}

			fin.close();

			map_loaded = true;
		}
		else
		{
			std::string message = "Error opening file \"" + path + "\"";
			System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
		}
	}
	table.reset(new Table());
	goal_reward = map_size.x * map_size.x * map_size.y * map_size.y;
}

void ql::load_map_from_file_3d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
}

void ql::load_result_from_file_2d()
{
	table.reset(new Table());

	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	
	fin.open(path);
	if (fin.is_open())
	{
		std::string line;
		for (int y = 0; y < map_size.y; y++)
		{
			std::getline(fin, line);
			line.erase(std::remove(line.begin(), line.end(), ';'), line.end());
			for (int x = 0; x < map_size.x; x++)
				table->R[y][x] = line[x];
		}
		fout.close();
	}
	else
	{
		std::string message = "Error opening file \"" + path + "\"";
		System::Windows::Forms::MessageBox::Show(gcnew System::String(message.c_str()));
	}
}

void ql::load_result_from_file_3d()
{

}

void ql::with_visualization_2d()
{
	table.reset(new Table());
	agent.reset(new Agent());

	sf::RenderWindow window(sf::VideoMode(width, height), "Map");

	int repetitions_k = 0, initials_k = 0;

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

		std::ostringstream repetitions_str;
		repetitions_str << repetitions_k;
		text[3].setString(repetitions_str.str());

		initials_k++;

		if (initials_k > initials.size() - 1)
		{
			initials_k = 0;
			repetitions_k++;
		}

		if (repetitions_k > repetitions)
		{
			fout.open("Resource Files/Data/QL/output.csv");
			if (fout.is_open())
			{
				for (int y = 0; y < map_size.x * map_size.y; y++)
				{
					for (int x = 0; x < map_size.x * map_size.y; x++)
						fout << table->Q[y][x] << ';';
					fout << std::endl;
				}
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file: \"output.csv\"");

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

void ql::with_visualization_3d()
{

}

void ql::without_visualization_2d()
{
	table.reset(new Table());
	agent.reset(new Agent());

	for (int i = 0; i < repetitions; i++)
		for (auto& el : initials)
			table->episode(el);

	fout.open("Resource Files/Data/QL/way.txt");
	if (fout.is_open())
	{
		for (int y = 0; y < map_size.x * map_size.y; y++)
		{
			for (int x = 0; x < map_size.x * map_size.y; x++)
				fout << table->Q[y][x] << ' ';
			fout << std::endl;
		}
		fout.close();
	}
	else System::Windows::Forms::MessageBox::Show("Error opening file \"way.txt\"");
}

void ql::without_visualization_3d()
{

}