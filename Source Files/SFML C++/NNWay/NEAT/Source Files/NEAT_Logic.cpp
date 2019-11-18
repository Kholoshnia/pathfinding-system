#include <NEAT/Header Files/NEAT_Logic.h>

void neat::check_2d()
{
	std::vector<sf::Vector2f> check;
	population_quantity = 1;
	population.reset(new Population());

	sf::RenderWindow window(sf::VideoMode(800, 800), "Check");
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

		for (auto& check : check)
		{
			circle[1].setPosition(check);
			window.draw(circle[1]);
		}

		window.draw(controls[0]);
		window.display();
	}
}

void neat::check_3d()
{
	language == Languages::EN ? System::Windows::Forms::MessageBox::Show("Open \"NNWay3D\", enable \"cheker\" in main script (Goal object) and run") : System::Windows::Forms::MessageBox::Show("Откройте \"Map Creator\", включите \"cheker\" в галвном скрипте (объект Goal) и запустите");
}

void neat::create_new_map_2d()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Map creator");
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
				if (el == sf::Vector2f((float)x, (float)y))
					alreadyThere = true;
			if (!alreadyThere)
				pos.emplace_back(x, y);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			for (int i = 0; i < 80; i++)
			{
				pos.emplace_back(0, i);
				pos.emplace_back(79, i);
				pos.emplace_back(i, 0);
				pos.emplace_back(i, 79);
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && event.mouseMove.y > 1 && event.mouseMove.x > 1)
			circle[0].setPosition((float)event.mouseMove.x, (float)event.mouseMove.y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			circle[0].setRadius(circle[0].getRadius() + 0.1f);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circle[0].getRadius() > 0)
			circle[0].setRadius(circle[0].getRadius() - 0.1f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && event.mouseMove.y > 1 && event.mouseMove.x > 1 && event.mouseMove.y != 250 && event.mouseMove.x != 37)
			circle[1].setPosition((float)event.mouseMove.x, (float)event.mouseMove.y);

		dot_pos = sf::Vector2f(circle[1].getPosition().x / 10.0f, circle[1].getPosition().y / 10.0f);
		circle[1].setPosition(dot_pos.x * 10.0f, dot_pos.y * 10.0f);
		circle[0].setOrigin(sf::Vector2f(circle[0].getRadius(), circle[0].getRadius()));
		goal_pos = sf::Vector2f(circle[0].getPosition().x / 10.0f, circle[0].getPosition().y / 10.0f);
		circle[0].setPosition(goal_pos.x * 10.0f, goal_pos.y * 10.0f);

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

			fout.open("Resource Files/Data/NEAT/map.txt");
			if (fout.is_open())
			{
				bool alreadyThere = false;

				for (int i = 0; i < 80; i++)
				{
					for (int j = 0; j < 80; j++)
					{
						if (i == dot_pos.y && j == dot_pos.x)
							fout << '*';
						else if (i == goal_pos.y && j == goal_pos.x)
							fout << '0';
						else
						{
							for (int l = 0; l < pos.size(); l++)
							{
								if (i == pos[l].y && j == pos[l].x)
								{
									fout << '#';
									alreadyThere = true;
									break;
								}
								else alreadyThere = false;
							}
							if (!alreadyThere)
								fout << '.';
						}
					}
					fout << std::endl;
				}
				fout << circle[0].getRadius();
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"map.txt\"");
			fout.open("Resource Files/Data/NEAT/map.txt");

			map_loaded = true;

			if (fout.is_open())
			{
				for (int i = 0; i < 80; i++)
					fout >> map_markup[i];
				fout >> goal_radius;
				map.reset(new Map());
				fout.close();
				window.close();
				map_loaded = true;
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"map.txt\"");
		}
		window.draw(controls[2]);
		window.display();
	}
}

void neat::create_new_map_3d()
{
	language == Languages::EN ? System::Windows::Forms::MessageBox::Show("Open \"Map Creator\" and start when you done creating new map and then load from file") : System::Windows::Forms::MessageBox::Show("Откройте \"Map Creator\" и запустите, когда закончите создание новой карты и затем загрузите из файла");
}

void neat::load_map_from_file_2d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
	std::string str;
	for (int i = (int)path.length() - 1; i >= 0; i--)
		if (path[i] != '.')
			str += path[i];
		else
			break;
	if (str == "gnp" || str == "gepj") from_image = true;
	else from_image = false;
	str.clear();

	if (from_image)
	{
		sf::Image map_image;
		map_image.loadFromFile(path);
		for (unsigned int y = 0; y < 80; y++)
		{
			map_markup[y].resize(80);
			for (unsigned int x = 0; x < 80; x++)
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

		fout.open("Resource Files/Data/NEAT/map_image.txt");
		if (fout.is_open())
		{
			for (int i = 0; i < 80; i++)
				fout >> map_markup[i];
			fout >> goal_radius;
			map.reset(new Map());
			fout.close();
			map_loaded = true;
		}
		else System::Windows::Forms::MessageBox::Show("Error opening file \"map_image.txt\"");
	}
	else
	{
		fout.open(path);
		if (fout.is_open())
		{
			if (fout.is_open())
				for (int i = 0; i < 80; i++)
					fout >> map_markup[i];
			fout >> goal_radius;
			map.reset(new Map());
			fout.close();
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
		path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
}

void neat::load_result_from_file_2d()
{
	System::Windows::Forms::OpenFileDialog^ open_file_dialog = gcnew System::Windows::Forms::OpenFileDialog();
	if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open_file_dialog->InitialDirectory + open_file_dialog->FileName).ToPointer();
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

	sf::RenderWindow window(sf::VideoMode(800, 800), "Learning");
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

		layers->update();
		layers->show(window);

		if (layers->get_best_population().reached_the_goal) language == Languages::EN ? text[1].setString(L"Yes") : text[1].setString(L"Да");
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
		fout << '1' << std::endl << direction_array_size << std::endl << population_quantity << std::endl << layers_quantity << std::endl << auto_end << std::endl << auto_exit << std::endl << language;
		fout.close();
	}
	else
	{
		std::string message;
		language == Languages::EN ? message = "Error opening file \"" + path + "\"" : message = "Ошибка открытия файла \"" + path + "\"";
		System::String^ str = gcnew System::String(message.c_str());
		System::Windows::Forms::MessageBox::Show(str);
	}

	language == Languages::EN ? System::Windows::Forms::MessageBox::Show("Open \"NNWay3D\" and start with map file") : System::Windows::Forms::MessageBox::Show("Откройте \"NNWay3D\" и запустите с файлом карты");
}

void neat::without_visualization_2d()
{
	layers.reset(new Layers());
	bool calculating = true;

	while (calculating)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || (auto_end && layers->get_best_population().after_reach > auto_exit))
		{
			fout.open("Resource Files/Data/NEAT/way.txt");
			if (fout.is_open())
			{
				for (auto& el : layers->get_best_population().agents[layers->get_best_population().best_agent].brain.directions)
					fout << el.x << ' ' << el.y << std::endl;
				fout.close();
			}
			else System::Windows::Forms::MessageBox::Show("Error opening file \"way.txt\"");
		}

		layers->update();
	}
}

void neat::without_visualization_3d()
{
	fout.open(path, std::fstream::app);
	if (fout.is_open())
	{
		fout << '0' << std::endl << direction_array_size << std::endl << population_quantity << std::endl << layers_quantity << std::endl << auto_end << auto_exit << std::endl << language;
		fout.close();
	}
	else
	{
		std::string message;
		language == Languages::EN ? message = "Error opening file \"" + path + "\"" : message = "Ошибка открытия файла \"" + path + "\"";
		System::String^ str = gcnew System::String(message.c_str());
		System::Windows::Forms::MessageBox::Show(str);
	}
	language == Languages::EN ? System::Windows::Forms::MessageBox::Show("Open \"NNWay3D\" and start with map file") : System::Windows::Forms::MessageBox::Show("Откройте \"NNWay3D\" и запустите с файлом карты");
}