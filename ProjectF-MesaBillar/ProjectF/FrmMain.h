#pragma once
#include "Controller.h"

namespace ProjectF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	private:
		Controller* controller;
		Graphics^ g; //Lienzo

	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			g = panel1->CreateGraphics();
			controller = new Controller(g);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::ComponentModel::IContainer^ components;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel1->Location = System::Drawing::Point(1, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1021, 579);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMain::Game_MouseClick);
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LimeGreen;
			this->ClientSize = System::Drawing::Size(1023, 596);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"Mesa de billar";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMain::FrmMain_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Erase
		g->Clear(Color::LimeGreen);
		//Collision
		controller->collision();
		//Move
		controller->moveEverything(g);
		//Draw
		controller->drawEverything(g);
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		//case Keys::Click
		case Keys::Space:
			controller->addCircle2(); break;
		}
	}
	
	private: System::Void Game_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//switch (e->Clicks)
		//{
		//case Keys::Click
		//	case MouseClick = true;
		controller->addCircle(e->X,e->Y);
	}
	private: System::Void FrmMain_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//controller->addCircle2();
	}
};
}