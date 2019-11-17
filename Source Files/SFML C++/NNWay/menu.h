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
	protected:

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
	private: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip1->Size = System::Drawing::Size(356, 25);
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
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Language:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"English", L"Ðóññêèé" });
			this->comboBox1->Location = System::Drawing::Point(199, 117);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(147, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Learn", L"Check" });
			this->comboBox2->Location = System::Drawing::Point(199, 145);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(147, 21);
			this->comboBox2->TabIndex = 5;
			this->comboBox2->Text = L"Choose action...";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 148);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Mode:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"2D", L"3D" });
			this->comboBox3->Location = System::Drawing::Point(199, 173);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(147, 21);
			this->comboBox3->TabIndex = 7;
			this->comboBox3->Text = L"Choose action...";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(10, 176);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Dimension:";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"NEAT", L"Q-Learning" });
			this->comboBox4->Location = System::Drawing::Point(199, 201);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(147, 21);
			this->comboBox4->TabIndex = 9;
			this->comboBox4->Text = L"Choose action...";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(10, 204);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Learning algorithm:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 300);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 10;
			this->button1->Text = L"&Go to";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
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
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			this->label6->TabIndex = 1;
			this->label6->Text = L"NEAT, 2D, Learn";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(11, 120);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 13);
			this->label7->TabIndex = 2;
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
			this->comboBox5->TabIndex = 3;
			this->comboBox5->Text = L"Choose action...";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(11, 148);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(94, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Number of agents:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(11, 175);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 13);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Number of layers:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(199, 145);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(147, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"250";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(199, 172);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(147, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"5";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(11, 202);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(86, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Auto ñompletion:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(199, 199);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(147, 20);
			this->textBox4->TabIndex = 11;
			this->textBox4->Text = L"100";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 300);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 30);
			this->button2->TabIndex = 12;
			this->button2->Text = L"&Start";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			this->label8->TabIndex = 1;
			this->label8->Text = L"NEAT, 3D, Learn";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 120);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(95, 13);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Map configuration:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(11, 148);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(94, 13);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Number of agents:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(11, 176);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(89, 13);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Number of layers:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(11, 204);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(86, 13);
			this->label15->TabIndex = 10;
			this->label15->Text = L"Auto ñompletion:";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox6->Location = System::Drawing::Point(198, 117);
			this->comboBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(147, 21);
			this->comboBox6->TabIndex = 3;
			this->comboBox6->Text = L"Choose action...";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 201);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(147, 20);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"100";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(198, 145);
			this->textBox5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(147, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->Text = L"250";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(198, 173);
			this->textBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(147, 20);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"5";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(140, 300);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 30);
			this->button3->TabIndex = 12;
			this->button3->Text = L"&Start";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
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
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->modeToolStripMenuItem, this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(197, 144);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(147, 21);
			this->button7->TabIndex = 5;
			this->button7->Text = L"&Load";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(140, 300);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 30);
			this->button8->TabIndex = 6;
			this->button8->Text = L"&Check";
			this->button8->UseVisualStyleBackColor = true;
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
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->modeToolStripMenuItem, this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(197, 144);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(147, 21);
			this->button10->TabIndex = 5;
			this->button10->Text = L"&Load";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(140, 300);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 30);
			this->button11->TabIndex = 6;
			this->button11->Text = L"&Check";
			this->button11->UseVisualStyleBackColor = true;
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
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			this->label16->TabIndex = 1;
			this->label16->Text = L"Q-Learning, 2D, Learn";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(11, 148);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(46, 13);
			this->label18->TabIndex = 5;
			this->label18->Text = L"Gamma:";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new map", L"Load map from file" });
			this->comboBox7->Location = System::Drawing::Point(200, 117);
			this->comboBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(147, 21);
			this->comboBox7->TabIndex = 3;
			this->comboBox7->Text = L"Choose action...";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(140, 300);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 30);
			this->button4->TabIndex = 12;
			this->button4->Text = L"&Start";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(200, 145);
			this->textBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(147, 20);
			this->textBox7->TabIndex = 13;
			this->textBox7->Text = L"0.8";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(11, 120);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(95, 13);
			this->label17->TabIndex = 14;
			this->label17->Text = L"Map configuration:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(200, 173);
			this->textBox10->Margin = System::Windows::Forms::Padding(2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(147, 20);
			this->textBox10->TabIndex = 16;
			this->textBox10->Text = L"5";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(11, 176);
			this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(104, 13);
			this->label23->TabIndex = 15;
			this->label23->Text = L"Number of iterations:";
			// 
			// menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(356, 361);
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
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
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
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &menu::aboutToolStripMenuItem_Click);
			// 
			// howToUseToolStripMenuItem
			// 
			this->howToUseToolStripMenuItem->Name = L"howToUseToolStripMenuItem";
			this->howToUseToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->howToUseToolStripMenuItem->Text = L"How to use";
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			this->menuStrip1->Size = System::Drawing::Size(356, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::Blue;
			this->label19->Location = System::Drawing::Point(10, 50);
			this->label19->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(336, 37);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Q-Learning, 3D, Learn";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(10, 120);
			this->label20->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(95, 13);
			this->label20->TabIndex = 14;
			this->label20->Text = L"Map configuration:";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Create new", L"Load from file" });
			this->comboBox8->Location = System::Drawing::Point(199, 117);
			this->comboBox8->Margin = System::Windows::Forms::Padding(2);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(147, 21);
			this->comboBox8->TabIndex = 3;
			this->comboBox8->Text = L"Choose action...";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(199, 145);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(147, 20);
			this->textBox8->TabIndex = 13;
			this->textBox8->Text = L"0,8";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(140, 300);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 30);
			this->button5->TabIndex = 12;
			this->button5->Text = L"&Start";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(10, 148);
			this->label21->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(46, 13);
			this->label21->TabIndex = 15;
			this->label21->Text = L"Gamma:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(10, 175);
			this->label22->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(104, 13);
			this->label22->TabIndex = 17;
			this->label22->Text = L"Number of iterations:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(199, 172);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(147, 20);
			this->textBox9->TabIndex = 16;
			this->textBox9->Text = L"5";
			// 
			// menu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(356, 361);
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
			this->Margin = System::Windows::Forms::Padding(2);
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
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->modeToolStripMenuItem, this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(197, 144);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(147, 21);
			this->button13->TabIndex = 5;
			this->button13->Text = L"&Load";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(140, 300);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 30);
			this->button14->TabIndex = 6;
			this->button14->Text = L"&Check";
			this->button14->UseVisualStyleBackColor = true;
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
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->languageToolStripMenuItem,
					this->modeToolStripMenuItem, this->dimensionToolStripMenuItem, this->learningAlgorithmToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 19);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// languageToolStripMenuItem
			// 
			this->languageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->englishToolStripMenuItem,
					this->ðóññêèéToolStripMenuItem
			});
			this->languageToolStripMenuItem->Name = L"languageToolStripMenuItem";
			this->languageToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->languageToolStripMenuItem->Text = L"Language";
			// 
			// englishToolStripMenuItem
			// 
			this->englishToolStripMenuItem->Name = L"englishToolStripMenuItem";
			this->englishToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->englishToolStripMenuItem->Text = L"English";
			// 
			// ðóññêèéToolStripMenuItem
			// 
			this->ðóññêèéToolStripMenuItem->Name = L"ðóññêèéToolStripMenuItem";
			this->ðóññêèéToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->ðóññêèéToolStripMenuItem->Text = L"Ðóññêèé";
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
			// 
			// checkToolStripMenuItem
			// 
			this->checkToolStripMenuItem->Name = L"checkToolStripMenuItem";
			this->checkToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->checkToolStripMenuItem->Text = L"Check";
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
			// 
			// dToolStripMenuItem1
			// 
			this->dToolStripMenuItem1->Name = L"dToolStripMenuItem1";
			this->dToolStripMenuItem1->Size = System::Drawing::Size(88, 22);
			this->dToolStripMenuItem1->Text = L"3D";
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
			// 
			// qLearningToolStripMenuItem
			// 
			this->qLearningToolStripMenuItem->Name = L"qLearningToolStripMenuItem";
			this->qLearningToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->qLearningToolStripMenuItem->Text = L"Q-Learning";
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
			// 
			// bugReportToolStripMenuItem
			// 
			this->bugReportToolStripMenuItem->Name = L"bugReportToolStripMenuItem";
			this->bugReportToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->bugReportToolStripMenuItem->Text = L"Bug report";
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
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(197, 144);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(147, 21);
			this->button16->TabIndex = 5;
			this->button16->Text = L"&Load";
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(140, 300);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 30);
			this->button17->TabIndex = 6;
			this->button17->Text = L"&Check";
			this->button17->UseVisualStyleBackColor = true;
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
				MessageBox::Show("Àëãîðèòì ðàáîòàåò ïî ñëåäóþùåìó ïðèíöèïó: ïðè çàïóñêå ïðîãðàììû êàæäûé îáúåêò ñëó÷àéíûì îáðàçîì ôîðìèðóåò ìàññèâ íàïðàâëåíèé, ïðåäñòàâëåííûé â âèäå ïîçèöèé äëÿ ïåðåìåùåíèé, îáðàçîâàííûõ îò óãëîâ, ðàçìåð ýòîãî ìàññèâà òàêæå ìîæíî ðåãóëèðîâàòü.Ïîñëå ýòîãî êàæäûé îáúåêò íà÷èíàåò äâèæåíèå â ñîîòâåòñòâèè ñ ýëåìåíòàìè ìàññèâà íàïðàâëåíèé.Îáúåêò ïåðåñòàåò äâèãàòüñÿ, êàê òîëüêî êàñàåòñÿ çàäàííîé ïîëüçîâàòåëåì îáëàñòè, íàïðèìåð, çäàíèå íà êàðòå, äîñòèãàåò öåëè èëè êîãäà çàêàí÷èâàþòñÿ ýëåìåíòû â ìàññèâå íàïðàâëåíèé(çàêàí÷èâàåòñÿ êîëè÷åñòâî õîäîâ).Ïîñëå ýòîãî ïðîèñõîäèò îòáîð ëó÷øåãî îáúåêòà äëÿ äàëüíåéøåãî îáó÷åíèÿ : ñðàâíèâàåòñÿ “öåííîñòü” îáúåêòîâ è îáúåêò ñ íàèáîëüøåé öåííîñòüþ çàïîìèíàåòñÿ êàê ëó÷øèé(öåííîñòü çàäàåòñÿ ïî îïðåäåëåííîé ôîðìóëå, òàê, íàïðèìåð, äëÿ äàííîãî àëãîðèòìà, öåííîñòü áîëüøå ó òîãî îáúåêòà, ðàññòîÿíèå ó êîòîðîãî äî öåëè ìåíüøå ÷åì ó îñòàëüíûõ).");
		}
		else if (learning_algorithm == LearningAlgorythms::QL)
		{
			if (language == Languages::EN)
				MessageBox::Show("When the algorithm starts, an array R (stateXactions) is created, which shows where the agent can go and where not, as well as the location of the targets on the map (the numbering starts at 0 and runs horizontally in ascending order). After this, training takes place: a second array Q is created and filled with zeros. He needs to check any such state (after creating the first array R, an array of initial states is also created). As a result, all possible subsequent actions. After that, the second array with weights is filled in accordance with the formula. After the training is completed, the second array, the user can enter any initial state and get the shortest route.");
			else
				MessageBox::Show("Ïðè çàïóñêå àëãîðèòìà ñîçäàåòñÿ ìàññèâ R (stateXactions), êîòîðûé ïîêàçûâàåò, ãäå àãåíò ìîæåò ïðîõîäèòü, à ãäå íåò, à òàêæå ðàñïîëîæåíèå öåëåé íà êàðòå (íóìåðàöèÿ íà÷èíàåòñÿ ñ 0 è èäåò ãîðèçîíòàëüíî ïî âîçðàñòàíèþ). Ïîñëå ýòîãî ïðîèñõîäèò îáó÷åíèå: ñîçäà¸òñÿ âòîðîé ìàññèâ Q è çàïîëíÿåòñÿ íóëÿìè. Åìó íåîáõîäèìî ïðîâåðèòü ëþáîå òàêîå ñîñòîÿíèå (ïîñëå ñîçäàíèÿ ïåðâîãî ìàññèâà R òàêæå ñîçäàåòñÿ ìàññèâ íà÷àëüíûõ ñîñòîÿíèé). Â ðåçóëüòàòå âñå âîçìîæíûå ïîñëåäóþùèå äåéñòâèÿ. Ïîñëå ýòîãî âòîðîé ìàññèâ ñ âåñàìè çàïîëíÿåòñÿ â ñîîòâåòñòâèè ñ ôîðìóëîé. Ïîñëå òîãî, êàê îáó÷åíèå çàêîí÷åíî, âòîðîé ìàññèâ ïîëüçîâàòåëü ìîæåò ââåñòè ëþáîå íà÷àëüíîå ñîñòîÿíèå è ïîëó÷èòü êðàò÷àéøèé ìàðøðóò.");
		}
	}
};
}