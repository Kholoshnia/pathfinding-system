#pragma once

#include <Windows.h>
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

#pragma region variables
Modes mode;
Dimensions dimension;
LearningAlgorythms learning_algorithm;

std::string path;

sf::Font font;
sf::Sprite loading;
sf::Texture loading_texture;
std::string path_input, path_output;

int fps, width, height;
bool from_image, check_from_file, map_loaded, result_loaded, output_path_set, pause, show_controls;

namespace neat
{
	VisualizationTypes visualization_type;

	std::shared_ptr<Map> map;
	std::shared_ptr<Layers> layers;
	std::shared_ptr<Population> population;

	std::fstream fout, fin;
	std::vector<sf::Vector2f> pos;
	std::vector<std::string> map_markup;

	sf::RectangleShape rect;
	sf::Text text[4], controls[3];
	sf::Vector2i map_size, wall_size, pos_agent, pos_goal;

	bool was_running, around;
	float agent_radius, goal_radius, max_speed, mutation_rate;
	int directions_array_size, population_quantity, layers_quantity, auto_exit;
}

namespace ql
{
	VisualizationTypes visualization_type;

	std::shared_ptr<Map> map;
	std::shared_ptr<Table> table;
	std::shared_ptr<Agent> agent;

	float gamma, thickness;
	std::vector<std::vector<char>> map_markup;
	std::vector<std::vector<long long int>> temp_Q;

	sf::Vector2i map_size;
	std::string image_path;
	std::fstream fout, fin;
	std::vector<int> initials;
	long long int goal_reward;
	sf::Text text[4], controls[3];
	int goal_state, iterations, repetitions;
	bool was_running, goal_loaded, show_controls, around;
}
#pragma endregion

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
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ label47;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::ComboBox^ comboBox7;
	private: System::Windows::Forms::ComboBox^ comboBox8;
	private: System::Windows::Forms::ComboBox^ comboBox9;
	private: System::Windows::Forms::ComboBox^ comboBox10;
	private: System::Windows::Forms::ComboBox^ comboBox11;

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
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::Label^ label48;
private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::Button^ button18;
private: System::Windows::Forms::Label^ label49;
private: System::Windows::Forms::Button^ button19;
private: System::Windows::Forms::CheckBox^ checkBox2;
private: System::Windows::Forms::CheckBox^ checkBox3;
private: System::Windows::Forms::CheckBox^ checkBox4;
private: System::Windows::Forms::CheckBox^ checkBox5;
private: System::Windows::Forms::CheckBox^ checkBox6;
private: System::Windows::Forms::Label^ label50;
private: System::Windows::Forms::Button^ button20;
private: System::Windows::Forms::CheckBox^ checkBox7;
private: System::Windows::Forms::Label^ label51;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::CheckBox^ checkBox8;
private: System::Windows::Forms::CheckBox^ checkBox9;
private: System::Windows::Forms::CheckBox^ checkBox10;
private: System::Windows::Forms::CheckBox^ checkBox11;
private: System::Windows::Forms::CheckBox^ checkBox12;

	private: System::ComponentModel::Container^ components;
#pragma endregion

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(356, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(86, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 37);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Main menu";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(10, 120);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 2;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Learn", L"Check" });
			this->comboBox2->Location = System::Drawing::Point(199, 118);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(147, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->Text = L"Choose action...";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 120);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Mode:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"2D", L"3D" });
			this->comboBox3->Location = System::Drawing::Point(199, 146);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(147, 21);
			this->comboBox3->TabIndex = 6;
			this->comboBox3->Text = L"Choose action...";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox3_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(10, 148);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Dimension:";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"NEAT", L"Q-Learning" });
			this->comboBox4->Location = System::Drawing::Point(199, 174);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(147, 21);
			this->comboBox4->TabIndex = 8;
			this->comboBox4->Text = L"Choose action...";
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox4_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(10, 176);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Learning algorithm:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 380);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 10;
			this->button1->Text = L"&Go to";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &menu::button1_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(356, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Blue;
			this->label6->Location = System::Drawing::Point(45, 50);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(263, 37);
			this->label6->TabIndex = 11;
			this->label6->Text = L"NEAT, 2D, Learn";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 120);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Map configuration:";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox5->Location = System::Drawing::Point(199, 117);
			this->comboBox5->Margin = System::Windows::Forms::Padding(2);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(147, 21);
			this->comboBox5->TabIndex = 13;
			this->comboBox5->Text = L"Choose action...";
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox5_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(11, 176);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(94, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Number of agents:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(11, 204);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Number of layers:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(199, 173);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 16;
			this->textBox2->Text = L"250";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(199, 202);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(147, 20);
			this->textBox3->TabIndex = 17;
			this->textBox3->Text = L"5";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox3_KeyPress);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(11, 232);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(138, 13);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Maximum movement speed:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(199, 230);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(147, 20);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"5";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox4_KeyPress);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 380);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 30);
			this->button2->TabIndex = 20;
			this->button2->Text = L"&Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &menu::button2_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(199, 314);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(147, 20);
			this->textBox11->TabIndex = 21;
			this->textBox11->Text = L"100";
			this->textBox11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox11_KeyPress);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(11, 316);
			this->label36->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(86, 13);
			this->label36->TabIndex = 22;
			this->label36->Text = L"Auto сompletion:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(199, 258);
			this->textBox13->Margin = System::Windows::Forms::Padding(2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(147, 20);
			this->textBox13->TabIndex = 23;
			this->textBox13->Text = L"0,01";
			this->textBox13->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox13_KeyPress);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(11, 260);
			this->label38->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(72, 13);
			this->label38->TabIndex = 24;
			this->label38->Text = L"Mutation rate:";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(199, 286);
			this->textBox15->Margin = System::Windows::Forms::Padding(2);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(147, 20);
			this->textBox15->TabIndex = 25;
			this->textBox15->Text = L"400";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(11, 288);
			this->label40->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(104, 13);
			this->label40->TabIndex = 26;
			this->label40->Text = L"Directions array size:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(11, 344);
			this->label44->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(91, 13);
			this->label44->TabIndex = 28;
			this->label44->Text = L"Visualization type:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"With visualization", L"Without visualization" });
			this->comboBox1->Location = System::Drawing::Point(199, 342);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(147, 21);
			this->comboBox1->TabIndex = 29;
			this->comboBox1->Text = L"Choose action...";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(10, 148);
			this->label48->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(80, 13);
			this->label48->TabIndex = 30;
			this->label48->Text = L"Result file path:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoCheck = false;
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(329, 148);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 31;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(199, 144);
			this->button18->Margin = System::Windows::Forms::Padding(2);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(125, 21);
			this->button18->TabIndex = 32;
			this->button18->Text = L"&Set";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &menu::button18_Click);
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label48);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->label40);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(356, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Blue;
			this->label8->Location = System::Drawing::Point(45, 50);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(263, 37);
			this->label8->TabIndex = 25;
			this->label8->Text = L"NEAT, 3D, Learn";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 120);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(95, 13);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Map configuration:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(11, 176);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(94, 13);
			this->label13->TabIndex = 27;
			this->label13->Text = L"Number of agents:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(11, 204);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(89, 13);
			this->label14->TabIndex = 28;
			this->label14->Text = L"Number of layers:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(11, 232);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(138, 13);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Maximum movement speed:";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox6->Location = System::Drawing::Point(198, 117);
			this->comboBox6->Margin = System::Windows::Forms::Padding(2);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(147, 21);
			this->comboBox6->TabIndex = 30;
			this->comboBox6->Text = L"Choose action...";
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox6_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 229);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 31;
			this->textBox1->Text = L"5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(198, 173);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(147, 20);
			this->textBox5->TabIndex = 32;
			this->textBox5->Text = L"250";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(198, 201);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(147, 20);
			this->textBox6->TabIndex = 33;
			this->textBox6->Text = L"5";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(140, 380);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 30);
			this->button3->TabIndex = 34;
			this->button3->Text = L"&Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &menu::button3_Click);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(198, 314);
			this->textBox12->Margin = System::Windows::Forms::Padding(2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(147, 20);
			this->textBox12->TabIndex = 35;
			this->textBox12->Text = L"100";
			this->textBox12->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox12_KeyPress);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(11, 316);
			this->label37->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(86, 13);
			this->label37->TabIndex = 36;
			this->label37->Text = L"Auto сompletion:";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(198, 258);
			this->textBox14->Margin = System::Windows::Forms::Padding(2);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(147, 20);
			this->textBox14->TabIndex = 37;
			this->textBox14->Text = L"0,01";
			this->textBox14->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox14_KeyPress);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(11, 260);
			this->label39->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(72, 13);
			this->label39->TabIndex = 38;
			this->label39->Text = L"Mutation rate:";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(198, 286);
			this->textBox16->Margin = System::Windows::Forms::Padding(2);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(147, 20);
			this->textBox16->TabIndex = 39;
			this->textBox16->Text = L"400";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(11, 288);
			this->label41->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(104, 13);
			this->label41->TabIndex = 40;
			this->label41->Text = L"Directions array size:";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(11, 344);
			this->label45->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(91, 13);
			this->label45->TabIndex = 41;
			this->label45->Text = L"Visualization type:";
			// 
			// comboBox9
			// 
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"With visualization", L"Without visualization" });
			this->comboBox9->Location = System::Drawing::Point(198, 341);
			this->comboBox9->Margin = System::Windows::Forms::Padding(2);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(147, 21);
			this->comboBox9->TabIndex = 42;
			this->comboBox9->Text = L"Choose action...";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(11, 148);
			this->label49->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(80, 13);
			this->label49->TabIndex = 43;
			this->label49->Text = L"Result file path:";
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(198, 144);
			this->button19->Margin = System::Windows::Forms::Padding(2);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(126, 21);
			this->button19->TabIndex = 44;
			this->button19->Text = L"&Set";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &menu::button19_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoCheck = false;
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(329, 148);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(15, 14);
			this->checkBox2->TabIndex = 45;
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->label49);
			this->Controls->Add(this->comboBox9);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->label41);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Size = System::Drawing::Size(356, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
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
			this->label24->TabIndex = 39;
			this->label24->Text = L"NEAT, 2D, Check";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(12, 120);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(96, 13);
			this->label25->TabIndex = 40;
			this->label25->Text = L"Lead map from file:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(12, 148);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(101, 13);
			this->label26->TabIndex = 41;
			this->label26->Text = L"Load result from file:";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(197, 116);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(126, 21);
			this->button6->TabIndex = 42;
			this->button6->Text = L"&Load";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &menu::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(197, 144);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(126, 21);
			this->button7->TabIndex = 43;
			this->button7->Text = L"&Load";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &menu::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(140, 380);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 30);
			this->button8->TabIndex = 44;
			this->button8->Text = L"&Check";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &menu::button8_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoCheck = false;
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(329, 120);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(15, 14);
			this->checkBox3->TabIndex = 45;
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoCheck = false;
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(329, 148);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(15, 14);
			this->checkBox4->TabIndex = 46;
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Size = System::Drawing::Size(356, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
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
			this->label27->TabIndex = 45;
			this->label27->Text = L"NEAT, 3D, Check";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(12, 120);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(96, 13);
			this->label28->TabIndex = 46;
			this->label28->Text = L"Lead map from file:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(12, 148);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(101, 13);
			this->label29->TabIndex = 47;
			this->label29->Text = L"Load result from file:";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(197, 116);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(126, 21);
			this->button9->TabIndex = 48;
			this->button9->Text = L"&Load";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &menu::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(197, 144);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(126, 21);
			this->button10->TabIndex = 49;
			this->button10->Text = L"&Load";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &menu::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(140, 380);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 30);
			this->button11->TabIndex = 50;
			this->button11->Text = L"&Check";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &menu::button11_Click);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoCheck = false;
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(329, 120);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(15, 14);
			this->checkBox5->TabIndex = 51;
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoCheck = false;
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(329, 148);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(15, 14);
			this->checkBox6->TabIndex = 52;
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->comboBox11 = (gcnew System::Windows::Forms::ComboBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(356, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->ForeColor = System::Drawing::Color::Blue;
			this->label16->Location = System::Drawing::Point(11, 50);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(336, 37);
			this->label16->TabIndex = 51;
			this->label16->Text = L"Q-Learning, 2D, Learn";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(11, 176);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(46, 13);
			this->label18->TabIndex = 52;
			this->label18->Text = L"Gamma:";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox7->Location = System::Drawing::Point(200, 117);
			this->comboBox7->Margin = System::Windows::Forms::Padding(2);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(147, 21);
			this->comboBox7->TabIndex = 53;
			this->comboBox7->Text = L"Choose action...";
			this->comboBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox7_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(140, 380);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 30);
			this->button4->TabIndex = 54;
			this->button4->Text = L"&Start";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &menu::button4_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(200, 173);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(147, 20);
			this->textBox7->TabIndex = 55;
			this->textBox7->Text = L"0,8";
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox7_KeyPress);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(11, 120);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(95, 13);
			this->label17->TabIndex = 56;
			this->label17->Text = L"Map configuration:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(200, 230);
			this->textBox10->Margin = System::Windows::Forms::Padding(2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(147, 20);
			this->textBox10->TabIndex = 57;
			this->textBox10->Text = L"5";
			this->textBox10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox10_KeyPress);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(11, 232);
			this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(110, 13);
			this->label23->TabIndex = 57;
			this->label23->Text = L"Number of repetitions:";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(200, 202);
			this->textBox17->Margin = System::Windows::Forms::Padding(2);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(147, 20);
			this->textBox17->TabIndex = 58;
			this->textBox17->Text = L"0";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(11, 204);
			this->label42->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(104, 13);
			this->label42->TabIndex = 59;
			this->label42->Text = L"Number of iterations:";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(10, 260);
			this->label47->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(110, 13);
			this->label47->TabIndex = 61;
			this->label47->Text = L"Number of repetitions:";
			// 
			// comboBox11
			// 
			this->comboBox11->FormattingEnabled = true;
			this->comboBox11->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"With visualization (iterations)", L"With visualization (states)",
					L"Without visualization"
			});
			this->comboBox11->Location = System::Drawing::Point(200, 257);
			this->comboBox11->Margin = System::Windows::Forms::Padding(2);
			this->comboBox11->Name = L"comboBox11";
			this->comboBox11->Size = System::Drawing::Size(147, 21);
			this->comboBox11->TabIndex = 62;
			this->comboBox11->Text = L"Choose action...";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(11, 149);
			this->label50->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(80, 13);
			this->label50->TabIndex = 63;
			this->label50->Text = L"Result file path:";
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(200, 145);
			this->button20->Margin = System::Windows::Forms::Padding(2);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(124, 21);
			this->button20->TabIndex = 64;
			this->button20->Text = L"&Set";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &menu::button20_Click);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoCheck = false;
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(329, 149);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(15, 14);
			this->checkBox7->TabIndex = 65;
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->label50);
			this->Controls->Add(this->comboBox11);
			this->Controls->Add(this->label47);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->label42);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(92, 29);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(161, 34);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(161, 34);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(137, 34);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(137, 34);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(202, 34);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(202, 34);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(122, 29);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(205, 34);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(205, 34);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(205, 34);
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(14, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(534, 37);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->ForeColor = System::Drawing::Color::Blue;
			this->label22->Location = System::Drawing::Point(16, 75);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(503, 55);
			this->label22->TabIndex = 59;
			this->label22->Text = L"Q-Learning, 3D, Learn";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(16, 264);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(73, 20);
			this->label21->TabIndex = 60;
			this->label21->Text = L"Gamma:";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox8->Location = System::Drawing::Point(300, 176);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(218, 28);
			this->comboBox8->TabIndex = 61;
			this->comboBox8->Text = L"Choose action...";
			this->comboBox8->SelectedIndexChanged += gcnew System::EventHandler(this, &menu::comboBox8_SelectedIndexChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(210, 570);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 45);
			this->button5->TabIndex = 62;
			this->button5->Text = L"&Start";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &menu::button5_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(300, 260);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(218, 26);
			this->textBox9->TabIndex = 63;
			this->textBox9->Text = L"0,8";
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox7_KeyPress);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(16, 180);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(147, 20);
			this->label20->TabIndex = 64;
			this->label20->Text = L"Map configuration:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(300, 345);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(218, 26);
			this->textBox8->TabIndex = 65;
			this->textBox8->Text = L"5";
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &menu::textBox10_KeyPress);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(16, 348);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(175, 20);
			this->label19->TabIndex = 66;
			this->label19->Text = L"Number of repetitions:";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(300, 303);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(218, 26);
			this->textBox18->TabIndex = 67;
			this->textBox18->Text = L"0";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(16, 306);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(166, 20);
			this->label43->TabIndex = 68;
			this->label43->Text = L"Number of iterations:";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(16, 390);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(175, 20);
			this->label46->TabIndex = 70;
			this->label46->Text = L"Number of repetitions:";
			// 
			// comboBox10
			// 
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"With visualization (iterations)", L"With visualization (states)",
					L"Without visualization"
			});
			this->comboBox10->Location = System::Drawing::Point(300, 386);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(218, 28);
			this->comboBox10->TabIndex = 71;
			this->comboBox10->Text = L"Choose action...";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(16, 222);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(126, 20);
			this->label51->TabIndex = 72;
			this->label51->Text = L"Result file path:";
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(300, 216);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(186, 32);
			this->button21->TabIndex = 73;
			this->button21->Text = L"&Set";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &menu::button21_Click);
			// 
			// checkBox8
			// 
			this->checkBox8->AutoCheck = false;
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(494, 222);
			this->checkBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(22, 21);
			this->checkBox8->TabIndex = 74;
			this->checkBox8->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(534, 646);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->label51);
			this->Controls->Add(this->comboBox10);
			this->Controls->Add(this->label46);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->label43);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Size = System::Drawing::Size(356, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
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
			this->label30->TabIndex = 67;
			this->label30->Text = L"Q-Learning, 2D, Check";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(12, 120);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(96, 13);
			this->label31->TabIndex = 68;
			this->label31->Text = L"Lead map from file:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(12, 148);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(101, 13);
			this->label32->TabIndex = 69;
			this->label32->Text = L"Load result from file:";
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(197, 116);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(126, 21);
			this->button12->TabIndex = 70;
			this->button12->Text = L"&Load";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &menu::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(197, 144);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(126, 21);
			this->button13->TabIndex = 71;
			this->button13->Text = L"&Load";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &menu::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(140, 380);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 30);
			this->button14->TabIndex = 72;
			this->button14->Text = L"&Check";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &menu::button14_Click);
			// 
			// checkBox9
			// 
			this->checkBox9->AutoCheck = false;
			this->checkBox9->AutoSize = true;
			this->checkBox9->Location = System::Drawing::Point(329, 120);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(15, 14);
			this->checkBox9->TabIndex = 73;
			this->checkBox9->UseVisualStyleBackColor = true;
			// 
			// checkBox10
			// 
			this->checkBox10->AutoCheck = false;
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(329, 148);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(15, 14);
			this->checkBox10->TabIndex = 74;
			this->checkBox10->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox10);
			this->Controls->Add(this->checkBox9);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(menu::typeid));
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->modeToolStripMenuItem,
					this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// modeToolStripMenuItem
			// 
			this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learnToolStripMenuItem,
					this->checkToolStripMenuItem
			});
			this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
			this->modeToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->modeToolStripMenuItem->Text = L"Mode";
			// 
			// learnToolStripMenuItem
			// 
			this->learnToolStripMenuItem->Name = L"learnToolStripMenuItem";
			this->learnToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->learnToolStripMenuItem->Text = L"Learn";
			this->learnToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::learnToolStripMenuItem_Click);
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
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
			this->dimensionToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->dimensionToolStripMenuItem->Text = L"Dimension";
			// 
			// dToolStripMenuItem
			// 
			this->dToolStripMenuItem->Name = L"dToolStripMenuItem";
			this->dToolStripMenuItem->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem->Text = L"2D";
			this->dToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::dToolStripMenuItem_Click);
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
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
			this->learningAlgorithmToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->learningAlgorithmToolStripMenuItem->Text = L"Learning algorithm";
			// 
			// nEATToolStripMenuItem
			// 
			this->nEATToolStripMenuItem->Name = L"nEATToolStripMenuItem";
			this->nEATToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->nEATToolStripMenuItem->Text = L"NEAT";
			this->nEATToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::nEATToolStripMenuItem_Click);
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
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
			this->informationToolStripMenuItem->Size = System::Drawing::Size(82, 19);
			this->informationToolStripMenuItem->Text = L"Information";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			this->howToUseToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::howToUseToolStripMenuItem_Click);
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
			this->bugReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::bugReportToolStripMenuItem_Click);
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
			this->menuStrip1->Size = System::Drawing::Size(356, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
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
			this->label33->TabIndex = 73;
			this->label33->Text = L"Q-Learning, 3D, Check";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(12, 120);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(96, 13);
			this->label34->TabIndex = 74;
			this->label34->Text = L"Lead map from file:";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(12, 148);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(101, 13);
			this->label35->TabIndex = 75;
			this->label35->Text = L"Load result from file:";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(197, 116);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(126, 21);
			this->button15->TabIndex = 76;
			this->button15->Text = L"&Load";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &menu::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(197, 144);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(126, 21);
			this->button16->TabIndex = 77;
			this->button16->Text = L"&Load";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &menu::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(140, 380);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 30);
			this->button17->TabIndex = 78;
			this->button17->Text = L"&Check";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &menu::button17_Click);
			// 
			// checkBox11
			// 
			this->checkBox11->AutoCheck = false;
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(329, 120);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(15, 14);
			this->checkBox11->TabIndex = 79;
			this->checkBox11->UseVisualStyleBackColor = true;
			// 
			// checkBox12
			// 
			this->checkBox12->AutoCheck = false;
			this->checkBox12->AutoSize = true;
			this->checkBox12->Location = System::Drawing::Point(329, 148);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(15, 14);
			this->checkBox12->TabIndex = 80;
			this->checkBox12->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 431);
			this->Controls->Add(this->checkBox12);
			this->Controls->Add(this->checkBox11);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NEAT-QL";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region functions
		void InitializeVariables(void)
		{
			font.loadFromFile("Resource Files/Fonts/sans-serif.ttf");

			loading_texture.loadFromFile("Resource Files/Textures/loading.png");
			loading.setOrigin(100, 25);
			loading.setPosition(400, 400);
			loading.setTexture(loading_texture);

			mode = Modes::LEARN;
			dimension = Dimensions::TWOD;
			learning_algorithm = LearningAlgorythms::NEAT;

			width = 800;
			height = 800;
			pause = false;
			from_image = false;
			map_loaded = false;
			show_controls = false;
			result_loaded = false;
			check_from_file = false;
			output_path_set = false;

			neat::visualization_type = neat::VisualizationTypes::WITH;

			neat::max_speed = 5;
			neat::auto_exit = 10;
			neat::map_size.x = 80;
			neat::map_size.y = 80;
			neat::agent_radius = 4;
			neat::goal_radius = 10;
			neat::layers_quantity = 3;
			neat::mutation_rate = 0.01f;
			neat::population_quantity = 250;
			neat::directions_array_size = 400;

			neat::around = false;
			neat::was_running = false;

			neat::controls[0].setPosition(685, 10);
			neat::controls[0].setString(L"[Esc] - Exit");
			neat::controls[1].setPosition(612, 10);
			neat::controls[1].setString(L"[E] - Show controls");
			neat::controls[2].setPosition(612, 10);
			neat::controls[2].setString(L"[E] - Show controls");

			for (int i = 0; i < 3; i++)
			{
				neat::controls[i].setFont(font);
				neat::controls[i].setCharacterSize(20);
				neat::controls[i].setOutlineThickness(3);
				neat::controls[i].setOutlineColor(sf::Color::White);
				neat::controls[i].setFillColor(sf::Color::Black);
			}

			neat::rect.setFillColor(sf::Color::Blue);
			neat::rect.setSize(sf::Vector2f(10, 10));

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
				neat::text[i].setFont(font);
				neat::text[i].setCharacterSize(20);
				neat::text[i].setOutlineThickness(3);
				neat::text[i].setOutlineColor(sf::Color::White);
				neat::text[i].setFillColor(sf::Color::Black);
			}

			ql::visualization_type = ql::VisualizationTypes::ITERATIONS;

			ql::gamma = 0.8f;
			ql::repetitions = 5;
			ql::map_size.x = 10;
			ql::map_size.y = 10;
			ql::thickness = 2.5f;
			ql::goal_reward = 100;

			ql::around = false;
			ql::was_running = false;
			ql::goal_loaded = false;

			ql::text[0].setPosition(15, 10);
			ql::text[0].setString(L"Position: ");
			ql::text[1].setPosition(100, 10);
			ql::text[1].setString(L"0");
			ql::text[2].setPosition(15, 30);
			ql::text[2].setString(L"Repetition: ");
			ql::text[3].setPosition(117, 30);
			ql::text[3].setString(L"0");

			for (int i = 0; i < 4; i++)
			{
				ql::text[i].setFont(font);
				ql::text[i].setCharacterSize(20);
				ql::text[i].setOutlineThickness(3);
				ql::text[i].setOutlineColor(sf::Color::White);
				ql::text[i].setFillColor(sf::Color::Black);
			}

			ql::controls[0].setPosition(685, 10);
			ql::controls[0].setString(L"[Esc] - Exit");
			ql::controls[1].setPosition(612, 10);
			ql::controls[1].setString(L"[E] - Show controls");
			ql::controls[2].setPosition(612, 10);
			ql::controls[2].setString(L"[E] - Show controls");

			for (int i = 0; i < 3; i++)
			{
				ql::controls[i].setFont(font);
				ql::controls[i].setCharacterSize(20);
				ql::controls[i].setOutlineThickness(3);
				ql::controls[i].setOutlineColor(sf::Color::White);
				ql::controls[i].setFillColor(sf::Color::Black);
			}
		}
		void ResetVariables(void)
		{
			width = 800;
			height = 800;
			pause = false;
			from_image = false;
			map_loaded = false;
			show_controls = false;
			result_loaded = false;
			check_from_file = false;
			output_path_set = false;

			neat::visualization_type = neat::VisualizationTypes::WITH;

			neat::max_speed = 5;
			neat::auto_exit = 10;
			neat::map_size.x = 80;
			neat::map_size.y = 80;
			neat::agent_radius = 4;
			neat::goal_radius = 10;
			neat::layers_quantity = 3;
			neat::mutation_rate = 0.01f;
			neat::population_quantity = 250;
			neat::directions_array_size = 400;

			neat::around = false;
			neat::was_running = false;

			neat::controls[1].setPosition(612, 10);
			neat::controls[1].setString(L"[E] - Show controls");
			neat::controls[2].setPosition(612, 10);
			neat::controls[2].setString(L"[E] - Show controls");

			neat::rect.setFillColor(sf::Color::Blue);
			neat::rect.setSize(sf::Vector2f(10, 10));

			neat::text[1].setPosition(185, 10);
			neat::text[1].setString(L"No");
			neat::text[3].setPosition(65, 30);
			neat::text[3].setString(L"0");

			ql::visualization_type = ql::VisualizationTypes::ITERATIONS;

			ql::gamma = 0.8f;
			ql::repetitions = 5;
			ql::map_size.x = 10;
			ql::map_size.y = 10;
			ql::thickness = 2.5f;
			ql::goal_reward = 100;

			ql::around = false;
			ql::was_running = false;
			ql::goal_loaded = false;

			ql::text[1].setPosition(100, 10);
			ql::text[1].setString(L"0");
			ql::text[3].setPosition(117, 30);
			ql::text[3].setString(L"0");

			ql::controls[1].setPosition(612, 10);
			ql::controls[1].setString(L"[E] - Show controls");
			ql::controls[2].setPosition(612, 10);
			ql::controls[2].setString(L"[E] - Show controls");
		}
		void ChooseInitializer(void)
		{
			this->Controls->Clear();
			ResetVariables();
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
						InitializeComponentNEAT3DCheck();
				}
				else if (learning_algorithm == LearningAlgorythms::QL)
				{
					if (dimension == Dimensions::TWOD)
						InitializeComponentQL2DCheck();
					else if (dimension == Dimensions::THREED)
						InitializeComponentQL3DCheck();
				}
			}
		}
#pragma endregion

#pragma region Tool strip menu actions
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
		System::Windows::Forms::MessageBox::Show("A universal and adaptable algorithm for finding the shortest path based on a self-learning neural network and its software implementation. The universality of the algorithm lies in the fact that the User can independently determine the script for the execution of the algorithm - choose the optimal learning algorithm, create the necessary map of the area and set the logic of the movement of the object. To demonstrate these features, a user interface was developed for an effective software implementation of the algorithm. An algorithm for visualizing the learning process of the genetic algorithm and reinforcement learning for finding the shortest path has been developed.", "About");
	}
	private: System::Void howToUseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::MessageBox::Show("Choose parameterers and then press start or check to begin learning or cheking. For the genetic algorithm, the User can choose the speed of training and, accordingly, obtain the desired result. The speed and accuracy of training is regulated by changing the number of agents (the more agents, the higher the training speed), but for this it is necessary to increase the computing power - a separate processor stream is allocated for each layer. For reinforcement learning, the User can select the learning speed by adjusting the parameter gamma. The larger the parameter, the higher the learning speed, but also the likelihood of missing a useful learning outcome. To implement the ability to use spatial grid as a map, an algorithm for representing the terrain map in the form of a two-dimensional array of possible states and actions was compiled.", "How to use");
	}
	private: System::Void bugReportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::MessageBox::Show("Email: vhd-ru@yandex.ru", "Bug report");
	}
#pragma endregion

#pragma region Main menu actions
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
		if (comboBox2->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, select mode", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (comboBox3->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, select dimension", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (comboBox4->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, select learning algorithm", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
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
	private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox13_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08; }
	private: System::Void textBox11_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::set_result_file_path();
		this->checkBox1->Checked = output_path_set;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::population_quantity = Convert::ToInt32(textBox2->Text);
		neat::layers_quantity = Convert::ToInt32(textBox3->Text);
		neat::max_speed = Convert::ToSingle(textBox4->Text);
		try { neat::mutation_rate = Convert::ToSingle(textBox13->Text); }
		catch (System::FormatException^)
		{
			Windows::Forms::MessageBox::Show("Error: Check mutation rate value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		neat::directions_array_size = Convert::ToInt32(textBox15->Text);
		neat::auto_exit = Convert::ToInt32(textBox11->Text);
		switch (comboBox1->SelectedIndex)
		{
		case -1:
			Windows::Forms::MessageBox::Show("Error: Please, choose visualization type", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		case 0:
			neat::visualization_type = neat::VisualizationTypes::WITH;
			break;
		case 1:
			neat::visualization_type = neat::VisualizationTypes::WITHOUT;
			break;
		}

		if (comboBox5->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, choose action with map", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox1->Checked)
			Windows::Forms::MessageBox::Show("Error: Please, set file path for result", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::population_quantity == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check number of populations value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::layers_quantity == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check number of layers value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::max_speed == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check maximum movement speed value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::mutation_rate == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check mutation rate value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::directions_array_size == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check directions array size value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			if (neat::visualization_type == neat::VisualizationTypes::WITH)
				neat::with_visualization_2d();
			else if (neat::visualization_type == neat::VisualizationTypes::WITHOUT)
				neat::without_visualization_2d();
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
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::set_result_file_path();
		this->checkBox2->Checked = output_path_set;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::population_quantity = Convert::ToInt32(textBox5->Text);
		neat::layers_quantity = Convert::ToInt32(textBox6->Text);
		neat::max_speed = Convert::ToSingle(textBox1->Text);
		try { neat::mutation_rate = Convert::ToSingle(textBox14->Text); }
		catch (System::FormatException^)
		{
			Windows::Forms::MessageBox::Show("Error: Check mutation rate value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		neat::directions_array_size = Convert::ToInt32(textBox16->Text);
		neat::auto_exit = Convert::ToInt32(textBox12->Text);
		switch (comboBox9->SelectedIndex)
		{
		case -1:
			Windows::Forms::MessageBox::Show("Error: Please, choose visualization type", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		case 0:
			neat::visualization_type = neat::VisualizationTypes::WITH;
			break;
		case 1:
			neat::visualization_type = neat::VisualizationTypes::WITHOUT;
			break;
		}

		if (comboBox6->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, choose action with map", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox2->Checked)
			Windows::Forms::MessageBox::Show("Error: Please, set file path for result", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::population_quantity == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check number of populations value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::layers_quantity == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check number of layers value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::max_speed == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check maximum movement speed value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::mutation_rate == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check mutation rate value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (neat::directions_array_size == 0)
			Windows::Forms::MessageBox::Show("Error: Please, Check directions array size value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			if (neat::visualization_type == neat::VisualizationTypes::WITH)
				neat::with_visualization_3d();
			else if (neat::visualization_type == neat::VisualizationTypes::WITHOUT)
				neat::without_visualization_3d();
	}
#pragma endregion

#pragma region NEAT, 2D, Check actions
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::load_map_from_file_2d();
		this->checkBox3->Checked = map_loaded;
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::load_result_from_file_2d();
		this->checkBox4->Checked = result_loaded;
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!checkBox3->Checked)
			Windows::Forms::MessageBox::Show("Error: Map wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		if (!checkBox4->Checked)
			Windows::Forms::MessageBox::Show("Error: Result wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			neat::check_2d();
	}
#pragma endregion

#pragma region NEAT, 3D, Check actions
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::load_map_from_file_3d();
		this->checkBox5->Checked = map_loaded;
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e)
	{
		neat::load_result_from_file_3d();
		this->checkBox6->Checked = result_loaded;
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!checkBox5->Checked)
			Windows::Forms::MessageBox::Show("Error: Map wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		if (!checkBox6->Checked)
			Windows::Forms::MessageBox::Show("Error: Result wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			neat::check_3d();
	}
#pragma endregion

#pragma region QL, 2D, Learn actions
	private: System::Void textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08; }
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
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::set_result_file_path();
		this->checkBox7->Checked = output_path_set;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try { ql::gamma = Convert::ToSingle(textBox7->Text); }
		catch (System::FormatException^)
		{
			Windows::Forms::MessageBox::Show("Error: Please, check gamma value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		ql::repetitions = Convert::ToInt32(textBox10->Text);
		if (Convert::ToInt32(textBox17->Text) == 0) ql::iterations = ql::map_size.x * ql::map_size.y;
		else ql::iterations = Convert::ToInt32(textBox17->Text);
		switch (comboBox11->SelectedIndex)
		{
		case -1:
			Windows::Forms::MessageBox::Show("Error: Please, choose visualization type", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		case 0:
			ql::visualization_type = ql::VisualizationTypes::ITERATIONS;
			break;
		case 1:
			ql::visualization_type = ql::VisualizationTypes::STATES;
			break;
		case 2:
			ql::visualization_type = ql::VisualizationTypes::WITHOUT;
			break;
		}

		if (comboBox7->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, choose action with map", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox7->Checked)
			Windows::Forms::MessageBox::Show("Error: Please, set file path for result", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (ql::gamma == 0 || ql::gamma > 1)
			Windows::Forms::MessageBox::Show("Error: Please, check gamma value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (ql::repetitions == 0)
			Windows::Forms::MessageBox::Show("Error: Please, check number of iteration value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			if (ql::visualization_type == ql::VisualizationTypes::ITERATIONS || ql::visualization_type == ql::VisualizationTypes::STATES)
				ql::with_visualization_2d();
			else if (ql::visualization_type == ql::VisualizationTypes::WITHOUT)
				ql::without_visualization_2d();
	}
#pragma endregion

#pragma region QL, 3D, Learn actions
	private: System::Void textBox8_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08; }
	private: System::Void textBox9_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) { e->Handled = !Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != 0x08; }
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
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::set_result_file_path();
		this->checkBox8->Checked = output_path_set;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try { ql::gamma = Convert::ToSingle(textBox9->Text); }
		catch (System::FormatException^)
		{
			Windows::Forms::MessageBox::Show("Error: Please, check gamma value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		ql::repetitions = Convert::ToInt32(textBox8->Text);
		if (Convert::ToInt32(textBox18->Text) == 0) ql::iterations = ql::map_size.x * ql::map_size.y;
		else ql::iterations = Convert::ToInt32(textBox18->Text);
		switch (comboBox10->SelectedIndex)
		{
		case -1:
			Windows::Forms::MessageBox::Show("Error: Please, choose visualization type", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
			return;
		case 0:
			ql::visualization_type = ql::VisualizationTypes::ITERATIONS;
			break;
		case 1:
			ql::visualization_type = ql::VisualizationTypes::STATES;
			break;
		case 2:
			ql::visualization_type = ql::VisualizationTypes::WITHOUT;
			break;
		}

		if (comboBox8->SelectedIndex == -1)
			Windows::Forms::MessageBox::Show("Error: Please, choose action with map", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox8->Checked)
			Windows::Forms::MessageBox::Show("Error: Please, set file path for result", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (ql::gamma == 0 || ql::gamma > 1)
			Windows::Forms::MessageBox::Show("Error: Please, check gamma value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (ql::repetitions == 0)
			Windows::Forms::MessageBox::Show("Error: Please, check number of iteration value correctness", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			if (ql::visualization_type == ql::VisualizationTypes::ITERATIONS || ql::visualization_type == ql::VisualizationTypes::STATES)
				ql::with_visualization_3d();
			else if (ql::visualization_type == ql::VisualizationTypes::WITHOUT)
				ql::without_visualization_3d();
	}
#pragma endregion

#pragma region QL, 2D, Check actions
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::load_map_from_file_2d();
		this->checkBox9->Checked = map_loaded;
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!checkBox9->Checked)
			Windows::Forms::MessageBox::Show("Error: Map wasn't loaded. Load map first", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
		{
			ql::load_result_from_file_2d();
			this->checkBox10->Checked = result_loaded;
		}
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!checkBox9->Checked)
			Windows::Forms::MessageBox::Show("Error: Map wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox10->Checked)
			Windows::Forms::MessageBox::Show("Error: Result wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			ql::check_2d();
	}
#pragma endregion

#pragma region QL, 3D, Check actions
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::load_map_from_file_3d();
		this->checkBox11->Checked = map_loaded;
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ql::load_result_from_file_3d();
		this->checkBox12->Checked = result_loaded;
}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!checkBox11->Checked)
			Windows::Forms::MessageBox::Show("Error: Map wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else if (!checkBox12->Checked)
			Windows::Forms::MessageBox::Show("Error: Result wasn't loaded", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
		else
			ql::check_3d();
	}
#pragma endregion
	};
}