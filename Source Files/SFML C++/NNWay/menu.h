#pragma once

#include <SFML/Graphics.hpp>

#include <NEAT/Header Files/NEAT_Map.h>
#include <NEAT/Header Files/NEAT_Brain.h>
#include <NEAT/Header Files/NEAT_Logic.h>
#include <NEAT/Header Files/NEAT_Layers.h>
#include <NEAT/Header Files/NEAT_Population.h>

#include <Enums.h>

#include <QL/Header Files/QL_Map.h>
#include <QL/Header Files/QL_Table.h>
#include <QL/Header Files/QL_Logic.h>
#include <QL/Header Files/QL_Agent.h>

Pages page;
Modes mode;
Languages language;
Dimentions dimention;
LearningAlgorythms learning_algorithm;

std::string path;

sf::Font font;
sf::Sprite loading;
sf::Texture loading_texture;

int auto_exit, fps;
bool visualisation, auto_end, from_image, check_from_file;

namespace neat
{
	std::shared_ptr<Map> map;
	std::shared_ptr<Layers> layers;
	std::shared_ptr<Population> population;

	std::fstream fout, fin;
	std::string map_markup[80];
	std::vector<sf::Vector2f> pos;

	sf::RectangleShape rect;
	sf::CircleShape circle[2];
	sf::Text text[4], controls[3];
	sf::Vector2f goal_pos, dot_pos;

	float goal_radius;
	bool was_running, map_loaded;
	int direction_array_size, population_quantity, layers_quantity;
}

namespace ql
{
	std::shared_ptr<Map> map;
	std::shared_ptr<Table> table;
	std::shared_ptr<Agent> agent;

	sf::Text text[4];
	std::string image_path;
	std::fstream fout, fin;
	std::vector<int> initials;
	long long int finish_reward;
	bool was_running, map_loaded, finish_loaded;
	int map_size_x, map_size_y, width, height, finish_state, iterations;
}

namespace NNWay
{
	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;

	public ref class menu : public System::Windows::Forms::Form
	{
	public:
		menu(void)
		{
			InitializeVariables();
			InitializeComponent();
		}
	protected:
		~menu() { if (components) delete components; }
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ informationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ languageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ englishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ русскийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ modeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ learnToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ checkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dimensionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ learningAlgorithmToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nEATToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ qLearningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ howToUseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bugReportToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;

	private:
		System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->русскийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->modeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->learnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dimensionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->learningAlgorithmToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nEATToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->qLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->howToUseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bugReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(28, 28);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->settingsToolStripMenuItem,
					this->informationToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(501, 38);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->modeToolStripMenuItem, this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(105, 34);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->русскийToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// русскийToolStripMenuItem
			// 
			this->русскийToolStripMenuItem->Name = L"русскийToolStripMenuItem";
			this->русскийToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->русскийToolStripMenuItem->Text = L"Русский";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			// 
			// informationToolStripMenuItem
			// 
			this->informationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutToolStripMenuItem,
					this->howToUseToolStripMenuItem, this->bugReportToolStripMenuItem
			});
			this->informationToolStripMenuItem->Name = L"informationToolStripMenuItem";
			this->informationToolStripMenuItem->Size = System::Drawing::Size(140, 34);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(100, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 64);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Main menu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 32);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Language:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"English", L"Русский" });
			this->comboBox1->Location = System::Drawing::Point(344, 152);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(145, 32);
			this->comboBox1->TabIndex = 3;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Learn", L"Check" });
			this->comboBox2->Location = System::Drawing::Point(344, 190);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(145, 32);
			this->comboBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 190);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 32);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Mode:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"2D", L"3D" });
			this->comboBox3->Location = System::Drawing::Point(344, 228);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(145, 32);
			this->comboBox3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(158, 32);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Dimension:";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"NEAT", L"Q-Learning" });
			this->comboBox4->Location = System::Drawing::Point(344, 266);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(145, 32);
			this->comboBox4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 266);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(260, 32);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Learning algorithm:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(168, 333);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 34);
			this->button1->TabIndex = 10;
			this->button1->Text = L"&Go to";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 386);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeVariables(void)
		{
			page = Pages::MENU;
			mode = Modes::LEARN;
			language = Languages::EN;
			dimention = Dimentions::TWOD;
			learning_algorithm = LearningAlgorythms::NEAT;

			auto_exit = 10;
			neat::goal_radius = 10;
			neat::layers_quantity = 3;
			neat::population_quantity = 250;
			neat::direction_array_size = 400;

			ql::width = 800;
			ql::height = 800;
			ql::iterations = 3;
			ql::map_size_x = 10;
			ql::map_size_y = 10;
			ql::finish_reward = 100;

			auto_end = false;
			from_image = false;
			visualisation = false;
			check_from_file = false;
			ql::was_running = false;
			neat::was_running = false;
			ql::finish_loaded = false;

			loading_texture.loadFromFile("Resource Files/Textures/loading.png");
			loading.setOrigin(100, 25);
			loading.setPosition(400, 400);
			loading.setTexture(loading_texture);

			neat::circle[0].setRadius(neat::goal_radius);
			neat::circle[0].setFillColor(sf::Color::Red);
			neat::circle[0].setPosition(400, 400);

			neat::circle[1].setOrigin(4, 4);
			neat::circle[1].setFillColor(sf::Color::Black);
			neat::circle[1].setRadius(4.0f);
			neat::circle[1].setPosition(400, 300);

			neat::rect.setFillColor(sf::Color::Blue);
			neat::rect.setSize(sf::Vector2f(10, 10));

			font.loadFromFile("Resource Files/Fonts/arial.TTF");

			neat::text[0].setPosition(15, 10);
			neat::text[0].setString(L"Reached the goal: ");
			neat::text[1].setPosition(185, 10);
			neat::text[1].setString(L"No");
			neat::text[2].setPosition(15, 30);
			neat::text[2].setString(L"Gen: ");
			neat::text[3].setPosition(65, 30);
			neat::text[3].setString(L"0");

			for (int i = 0; i < 4; i++)
			{
				neat::text[i].setCharacterSize(20);
				neat::text[i].setFont(font);
				neat::text[i].setFillColor(sf::Color::Black);
				neat::text[i].setOutlineThickness(3);
				neat::text[i].setOutlineColor(sf::Color::White);
			}

			ql::text[0].setPosition(15, 10);
			ql::text[0].setString(L"Position: ");
			ql::text[1].setPosition(100, 10);
			ql::text[1].setString(L"0");
			ql::text[2].setPosition(15, 30);
			ql::text[2].setString(L"Iteration: ");
			ql::text[3].setPosition(100, 30);
			ql::text[3].setString(L"0");

			for (int i = 0; i < 4; i++)
			{
				ql::text[i].setCharacterSize(20);
				ql::text[i].setFont(font);
				ql::text[i].setFillColor(sf::Color::Black);
				ql::text[i].setOutlineThickness(3);
				ql::text[i].setOutlineColor(sf::Color::White);
			}

			neat::controls[0].setPosition(685, 10);
			neat::controls[0].setString(L"[Esc] - exit");
			neat::controls[1].setPosition(552, 10);
			neat::controls[1].setString(L"[Esc] - exit without saving\n[Enter] - save&exit");
			neat::controls[2].setPosition(612, 10);
			neat::controls[2].setString(L"[Alt] - move goal\n[LCtrl] - move object\n[Space] - fill around");

			for (int i = 0; i < 3; i++)
			{
				neat::controls[i].setCharacterSize(20);
				neat::controls[i].setFont(font);
				neat::controls[i].setFillColor(sf::Color::Black);
				neat::controls[i].setOutlineThickness(3);
				neat::controls[i].setOutlineColor(sf::Color::White);
			}
		}
		/*void ChooseInitializer(void)
		{
			if (mode == Modes::LEARN)
			{
				if (learning_algorithm == LearningAlgorythms::NEAT)
				{
					if (dimention == Dimentions::TWOD)
					{
						page = Pages::NEATLEARN2D;
						if (language == Languages::EN) InitializeComponentNEATLearn2DEN();
						else if (language == Languages::RU) InitializeComponentNEATLearn2DRU();
						
					}
					else if (dimention == Dimentions::THREED)
					{
						page = Pages::NEATLEARN3D;
						if (language == Languages::EN) InitializeComponentNEATLearn3DEN();
						else if (language == Languages::RU) InitializeComponentNEATLearn3DRU();
					}
				}
				else if (learning_algorithm == LearningAlgorythms::QL)
				{
					if (dimention == Dimentions::TWOD)
					{
						page = Pages::QLLEARN2D;
						if (language == Languages::EN) InitializeComponentQLLearn2DEN();
						else if (language == Languages::RU) InitializeComponentQLLearn2DRU();
					}
					else if (dimention == Dimentions::THREED)
					{
						page = Pages::QLLEARN3D;
						if (language == Languages::EN) InitializeComponentQLLearn3DEN();
						else if (language == Languages::RU) InitializeComponentQLLearn3DRU();
					}
				}
			}
			else if (mode == Modes::CHECK)
			{
				if (learning_algorithm == LearningAlgorythms::NEAT)
				{
					if (dimention == Dimentions::TWOD)
					{
						page = Pages::NEATCHECK2D;
						if (language == Languages::EN) InitializeComponentNEATCheck2DEN();
						else if (language == Languages::RU) InitializeComponentNEATCheck2DRU();
					}
					else if (dimention == Dimentions::THREED)
					{
						page = Pages::NEATCHECK3D;
						if (language == Languages::EN) InitializeComponentNEATCheck3DEN();
						else if (language == Languages::RU) InitializeComponentNEATCheck3DRU();
					}
				}
				else if (learning_algorithm == LearningAlgorythms::QL)
				{
					if (dimention == Dimentions::TWOD)
					{
						page = Pages::QLCHECK2D;
						if (language == Languages::EN) InitializeComponentQLCheck2DEN();
						else if (language == Languages::RU) InitializeComponentQLCheck2DRU();
					}
					else if (dimention == Dimentions::THREED)
					{
						page = Pages::QLCHECK3D;
						if (language == Languages::EN) InitializeComponentQLCheck3DEN();
						else if (language == Languages::RU) InitializeComponentQLCheck3DRU();
					}
				}
			}
		}*/
#pragma endregion

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (learning_algorithm == LearningAlgorythms::NEAT)
		{
			if (language == Languages::EN)
				MessageBox::Show("The algorithm works according to the following principle: when the program starts, each object randomly forms an array of directions, represented as positions for displacements formed from corners, the size of this array can also be adjusted. After that, each object starts moving in accordance with the elements of the direction array. The object ceases move as soon as it touches a user-defined area, for example, a building on a map, reaches a goal or when elements in an array of directions end (the number of ode). After this, the best object for further study is selected: the “value” of agents is compared and the object with the highest value is remembered as the best (the value is given by a certain formula, for example, for a given algorithm, the value is greater for that object, to the goal is less than the rest).", "About");
			else
				MessageBox::Show("Алгоритм работает по следующему принципу: при запуске программы каждый объект случайным образом формирует массив направлений, представленный в виде позиций для перемещений, образованных от углов, размер этого массива также можно регулировать.После этого каждый объект начинает движение в соответствии с элементами массива направлений.Объект перестает двигаться, как только касается заданной пользователем области, например, здание на карте, достигает цели или когда заканчиваются элементы в массиве направлений(заканчивается количество ходов).После этого происходит отбор лучшего объекта для дальнейшего обучения : сравнивается “ценность” объектов и объект с наибольшей ценностью запоминается как лучший(ценность задается по определенной формуле, так, например, для данного алгоритма, ценность больше у того объекта, расстояние у которого до цели меньше чем у остальных).");
		}
		else if (learning_algorithm == LearningAlgorythms::QL)
		{
			if (language == Languages::EN)
				MessageBox::Show("When the algorithm starts, an array R (stateXactions) is created, which shows where the agent can go and where not, as well as the location of the targets on the map (the numbering starts at 0 and runs horizontally in ascending order). After this, training takes place: a second array Q is created and filled with zeros. He needs to check any such state (after creating the first array R, an array of initial states is also created). As a result, all possible subsequent actions. After that, the second array with weights is filled in accordance with the formula. After the training is completed, the second array, the user can enter any initial state and get the shortest route.");
			else
				MessageBox::Show("При запуске алгоритма создается массив R (stateXactions), который показывает, где агент может проходить, а где нет, а также расположение целей на карте (нумерация начинается с 0 и идет горизонтально по возрастанию). После этого происходит обучение: создаётся второй массив Q и заполняется нулями. Ему необходимо проверить любое такое состояние (после создания первого массива R также создается массив начальных состояний). В результате все возможные последующие действия. После этого второй массив с весами заполняется в соответствии с формулой. После того, как обучение закончено, второй массив пользователь может ввести любое начальное состояние и получить кратчайший маршрут.");
		}
	}
};
}