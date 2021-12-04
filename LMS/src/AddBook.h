#pragma once
#include "pch.h"
namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for AddBook
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class AddBook : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Public variable for transfering the ID of the Book
		/// </summary>
		/// It transfers the ID of the user as String which is part of the public ref class and a member of System.
		String^ transfer_id;

		/// <summary>
		/// Public variables for transfering whether the user is a librarian or not
		/// </summary>
		/// It transfers a boolean value with true representing the user is a librarian and false if the user is not a librarian
		bool is_librarian;

	public:
		// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		AddBook(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_transfer_id">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		AddBook(String^ input_transfer_id, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~AddBook();

	private:
		/// <summary>
		/// Label for Book Name
		/// </summary>
		System::Windows::Forms::Label^ bookname_lbl;
	private:
		/// <summary>
		/// Label for Book Author
		/// </summary>
		System::Windows::Forms::Label^ author_lbl;
	private:
		/// <summary>
		/// Label for Book Publisher
		/// </summary>
		System::Windows::Forms::Label^ publisher_lbl;
	private:
		/// <summary>
		/// Label for Book Category
		/// </summary>
		System::Windows::Forms::Label^ category_lbl;
	private:
		/// <summary>
		/// Label for Edition No. of the Book
		/// </summary>
		System::Windows::Forms::Label^ edition_no_lbl;
	private:
		/// <summary>
		/// Label for No. of copies being added
		/// </summary>
		System::Windows::Forms::Label^ no_of_copies_lbl;
	private:
		/// <summary>
		/// Label for Price of the Book
		/// </summary>
		System::Windows::Forms::Label^ price_lbl;
	private:
		/// <summary>
		/// Input TextBox for Name of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ bookname_txt;
	private:
		/// <summary>
		/// Input TextBox for Author of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ author_txt;
	private:
		/// <summary>
		/// Input TextBox for Book's Publisher
		/// </summary>
		System::Windows::Forms::TextBox^ publisher_txt;
	private:
		/// <summary>
		/// Input TextBox for Category of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ category_txt;
	private:
		/// <summary>
		/// Input TextBox for Edition Number of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ edition_no_txt;
	private:
		/// <summary>
		/// Input TextBox for No. of copies being added
		/// </summary>
		System::Windows::Forms::TextBox^ no_of_copies_txt;
	private:
		/// <summary>
		/// Input TextBox for Price of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ price_txt;
	private:
		/// <summary>
		/// Button to Add Books into the Library Database
		/// </summary>
		System::Windows::Forms::Button^ add_button;
	private:
		/// <summary>
		/// Button for navigating to HomePage
		/// </summary>
		System::Windows::Forms::Button^ back_button;

	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes
		/// </summary>
		System::Windows::Forms::GroupBox^ groupBox1;

	private:
		/// <summary>
		/// ListBox to display the ID's of the books added
		/// </summary>
		System::Windows::Forms::ListBox^ id_listbox;

	protected:

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
		/// To Initialize all the components required to load the form
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddBook::typeid));
			this->bookname_lbl = (gcnew System::Windows::Forms::Label());
			this->author_lbl = (gcnew System::Windows::Forms::Label());
			this->publisher_lbl = (gcnew System::Windows::Forms::Label());
			this->category_lbl = (gcnew System::Windows::Forms::Label());
			this->edition_no_lbl = (gcnew System::Windows::Forms::Label());
			this->no_of_copies_lbl = (gcnew System::Windows::Forms::Label());
			this->price_lbl = (gcnew System::Windows::Forms::Label());
			this->bookname_txt = (gcnew System::Windows::Forms::TextBox());
			this->author_txt = (gcnew System::Windows::Forms::TextBox());
			this->publisher_txt = (gcnew System::Windows::Forms::TextBox());
			this->category_txt = (gcnew System::Windows::Forms::TextBox());
			this->edition_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->no_of_copies_txt = (gcnew System::Windows::Forms::TextBox());
			this->price_txt = (gcnew System::Windows::Forms::TextBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->id_listbox = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(17, 49);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(35, 13);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(17, 90);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(38, 13);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(17, 134);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(50, 13);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// category_lbl
			// 
			this->category_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->category_lbl->AutoSize = true;
			this->category_lbl->Location = System::Drawing::Point(18, 177);
			this->category_lbl->Name = L"category_lbl";
			this->category_lbl->Size = System::Drawing::Size(49, 13);
			this->category_lbl->TabIndex = 3;
			this->category_lbl->Text = L"Category";
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(17, 216);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(59, 13);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// no_of_copies_lbl
			// 
			this->no_of_copies_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->no_of_copies_lbl->AutoSize = true;
			this->no_of_copies_lbl->Location = System::Drawing::Point(17, 266);
			this->no_of_copies_lbl->Name = L"no_of_copies_lbl";
			this->no_of_copies_lbl->Size = System::Drawing::Size(70, 13);
			this->no_of_copies_lbl->TabIndex = 5;
			this->no_of_copies_lbl->Text = L"No. of copies";
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(18, 317);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(31, 13);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(167, 46);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->Size = System::Drawing::Size(100, 20);
			this->bookname_txt->TabIndex = 8;
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(167, 87);
			this->author_txt->Name = L"author_txt";
			this->author_txt->Size = System::Drawing::Size(100, 20);
			this->author_txt->TabIndex = 9;
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(167, 131);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->Size = System::Drawing::Size(100, 20);
			this->publisher_txt->TabIndex = 10;
			// 
			// category_txt
			// 
			this->category_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->category_txt->Location = System::Drawing::Point(167, 174);
			this->category_txt->Name = L"category_txt";
			this->category_txt->Size = System::Drawing::Size(100, 20);
			this->category_txt->TabIndex = 11;
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(167, 213);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->Size = System::Drawing::Size(100, 20);
			this->edition_no_txt->TabIndex = 12;
			// 
			// no_of_copies_txt
			// 
			this->no_of_copies_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->no_of_copies_txt->Location = System::Drawing::Point(167, 263);
			this->no_of_copies_txt->Name = L"no_of_copies_txt";
			this->no_of_copies_txt->Size = System::Drawing::Size(100, 20);
			this->no_of_copies_txt->TabIndex = 13;
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(167, 314);
			this->price_txt->Name = L"price_txt";
			this->price_txt->Size = System::Drawing::Size(100, 20);
			this->price_txt->TabIndex = 14;
			// 
			// add_button
			// 
			this->add_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->add_button->Location = System::Drawing::Point(433, 549);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(121, 43);
			this->add_button->TabIndex = 16;
			this->add_button->Text = L"Add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &AddBook::AddBook_Click);
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(58, 49);
			this->back_button->Margin = System::Windows::Forms::Padding(2);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(50, 29);
			this->back_button->TabIndex = 17;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &AddBook::BackButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->no_of_copies_txt);
			this->groupBox1->Controls->Add(this->bookname_lbl);
			this->groupBox1->Controls->Add(this->author_lbl);
			this->groupBox1->Controls->Add(this->price_txt);
			this->groupBox1->Controls->Add(this->publisher_lbl);
			this->groupBox1->Controls->Add(this->category_lbl);
			this->groupBox1->Controls->Add(this->edition_no_txt);
			this->groupBox1->Controls->Add(this->edition_no_lbl);
			this->groupBox1->Controls->Add(this->category_txt);
			this->groupBox1->Controls->Add(this->no_of_copies_lbl);
			this->groupBox1->Controls->Add(this->publisher_txt);
			this->groupBox1->Controls->Add(this->price_lbl);
			this->groupBox1->Controls->Add(this->author_txt);
			this->groupBox1->Controls->Add(this->bookname_txt);
			this->groupBox1->Location = System::Drawing::Point(348, 131);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(289, 360);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add Book";
			// 
			// id_listbox
			// 
			this->id_listbox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->id_listbox->FormattingEnabled = true;
			this->id_listbox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"", L"ID\'s of the books added recently : " });
			this->id_listbox->Location = System::Drawing::Point(761, 177);
			this->id_listbox->Name = L"id_listbox";
			this->id_listbox->Size = System::Drawing::Size(226, 251);
			this->id_listbox->TabIndex = 21;
			this->id_listbox->Visible = false;
			// 
			// AddBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1113, 674);
			this->Controls->Add(this->id_listbox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->add_button);
			this->Name = L"AddBook";
			this->Text = L"LMS: Add Book";
			this->Load += gcnew System::EventHandler(this, &AddBook::AddBook_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		/// <summary>
		/// System::Void function to Load AddBook form
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void AddBook_Load(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Add Books into the Library database considering the details provided 
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void AddBook_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick of back button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
