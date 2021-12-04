#pragma once
//#include "connection_sql_func.h"
#include "written_functions/Borrow_book_functions.h"
#include "written_functions/connection_sql_func.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for BorrowBook
	/// </summary>
	public ref class BorrowBook : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		BorrowBook(void);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~BorrowBook();


	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes for Borrower/User
		/// </summary>
		System::Windows::Forms::GroupBox^ BorrowBook_group;

	private:
		/// <summary>
		/// A TextBox to take input of member_id, to Borrow a book for member 
		/// </summary>
		System::Windows::Forms::TextBox^ member_id_txt;

	private:
		/// <summary>
		/// A TextBox to take input of Book_id, for Book to borrow
		/// </summary>
		System::Windows::Forms::TextBox^ book_id_txt;

	private:
		/// <summary>
		/// Label for Book id
		/// </summary>
		System::Windows::Forms::Label^ book_id_lbl;

	private:
		/// <summary>
		/// Label for Member id
		/// </summary>
		System::Windows::Forms::Label^ member_id_lbl;


	private:
		/// <summary>
		/// Borrow button to borrow a Book
		/// </summary>
		System::Windows::Forms::Button^ borrow_button;


	private:
		/// <summary>
		/// Back button to navigate backward.
		/// </summary>
		System::Windows::Forms::Button^ Back_button;



	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->member_id_lbl = (gcnew System::Windows::Forms::Label());
			this->book_id_lbl = (gcnew System::Windows::Forms::Label());
			this->borrow_button = (gcnew System::Windows::Forms::Button());
			this->member_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->book_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->Back_button = (gcnew System::Windows::Forms::Button());
			this->BorrowBook_group = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->BorrowBook_group->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			this->fileSystemWatcher1->Changed += gcnew System::IO::FileSystemEventHandler(this, &BorrowBook::fileSystemWatcher1_Changed);
			// 
			// member_id_lbl
			// 
			this->member_id_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->member_id_lbl->AutoSize = true;
			this->member_id_lbl->Location = System::Drawing::Point(96, 63);
			this->member_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->member_id_lbl->Name = L"member_id_lbl";
			this->member_id_lbl->Size = System::Drawing::Size(88, 20);
			this->member_id_lbl->TabIndex = 0;
			this->member_id_lbl->Text = L"Member ID";
			// 
			// book_id_lbl
			// 
			this->book_id_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_lbl->AutoSize = true;
			this->book_id_lbl->Location = System::Drawing::Point(96, 149);
			this->book_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->book_id_lbl->Name = L"book_id_lbl";
			this->book_id_lbl->Size = System::Drawing::Size(67, 20);
			this->book_id_lbl->TabIndex = 1;
			this->book_id_lbl->Text = L"Book ID";
			this->book_id_lbl->Click += gcnew System::EventHandler(this, &BorrowBook::book_id_lbl_Click);
			// 
			// borrow_button
			// 
			this->borrow_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrow_button->Location = System::Drawing::Point(176, 246);
			this->borrow_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->borrow_button->Name = L"borrow_button";
			this->borrow_button->Size = System::Drawing::Size(112, 35);
			this->borrow_button->TabIndex = 2;
			this->borrow_button->Text = L"Borrow ";
			this->borrow_button->UseVisualStyleBackColor = true;
			this->borrow_button->Click += gcnew System::EventHandler(this, &BorrowBook::borrow_button_Click);
			// 
			// member_id_txt
			// 
			this->member_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->member_id_txt->Location = System::Drawing::Point(219, 58);
			this->member_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->member_id_txt->Name = L"member_id_txt";
			this->member_id_txt->Size = System::Drawing::Size(148, 26);
			this->member_id_txt->TabIndex = 3;
			this->member_id_txt->TextChanged += gcnew System::EventHandler(this, &BorrowBook::stud_id_txt_TextChanged);
			// 
			// book_id_txt
			// 
			this->book_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_txt->Location = System::Drawing::Point(219, 145);
			this->book_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->Size = System::Drawing::Size(148, 26);
			this->book_id_txt->TabIndex = 4;
			// 
			// Back_button
			// 
			this->Back_button->Image = Image::FromFile("images\\back-icon.png");
			this->Back_button->Location = System::Drawing::Point(78, 65);
			this->Back_button->Margin = System::Windows::Forms::Padding(2);
			this->Back_button->Name = L"Back_button";
			this->Back_button->Size = System::Drawing::Size(51, 45);
			this->Back_button->TabIndex = 16;
			this->Back_button->UseVisualStyleBackColor = true;
			this->Back_button->Click += gcnew System::EventHandler(this, &BorrowBook::Back_button_Click);
			// 
			// BorrowBook_group
			// 
			this->BorrowBook_group->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BorrowBook_group->Controls->Add(this->borrow_button);
			this->BorrowBook_group->Controls->Add(this->member_id_lbl);
			this->BorrowBook_group->Controls->Add(this->book_id_txt);
			this->BorrowBook_group->Controls->Add(this->book_id_lbl);
			this->BorrowBook_group->Controls->Add(this->member_id_txt);
			this->BorrowBook_group->Location = System::Drawing::Point(244, 188);
			this->BorrowBook_group->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->BorrowBook_group->Name = L"BorrowBook_group";
			this->BorrowBook_group->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->BorrowBook_group->Size = System::Drawing::Size(480, 340);
			this->BorrowBook_group->TabIndex = 17;
			this->BorrowBook_group->TabStop = false;
			this->BorrowBook_group->Text = L"Borrow Book";
			// 
			// BorrowBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 728);
			this->Controls->Add(this->BorrowBook_group);
			this->Controls->Add(this->Back_button);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(991, 758);
			this->Name = L"BorrowBook";
			this->Text = L"LMS: Borrow Book";
			this->Load += gcnew System::EventHandler(this, &BorrowBook::BorrowBook_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->BorrowBook_group->ResumeLayout(false);
			this->BorrowBook_group->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
	}


	private: System::Void BorrowBook_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void borrow_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Back_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void stud_id_txt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void book_id_lbl_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}