#pragma once
#include "CommandSender.h"
#include <thread>
#include "GraphicsLib.cpp"

namespace GraphicsController {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			commandSender = gcnew GraphicsController::CommandSender(); // Ініціалізація екземпляра CommandSender

			this->commandComboBox->Items->Add("Clear Display");
			this->commandComboBox->Items->Add("Draw Pixel");
			this->commandComboBox->Items->Add("Draw Line");
			this->commandComboBox->Items->Add("Draw Rectangle");
			this->commandComboBox->Items->Add("Fill Rectangle");
			this->commandComboBox->Items->Add("Draw Ellipse");
			this->commandComboBox->Items->Add("Fill Ellipse");
			this->commandComboBox->Items->Add("Draw Circle");
			this->commandComboBox->Items->Add("Fill Circle");
			this->commandComboBox->Items->Add("Draw Rounded Rectangle");
			this->commandComboBox->Items->Add("Fill Rounded Rectangle");
			this->commandComboBox->Items->Add("Draw Text");

			// Спочатку ховаємо всі елементи
			this->label1->Visible = false;
			this->label2->Visible = false;
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->textBox1->Visible = false;
			this->textBox2->Visible = false;
			this->textBox3->Visible = false;
			this->textBox4->Visible = false;
			this->textBox5->Visible = false;
			this->textBox6->Visible = false;
			this->button1->Visible = false;

			// Додаємо елементи до ComboBox
			this->comboBoxOrientation->Items->Add("0 - Portrait");
			this->comboBoxOrientation->Items->Add("1 - Landscape");
			this->comboBoxOrientation->Items->Add("2 ");
			this->comboBoxOrientation->Items->Add("3 ");

			// Встановлюємо перший елемент як вибраний
			this->comboBoxOrientation->SelectedIndex = 0;

		}
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btnStartClock;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxClockX;
	private: System::Windows::Forms::TextBox^ textBoxClockY;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxColor;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBoxClockFontSize;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Timer^ clockTimer;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ btnDrawTextWithLines;
	private: System::Windows::Forms::TextBox^ textBoxTextLinesX;
	private: System::Windows::Forms::TextBox^ textBoxTextLinesY;
	private: System::Windows::Forms::TextBox^ textBoxTextColorLines;

	private: System::Windows::Forms::TextBox^ textBoxTextLines;





	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::ComboBox^ comboBoxOrientation;
	private: System::Windows::Forms::Button^ btnSetOrientation;
	private: System::Windows::Forms::Button^ btnSetWidth;
	private: System::Windows::Forms::TextBox^ textBoxWidth;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Button^ btnSetHeight;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::TextBox^ textBoxHeight;
	private: System::Windows::Forms::Button^ btnCreateSprite;
	private: System::Windows::Forms::Button^ btnShowSprite;
	private: System::Windows::Forms::TextBox^ textBoxSpriteIndex;
	private: System::Windows::Forms::TextBox^ textBoxShowSpriteIndex;
	private: System::Windows::Forms::TextBox^ textBoxShowSpriteX;
private: System::Windows::Forms::TextBox^ textBoxShowSpriteY;
private: System::Windows::Forms::TextBox^ textBoxSpriteWidth;
private: System::Windows::Forms::TextBox^ textBoxSpriteHeight;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::TextBox^ textBoxMarqueeY;
private: System::Windows::Forms::TextBox^ textBoxFontSize;
private: System::Windows::Forms::TextBox^ textBoxMarqueeText;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Button^ btnSendMarqueeText;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::TextBox^ textBoxMarqueeTextColor;


















	private:
		GraphicsController::CommandSender^ commandSender; // Поле для зберігання екземпляра CommandSender

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ commandComboBox;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->commandComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnStartClock = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxClockX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxClockY = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxColor = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBoxClockFontSize = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->clockTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->btnDrawTextWithLines = (gcnew System::Windows::Forms::Button());
			this->textBoxTextLinesX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTextLinesY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTextColorLines = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTextLines = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->comboBoxOrientation = (gcnew System::Windows::Forms::ComboBox());
			this->btnSetOrientation = (gcnew System::Windows::Forms::Button());
			this->btnSetWidth = (gcnew System::Windows::Forms::Button());
			this->textBoxWidth = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->btnSetHeight = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBoxHeight = (gcnew System::Windows::Forms::TextBox());
			this->btnCreateSprite = (gcnew System::Windows::Forms::Button());
			this->btnShowSprite = (gcnew System::Windows::Forms::Button());
			this->textBoxSpriteIndex = (gcnew System::Windows::Forms::TextBox());
			this->textBoxShowSpriteIndex = (gcnew System::Windows::Forms::TextBox());
			this->textBoxShowSpriteX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxShowSpriteY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSpriteWidth = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSpriteHeight = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBoxMarqueeY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFontSize = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMarqueeText = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->btnSendMarqueeText = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->textBoxMarqueeTextColor = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// commandComboBox
			// 
			this->commandComboBox->FormattingEnabled = true;
			this->commandComboBox->Location = System::Drawing::Point(35, 41);
			this->commandComboBox->Name = L"commandComboBox";
			this->commandComboBox->Size = System::Drawing::Size(249, 24);
			this->commandComboBox->TabIndex = 0;
			this->commandComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(222, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(105, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(192, 44);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(222, 165);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(105, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 224);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(222, 218);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(105, 22);
			this->textBox3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(32, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(222, 270);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(105, 22);
			this->textBox4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 325);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(222, 325);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(105, 22);
			this->textBox5->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 375);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"label6";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(222, 375);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(105, 22);
			this->textBox6->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(35, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(169, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Список основних команд";
			// 
			// btnStartClock
			// 
			this->btnStartClock->Location = System::Drawing::Point(408, 202);
			this->btnStartClock->Name = L"btnStartClock";
			this->btnStartClock->Size = System::Drawing::Size(180, 33);
			this->btnStartClock->TabIndex = 15;
			this->btnStartClock->Text = L"Показати час";
			this->btnStartClock->UseVisualStyleBackColor = true;
			this->btnStartClock->Click += gcnew System::EventHandler(this, &MyForm::btnStartClock_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(454, 44);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"X:";
			// 
			// textBoxClockX
			// 
			this->textBoxClockX->Location = System::Drawing::Point(488, 41);
			this->textBoxClockX->Name = L"textBoxClockX";
			this->textBoxClockX->Size = System::Drawing::Size(100, 22);
			this->textBoxClockX->TabIndex = 17;
			// 
			// textBoxClockY
			// 
			this->textBoxClockY->Location = System::Drawing::Point(488, 79);
			this->textBoxClockY->Name = L"textBoxClockY";
			this->textBoxClockY->Size = System::Drawing::Size(100, 22);
			this->textBoxClockY->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(453, 82);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(19, 16);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Y:";
			// 
			// textBoxColor
			// 
			this->textBoxColor->Location = System::Drawing::Point(488, 122);
			this->textBoxColor->Name = L"textBoxColor";
			this->textBoxColor->Size = System::Drawing::Size(100, 22);
			this->textBoxColor->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(430, 125);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Color:";
			// 
			// textBoxClockFontSize
			// 
			this->textBoxClockFontSize->Location = System::Drawing::Point(488, 165);
			this->textBoxClockFontSize->Name = L"textBoxClockFontSize";
			this->textBoxClockFontSize->Size = System::Drawing::Size(100, 22);
			this->textBoxClockFontSize->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(405, 168);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 16);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Font size:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(405, 13);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(135, 16);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Показати годинник";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(408, 260);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(166, 16);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Малювати текст лініями ";
			// 
			// btnDrawTextWithLines
			// 
			this->btnDrawTextWithLines->Location = System::Drawing::Point(411, 456);
			this->btnDrawTextWithLines->Name = L"btnDrawTextWithLines";
			this->btnDrawTextWithLines->Size = System::Drawing::Size(177, 37);
			this->btnDrawTextWithLines->TabIndex = 26;
			this->btnDrawTextWithLines->Text = L"Намалювати текст";
			this->btnDrawTextWithLines->UseVisualStyleBackColor = true;
			this->btnDrawTextWithLines->Click += gcnew System::EventHandler(this, &MyForm::btnDrawTextWithLines_Click_1);
			// 
			// textBoxTextLinesX
			// 
			this->textBoxTextLinesX->Location = System::Drawing::Point(491, 292);
			this->textBoxTextLinesX->Name = L"textBoxTextLinesX";
			this->textBoxTextLinesX->Size = System::Drawing::Size(100, 22);
			this->textBoxTextLinesX->TabIndex = 27;
			// 
			// textBoxTextLinesY
			// 
			this->textBoxTextLinesY->Location = System::Drawing::Point(491, 330);
			this->textBoxTextLinesY->Name = L"textBoxTextLinesY";
			this->textBoxTextLinesY->Size = System::Drawing::Size(100, 22);
			this->textBoxTextLinesY->TabIndex = 28;
			// 
			// textBoxTextColorLines
			// 
			this->textBoxTextColorLines->Location = System::Drawing::Point(491, 375);
			this->textBoxTextColorLines->Name = L"textBoxTextColorLines";
			this->textBoxTextColorLines->Size = System::Drawing::Size(100, 22);
			this->textBoxTextColorLines->TabIndex = 29;
			// 
			// textBoxTextLines
			// 
			this->textBoxTextLines->Location = System::Drawing::Point(491, 412);
			this->textBoxTextLines->Name = L"textBoxTextLines";
			this->textBoxTextLines->Size = System::Drawing::Size(100, 22);
			this->textBoxTextLines->TabIndex = 31;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(444, 298);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(18, 16);
			this->label14->TabIndex = 32;
			this->label14->Text = L"X:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(444, 336);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 16);
			this->label15->TabIndex = 33;
			this->label15->Text = L"Y:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(420, 378);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(42, 16);
			this->label16->TabIndex = 34;
			this->label16->Text = L"Color:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(420, 418);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(36, 16);
			this->label18->TabIndex = 36;
			this->label18->Text = L"Text:";
			// 
			// comboBoxOrientation
			// 
			this->comboBoxOrientation->FormattingEnabled = true;
			this->comboBoxOrientation->Location = System::Drawing::Point(12, 533);
			this->comboBoxOrientation->Name = L"comboBoxOrientation";
			this->comboBoxOrientation->Size = System::Drawing::Size(121, 24);
			this->comboBoxOrientation->TabIndex = 37;
			// 
			// btnSetOrientation
			// 
			this->btnSetOrientation->Location = System::Drawing::Point(12, 570);
			this->btnSetOrientation->Name = L"btnSetOrientation";
			this->btnSetOrientation->Size = System::Drawing::Size(219, 35);
			this->btnSetOrientation->TabIndex = 38;
			this->btnSetOrientation->Text = L"Змінити орієнтацію дисплея";
			this->btnSetOrientation->UseVisualStyleBackColor = true;
			this->btnSetOrientation->Click += gcnew System::EventHandler(this, &MyForm::btnSetOrientation_Click);
			// 
			// btnSetWidth
			// 
			this->btnSetWidth->Location = System::Drawing::Point(250, 607);
			this->btnSetWidth->Name = L"btnSetWidth";
			this->btnSetWidth->Size = System::Drawing::Size(128, 46);
			this->btnSetWidth->TabIndex = 39;
			this->btnSetWidth->Text = L"Змінити ширину диспплея";
			this->btnSetWidth->UseVisualStyleBackColor = true;
			this->btnSetWidth->Click += gcnew System::EventHandler(this, &MyForm::btnSetWidth_Click);
			// 
			// textBoxWidth
			// 
			this->textBoxWidth->Location = System::Drawing::Point(323, 567);
			this->textBoxWidth->Name = L"textBoxWidth";
			this->textBoxWidth->Size = System::Drawing::Size(96, 22);
			this->textBoxWidth->TabIndex = 40;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(247, 570);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(61, 16);
			this->label17->TabIndex = 41;
			this->label17->Text = L"Ширина:";
			// 
			// btnSetHeight
			// 
			this->btnSetHeight->Location = System::Drawing::Point(433, 607);
			this->btnSetHeight->Name = L"btnSetHeight";
			this->btnSetHeight->Size = System::Drawing::Size(126, 46);
			this->btnSetHeight->TabIndex = 42;
			this->btnSetHeight->Text = L"Змінити висоту дисплея";
			this->btnSetHeight->UseVisualStyleBackColor = true;
			this->btnSetHeight->Click += gcnew System::EventHandler(this, &MyForm::btnSetHeight_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(433, 570);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(57, 16);
			this->label19->TabIndex = 43;
			this->label19->Text = L"Висота:";
			// 
			// textBoxHeight
			// 
			this->textBoxHeight->Location = System::Drawing::Point(515, 570);
			this->textBoxHeight->Name = L"textBoxHeight";
			this->textBoxHeight->Size = System::Drawing::Size(98, 22);
			this->textBoxHeight->TabIndex = 44;
			// 
			// btnCreateSprite
			// 
			this->btnCreateSprite->Location = System::Drawing::Point(732, 152);
			this->btnCreateSprite->Name = L"btnCreateSprite";
			this->btnCreateSprite->Size = System::Drawing::Size(115, 23);
			this->btnCreateSprite->TabIndex = 45;
			this->btnCreateSprite->Text = L"CreateSprite";
			this->btnCreateSprite->UseVisualStyleBackColor = true;
			this->btnCreateSprite->Click += gcnew System::EventHandler(this, &MyForm::btnCreateSprite_Click);
			// 
			// btnShowSprite
			// 
			this->btnShowSprite->Location = System::Drawing::Point(732, 291);
			this->btnShowSprite->Name = L"btnShowSprite";
			this->btnShowSprite->Size = System::Drawing::Size(115, 23);
			this->btnShowSprite->TabIndex = 46;
			this->btnShowSprite->Text = L"Show Sprite";
			this->btnShowSprite->UseVisualStyleBackColor = true;
			this->btnShowSprite->Click += gcnew System::EventHandler(this, &MyForm::btnShowSprite_Click);
			// 
			// textBoxSpriteIndex
			// 
			this->textBoxSpriteIndex->Location = System::Drawing::Point(747, 41);
			this->textBoxSpriteIndex->Name = L"textBoxSpriteIndex";
			this->textBoxSpriteIndex->Size = System::Drawing::Size(100, 22);
			this->textBoxSpriteIndex->TabIndex = 47;
			// 
			// textBoxShowSpriteIndex
			// 
			this->textBoxShowSpriteIndex->Location = System::Drawing::Point(747, 200);
			this->textBoxShowSpriteIndex->Name = L"textBoxShowSpriteIndex";
			this->textBoxShowSpriteIndex->Size = System::Drawing::Size(100, 22);
			this->textBoxShowSpriteIndex->TabIndex = 48;
			// 
			// textBoxShowSpriteX
			// 
			this->textBoxShowSpriteX->Location = System::Drawing::Point(747, 228);
			this->textBoxShowSpriteX->Name = L"textBoxShowSpriteX";
			this->textBoxShowSpriteX->Size = System::Drawing::Size(100, 22);
			this->textBoxShowSpriteX->TabIndex = 49;
			// 
			// textBoxShowSpriteY
			// 
			this->textBoxShowSpriteY->Location = System::Drawing::Point(747, 260);
			this->textBoxShowSpriteY->Name = L"textBoxShowSpriteY";
			this->textBoxShowSpriteY->Size = System::Drawing::Size(100, 22);
			this->textBoxShowSpriteY->TabIndex = 50;
			// 
			// textBoxSpriteWidth
			// 
			this->textBoxSpriteWidth->Location = System::Drawing::Point(747, 77);
			this->textBoxSpriteWidth->Name = L"textBoxSpriteWidth";
			this->textBoxSpriteWidth->Size = System::Drawing::Size(100, 22);
			this->textBoxSpriteWidth->TabIndex = 51;
			// 
			// textBoxSpriteHeight
			// 
			this->textBoxSpriteHeight->Location = System::Drawing::Point(747, 112);
			this->textBoxSpriteHeight->Name = L"textBoxSpriteHeight";
			this->textBoxSpriteHeight->Size = System::Drawing::Size(100, 22);
			this->textBoxSpriteHeight->TabIndex = 52;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(661, 44);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(80, 16);
			this->label20->TabIndex = 53;
			this->label20->Text = L"Sprite Index:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(659, 80);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(82, 16);
			this->label21->TabIndex = 54;
			this->label21->Text = L"Sprite Width:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(661, 112);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(87, 16);
			this->label22->TabIndex = 55;
			this->label22->Text = L"Sprite Height:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(659, 206);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(80, 16);
			this->label23->TabIndex = 56;
			this->label23->Text = L"Sprite Index:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(662, 238);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(56, 16);
			this->label24->TabIndex = 57;
			this->label24->Text = L"Sprite X:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(662, 265);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(57, 16);
			this->label25->TabIndex = 58;
			this->label25->Text = L"Sprite Y:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(632, 13);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(238, 16);
			this->label26->TabIndex = 59;
			this->label26->Text = L"Створення і відображення спрайтів";
			// 
			// textBoxMarqueeY
			// 
			this->textBoxMarqueeY->Location = System::Drawing::Point(732, 359);
			this->textBoxMarqueeY->Name = L"textBoxMarqueeY";
			this->textBoxMarqueeY->Size = System::Drawing::Size(100, 22);
			this->textBoxMarqueeY->TabIndex = 60;
			// 
			// textBoxFontSize
			// 
			this->textBoxFontSize->Location = System::Drawing::Point(732, 402);
			this->textBoxFontSize->Name = L"textBoxFontSize";
			this->textBoxFontSize->Size = System::Drawing::Size(100, 22);
			this->textBoxFontSize->TabIndex = 61;
			// 
			// textBoxMarqueeText
			// 
			this->textBoxMarqueeText->Location = System::Drawing::Point(732, 446);
			this->textBoxMarqueeText->Name = L"textBoxMarqueeText";
			this->textBoxMarqueeText->Size = System::Drawing::Size(100, 22);
			this->textBoxMarqueeText->TabIndex = 62;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(653, 365);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(26, 16);
			this->label27->TabIndex = 63;
			this->label27->Text = L"Y0:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(652, 405);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(65, 16);
			this->label28->TabIndex = 64;
			this->label28->Text = L"Font Size:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(652, 452);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(36, 16);
			this->label29->TabIndex = 65;
			this->label29->Text = L"Text:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(655, 326);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(188, 16);
			this->label30->TabIndex = 66;
			this->label30->Text = L"Створити анімований текст";
			// 
			// btnSendMarqueeText
			// 
			this->btnSendMarqueeText->Location = System::Drawing::Point(675, 525);
			this->btnSendMarqueeText->Name = L"btnSendMarqueeText";
			this->btnSendMarqueeText->Size = System::Drawing::Size(157, 39);
			this->btnSendMarqueeText->TabIndex = 67;
			this->btnSendMarqueeText->Text = L"Send Marquee Text";
			this->btnSendMarqueeText->UseVisualStyleBackColor = true;
			this->btnSendMarqueeText->Click += gcnew System::EventHandler(this, &MyForm::btnSendMarqueeText_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(655, 489);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(42, 16);
			this->label31->TabIndex = 68;
			this->label31->Text = L"Color:";
			// 
			// textBoxMarqueeTextColor
			// 
			this->textBoxMarqueeTextColor->Location = System::Drawing::Point(732, 486);
			this->textBoxMarqueeTextColor->Name = L"textBoxMarqueeTextColor";
			this->textBoxMarqueeTextColor->Size = System::Drawing::Size(100, 22);
			this->textBoxMarqueeTextColor->TabIndex = 69;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(899, 665);
			this->Controls->Add(this->textBoxMarqueeTextColor);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->btnSendMarqueeText);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->textBoxMarqueeText);
			this->Controls->Add(this->textBoxFontSize);
			this->Controls->Add(this->textBoxMarqueeY);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->textBoxSpriteHeight);
			this->Controls->Add(this->textBoxSpriteWidth);
			this->Controls->Add(this->textBoxShowSpriteY);
			this->Controls->Add(this->textBoxShowSpriteX);
			this->Controls->Add(this->textBoxShowSpriteIndex);
			this->Controls->Add(this->textBoxSpriteIndex);
			this->Controls->Add(this->btnShowSprite);
			this->Controls->Add(this->btnCreateSprite);
			this->Controls->Add(this->textBoxHeight);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->btnSetHeight);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBoxWidth);
			this->Controls->Add(this->btnSetWidth);
			this->Controls->Add(this->btnSetOrientation);
			this->Controls->Add(this->comboBoxOrientation);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBoxTextLines);
			this->Controls->Add(this->textBoxTextColorLines);
			this->Controls->Add(this->textBoxTextLinesY);
			this->Controls->Add(this->textBoxTextLinesX);
			this->Controls->Add(this->btnDrawTextWithLines);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBoxClockFontSize);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBoxColor);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxClockY);
			this->Controls->Add(this->textBoxClockX);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnStartClock);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->commandComboBox);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		// Сховати всі елементи перед відображенням нових
		this->label1->Visible = false;
		this->label2->Visible = false;
		this->label3->Visible = false;
		this->label4->Visible = false;
		this->label5->Visible = false;
		this->label6->Visible = false;
		this->textBox1->Visible = false;
		this->textBox2->Visible = false;
		this->textBox3->Visible = false;
		this->textBox4->Visible = false;
		this->textBox5->Visible = false;
		this->textBox6->Visible = false;
		this->button1->Visible = false;

        // Очищення текстових полів
		this->textBox1->Text = "";
		this->textBox2->Text = "";
		this->textBox3->Text = "";
		this->textBox4->Text = "";
		this->textBox5->Text = "";
		this->textBox6->Text = "";

		String^ selectedCommand = this->commandComboBox->SelectedItem->ToString();

		if (selectedCommand == "Clear Display") {
			this->label1->Text = "Enter Color (RGB565):";
			this->label1->Visible = true;
			this->textBox1->Visible = true; 
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Pixel") {
			this->label1->Text = "X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter Color (RGB565):";
			this->label3->Visible = true;

			this->textBox1->Visible = true; // Поле для введення X
			this->textBox2->Visible = true; // Поле для введення Y
			this->textBox3->Visible = true; // Поле для введення кольору
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Line") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "End X Coordinate:";
			this->label3->Visible = true;

			this->label4->Text = "End Y Coordinate:";
			this->label4->Visible = true;

			this->label5->Text = "Enter Color (RGB565):";
			this->label5->Visible = true;

			this->textBox1->Visible = true; 
			this->textBox2->Visible = true; 
			this->textBox3->Visible = true; 
			this->textBox4->Visible = true; 
			this->textBox5->Visible = true; 
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Rectangle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter width:";
			this->label3->Visible = true;

			this->label4->Text = "Enter height:";
			this->label4->Visible = true;

			this->label5->Text = "Enter Color (RGB565):";
			this->label5->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Fill Rectangle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter width:";
			this->label3->Visible = true;

			this->label4->Text = "Enter height:";
			this->label4->Visible = true;

			this->label5->Text = "Enter Color (RGB565):";
			this->label5->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Ellipse") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter radius X:";
			this->label3->Visible = true;

			this->label4->Text = "Enter radius Y:";
			this->label4->Visible = true;

			this->label5->Text = "Enter Color (RGB565):";
			this->label5->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Fill Ellipse") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter radius X:";
			this->label3->Visible = true;

			this->label4->Text = "Enter radius Y:";
			this->label4->Visible = true;

			this->label5->Text = "Enter Color (RGB565):";
			this->label5->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Circle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter radius:";
			this->label3->Visible = true;

			this->label4->Text = "Enter Color (RGB565):";
			this->label4->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}


		if (selectedCommand == "Fill Circle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter radius:";
			this->label3->Visible = true;

			this->label4->Text = "Enter Color (RGB565):";
			this->label4->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;

			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Rounded Rectangle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter width:";
			this->label3->Visible = true;

			this->label4->Text = "Enter height:";
			this->label4->Visible = true;

			this->label5->Text = "Enter radius:";
			this->label5->Visible = true;

			this->label6->Text = "Enter Color (RGB565):";
			this->label6->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->textBox6->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Fill Rounded Rectangle") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter width:";
			this->label3->Visible = true;

			this->label4->Text = "Enter height:";
			this->label4->Visible = true;

			this->label5->Text = "Enter radius:";
			this->label5->Visible = true;

			this->label6->Text = "Enter Color (RGB565):";
			this->label6->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->textBox6->Visible = true;
			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}

		if (selectedCommand == "Draw Text") {
			this->label1->Text = "Start X Coordinate:";
			this->label1->Visible = true;

			this->label2->Text = "Start Y Coordinate:";
			this->label2->Visible = true;

			this->label3->Text = "Enter Color (RGB565):";
			this->label3->Visible = true;

			this->label4->Text = "Enter Font size (1-8):";
			this->label4->Visible = true;

			this->label5->Text = "Enter Text:";
			this->label5->Visible = true;

			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;

			this->button1->Text = "Execute Command";
			this->button1->Visible = true;
		}




	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ command = this->commandComboBox->Text;

		if (command == "Clear Display")
		{
			try
			{
				// Зчитуємо колір у форматі RGB565
				int color = Convert::ToInt32(this->textBox1->Text, 16); // Введення в шістнадцятковому форматі (наприклад, "FFFF").
				if (color < 0 || color > 0xFFFF)
				{
					MessageBox::Show("Invalid color value. Please enter a valid 16-bit RGB565 color.", "Error");
					return;
				}

				// Формуємо пакет для команди
				array<Byte>^ packet = gcnew array<Byte>(3);
				packet[0] = 0x01; // ID команди
				packet[1] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[2] = color & 0xFF;        // Молодший байт кольору

				// Використання класу CommandSender для відправлення команди
				commandSender->SendCommand(packet); // Викликаємо метод SendCommand

				MessageBox::Show("Clear Display command sent successfully!", "Success");
			}
			catch (FormatException^)
			{
				MessageBox::Show("Please enter a valid hexadecimal value for the color.", "Error");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}
		
		if (command == "Draw Pixel") {
			try {
				int x = Convert::ToInt32(this->textBox1->Text); // Зчитуємо координату X
				int y = Convert::ToInt32(this->textBox2->Text); // Зчитуємо координату Y
				int color = Convert::ToInt32(this->textBox3->Text, 16); // Зчитуємо колір

				// Перевірка валідності координат і кольору
				if (x < 0 || y < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(7); 
				packet[0] = 0x02; // ID команди для "Draw Pixel"
				packet[1] = (x >> 8) & 0xFF; // Старший байт X
				packet[2] = x & 0xFF; // Молодший байт X
				packet[3] = (y >> 8) & 0xFF; // Старший байт Y
				packet[4] = y & 0xFF; // Молодший байт Y
				packet[5] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[6] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet); 

				MessageBox::Show("Draw Pixel command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Draw Line")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text); // Зчитуємо координату X0
				int y0 = Convert::ToInt32(this->textBox2->Text); // Зчитуємо координату Y0
				int x1 = Convert::ToInt32(this->textBox3->Text); // Зчитуємо координату X1
				int y1 = Convert::ToInt32(this->textBox4->Text); // Зчитуємо координату Y1
				int color = Convert::ToInt32(this->textBox5->Text, 16); // Зчитуємо колір

				if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x03; 
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (x1 >> 8) & 0xFF; // Старший байт X1
				packet[6] = x1 & 0xFF; // Молодший байт X1
				packet[7] = (y1 >> 8) & 0xFF; // Старший байт Y1
				packet[8] = y1 & 0xFF; // Молодший байт Y1
				packet[9] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[10] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet); 

				MessageBox::Show("Draw Line command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}

		}

		if (command == "Draw Rectangle") 
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int w = Convert::ToInt32(this->textBox3->Text);
				int h = Convert::ToInt32(this->textBox4->Text);
				int color = Convert::ToInt32(this->textBox5->Text, 16);

				if (x0 < 0 || y0 < 0 || w < 0 || h < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x04;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (w >> 8) & 0xFF; // Старший байт w
				packet[6] = w & 0xFF; // Молодший байт w
				packet[7] = (h >> 8) & 0xFF; // Старший байт h
				packet[8] = h & 0xFF; // Молодший байт h
				packet[9] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[10] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Draw Rectangle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Fill Rectangle")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int w = Convert::ToInt32(this->textBox3->Text);
				int h = Convert::ToInt32(this->textBox4->Text);
				int color = Convert::ToInt32(this->textBox5->Text, 16);

				if (x0 < 0 || y0 < 0 || w < 0 || h < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x05;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (w >> 8) & 0xFF; // Старший байт w
				packet[6] = w & 0xFF; // Молодший байт w
				packet[7] = (h >> 8) & 0xFF; // Старший байт h
				packet[8] = h & 0xFF; // Молодший байт h
				packet[9] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[10] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Fill Rectangle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Draw Ellipse")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int radius_x = Convert::ToInt32(this->textBox3->Text);
				int radius_y = Convert::ToInt32(this->textBox4->Text);
				int color = Convert::ToInt32(this->textBox5->Text, 16);

				if (x0 < 0 || y0 < 0 || radius_x < 0 || radius_y < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x06;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (radius_x >> 8) & 0xFF; // Старший байт radius_x
				packet[6] = radius_x & 0xFF; // Молодший байт radius_x
				packet[7] = (radius_y >> 8) & 0xFF; // Старший байт radius_y
				packet[8] = radius_y & 0xFF; // Молодший байт radius_y
				packet[9] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[10] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Draw Ellipse command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Fill Ellipse")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int radius_x = Convert::ToInt32(this->textBox3->Text);
				int radius_y = Convert::ToInt32(this->textBox4->Text);
				int color = Convert::ToInt32(this->textBox5->Text, 16);

				if (x0 < 0 || y0 < 0 || radius_x < 0 || radius_y < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x07;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (radius_x >> 8) & 0xFF; // Старший байт radius_x
				packet[6] = radius_x & 0xFF; // Молодший байт radius_x
				packet[7] = (radius_y >> 8) & 0xFF; // Старший байт radius_y
				packet[8] = radius_y & 0xFF; // Молодший байт radius_y
				packet[9] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[10] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Fill Ellipse command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Draw Circle")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int radius = Convert::ToInt32(this->textBox3->Text);
				int color = Convert::ToInt32(this->textBox4->Text, 16);

				if (x0 < 0 || y0 < 0 || radius < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(9);
				packet[0] = 0x08;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (radius >> 8) & 0xFF; // Старший байт radius
				packet[6] = radius & 0xFF; // Молодший байт radius
				packet[7] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[8] = color & 0xFF; // Молодший байт кольору
				
				commandSender->SendCommand(packet);

				MessageBox::Show("Draw Circle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Fill Circle")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int radius = Convert::ToInt32(this->textBox3->Text);
				int color = Convert::ToInt32(this->textBox4->Text, 16);

				if (x0 < 0 || y0 < 0 || radius < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(9);
				packet[0] = 0x09;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (radius >> 8) & 0xFF; // Старший байт radius
				packet[6] = radius & 0xFF; // Молодший байт radius
				packet[7] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[8] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Fill Circle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Draw Rounded Rectangle")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text); 
				int y0 = Convert::ToInt32(this->textBox2->Text); 
				int w = Convert::ToInt32(this->textBox3->Text); 
				int h = Convert::ToInt32(this->textBox4->Text); 
				int radius = Convert::ToInt32(this->textBox5->Text);
				int color = Convert::ToInt32(this->textBox6->Text, 16); 

				if (x0 < 0 || y0 < 0 || w < 0 || h < 0 || radius < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(13);
				packet[0] = 0x0A;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (w >> 8) & 0xFF; // Старший байт W
				packet[6] = w & 0xFF; // Молодший байт W
				packet[7] = (h >> 8) & 0xFF; // Старший байт H
				packet[8] = h & 0xFF; // Молодший байт H
				packet[9] = (radius >> 8) & 0xFF; // Старший байт radius
			    packet[10] = radius & 0xFF; // Молодший байт radius
				packet[11] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[12] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Draw Rounded Rectangle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Fill Rounded Rectangle")
		{
			try {
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int w = Convert::ToInt32(this->textBox3->Text);
				int h = Convert::ToInt32(this->textBox4->Text);
				int radius = Convert::ToInt32(this->textBox5->Text);
				int color = Convert::ToInt32(this->textBox6->Text, 16);

				if (x0 < 0 || y0 < 0 || w < 0 || h < 0 || radius < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(13);
				packet[0] = 0x0B;
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (w >> 8) & 0xFF; // Старший байт W
				packet[6] = w & 0xFF; // Молодший байт W
				packet[7] = (h >> 8) & 0xFF; // Старший байт H
				packet[8] = h & 0xFF; // Молодший байт H
				packet[9] = (radius >> 8) & 0xFF; // Старший байт radius
				packet[10] = radius & 0xFF; // Молодший байт radius
				packet[11] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[12] = color & 0xFF; // Молодший байт кольору

				commandSender->SendCommand(packet);

				MessageBox::Show("Fill Rounded Rectangle command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}

		if (command == "Draw Text") {
			try {
				// Зчитуємо значення
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int color = Convert::ToInt32(this->textBox3->Text, 16);
				int font = Convert::ToInt32(this->textBox4->Text);
				String^ text = this->textBox5->Text;

				// Автоматично визначаємо довжину тексту
				int text_length = text->Length;

				// Перевіряємо вхідні дані
				if (x0 < 0 || y0 < 0 || color < 0 || color > 0xFFFF || font < 0 || text_length > 255) {
					MessageBox::Show("Invalid input values. Please check your inputs.", "Error");
					return;
				}

				// Розрахунок розміру пакета
				int packet_length = 9 + text_length; // 8 фіксованих байтів + довжина тексту

				// Створення пакета
				array<Byte>^ packet = gcnew array<Byte>(packet_length);

				// Запис базових даних
				packet[0] = 0x0C; // Command ID
				packet[1] = (x0 >> 8) & 0xFF; // Старший байт X0
				packet[2] = x0 & 0xFF; // Молодший байт X0
				packet[3] = (y0 >> 8) & 0xFF; // Старший байт Y0
				packet[4] = y0 & 0xFF; // Молодший байт Y0
				packet[5] = (color >> 8) & 0xFF; // Старший байт кольору
				packet[6] = color & 0xFF; // Молодший байт кольору
				packet[7] = font; // розмір шрифту
				packet[8] = text_length; // Довжина тексту

				// Перевіряємо текст перед записом
				for (int i = 0; i < text_length; i++) {
					if (i + 9 >= packet->Length) {
						throw gcnew Exception("Text length exceeds packet size.");
					}
					packet[9 + i] = (Byte)text[i];
				}

				// Відправлення пакета на сервер
				commandSender->SendCommand(packet);

				MessageBox::Show("Draw Text command sent successfully!", "Success");
			}
			catch (FormatException^) {
				MessageBox::Show("Please enter valid numeric values for coordinates and hexadecimal value for color.", "Error");
			}
			catch (Exception^ ex) {
				MessageBox::Show("An error occurred: " + ex->Message, "Error");
			}
		}




	}

	private: System::Void btnStartClock_Click(System::Object^ sender, System::EventArgs^ e) {
		 try {
			 
			 int x0 = Convert::ToInt32(this->textBoxClockX->Text); 
			 int y0 = Convert::ToInt32(this->textBoxClockY->Text); 
			 int color = Convert::ToInt32(this->textBoxColor->Text, 16); 
			 int fontSize = Convert::ToInt32(this->textBoxClockFontSize->Text); 

			
			 if (color < 0 || color > 0xFFFF) {
				 MessageBox::Show("Invalid color value. Please enter a valid 16-bit RGB565 color.", "Error");
				 return;
			 }

			 
			 array<Byte>^ packet = gcnew array<Byte>(8);
			 packet[0] = 0x0D; 
			 packet[1] = (x0 >> 8) & 0xFF; 
			 packet[2] = x0 & 0xFF;        
			 packet[3] = (y0 >> 8) & 0xFF; 
			 packet[4] = y0 & 0xFF;       
			 packet[5] = (color >> 8) & 0xFF; 
			 packet[6] = color & 0xFF;        
			 packet[7] = (fontSize & 0xFF);   

			 
			 commandSender->SendCommand(packet); 

			 // Initialize and start the timer
			 clockTimer = gcnew System::Windows::Forms::Timer();
			 clockTimer->Interval = 1000; 
			 clockTimer->Tick += gcnew EventHandler(this, &MyForm::UpdateClock);
			 clockTimer->Start();

			 MessageBox::Show("Draw Clock command sent successfully! Clock will update every second.", "Success");
		 }
		 catch (FormatException^) {
			 MessageBox::Show("Please enter valid numeric values.", "Error");
		 }
		 catch (Exception^ ex) {
			 MessageBox::Show("An error occurred: " + ex->Message, "Error");
		 }
	 }

	private: System::Void UpdateClock(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			int x0 = Convert::ToInt32(this->textBoxClockX->Text); 
			int y0 = Convert::ToInt32(this->textBoxClockY->Text); 
			int color = Convert::ToInt32(this->textBoxColor->Text, 16); 
			int fontSize = Convert::ToInt32(this->textBoxClockFontSize->Text); 

			
			int clearWidth = 200; 
			int clearHeight = 50; 
			int backgroundColor = 0x0000; 

			
			array<Byte>^ clearPacket = gcnew array<Byte>(11); 
			clearPacket[0] = 0x05; 
			clearPacket[1] = (x0 >> 8) & 0xFF; 
			clearPacket[2] = x0 & 0xFF;        
			clearPacket[3] = (y0 >> 8) & 0xFF; 
			clearPacket[4] = y0 & 0xFF;        
			clearPacket[5] = (clearWidth >> 8) & 0xFF; 
			clearPacket[6] = clearWidth & 0xFF;        
			clearPacket[7] = (clearHeight >> 8) & 0xFF; 
			clearPacket[8] = clearHeight & 0xFF;        
			clearPacket[9] = (backgroundColor >> 8) & 0xFF; 
			clearPacket[10] = backgroundColor & 0xFF;        

			
			commandSender->SendCommand(clearPacket);

			
			String^ currentTime = DateTime::Now.ToString("HH:mm:ss");

			
			array<Byte>^ packet = gcnew array<Byte>(8); 
			packet[0] = 0x0D; 
			packet[1] = (x0 >> 8) & 0xFF; 
			packet[2] = x0 & 0xFF;        
			packet[3] = (y0 >> 8) & 0xFF;
			packet[4] = y0 & 0xFF;       
			packet[5] = (color >> 8) & 0xFF; 
			packet[6] = color & 0xFF;        
			packet[7] = (fontSize & 0xFF);   

			commandSender->SendCommand(packet); 

		}
		catch (FormatException^) {
			MessageBox::Show("Please enter valid numeric values.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
	}

    private: System::Void btnDrawTextWithLines_Click_1(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			int x0 = Convert::ToInt32(this->textBoxTextLinesX->Text);
			int y0 = Convert::ToInt32(this->textBoxTextLinesY->Text);
			int color = Convert::ToInt32(this->textBoxTextColorLines->Text, 16);
			String^ text = this->textBoxTextLines->Text;

			
			int fontSize = 50; 

			
			if (color < 0 || color > 0xFFFF) {
				MessageBox::Show("Invalid color value. Please enter a valid 16-bit RGB565 color.", "Error");
				return;
			}

			
			int textLength = text->Length;

			
			array<Byte>^ packet = gcnew array<Byte>(8 + textLength);
			packet[0] = 0x0E; 
			packet[1] = (x0 >> 8) & 0xFF; 
			packet[2] = x0 & 0xFF;        
			packet[3] = (y0 >> 8) & 0xFF; 
			packet[4] = y0 & 0xFF;       
			packet[5] = (color >> 8) & 0xFF;
			packet[6] = color & 0xFF;        
			packet[7] = (fontSize & 0xFF);   

			
			for (int i = 0; i < textLength; i++) {
				packet[8 + i] = (Byte)text[i]; 
			}

			
			commandSender->SendCommand(packet);

			MessageBox::Show("Draw Text with Lines command sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter valid numeric values.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
    }

	private: System::Void btnSetOrientation_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			String^ selectedItem = this->comboBoxOrientation->SelectedItem->ToString();

			
			int orientation = Convert::ToInt32(selectedItem->Substring(0, 1)); 
			
			if (orientation < 0 || orientation > 3) {
				MessageBox::Show("Invalid orientation value. Please select a valid orientation (0-3).", "Error");
				return;
			}

			array<Byte>^ packet = gcnew array<Byte>(2);
			packet[0] = 0x0F; 
			packet[1] = (Byte)orientation; 

		
			commandSender->SendCommand(packet);

			MessageBox::Show("Set Orientation command sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please select a valid orientation.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
	}
    
	private: System::Void btnSetWidth_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int width = Convert::ToInt32(this->textBoxWidth->Text); 

			
			if (width <= 0) {
				MessageBox::Show("Invalid width value. Please enter a positive integer.", "Error");
				return;
			}

			array<Byte>^ packet = gcnew array<Byte>(3);
			packet[0] = 0x10; 
			packet[1] = (width >> 8) & 0xFF;
			packet[2] = width & 0xFF; 

			
			commandSender->SendCommand(packet);

			MessageBox::Show("Set Width command sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter a valid numeric value for width.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
    }

    private: System::Void btnSetHeight_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int height = Convert::ToInt32(this->textBoxHeight->Text); 

			if (height <= 0) {
				MessageBox::Show("Invalid height value. Please enter a positive integer.", "Error");
				return;
			}

			array<Byte>^ packet = gcnew array<Byte>(3);
			packet[0] = 0x11; 
			packet[1] = (height >> 8) & 0xFF; 
			packet[2] = height & 0xFF; 

			commandSender->SendCommand(packet);

			MessageBox::Show("Set Height command sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter a valid numeric value for height.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
    }
    
	private: System::Void btnCreateSprite_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			int index = Convert::ToInt32(this->textBoxSpriteIndex->Text);
			int width = Convert::ToInt32(this->textBoxSpriteWidth->Text);
			int height = Convert::ToInt32(this->textBoxSpriteHeight->Text);

			array<Byte>^ spriteData = gcnew array<Byte>(width * height * 2); 

			for (int i = 0; i < width * height; i++) {
				spriteData[i * 2] = 0xFF; 
				spriteData[i * 2 + 1] = 0x00; 
			}

			
			int packetSize = 6 + spriteData->Length; 
			array<Byte>^ packet = gcnew array<Byte>(packetSize);
			packet[0] = 0x12; 
			packet[1] = (Byte)index; 
			packet[2] = (width >> 8) & 0xFF; 
			packet[3] = width & 0xFF; 
			packet[4] = (height >> 8) & 0xFF; 
			packet[5] = height & 0xFF; 

			for (int i = 0; i < spriteData->Length; i++) {
				packet[6 + i] = spriteData[i];
			}

			commandSender->SendCommand(packet);

			MessageBox::Show("Sprite created and sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter valid numeric values.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
	}

	private: System::Void btnShowSprite_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			
			int index = Convert::ToInt32(this->textBoxSpriteIndex->Text);
			int x = Convert::ToInt32(this->textBoxShowSpriteX->Text); 
			int y = Convert::ToInt32(this->textBoxShowSpriteY->Text); 

			
			array<Byte>^ packet = gcnew array<Byte>(6); 
			packet[0] = 0x13; 
			packet[1] = (Byte)index; 
			packet[2] = (x >> 8) & 0xFF; 
			packet[3] = x & 0xFF; 
			packet[4] = (y >> 8) & 0xFF; 
			packet[5] = y & 0xFF; 

			// Send the command
			commandSender->SendCommand(packet);

			MessageBox::Show("Sprite shown successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter valid numeric values.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
	}
	
	private: System::Void btnSendMarqueeText_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Отримуємо введені значення
			int y0 = Convert::ToInt32(this->textBoxMarqueeY->Text);
			int fontSize = Convert::ToInt32(this->textBoxFontSize->Text);
			String^ text = this->textBoxMarqueeText->Text;

			// Отримуємо введений колір у форматі RGB565
			int color = Convert::ToInt32(this->textBoxMarqueeTextColor->Text, 16);

			// Перетворюємо текст у байтовий масив
			array<Byte>^ textBytes = System::Text::Encoding::UTF8->GetBytes(text);
			int textLength = textBytes->Length;

			// Перевірка на максимальну довжину тексту
			if (textLength > 255) {
				MessageBox::Show("Text length exceeds the maximum allowed length of 255 bytes.", "Error");
				return;
			}

			// Створюємо пакет для команди
			array<Byte>^ packet = gcnew array<Byte>(7 + textLength); 
			packet[0] = 0x14; // ID команди для "рядка, що біжить"
			packet[1] = (y0 >> 8) & 0xFF; // Високий байт координати Y
			packet[2] = y0 & 0xFF; // Низький байт координати Y
			packet[3] = (color >> 8) & 0xFF; // Високий байт кольору
			packet[4] = color & 0xFF; // Низький байт кольору
			packet[5] = (fontSize & 0xFF); // Розмір шрифту
			packet[6] = (Byte)textLength; // Довжина тексту

			// Копіюємо байти тексту в пакет
			for (int i = 0; i < textLength; i++) {
				packet[7 + i] = textBytes[i];
			}

			// Відправляємо команду
			commandSender->SendCommand(packet);

			MessageBox::Show("Marquee text sent successfully!", "Success");
		}
		catch (FormatException^) {
			MessageBox::Show("Please enter valid numeric values.", "Error");
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error");
		}
	}
    


};
}
