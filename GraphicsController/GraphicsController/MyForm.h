#pragma once
#include "CommandSender.h"
#include <thread>

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
			commandSender = gcnew GraphicsController::CommandSender(); // ������������ ���������� CommandSender

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

			// �������� ������ �� ��������
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





	private:
		GraphicsController::CommandSender^ commandSender; // ���� ��� ��������� ���������� CommandSender

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
			this->button1->Location = System::Drawing::Point(222, 432);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(153, 58);
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
			this->label7->Size = System::Drawing::Size(269, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"������� ������� �� ������ ���������";
			// 
			// btnStartClock
			// 
			this->btnStartClock->Location = System::Drawing::Point(411, 193);
			this->btnStartClock->Name = L"btnStartClock";
			this->btnStartClock->Size = System::Drawing::Size(177, 33);
			this->btnStartClock->TabIndex = 15;
			this->btnStartClock->Text = L"�������� ���";
			this->btnStartClock->UseVisualStyleBackColor = true;
			this->btnStartClock->Click += gcnew System::EventHandler(this, &MyForm::btnStartClock_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(454, 35);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"X:";
			// 
			// textBoxClockX
			// 
			this->textBoxClockX->Location = System::Drawing::Point(488, 32);
			this->textBoxClockX->Name = L"textBoxClockX";
			this->textBoxClockX->Size = System::Drawing::Size(100, 22);
			this->textBoxClockX->TabIndex = 17;
			// 
			// textBoxClockY
			// 
			this->textBoxClockY->Location = System::Drawing::Point(488, 70);
			this->textBoxClockY->Name = L"textBoxClockY";
			this->textBoxClockY->Size = System::Drawing::Size(100, 22);
			this->textBoxClockY->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(453, 73);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(19, 16);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Y:";
			// 
			// textBoxColor
			// 
			this->textBoxColor->Location = System::Drawing::Point(488, 113);
			this->textBoxColor->Name = L"textBoxColor";
			this->textBoxColor->Size = System::Drawing::Size(100, 22);
			this->textBoxColor->TabIndex = 20;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(430, 116);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 16);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Color:";
			// 
			// textBoxClockFontSize
			// 
			this->textBoxClockFontSize->Location = System::Drawing::Point(488, 156);
			this->textBoxClockFontSize->Name = L"textBoxClockFontSize";
			this->textBoxClockFontSize->Size = System::Drawing::Size(100, 22);
			this->textBoxClockFontSize->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(405, 159);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 16);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Font size:";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(670, 515);
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
		
		// ������� �� �������� ����� ������������ �����
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

        // �������� ��������� ����
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

			this->textBox1->Visible = true; // ���� ��� �������� X
			this->textBox2->Visible = true; // ���� ��� �������� Y
			this->textBox3->Visible = true; // ���� ��� �������� �������
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
				// ������� ���� � ������ RGB565
				int color = Convert::ToInt32(this->textBox1->Text, 16); // �������� � ���������������� ������ (���������, "FFFF").
				if (color < 0 || color > 0xFFFF)
				{
					MessageBox::Show("Invalid color value. Please enter a valid 16-bit RGB565 color.", "Error");
					return;
				}

				// ������� ����� ��� �������
				array<Byte>^ packet = gcnew array<Byte>(3);
				packet[0] = 0x01; // ID �������
				packet[1] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[2] = color & 0xFF;        // �������� ���� �������

				// ������������ ����� CommandSender ��� ����������� �������
				commandSender->SendCommand(packet); // ��������� ����� SendCommand

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
				int x = Convert::ToInt32(this->textBox1->Text); // ������� ���������� X
				int y = Convert::ToInt32(this->textBox2->Text); // ������� ���������� Y
				int color = Convert::ToInt32(this->textBox3->Text, 16); // ������� ����

				// �������� �������� ��������� � �������
				if (x < 0 || y < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(7); 
				packet[0] = 0x02; // ID ������� ��� "Draw Pixel"
				packet[1] = (x >> 8) & 0xFF; // ������� ���� X
				packet[2] = x & 0xFF; // �������� ���� X
				packet[3] = (y >> 8) & 0xFF; // ������� ���� Y
				packet[4] = y & 0xFF; // �������� ���� Y
				packet[5] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[6] = color & 0xFF; // �������� ���� �������

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
				int x0 = Convert::ToInt32(this->textBox1->Text); // ������� ���������� X0
				int y0 = Convert::ToInt32(this->textBox2->Text); // ������� ���������� Y0
				int x1 = Convert::ToInt32(this->textBox3->Text); // ������� ���������� X1
				int y1 = Convert::ToInt32(this->textBox4->Text); // ������� ���������� Y1
				int color = Convert::ToInt32(this->textBox5->Text, 16); // ������� ����

				if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0 || color < 0 || color > 0xFFFF) {
					MessageBox::Show("Invalid input values. Please check your coordinates and color.", "Error");
					return;
				}

				array<Byte>^ packet = gcnew array<Byte>(11);
				packet[0] = 0x03; 
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (x1 >> 8) & 0xFF; // ������� ���� X1
				packet[6] = x1 & 0xFF; // �������� ���� X1
				packet[7] = (y1 >> 8) & 0xFF; // ������� ���� Y1
				packet[8] = y1 & 0xFF; // �������� ���� Y1
				packet[9] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[10] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (w >> 8) & 0xFF; // ������� ���� w
				packet[6] = w & 0xFF; // �������� ���� w
				packet[7] = (h >> 8) & 0xFF; // ������� ���� h
				packet[8] = h & 0xFF; // �������� ���� h
				packet[9] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[10] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (w >> 8) & 0xFF; // ������� ���� w
				packet[6] = w & 0xFF; // �������� ���� w
				packet[7] = (h >> 8) & 0xFF; // ������� ���� h
				packet[8] = h & 0xFF; // �������� ���� h
				packet[9] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[10] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (radius_x >> 8) & 0xFF; // ������� ���� radius_x
				packet[6] = radius_x & 0xFF; // �������� ���� radius_x
				packet[7] = (radius_y >> 8) & 0xFF; // ������� ���� radius_y
				packet[8] = radius_y & 0xFF; // �������� ���� radius_y
				packet[9] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[10] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (radius_x >> 8) & 0xFF; // ������� ���� radius_x
				packet[6] = radius_x & 0xFF; // �������� ���� radius_x
				packet[7] = (radius_y >> 8) & 0xFF; // ������� ���� radius_y
				packet[8] = radius_y & 0xFF; // �������� ���� radius_y
				packet[9] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[10] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (radius >> 8) & 0xFF; // ������� ���� radius
				packet[6] = radius & 0xFF; // �������� ���� radius
				packet[7] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[8] = color & 0xFF; // �������� ���� �������
				
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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (radius >> 8) & 0xFF; // ������� ���� radius
				packet[6] = radius & 0xFF; // �������� ���� radius
				packet[7] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[8] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (w >> 8) & 0xFF; // ������� ���� W
				packet[6] = w & 0xFF; // �������� ���� W
				packet[7] = (h >> 8) & 0xFF; // ������� ���� H
				packet[8] = h & 0xFF; // �������� ���� H
				packet[9] = (radius >> 8) & 0xFF; // ������� ���� radius
			    packet[10] = radius & 0xFF; // �������� ���� radius
				packet[11] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[12] = color & 0xFF; // �������� ���� �������

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
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (w >> 8) & 0xFF; // ������� ���� W
				packet[6] = w & 0xFF; // �������� ���� W
				packet[7] = (h >> 8) & 0xFF; // ������� ���� H
				packet[8] = h & 0xFF; // �������� ���� H
				packet[9] = (radius >> 8) & 0xFF; // ������� ���� radius
				packet[10] = radius & 0xFF; // �������� ���� radius
				packet[11] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[12] = color & 0xFF; // �������� ���� �������

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
				// ������� ��������
				int x0 = Convert::ToInt32(this->textBox1->Text);
				int y0 = Convert::ToInt32(this->textBox2->Text);
				int color = Convert::ToInt32(this->textBox3->Text, 16);
				int font = Convert::ToInt32(this->textBox4->Text);
				String^ text = this->textBox5->Text;

				// ����������� ��������� ������� ������
				int text_length = text->Length;

				// ���������� ������ ����
				if (x0 < 0 || y0 < 0 || color < 0 || color > 0xFFFF || font < 0 || text_length > 255) {
					MessageBox::Show("Invalid input values. Please check your inputs.", "Error");
					return;
				}

				// ���������� ������ ������
				int packet_length = 9 + text_length; // 8 ���������� ����� + ������� ������

				// ��������� ������
				array<Byte>^ packet = gcnew array<Byte>(packet_length);

				// ����� ������� �����
				packet[0] = 0x0C; // Command ID
				packet[1] = (x0 >> 8) & 0xFF; // ������� ���� X0
				packet[2] = x0 & 0xFF; // �������� ���� X0
				packet[3] = (y0 >> 8) & 0xFF; // ������� ���� Y0
				packet[4] = y0 & 0xFF; // �������� ���� Y0
				packet[5] = (color >> 8) & 0xFF; // ������� ���� �������
				packet[6] = color & 0xFF; // �������� ���� �������
				packet[7] = font; // ����� ������
				packet[8] = text_length; // ������� ������

				// ���������� ����� ����� �������
				for (int i = 0; i < text_length; i++) {
					if (i + 9 >= packet->Length) {
						throw gcnew Exception("Text length exceeds packet size.");
					}
					packet[9 + i] = (Byte)text[i];
				}

				// ³���������� ������ �� ������
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

    
	
};
}