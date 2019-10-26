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
			InitializeComponent();
			InitializeVariables();
		}
	protected:
		~menu() { if (components) delete components; }
	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox5;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::CheckBox^ checkBox1;
		System::Windows::Forms::CheckBox^ checkBox2;
		System::Windows::Forms::CheckBox^ checkBox4;
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem1;
		System::Windows::Forms::ToolStripMenuItem^ nEATToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ englishToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ русскийToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ languageToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ howToUseToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ dimensionToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ bugReportToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ qLearningToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ informationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ modeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ learnToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ checkToolStripMenuItem;
		   System::Windows::Forms::ToolStripMenuItem^ learningAlgorithmToolStripMenuItem;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dimensionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->русскийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->learningAlgorithmToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nEATToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->qLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->howToUseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bugReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->modeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->learnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->settingsToolStripMenuItem,
					this->informationToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(368, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->dimensionToolStripMenuItem,
					this->languageToolStripMenuItem, this->learningAlgorithmToolStripMenuItem, this->modeToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::DToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::DToolStripMenuItem1_Click);
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->русскийToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::EnglishToolStripMenuItem_Click);
			// 
			// русскийToolStripMenuItem
			// 
			this->русскийToolStripMenuItem->Name = L"русскийToolStripMenuItem";
			this->русскийToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->русскийToolStripMenuItem->Text = L"Русский";
			this->русскийToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::РусскийToolStripMenuItem_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::NEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::QLearningToolStripMenuItem_Click);
			// 
			// informationToolStripMenuItem
			// 
			this->informationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutToolStripMenuItem,
					this->howToUseToolStripMenuItem, this->bugReportToolStripMenuItem
			});
			this->informationToolStripMenuItem->Name = L"informationToolStripMenuItem";
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::AboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::HowToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(55, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(263, 39);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Main menu (NEAT)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Set direction array size:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(131, 19);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Map configuration:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 191);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 19);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Set number of objects:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 309);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"FPS:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(8, 236);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(146, 19);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Set number of layers:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label7->Location = System::Drawing::Point(12, 352);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Exit after:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(250, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 21);
			this->button1->TabIndex = 8;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &menu::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(250, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 21);
			this->button2->TabIndex = 9;
			this->button2->Text = L"&OK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &menu::Button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(250, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 21);
			this->button3->TabIndex = 10;
			this->button3->Text = L"&OK";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &menu::Button3_Click);
			// 
			// button4
			// 
			this->button4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button4->Location = System::Drawing::Point(188, 307);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 70);
			this->button4->TabIndex = 20;
			this->button4->Text = L"&Start";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &menu::Button4_Click);
			// 
			// button5
			// 
			this->button5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button5->Location = System::Drawing::Point(276, 307);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(70, 70);
			this->button5->TabIndex = 21;
			this->button5->Text = L"&Check";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &menu::Button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(250, 257);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(106, 21);
			this->button6->TabIndex = 24;
			this->button6->Text = L"&OK";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &menu::Button6_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 168);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"400";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::TextBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 213);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(232, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"250";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::TextBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(48, 306);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(50, 20);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"60";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::TextBox3_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(69, 349);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(50, 20);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"10";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::TextBox4_KeyPress);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 258);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(232, 20);
			this->textBox5->TabIndex = 23;
			this->textBox5->Text = L"3";
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::TextBox5_KeyPress);
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Load from file", L"Create new" });
			this->comboBox1->Location = System::Drawing::Point(12, 122);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(232, 21);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->Text = L"(Choose action)";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::ComboBox1_SelectedIndexChanged);
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::ComboBox1_KeyPress);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(15, 289);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(123, 17);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Graphic visualization";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &menu::CheckBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(15, 332);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(107, 17);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"Exit automatically";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &menu::CheckBox2_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(15, 375);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(96, 17);
			this->checkBox4->TabIndex = 26;
			this->checkBox4->Text = L"Check from file";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &menu::CheckBox4_CheckedChanged);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(368, 402);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NNWay";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeVariables(void)
		{
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
#pragma endregion
		System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == 0)
			{
				if (comboBox1->SelectedIndex == 0) neat::load_from_file();
				else if (comboBox1->SelectedIndex == 1) neat::create_new_map();
				else if (comboBox1->SelectedIndex == -1) language == Languages::EN ? MessageBox::Show("Please, select action") : MessageBox::Show("Пожалуйста, выберите дейсивте");
			}
			else
			{
				if (comboBox1->SelectedIndex == 0)
				{
					ql::load_from_file();

					if (from_image)
					{
						this->textBox2->Enabled = true;
						this->textBox5->Enabled = true;
					}
				}
				else if (comboBox1->SelectedIndex == 1) ql::create_new_map();
				else if (comboBox1->SelectedIndex == -1) language == Languages::EN ? MessageBox::Show("Please, select action") : MessageBox::Show("Пожалуйста, выберите дейсивте");
			}
		}
		System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == 0)
			{
				if (Convert::ToInt32(textBox1->Text) <= 0)
					language == Languages::EN ? MessageBox::Show("Error, incorrect number") : MessageBox::Show("Ошибка, неверное число");
				else
					neat::direction_array_size = Convert::ToInt32(textBox1->Text);
			}
			else
			{
				if (Convert::ToInt32(textBox1->Text) <= 0)
					language == Languages::EN ? MessageBox::Show("Error, incorrect number") : MessageBox::Show("Ошибка, неверное число");
				else
					ql::iterations = Convert::ToInt32(textBox1->Text);
			}
		}
		System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == 0)
			{
				if (Convert::ToInt32(textBox2->Text) <= 0)
					language == Languages::EN ? MessageBox::Show("Error, incorrect number") : MessageBox::Show("Ошибка, неверное число");
				else
					neat::population_quantity = Convert::ToInt32(textBox2->Text);
			}
			else
			{
				if (Convert::ToInt32(textBox2->Text) < 10 || Convert::ToInt32(textBox5->Text) < 10)
					language == Languages::EN ? MessageBox::Show("Error, incorrect number (< 10)") : MessageBox::Show("Ошибка, неверное число (< 10)");
				else
				{
					ql::map_size_x = Convert::ToInt32(textBox2->Text);
					ql::map_size_y = Convert::ToInt32(textBox5->Text);
				}

				ql::load_from_image();

				if (!ql::finish_loaded)
					language == Languages::EN ? MessageBox::Show("Error, finish coordinates not loaded, check file or change map size") : MessageBox::Show("Ошибка, координаты цели не загружены, проверьте файл или измените размер карты");
			}
		}
		System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e)
		{
			fps = Convert::ToInt32(textBox3->Text);

			if (learning_algorithm == 0)
			{
				neat::was_running = true;
				auto_exit = Convert::ToInt32(textBox4->Text);

				if (!neat::map_loaded)
					language == Languages::EN ? MessageBox::Show("Error, map not loaded") : MessageBox::Show("Ошибка, карта не загружена");
				else if (neat::layers_quantity <= 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong layers number") : MessageBox::Show("Ошибка, неверное число слоев");
				else if (neat::population_quantity <= 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong objects number") : MessageBox::Show("Ошибка, неверное число объектов");
				else if (neat::direction_array_size <= 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong direction array size") : MessageBox::Show("Ошибка, неверный размер массива направлений");
				else if (auto_end && auto_exit < 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong automatic exit number") : MessageBox::Show("Ошибка, неверное число ходов для автомачисеского завершения");
				else if (fps < 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong frames per second number") : MessageBox::Show("Ошибка, неверное число кадров в секунду");
				else if (comboBox1->SelectedIndex == -1)
					language == Languages::EN ? MessageBox::Show("Error, chose action with neat::map") : MessageBox::Show("Ошибка, выберете действие с картой");
				else if (visualisation)
					neat::with_visualization();
				else
					neat::without_visualization();
			}
			else
			{
				ql::was_running = true;

				if (!ql::map_loaded)
					language == Languages::EN ? MessageBox::Show("Error, map not loaded") : MessageBox::Show("Ошибка, карта не загружена");
				else if (ql::iterations <= 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong iterations number") : MessageBox::Show("Ошибка, неверное число повторений");
				else if (fps < 0)
					language == Languages::EN ? MessageBox::Show("Error, wrong frames per second number") : MessageBox::Show("Ошибка, неверное число кадров в секунду");
				else if (comboBox1->SelectedIndex == -1)
					language == Languages::EN ? MessageBox::Show("Error, chose action with neat::map") : MessageBox::Show("Ошибка, выберете действие с картой");
				else if (visualisation)
					ql::with_visualization();
				else
					ql::without_visualization();
			}
		}
		System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == 0)
			{
				if (check_from_file)
				{
					if (comboBox1->SelectedIndex == -1 || neat::map.get() == nullptr) language == Languages::EN ? MessageBox::Show("Please, load map") : MessageBox::Show("Пожалуйста, загрузите карту");
					else neat::check_from_file();
				}
				else
				{
					if (neat::was_running) neat::check();
					else language == Languages::EN ? MessageBox::Show("Error, the program has not started yet") : MessageBox::Show("Ошибка, программа еще не запускалась");
				}
			}
			else
			{
				if (check_from_file)
				{
					if (comboBox1->SelectedIndex == -1 || ql::map.get() == nullptr) language == Languages::EN ? MessageBox::Show("Please, load map") : MessageBox::Show("Пожалуйста, загрузите карту");
					else ql::check_from_file();
				}
				else
				{
					if (ql::was_running) ql::check();
					else language == Languages::EN ? MessageBox::Show("Error, the program has not started yet") : MessageBox::Show("Ошибка, программа еще не запускалась");
				}
			}
		}
		System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (Convert::ToInt32(textBox5->Text) <= 0)
				language == Languages::EN ? MessageBox::Show("Error, incorrect number") : MessageBox::Show("Ошибка, неверное число");
			else
				neat::layers_quantity = Convert::ToInt32(textBox5->Text);
		}
		System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			textBox3->ReadOnly = !textBox3->ReadOnly;
			visualisation = !visualisation;
		}
		System::Void CheckBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			textBox4->ReadOnly = !textBox4->ReadOnly;
			auto_end = !auto_end;
		}
		System::Void DToolStripMenuItem_Click(Object^ sender, EventArgs^ e) { dimention = Dimentions::TWOD; }
		System::Void DToolStripMenuItem1_Click(Object^ sender, EventArgs^ e) { dimention = Dimentions::THREED; }
		System::Void EnglishToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			language = Languages::EN;
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			this->languageToolStripMenuItem->Text = L"Language";
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			this->informationToolStripMenuItem->Text = L"Information";
			this->aboutToolStripMenuItem->Text = L"About";
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			if (learning_algorithm == 0)
			{
				this->label1->Text = L"Main menu (NEAT)";
				this->label1->Location = System::Drawing::Point(55, 40);
				this->label2->Text = L"Set direction array size:";
			}
			else
			{
				this->label1->Text = L"Main menu (QL)";
				this->label1->Location = System::Drawing::Point(75, 40);
				this->label2->Text = L"Set number of iterations:";
			}
			this->label3->Text = L"Map configuration:";
			this->label4->Text = L"Set number of objects:";
			this->label6->Text = L"Set number of layers:";
			this->textBox4->Location = System::Drawing::Point(69, 349);
			this->checkBox1->Text = L"Graphic visualization";
			this->label7->Text = L"Exit after:";
			this->checkBox2->Text = L"Exit automatically";
			this->button4->Text = L"&Start";
			this->button5->Text = L"&Check";
			comboBox1->Items->Clear();
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Load from file", L"Create new" });
			this->comboBox1->Text = L"(Choose action)";
			this->checkBox4->Text = L"Check from file";
			neat::text[0].setPosition(15, 10);
			neat::text[0].setString(L"Reached the goal: ");
			neat::text[1].setPosition(185, 10);
			neat::text[1].setString(L"No");
			neat::text[2].setPosition(15, 30);
			neat::text[2].setString(L"Gen: ");
			neat::text[3].setPosition(65, 30);
			neat::text[3].setString(L"0");
			neat::controls[0].setPosition(685, 10);
			neat::controls[0].setString(L"[Esc] - exit");
			neat::controls[1].setPosition(552, 10);
			neat::controls[1].setString(L"[Esc] - exit without saving\n[Enter] - save&exit");
			neat::controls[2].setPosition(612, 10);
			neat::controls[2].setString(L"[Alt] - move goal\n[LCtrl] - move object\n[Space] - fill around");
			ql::text[0].setPosition(15, 10);
			ql::text[0].setString(L"Position: ");
			ql::text[1].setPosition(100, 10);
			ql::text[1].setString(L"0");
			ql::text[2].setPosition(15, 30);
			ql::text[2].setString(L"Iteration: ");
			ql::text[3].setPosition(100, 30);
			ql::text[3].setString(L"0");
		}
		System::Void РусскийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			language = Languages::RU;
			this->settingsToolStripMenuItem->Text = L"Настройкии";
			this->dimensionToolStripMenuItem->Text = L"Изамерение";
			this->languageToolStripMenuItem->Text = L"Язык";
			this->learningAlgorithmToolStripMenuItem->Text = L"Алгоритм обучения";
			this->informationToolStripMenuItem->Text = L"Информация";
			this->aboutToolStripMenuItem->Text = L"О продукте";
			this->howToUseToolStripMenuItem->Text = L"Как пользоваться";
			this->bugReportToolStripMenuItem->Text = L"Сообщить об ошибке";
			if (learning_algorithm == 0)
			{
				this->label1->Text = L"Главное меню (NEAT)";
				this->label1->Location = System::Drawing::Point(30, 40);
				this->label2->Text = L"Установить размер массива направлений:";
			}
			else
			{
				this->label1->Text = L"Главное меню (QL)";
				this->label1->Location = System::Drawing::Point(50, 40);
				this->label2->Text = L"Установить количество повторений:";
			}
			this->label3->Text = L"Конфигурация карты:";
			this->label4->Text = L"Установить количество объектов:";
			this->label6->Text = L"Установить количество слоев:";
			this->textBox4->Location = System::Drawing::Point(114, 349);
			this->checkBox1->Text = L"Графическая визуализация";
			this->label7->Text = L"Закончить после:";
			this->checkBox2->Text = L"Закончить автоматически";
			this->button4->Text = L"&Начать";
			this->button5->Text = L"&Проверить";
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Загрузить из файла", L"Создать новую" });
			this->comboBox1->Text = L"(Выберете действие)";
			this->checkBox4->Text = L"Проверить из файла";
			neat::text[0].setPosition(15, 10);
			neat::text[0].setString(L"Достиг цели: ");
			neat::text[1].setPosition(140, 10);
			neat::text[1].setString(L"Нет");
			neat::text[2].setPosition(15, 30);
			neat::text[2].setString(L"Поколение: ");
			neat::text[3].setPosition(125, 30);
			neat::text[3].setString(L"0");
			neat::controls[0].setPosition(660, 10);
			neat::controls[0].setString(L"[Esc] - выход");
			neat::controls[1].setPosition(510, 10);
			neat::controls[1].setString(L"[Esc] - выход без сохранения\n[Enter] - сохранить&выйти");
			neat::controls[2].setPosition(535, 10);
			neat::controls[2].setString(L"[Alt] - перемещать цель\n[LCtrl] - пемещать объект\n[Space] - заполнить вокруг");
			ql::text[0].setPosition(15, 10);
			ql::text[0].setString(L"Позиция: ");
			ql::text[1].setPosition(105, 10);
			ql::text[1].setString(L"0");
			ql::text[2].setPosition(15, 30);
			ql::text[2].setString(L"Повторение: ");
			ql::text[3].setPosition(140, 30);
			ql::text[3].setString(L"0");

		}
		System::Void TextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		System::Void TextBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		System::Void TextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		System::Void TextBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		System::Void TextBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		System::Void ComboBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e)
		{
			if (learning_algorithm == 1)
			{
				this->textBox2->Enabled = false;
				this->textBox5->Enabled = false;
			}
			if (comboBox1->SelectedIndex == 0)
				language == Languages::EN ? button1->Text = L"Select" : button1->Text = L"Выбрать";
			else if (comboBox1->SelectedIndex == 1)
				language == Languages::EN ? button1->Text = L"Create" : button1->Text = L"Создать";
		}
		System::Void AboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == LearningAlgorythms::NEAT)
			{
				if (language == Languages::EN)
					MessageBox::Show("The algorithm works according to the following principle: when the program starts, each object randomly forms an array of directions, represented as positions for displacements formed from corners, the size of this array can also be adjusted. After that, each object starts moving in accordance with the elements of the direction array. The object ceases move as soon as it touches a user-defined area, for example, a building on a map, reaches a goal or when elements in an array of directions end (the number of ode). After this, the best object for further study is selected: the “value” of objects is compared and the object with the highest value is remembered as the best (the value is given by a certain formula, for example, for a given algorithm, the value is greater for that object, to the goal is less than the rest).");
				else
					MessageBox::Show("Алгоритм работает по следующему принципу : при запуске программы каждый объект случайным образом формирует массив направлений, представленный в виде позиций для перемещений, образованных от углов, размер этого массива также можно регулировать.После этого каждый объект начинает движение в соответствии с элементами массива направлений.Объект перестает двигаться, как только касается заданной пользователем области, например, здание на карте, достигает цели или когда заканчиваются элементы в массиве направлений(заканчивается количество ходов).После этого происходит отбор лучшего объекта для дальнейшего обучения : сравнивается “ценность” объектов и объект с наибольшей ценностью запоминается как лучший(ценность задается по определенной формуле, так, например, для данного алгоритма, ценность больше у того объекта, расстояние у которого до цели меньше чем у остальных).");
			}
			else if (learning_algorithm == LearningAlgorythms::QL)
			{
				if (language == Languages::EN)
					MessageBox::Show("When the algorithm starts, an array R (stateXactions) is created, which shows where the agent can go and where not, as well as the location of the targets on the map (the numbering starts at 0 and runs horizontally in ascending order). After this, training takes place: a second array Q is created and filled with zeros. He needs to check any such state (after creating the first array R, an array of initial states is also created). As a result, all possible subsequent actions. After that, the second array with weights is filled in accordance with the formula. After the training is completed, the second array, the user can enter any initial state and get the shortest route.");
				else
					MessageBox::Show("При запуске алгоритма создается массив R (stateXactions), который показывает, где агент может проходить, а где нет, а также расположение целей на карте (нумерация начинается с 0 и идет горизонтально по возрастанию). После этого происходит обучение: создаётся второй массив Q и заполняется нулями. Ему необходимо проверить любое такое состояние (после создания первого массива R также создается массив начальных состояний). В результате все возможные последующие действия. После этого второй массив с весами заполняется в соответствии с формулой. После того, как обучение закончено, второй массив пользователь может ввести любое начальное состояние и получить кратчайший маршрут.");
			}
		}
		System::Void HowToUseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (learning_algorithm == LearningAlgorythms::NEAT)
			{
				if (language == Languages::EN)
					MessageBox::Show("Before launching the program, the user needs to add a map of the terrain on which the route should be laid, after selecting the number of measurements (two-dimensional or three-dimensional map). The user can choose the speed of learning NA and, accordingly, the speed of obtaining the desired result. The learning rate is regulated by changing the number of objects (conditional agents) (the more objects, the higher the learning rate), but for this it is necessary to increase the computing power. The accuracy of training is governed by the number of layers (the more there are, the higher the accuracy of training), this also requires an increase in computing power.");
				else
					MessageBox::Show("Перед запуском программы пользователю необходимо добавить карту местности, на которой необходимо проложить маршрут, предварительно выбрав количество измерений (двухмерная или трехмерная карта). Пользователь может выбрать скорость обучения НС и соответственно быстроту получения желаемого результата. Скорость обучения регулируется посредством изменения количества объектов (условных нейронов) (чем больше объектов, тем выше скорость обучения), но для этого необходимо увеличивать и вычислительные мощности. Точность обучения регулируется количеством слоев (чем их больше, тем точность обучения выше), для этого также требуется увеличение вычислительной мощности.");
			}
			else if (learning_algorithm == LearningAlgorythms::QL)
			{
				if (language == Languages::EN)
					MessageBox::Show("Pre-selected number of measurements (two-dimensional or three-dimensional map). The user can select the learning speed. The learning speed is regulated by changing gamma parameters and changing the size of the map and changes in the number of iterations.");
				else
					MessageBox::Show("Перед запуском программы пользователю необходимо добавить карту местности, на которой необходимо проложить маршрут, предварительно выбрав количество измерений (двухмерная или трехмерная карта). Пользователь может выбрать скорость обучения НС и соответственно быстроту получения желаемого результата. Скорость обучения регулируется посредством изменения параметра gamma, изменения размера карты и изменения количества повторений.");
			}
		}
		System::Void ComboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = true; }
		System::Void BugReportToolStripMenuItem_Click(Object^ sender, EventArgs^ e) { MessageBox::Show("e-mail: vhd-ru@yandex.ru"); }
		System::Void NEATToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			mode = Modes::LEARN;
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

			this->Controls->Clear();
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->menuStrip1);
			this->textBox2->Location = System::Drawing::Point(12, 213);
			this->textBox2->Size = System::Drawing::Size(232, 20);
			this->textBox5->Location = System::Drawing::Point(12, 258);
			this->textBox5->Size = System::Drawing::Size(232, 20);
			this->textBox1->Text = L"400";
			this->textBox2->Text = L"250";
			this->textBox5->Text = L"3";
			this->textBox2->Enabled = true;
			this->textBox5->Enabled = true;
			this->checkBox2->Location = System::Drawing::Point(15, 332);
			if (language == Languages::EN)
			{
				this->label1->Text = L"Main menu (NEAT)";
				this->label1->Location = System::Drawing::Point(55, 40);
				this->label2->Text = L"Set direction array size:";
				this->label4->Text = L"Set number of objects:";
				this->checkBox2->Text = L"Exit automatically";
				this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			}
			else if (language == Languages::RU)
			{
				this->label1->Text = L"Главное меню (NEAT)";
				this->label1->Location = System::Drawing::Point(30, 40);
				this->label2->Text = L"Установить размер массива направлений:";
				this->label4->Text = L"Установить количество объектов:";
				this->checkBox2->Text = L"Закончить автоматически";
				this->learningAlgorithmToolStripMenuItem->Text = L"Алгоритм обучения";
			}
		}
		System::Void QLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			mode = Modes::LEARN;
			dimention = Dimentions::TWOD;
			learning_algorithm = LearningAlgorythms::QL;

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

			this->Controls->Clear();
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->menuStrip1);
			this->textBox2->Location = System::Drawing::Point(12, 213);
			this->textBox2->Size = System::Drawing::Size(110, 20);
			this->textBox5->Location = System::Drawing::Point(128, 213);
			this->textBox5->Size = System::Drawing::Size(110, 20);
			this->textBox1->Text = L"3";
			this->textBox2->Text = L"50";
			this->textBox5->Text = L"50";
			this->textBox2->Enabled = false;
			this->textBox5->Enabled = false;
			this->checkBox2->Location = System::Drawing::Point(249, 239);
			if (language == Languages::EN)
			{
				this->label1->Text = L"Main menu (QL)";
				this->label1->Location = System::Drawing::Point(75, 40);
				this->label2->Text = L"Set number of iterations:";
				this->label4->Text = L"Set number of fields (X and Y)";
				this->checkBox2->Text = L"From image";
			}
			else if (language == Languages::RU)
			{
				this->label1->Location = System::Drawing::Point(50, 40);
				this->label1->Text = L"Главное меню (QL)";
				this->label2->Text = L"Установить количество повторений:";
				this->label4->Text = L"Установить количество полей (X и Y)";
				this->checkBox2->Text = L"Из изображения";
			}
		}
		System::Void CheckBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { check_from_file = !check_from_file; }
		System::Void learnToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}
		System::Void checkToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}
	};
}