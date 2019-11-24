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
Dimensions dimension;
LearningAlgorythms learning_algorithm;

std::string path;

sf::Font font;
sf::Sprite loading;
sf::Texture loading_texture;

int fps, width, height;
bool visualization, from_image, check_from_file;

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
	sf::Vector2f goal_pos, pos_goal;
	sf::Vector2i map_size, wall_size;

	bool was_running, map_loaded, auto_end;
	float agent_radius, goal_radius, max_speed, mutation_rate;
	int direction_array_size, population_quantity, layers_quantity, auto_exit;
}

namespace ql
{
	std::shared_ptr<Map> map;
	std::shared_ptr<Table> table;
	std::shared_ptr<Agent> agent;

	float gamma;
	sf::Text text[4];
	sf::Vector2i map_size;
	std::string image_path;
	std::fstream fout, fin;
	std::vector<int> initials;
	long long int finish_reward;
	bool was_running, map_loaded, finish_loaded;
	int finish_state, iterations;
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
	protected:

#pragma region Create components
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ languageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ englishToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ðóññêèéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ modeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ learnToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ checkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dimensionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ learningAlgorithmToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nEATToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ qLearningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ informationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ howToUseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bugReportToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::ComboBox^ comboBox7;
	private: System::Windows::Forms::ComboBox^ comboBox8;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
private: System::Windows::Forms::TextBox^ textBox11;
private: System::Windows::Forms::Label^ label36;
private: System::Windows::Forms::TextBox^ textBox12;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::TextBox^ textBox13;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::TextBox^ textBox14;
private: System::Windows::Forms::Label^ label39;
	private: System::ComponentModel::Container^ components;
#pragma endregion

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(28, 28);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->settingsToolStripMenuItem,
					this->informationToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(623, 44);
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(150, 88);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 64);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Main menu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(18, 210);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Language:";
			// 
			// comboBox1
			// 
			this->comboBox1->DisplayMember = L"0";
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"English", L"Ðóññêèé" });
			this->comboBox1->Location = System::Drawing::Point(348, 205);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(254, 32);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox1_SelectedIndexChanged);
			this->comboBox1->SelectedIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Learn", L"Check" });
			this->comboBox2->Location = System::Drawing::Point(348, 254);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(254, 32);
			this->comboBox2->TabIndex = 5;
			this->comboBox2->Text = L"Choose action...";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(18, 259);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Mode:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"2D", L"3D" });
			this->comboBox3->Location = System::Drawing::Point(348, 303);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(254, 32);
			this->comboBox3->TabIndex = 7;
			this->comboBox3->Text = L"Choose action...";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox3_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(18, 308);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Dimension:";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"NEAT", L"Q-Learning" });
			this->comboBox4->Location = System::Drawing::Point(348, 352);
			this->comboBox4->Margin = System::Windows::Forms::Padding(4);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(254, 32);
			this->comboBox4->TabIndex = 9;
			this->comboBox4->Text = L"Choose action...";
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox4_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(18, 357);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(178, 25);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Learning algorithm:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(245, 525);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 52);
			this->button1->TabIndex = 10;
			this->button1->Text = L"&Go to";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &menu::button1_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(623, 632);
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
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeComponentNEAT2DLearn(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(28, 9, 0, 9);
			this->menuStrip1->Size = System::Drawing::Size(623, 52);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Blue;
			this->label6->Location = System::Drawing::Point(79, 88);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(452, 64);
			this->label6->TabIndex = 1;
			this->label6->Text = L"NEAT, 2D, Learn";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 210);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(173, 25);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Map configuration:";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox5->Location = System::Drawing::Point(348, 205);
			this->comboBox5->Margin = System::Windows::Forms::Padding(4);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(254, 32);
			this->comboBox5->TabIndex = 3;
			this->comboBox5->Text = L"Choose action...";
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox5_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(19, 259);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(172, 25);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Number of agents:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(19, 308);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(165, 25);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Number of layers:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(348, 254);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(254, 29);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"250";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(348, 305);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(254, 29);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"5";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox3_KeyPress);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(19, 357);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(258, 25);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Maximum movement speed:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(348, 354);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(254, 29);
			this->textBox4->TabIndex = 11;
			this->textBox4->Text = L"5";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox4_KeyPress);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(245, 525);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(131, 52);
			this->button2->TabIndex = 12;
			this->button2->Text = L"&Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &menu::button2_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(348, 452);
			this->textBox11->Margin = System::Windows::Forms::Padding(4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(254, 29);
			this->textBox11->TabIndex = 14;
			this->textBox11->Text = L"100";
			this->textBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox11_KeyPress);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(20, 455);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(158, 25);
			this->label36->TabIndex = 13;
			this->label36->Text = L"Auto ñompletion:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(348, 403);
			this->textBox13->Margin = System::Windows::Forms::Padding(4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(254, 29);
			this->textBox13->TabIndex = 16;
			this->textBox13->Text = L"0,01";
			this->textBox13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox13_KeyPress);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(20, 406);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(131, 25);
			this->label38->TabIndex = 15;
			this->label38->Text = L"Mutation rate:";
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(623, 632);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentNEAT3DLearn(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(28, 9, 0, 9);
			this->menuStrip1->Size = System::Drawing::Size(623, 52);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Blue;
			this->label8->Location = System::Drawing::Point(79, 88);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(452, 64);
			this->label8->TabIndex = 1;
			this->label8->Text = L"NEAT, 3D, Learn";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(19, 210);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(173, 25);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Map configuration:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(19, 259);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(172, 25);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Number of agents:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(19, 308);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(165, 25);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Number of layers:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(19, 357);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(258, 25);
			this->label15->TabIndex = 10;
			this->label15->Text = L"Maximum movement speed:";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox6->Location = System::Drawing::Point(346, 205);
			this->comboBox6->Margin = System::Windows::Forms::Padding(4);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(254, 32);
			this->comboBox6->TabIndex = 3;
			this->comboBox6->Text = L"Choose action...";
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox6_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(346, 352);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 29);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(346, 254);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(254, 29);
			this->textBox5->TabIndex = 8;
			this->textBox5->Text = L"250";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(346, 303);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(254, 29);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"5";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(245, 525);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(131, 52);
			this->button3->TabIndex = 12;
			this->button3->Text = L"&Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &menu::button3_Click);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(346, 452);
			this->textBox12->Margin = System::Windows::Forms::Padding(4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(254, 29);
			this->textBox12->TabIndex = 14;
			this->textBox12->Text = L"100";
			this->textBox12->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox12_KeyPress);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(21, 455);
			this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(158, 25);
			this->label37->TabIndex = 13;
			this->label37->Text = L"Auto ñompletion:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(346, 403);
			this->textBox14->Margin = System::Windows::Forms::Padding(4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(254, 29);
			this->textBox14->TabIndex = 16;
			this->textBox14->Text = L"0,01";
			this->textBox14->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox14_KeyPress);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(21, 406);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(131, 25);
			this->label39->TabIndex = 15;
			this->label39->Text = L"Mutation rate:";
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(623, 632);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentNEAT2DCheck(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(623, 44);
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
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
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
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
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
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
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->ForeColor = System::Drawing::Color::Blue;
			this->label24->Location = System::Drawing::Point(42, 50);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(271, 37);
			this->label24->TabIndex = 1;
			this->label24->Text = L"NEAT, 2D, Check";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(12, 120);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(96, 13);
			this->label25->TabIndex = 2;
			this->label25->Text = L"Lead map from file:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(12, 148);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(101, 13);
			this->label26->TabIndex = 3;
			this->label26->Text = L"Load result from file:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(197, 116);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(147, 21);
			this->button6->TabIndex = 4;
			this->button6->Text = L"&Load";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &menu::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(197, 144);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(147, 21);
			this->button7->TabIndex = 5;
			this->button7->Text = L"&Load";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &menu::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(140, 300);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 30);
			this->button8->TabIndex = 6;
			this->button8->Text = L"&Check";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &menu::button8_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentNEAT3DCheck(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(623, 44);
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
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
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
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
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
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
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label27->ForeColor = System::Drawing::Color::Blue;
			this->label27->Location = System::Drawing::Point(42, 50);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(271, 37);
			this->label27->TabIndex = 1;
			this->label27->Text = L"NEAT, 3D, Check";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(12, 120);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(96, 13);
			this->label28->TabIndex = 2;
			this->label28->Text = L"Lead map from file:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(12, 148);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(101, 13);
			this->label29->TabIndex = 3;
			this->label29->Text = L"Load result from file:";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(197, 116);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(147, 21);
			this->button9->TabIndex = 4;
			this->button9->Text = L"&Load";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &menu::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(197, 144);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(147, 21);
			this->button10->TabIndex = 5;
			this->button10->Text = L"&Load";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &menu::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(140, 300);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 30);
			this->button11->TabIndex = 6;
			this->button11->Text = L"&Check";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &menu::button11_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeComponentQL2DLearn(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(28, 9, 0, 9);
			this->menuStrip1->Size = System::Drawing::Size(623, 52);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::Blue;
			this->label16->Location = System::Drawing::Point(19, 88);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(585, 64);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Q-Learning, 2D, Learn";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(19, 259);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(87, 25);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Gamma:";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox7->Location = System::Drawing::Point(350, 205);
			this->comboBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(254, 32);
			this->comboBox7->TabIndex = 3;
			this->comboBox7->Text = L"Choose action...";
			this->comboBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox7_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(245, 525);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(131, 52);
			this->button4->TabIndex = 12;
			this->button4->Text = L"&Start";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &menu::button4_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(350, 254);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(254, 29);
			this->textBox7->TabIndex = 13;
			this->textBox7->Text = L"0.8";
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox7_KeyPress);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(19, 210);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(173, 25);
			this->label17->TabIndex = 14;
			this->label17->Text = L"Map configuration:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(350, 303);
			this->textBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(254, 29);
			this->textBox10->TabIndex = 16;
			this->textBox10->Text = L"5";
			this->textBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox10_KeyPress);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(19, 308);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(191, 25);
			this->label23->TabIndex = 15;
			this->label23->Text = L"Number of iterations:";
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(623, 632);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->comboBox7);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentQL3DLearn(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
			// 
			// dimensionToolStripMenuItem
			// 
			this->dimensionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->dToolStripMenuItem,
					this->dToolStripMenuItem1
			});
			this->dimensionToolStripMenuItem->Name = L"dimensionToolStripMenuItem";
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
			// 
			// learningAlgorithmToolStripMenuItem
			// 
			this->learningAlgorithmToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->nEATToolStripMenuItem,
					this->qLearningToolStripMenuItem
			});
			this->learningAlgorithmToolStripMenuItem->Name = L"learningAlgorithmToolStripMenuItem";
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(306, 40);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(235, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(28, 9, 0, 9);
			this->menuStrip1->Size = System::Drawing::Size(623, 52);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->ForeColor = System::Drawing::Color::Blue;
			this->label22->Location = System::Drawing::Point(19, 88);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(585, 64);
			this->label22->TabIndex = 1;
			this->label22->Text = L"Q-Learning, 2D, Learn";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(19, 259);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(87, 25);
			this->label21->TabIndex = 5;
			this->label21->Text = L"Gamma:";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox8->Location = System::Drawing::Point(350, 205);
			this->comboBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(254, 32);
			this->comboBox8->TabIndex = 3;
			this->comboBox8->Text = L"Choose action...";
			this->comboBox8->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox7_SelectedIndexChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(245, 525);
			this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(131, 52);
			this->button5->TabIndex = 12;
			this->button5->Text = L"&Start";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &menu::button4_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(350, 254);
			this->textBox9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(254, 29);
			this->textBox9->TabIndex = 13;
			this->textBox9->Text = L"0.8";
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox7_KeyPress);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(19, 210);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(173, 25);
			this->label20->TabIndex = 14;
			this->label20->Text = L"Map configuration:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(350, 303);
			this->textBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(254, 29);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"5";
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox10_KeyPress);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(19, 308);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(191, 25);
			this->label19->TabIndex = 15;
			this->label19->Text = L"Number of iterations:";
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(168, 168);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(623, 632);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->comboBox8);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentQL2DCheck(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(623, 44);
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
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
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
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
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
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
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->ForeColor = System::Drawing::Color::Blue;
			this->label30->Location = System::Drawing::Point(6, 50);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(344, 37);
			this->label30->TabIndex = 1;
			this->label30->Text = L"Q-Learning, 2D, Check";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(12, 120);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(96, 13);
			this->label31->TabIndex = 2;
			this->label31->Text = L"Lead map from file:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(12, 148);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(101, 13);
			this->label32->TabIndex = 3;
			this->label32->Text = L"Load result from file:";
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(197, 116);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(147, 21);
			this->button12->TabIndex = 4;
			this->button12->Text = L"&Load";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &menu::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(197, 144);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(147, 21);
			this->button13->TabIndex = 5;
			this->button13->Text = L"&Load";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &menu::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(140, 300);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 30);
			this->button14->TabIndex = 6;
			this->button14->Text = L"&Check";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &menu::button14_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeComponentQL3DCheck(void)
		{
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->languageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->englishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ðóññêèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(16, 5, 0, 5);
			this->menuStrip1->Size = System::Drawing::Size(623, 44);
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
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->englishToolStripMenuItem->Text = L"English";
			this->englishToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::englishToolStripMenuItem_Click);
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(207, 40);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
			this->ðóññêèéToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::ðóññêèéToolStripMenuItem_Click);
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
			this->learnToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(187, 40);
			this->checkToolStripMenuItem->Text = L"Check";
			this->checkToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::checkToolStripMenuItem_Click);
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
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(157, 40);
			this->dToolStripMenuItem1->Text = L"3D";
			this->dToolStripMenuItem1->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem1_Click);
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
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(315, 40);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
			this->qLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::qLearningToolStripMenuItem_Click);
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
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(236, 40);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->ForeColor = System::Drawing::Color::Blue;
			this->label33->Location = System::Drawing::Point(6, 50);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(344, 37);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Q-Learning, 3D, Check";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(12, 120);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(96, 13);
			this->label34->TabIndex = 2;
			this->label34->Text = L"Lead map from file:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(12, 148);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(101, 13);
			this->label35->TabIndex = 3;
			this->label35->Text = L"Load result from file:";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(197, 116);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(147, 21);
			this->button15->TabIndex = 4;
			this->button15->Text = L"&Load";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &menu::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(197, 144);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(147, 21);
			this->button16->TabIndex = 5;
			this->button16->Text = L"&Load";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &menu::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(140, 300);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 30);
			this->button17->TabIndex = 6;
			this->button17->Text = L"&Check";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &menu::button17_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
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
			mode = Modes::LEARN;
			language = Languages::EN;
			dimension = Dimensions::TWOD;
			learning_algorithm = LearningAlgorythms::NEAT;

			width = 800;
			height = 800;
			from_image = false;
			visualization = false;
			check_from_file = false;

			neat::max_speed = 5;
			neat::auto_exit = 10;
			neat::goal_radius = 10;
			neat::layers_quantity = 3;
			neat::mutation_rate = 0.01f;
			neat::population_quantity = 250;
			neat::direction_array_size = 400;

			neat::auto_end = false;
			neat::was_running = false;

			ql::gamma = 0.8f;
			ql::iterations = 5;
			ql::map_size.x = 10;
			ql::map_size.y = 10;
			ql::finish_reward = 100;

			ql::was_running = false;
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
		void ChooseInitializer(void)
		{
			this->Controls->Clear();
			if (mode == Modes::LEARN)
			{
				if (learning_algorithm == LearningAlgorythms::NEAT)
				{
					if (dimension == Dimensions::TWOD)
						InitializeComponentNEAT2DLearn();
					else if (dimension == Dimensions::THREED)
						InitializeComponentNEAT3DLearn();
				}
				else if (learning_algorithm == LearningAlgorythms::QL)
				{
					if (dimension == Dimensions::TWOD)
						InitializeComponentQL2DLearn();
					else if (dimension == Dimensions::THREED)
						InitializeComponentQL3DLearn();
				}
			}
			else if (mode == Modes::CHECK)
			{
				if (learning_algorithm == LearningAlgorythms::NEAT)
				{
					if (dimension == Dimensions::TWOD)
						InitializeComponentNEAT2DCheck();
					else if (dimension == Dimensions::THREED)
						InitializeComponentNEAT2DCheck();
				}
				else if (learning_algorithm == LearningAlgorythms::QL)
				{
					if (dimension == Dimensions::TWOD)
						InitializeComponentQL2DCheck();
					else if (dimension == Dimensions::THREED)
						InitializeComponentQL2DCheck();
				}
			}
		}
#pragma endregion

#pragma region Tool strip menu actions
	private: System::Void englishToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void ðóññêèéToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void learnToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		mode = Modes::LEARN;
		ChooseInitializer();
	}
	private: System::Void checkToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		mode = Modes::CHECK;
		ChooseInitializer();
	}
	private: System::Void dToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		dimension = Dimensions::TWOD;
		ChooseInitializer();
	}
	private: System::Void dToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		dimension = Dimensions::THREED;
		ChooseInitializer();
	}
	private: System::Void nEATToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		learning_algorithm = LearningAlgorythms::NEAT;
		ChooseInitializer();
	}
	private: System::Void qLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		learning_algorithm = LearningAlgorythms::QL;
		ChooseInitializer();
	}
	private: System::Void nEATToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		learning_algorithm = LearningAlgorythms::QL;
		ChooseInitializer();
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void howToUseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void bugReportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
#pragma endregion

#pragma region Main menu actions
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox2->SelectedIndex)
		{
		case 0:
			mode = Modes::LEARN;
			break;
		case 1:
			mode = Modes::CHECK;
		default:
			break;
		}
	}
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox3->SelectedIndex)
		{
		case 0:
			dimension = Dimensions::TWOD;
			break;
		case 1:
			dimension = Dimensions::THREED;
		default:
			break;
		}
	}
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox4->SelectedIndex)
		{
		case 0:
			learning_algorithm = LearningAlgorythms::NEAT;
			break;
		case 1:
			learning_algorithm = LearningAlgorythms::QL;
		default:
			break;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (comboBox1->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (comboBox2->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (comboBox3->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (comboBox4->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else
			ChooseInitializer();
	}
#pragma endregion

#pragma region NEAT, 2D, Learn actions
	private: System::Void comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox5->SelectedIndex)
		{
		case 0:
			neat::create_new_map_2d();
			break;
		case 1:
			neat::load_map_from_file_2d();
			break;
		default:
			break;
		}
	}
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox11_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox13_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08; }
	private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::population_quantity = Convert::ToInt32(textBox2->Text);
		neat::layers_quantity = Convert::ToInt32(textBox3->Text);
		neat::max_speed = Convert::ToSingle(textBox4->Text);
		try { neat::mutation_rate = Convert::ToSingle(textBox13->Text); }
		catch (System::FormatException^ ex)
		{
			Windows::Forms::MessageBox::Show(ex->Message);
			return;
		}
		neat::auto_exit = Convert::ToInt32(textBox11->Text);

		if (comboBox5->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (neat::population_quantity == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::layers_quantity == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::max_speed == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::mutation_rate == 0)
			Windows::Forms::MessageBox::Show("");
		else
			neat::with_visualization_2d();
	}
#pragma endregion

#pragma region NEAT, 3D, Learn actions
	private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox6->SelectedIndex)
		{
		case 0:
			neat::create_new_map_3d();
			break;
		case 1:
			neat::load_map_from_file_3d();
			break;
		default:
			break;
		}
	}
	private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox12_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox14_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08; }
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::population_quantity = Convert::ToInt32(textBox2->Text);
		neat::layers_quantity = Convert::ToInt32(textBox3->Text);
		neat::max_speed = Convert::ToSingle(textBox12->Text);
		try { neat::mutation_rate = Convert::ToSingle(textBox14->Text); }
		catch (System::FormatException ^ ex)
		{
			Windows::Forms::MessageBox::Show(ex->Message);
			return;
		}
		neat::auto_exit = Convert::ToInt32(textBox4->Text);

		if (comboBox5->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (neat::population_quantity == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::layers_quantity == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::max_speed == 0)
			Windows::Forms::MessageBox::Show("");
		else if (neat::mutation_rate == 0)
			Windows::Forms::MessageBox::Show("");
		else
			neat::with_visualization_3d();
	}
#pragma endregion

#pragma region NEAT, 2D, Check actions
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { neat::load_map_from_file_2d(); }
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { neat::load_result_from_file_2d(); }
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { neat::check_2d(); }
#pragma endregion

#pragma region NEAT, 3D, Check actions
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { neat::load_map_from_file_3d(); }
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) { neat::load_result_from_file_3d(); }
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { neat::check_3d(); }
#pragma endregion

#pragma region QL, 2D, Learn actions
	private: System::Void textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox10_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void comboBox7_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox7->SelectedIndex)
		{
		case 0:
			ql::create_new_map_2d();
			break;
		case 1:
			ql::load_map_from_file_2d();
			break;
		default:
			break;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::gamma = Convert::ToSingle(textBox7->Text);
		ql::iterations = Convert::ToInt32(textBox10->Text);

		if (comboBox7->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (ql::gamma == 0 || ql::gamma > 1)
			Windows::Forms::MessageBox::Show("");
		else if (ql::iterations == 0)
			Windows::Forms::MessageBox::Show("");
		else
			neat::with_visualization_2d();
	}
#pragma endregion

#pragma region QL, 3D, Learn actions
	private: System::Void textBox8_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox9_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void comboBox8_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		switch (comboBox8->SelectedIndex)
		{
		case 0:
			ql::create_new_map_3d();
			break;
		case 1:
			ql::load_map_from_file_3d();
			break;
		default:
			break;
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::gamma = Convert::ToSingle(textBox7->Text);
		ql::iterations = Convert::ToInt32(textBox10->Text);

		if (comboBox7->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("");
		else if (ql::gamma == 0 || ql::gamma > 1)
			Windows::Forms::MessageBox::Show("");
		else if (ql::iterations == 0)
			Windows::Forms::MessageBox::Show("");
		else
			neat::with_visualization_3d();
	}
#pragma endregion

#pragma region QL, 2D, Check actions
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { ql::load_map_from_file_2d(); }
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) { ql::load_result_from_file_2d(); }
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { ql::check_2d(); }
#pragma endregion

#pragma region QL, 3D, Check actions
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) { ql::load_map_from_file_2d(); }
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) { ql::load_result_from_file_2d(); }
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) { ql::check_2d(); }
#pragma endregion
	};
}