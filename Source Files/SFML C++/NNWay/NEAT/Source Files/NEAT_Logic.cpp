#include <NEAT/Header Files/NEAT_Logic.h>

void neat::check_2d()
{
	std::vector<sf::Vector2f> check;
	population_quantity = 1;
	population.reset(new Population());

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

		if (!population->agents[population->best_agent].reached_goal) check.emplace_back(population->agents[0].circle.getPosition());

		for (auto& el : check)
		{
			circle[1].setPosition(el);
			window.draw(circle[1]);
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

	sf::RenderWindow window(sf::VideoMode(width, height), "Map creator");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
		window.clear(sf::Color::White);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && pos.size() > 0)
			pos.pop_back();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
		{
			bool alreadyThere = false;
			int x = int(event.mouseMove.x / 10);
			int y = int(event.mouseMove.y / 10);
			for (auto& el : pos)
				if (el == sf::Vector2f(static_cast<float>(x), static_cast<float>(y)))
					alreadyThere = true;
			if (!alreadyThere)
				pos.emplace_back(x, y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			for (int x = 0; x < map_size.x; x++)
			{
				pos.emplace_back(0, x);
				pos.emplace_back(map_size.y - 1, x);
				pos.emplace_back(x, 0);
				pos.emplace_back(x, map_size.y - 1);
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
			circle[0].setPosition(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			circle[0].setRadius(circle[0].getRadius() + 0.1f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circle[0].getRadius() > 0)
			circle[0].setRadius(circle[0].getRadius() - 0.1f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			circle[1].setRadius(circle[1].getRadius() + 0.1f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && circle[1].getRadius() > 0)
			circle[1].setRadius(circle[1].getRadius() - 0.1f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.mouseMove.y > 1 && event.mouseMove.x > 1 && event.mouseMove.y != 250 && event.mouseMove.x != 37)
			circle[1].setPosition(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));

		pos_agent = sf::Vector2f(circle[1].getPosition().x / 10.0f, circle[1].getPosition().y / 10.0f);
		circle[1].setPosition(pos_agent.x * 10.0f, pos_agent.y * 10.0f);
		circle[1].setOrigin(sf::Vector2f(circle[1].getRadius(), circle[1].getRadius()));

		pos_goal = sf::Vector2f(circle[0].getPosition().x / 10.0f, circle[0].getPosition().y / 10.0f);
		circle[0].setPosition(pos_goal.x * 10.0f, pos_goal.y * 10.0f);
		circle[0].setOrigin(sf::Vector2f(circle[0].getRadius(), circle[0].getRadius()));

		for (auto& el : pos)
		{
			rect.setPosition(el.x * 10.0f, el.y * 10.0f);
			window.draw(rect);
		}

		for (int i = 0; i < 2; i++)
			window.draw(circle[i]);

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
						if (x == pos_agent.x && y == pos_agent.y)
							fout << '*';
						else if (x == pos_goal.x && y == pos_goal.y)
							fout << '0';
						else if ([&x, &y]
						{
							for (int l = 0; l < pos.size(); l++)
								if (x == pos[l].x && y == pos[l].y)
									return true;
							return false;
						}())
							fout << '#';
						else
							fout << '.';
						fout << ';';
					}
					fout << std::endl;
				}
				fout << "agent-radius:;" << circle[1].getRadius() << std::endl;
				fout << "goal-radius:;" << circle[0].getRadius() << std::endl;
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"input.csv\"");

			fin.open("Resource Files/Data/NEAT/input.csv");
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
				map.reset(new Map());
				fin.close();
				map_loaded = true;
				window.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file: \"input.csv\"");
		}
		window.draw(controls[2]);
		window.display();
	}
}

void neat::create_new_map_3d()
{
	switch (language)
	{
	case EN:
		System::Windows::Forms::MessageBox::Show("Open \"Map Creator\" and start when you done creating new map and then load from file");
		break;
	case RU:
		System::Windows::Forms::MessageBox::Show("Откройте \"Map Creator\" и запустите, когда закончите создание новой карты и затем загрузите из файла");
		break;
	default:
		break;
	}
}

void neat::load_map_from_file_2d()
{
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
			map_markup[y].resize(map_size.y);
			for (int x = 0; x < map_size.x; x++)
			{
				if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Black)
					map_markup[y][x] = '#';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Red)
					map_markup[y][x] = '0';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Blue)
					map_markup[y][x] = '*';
				else if (map_image.getPixel(x * 10u, y * 10u) == sf::Color::Yellow)
					map_markup[y][x] = 'b';
				else
					map_markup[y][x] = '.';
			}
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
			map.reset(new Map());
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
}

void neat::load_map_from_file_3d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
}

void neat::load_result_from_file_2d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = static_cast<char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer());
	fout.open(path);
	if (fout.is_open())
	{
		for (auto& directions : population->agents[population->best_agent].brain.directions)
			fout >> directions.x >> directions.y;
		fout.close();
	}
	else
	{
		std::string message;
		language == Languages::EN ? message = "Error opening file \"" + path + "\"" : message = "Ошибка открытия файла \"" + path + "\"";
		System::String^ str = gcnew System::String(message.c_str());
		System::Windows::Forms::MessageBox::Show(str);
	}
}

void neat::load_result_from_file_3d()
{

}

void neat::with_visualization_2d()
{
	layers.reset(new Layers());
	neat::direction_array_size = neat::map_size.x * neat::map_size.y / static_cast<int>(neat::layers->populations[0].agents[0].circle.getRadius());

	sf::RenderWindow window(sf::VideoMode(width, height), "Learning");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (auto_end && layers->get_best_population().after_reach > auto_exit))
		{
			window.draw(loading);
			window.display();

			fout.open("Resource Files/Data/NEAT/way.txt");
			if (fout.is_open())
			{
				for (auto& el : layers->get_best_population().agents[layers->get_best_population().best_agent].brain.directions)
					fout << el.x << ' ' << el.y << std::endl;
				fout.close();
				window.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"way.txt\"");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.clear(sf::Color::White);
		map->show(window);

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
		{
			bool alreadyThere = false;
			int x = int(event.mouseMove.x / 10);
			int y = int(event.mouseMove.y / 10);
			for (auto& el : pos)
				if (el == sf::Vector2f(static_cast<float>(x), static_cast<float>(y)))
					alreadyThere = true;
			if (!alreadyThere)
				pos.emplace_back(x, y);
		}*/

		layers->update();
		layers->show(window);

		if (layers->get_best_population().agents[layers->get_best_population().best_agent].reached_goal) language == Languages::EN ? text[1].setString(L"Yes") : text[1].setString(L"Да");
		else language == Languages::EN ? text[1].setString(L"No") : text[1].setString(L"Нет");

		std::ostringstream str;
		str << layers->get_best_population().gen;
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
	layers.reset(new Layers());
	bool calculating = true;

	while (calculating)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (auto_end && layers->get_best_population().after_reach > auto_exit))
		{
			calculating = false;

			fout.open("Resource Files/Data/NEAT/output.csv");
			if (fout.is_open())
			{
				for (auto& el : layers->get_best_population().agents[layers->get_best_population().best_agent].brain.directions)
					fout << el.x << ';' << el.y << std::endl;
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file: \"output.csv\"");
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