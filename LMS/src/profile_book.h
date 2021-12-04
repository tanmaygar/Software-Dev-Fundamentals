#pragma once
#include "written_functions/connection_sql_func.h"
#include "written_functions/filling_datagrid.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for profile_book
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class profile_book : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Public variable for transfering the ID of the Book
		/// </summary>
		/// It transfers the ID of the user as String which is part of the public ref class and a member of System.
		String^ transfer_id_book;

		/// <summary>
		/// Public variables for transfering whether the user is a librarian or not
		/// </summary>
		/// It transfers a boolean value with true representing the user is a librarian and false if the user is not a librarian
		bool transfer_isLibrarian;

	public:
		// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		profile_book(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="label_book_id">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="isLibrarian">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		profile_book(String^ label_book_id, bool isLibrarian);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~profile_book();

	private:
		/// <summary>
		/// A Read-Only TextBox for Status if Book is Lost or Not
		/// </summary>

	private:
		/// <summary>
		/// Label for Status if Book is Lost or Not
		/// </summary>


	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes
		/// </summary>
		System::Windows::Forms::GroupBox^ book_profile_group;
	private:
		/// <summary>
		/// A Read-Only TextBox with Book ID
		/// </summary>
		System::Windows::Forms::TextBox^ book_id_txt;
	private:
		/// <summary>
		/// Label for Book ID
		/// </summary>
		System::Windows::Forms::Label^ book_id_lbl;
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
		/// A Read-Only TextBox with Price of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ price_txt;
	private:
		/// <summary>
		/// Label for Book Publisher
		/// </summary>
		System::Windows::Forms::Label^ publisher_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Edition No of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ edition_no_txt;
	private:
		/// <summary>
		/// Label for Book Edition
		/// </summary>
		System::Windows::Forms::Label^ edition_no_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Name of Publisher of Book
		/// </summary>
		System::Windows::Forms::TextBox^ publisher_txt;
	private:
		/// <summary>
		/// Label for Book Price
		/// </summary>
		System::Windows::Forms::Label^ price_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Author of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ author_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Name of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ bookname_txt;
	private:
		/// <summary>
		/// Button to Initiate Update Profile Mode
		/// </summary>
		System::Windows::Forms::Button^ update_profile_button;
	private:
		/// <summary>
		/// Button to delete profile of the User
		/// </summary>
		System::Windows::Forms::Button^ delete_profile_button;
	private:
		/// <summary>
		/// Button to Confirm the Changes made to the profile
		/// </summary>
		System::Windows::Forms::Button^ confirm_change_button;
	private:
		/// <summary>
		/// A Read-Only TextBox with Borrow Status of the Book as BORROWED or AVAILABLE
		/// </summary>
		System::Windows::Forms::TextBox^ borrow_stat_txt;
	private:
		/// <summary>
		/// Label for Book Status 
		/// </summary>
		System::Windows::Forms::Label^ borrow_stat_lbl;
	private:
		/// <summary>
		/// Data Grid to present other Copies of the Book with general details
		/// </summary>
		/// @see Open_profile
		System::Windows::Forms::DataGridView^ book_copies_dataGridView;
	private:
		/// <summary>
		/// A dedicated button inside the Data Grid to open the profile of other copies of the same book
		/// </summary>
		/// @see book_copies_dataGridView
		System::Windows::Forms::DataGridViewButtonColumn^ Open_profile;
	private:
		/// <summary>
		/// A Read-Only TextBox with Number of Copies in the Library of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ no_copies_txt;
	private:
		/// <summary>
		/// Label for Number of Copies in the Library of the Book
		/// </summary>
		System::Windows::Forms::Label^ no_copies_lbl;
	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button;
	private:
		/// <summary>
		/// A numeric UpDown for adding new copies to the database
		/// </summary>
		System::Windows::Forms::NumericUpDown^ numeric_updown_no_copies;
	private:
		/// <summary>
		/// A Read-Only TextBox with Category of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ category_txt;
	private:
		/// <summary>
		/// Label for Book Category
		/// </summary>
		System::Windows::Forms::Label^ category_lbl;
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
			this->book_profile_group = (gcnew System::Windows::Forms::GroupBox());
			this->category_txt = (gcnew System::Windows::Forms::TextBox());
			this->category_lbl = (gcnew System::Windows::Forms::Label());
			this->no_copies_lbl = (gcnew System::Windows::Forms::Label());
			this->no_copies_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_lbl = (gcnew System::Windows::Forms::Label());
			this->book_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->book_id_lbl = (gcnew System::Windows::Forms::Label());
			this->bookname_lbl = (gcnew System::Windows::Forms::Label());
			this->author_lbl = (gcnew System::Windows::Forms::Label());
			this->price_txt = (gcnew System::Windows::Forms::TextBox());
			this->publisher_lbl = (gcnew System::Windows::Forms::Label());
			this->edition_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->edition_no_lbl = (gcnew System::Windows::Forms::Label());
			this->publisher_txt = (gcnew System::Windows::Forms::TextBox());
			this->price_lbl = (gcnew System::Windows::Forms::Label());
			this->author_txt = (gcnew System::Windows::Forms::TextBox());
			this->bookname_txt = (gcnew System::Windows::Forms::TextBox());
			this->update_profile_button = (gcnew System::Windows::Forms::Button());
			this->delete_profile_button = (gcnew System::Windows::Forms::Button());
			this->confirm_change_button = (gcnew System::Windows::Forms::Button());
			this->book_copies_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Open_profile = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->numeric_updown_no_copies = (gcnew System::Windows::Forms::NumericUpDown());
			this->book_profile_group->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->book_copies_dataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_updown_no_copies))->BeginInit();
			this->SuspendLayout();
			// 
			// book_profile_group
			// 
			this->book_profile_group->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_profile_group->Controls->Add(this->category_txt);
			this->book_profile_group->Controls->Add(this->category_lbl);
			this->book_profile_group->Controls->Add(this->no_copies_lbl);
			this->book_profile_group->Controls->Add(this->no_copies_txt);
			this->book_profile_group->Controls->Add(this->borrow_stat_txt);
			this->book_profile_group->Controls->Add(this->borrow_stat_lbl);
			this->book_profile_group->Controls->Add(this->book_id_txt);
			this->book_profile_group->Controls->Add(this->book_id_lbl);
			this->book_profile_group->Controls->Add(this->bookname_lbl);
			this->book_profile_group->Controls->Add(this->author_lbl);
			this->book_profile_group->Controls->Add(this->price_txt);
			this->book_profile_group->Controls->Add(this->publisher_lbl);
			this->book_profile_group->Controls->Add(this->edition_no_txt);
			this->book_profile_group->Controls->Add(this->edition_no_lbl);
			this->book_profile_group->Controls->Add(this->publisher_txt);
			this->book_profile_group->Controls->Add(this->price_lbl);
			this->book_profile_group->Controls->Add(this->author_txt);
			this->book_profile_group->Controls->Add(this->bookname_txt);
			this->book_profile_group->Location = System::Drawing::Point(735, 58);
			this->book_profile_group->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_profile_group->Name = L"book_profile_group";
			this->book_profile_group->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_profile_group->Size = System::Drawing::Size(434, 572);
			this->book_profile_group->TabIndex = 19;
			this->book_profile_group->TabStop = false;
			this->book_profile_group->Text = L"Book Profile";
			// 
			// category_txt
			// 
			this->category_txt->Location = System::Drawing::Point(250, 448);
			this->category_txt->Name = L"category_txt";
			this->category_txt->ReadOnly = true;
			this->category_txt->Size = System::Drawing::Size(148, 26);
			this->category_txt->TabIndex = 27;
			// 
			// category_lbl
			// 
			this->category_lbl->AutoSize = true;
			this->category_lbl->Location = System::Drawing::Point(26, 448);
			this->category_lbl->Name = L"category_lbl";
			this->category_lbl->Size = System::Drawing::Size(73, 20);
			this->category_lbl->TabIndex = 26;
			this->category_lbl->Text = L"Category";
			// 
			// no_copies_lbl
			// 
			this->no_copies_lbl->AutoSize = true;
			this->no_copies_lbl->Location = System::Drawing::Point(26, 362);
			this->no_copies_lbl->Name = L"no_copies_lbl";
			this->no_copies_lbl->Size = System::Drawing::Size(101, 20);
			this->no_copies_lbl->TabIndex = 25;
			this->no_copies_lbl->Text = L"No. of copies";
			// 
			// no_copies_txt
			// 
			this->no_copies_txt->Location = System::Drawing::Point(250, 362);
			this->no_copies_txt->Name = L"no_copies_txt";
			this->no_copies_txt->ReadOnly = true;
			this->no_copies_txt->Size = System::Drawing::Size(148, 26);
			this->no_copies_txt->TabIndex = 24;
			// 
			// borrow_stat_txt
			// 
			this->borrow_stat_txt->Location = System::Drawing::Point(250, 249);
			this->borrow_stat_txt->Name = L"borrow_stat_txt";
			this->borrow_stat_txt->ReadOnly = true;
			this->borrow_stat_txt->Size = System::Drawing::Size(148, 26);
			this->borrow_stat_txt->TabIndex = 23;
			// 
			// borrow_stat_lbl
			// 
			this->borrow_stat_lbl->AutoSize = true;
			this->borrow_stat_lbl->Location = System::Drawing::Point(26, 255);
			this->borrow_stat_lbl->Name = L"borrow_stat_lbl";
			this->borrow_stat_lbl->Size = System::Drawing::Size(110, 20);
			this->borrow_stat_lbl->TabIndex = 22;
			this->borrow_stat_lbl->Text = L"Borrow Status";
			// 
			// book_id_txt
			// 
			this->book_id_txt->Location = System::Drawing::Point(250, 26);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->ReadOnly = true;
			this->book_id_txt->Size = System::Drawing::Size(148, 26);
			this->book_id_txt->TabIndex = 21;
			// 
			// book_id_lbl
			// 
			this->book_id_lbl->AutoSize = true;
			this->book_id_lbl->Location = System::Drawing::Point(26, 35);
			this->book_id_lbl->Name = L"book_id_lbl";
			this->book_id_lbl->Size = System::Drawing::Size(26, 20);
			this->book_id_lbl->TabIndex = 20;
			this->book_id_lbl->Text = L"ID";
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(26, 85);
			this->bookname_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(51, 20);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(26, 143);
			this->author_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(57, 20);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(250, 498);
			this->price_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->price_txt->Name = L"price_txt";
			this->price_txt->ReadOnly = true;
			this->price_txt->Size = System::Drawing::Size(148, 26);
			this->price_txt->TabIndex = 14;
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(26, 198);
			this->publisher_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(74, 20);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(250, 308);
			this->edition_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->ReadOnly = true;
			this->edition_no_txt->Size = System::Drawing::Size(148, 26);
			this->edition_no_txt->TabIndex = 12;
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(26, 308);
			this->edition_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(86, 20);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(250, 192);
			this->publisher_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->ReadOnly = true;
			this->publisher_txt->Size = System::Drawing::Size(148, 26);
			this->publisher_txt->TabIndex = 10;
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(33, 505);
			this->price_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(44, 20);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(250, 137);
			this->author_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->author_txt->Name = L"author_txt";
			this->author_txt->ReadOnly = true;
			this->author_txt->Size = System::Drawing::Size(148, 26);
			this->author_txt->TabIndex = 9;
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(250, 78);
			this->bookname_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->ReadOnly = true;
			this->bookname_txt->Size = System::Drawing::Size(148, 26);
			this->bookname_txt->TabIndex = 8;
			// 
			// update_profile_button
			// 
			this->update_profile_button->Location = System::Drawing::Point(1370, 12);
			this->update_profile_button->Name = L"update_profile_button";
			this->update_profile_button->Size = System::Drawing::Size(206, 49);
			this->update_profile_button->TabIndex = 22;
			this->update_profile_button->Text = L"UPDATE PROFILE";
			this->update_profile_button->UseVisualStyleBackColor = true;
			this->update_profile_button->Click += gcnew System::EventHandler(this, &profile_book::update_profile_button_Click);
			// 
			// delete_profile_button
			// 
			this->delete_profile_button->Location = System::Drawing::Point(1372, 68);
			this->delete_profile_button->Name = L"delete_profile_button";
			this->delete_profile_button->Size = System::Drawing::Size(202, 45);
			this->delete_profile_button->TabIndex = 21;
			this->delete_profile_button->Text = L"DELETE PROFILE";
			this->delete_profile_button->UseVisualStyleBackColor = true;
			this->delete_profile_button->Click += gcnew System::EventHandler(this, &profile_book::delete_profile_button_Click);
			// 
			// confirm_change_button
			// 
			this->confirm_change_button->Location = System::Drawing::Point(1377, 118);
			this->confirm_change_button->Name = L"confirm_change_button";
			this->confirm_change_button->Size = System::Drawing::Size(198, 42);
			this->confirm_change_button->TabIndex = 23;
			this->confirm_change_button->Text = L"MAKE CHANGES";
			this->confirm_change_button->UseVisualStyleBackColor = true;
			this->confirm_change_button->Visible = false;
			this->confirm_change_button->Click += gcnew System::EventHandler(this, &profile_book::confirm_change_button_Click);
			// 
			// book_copies_dataGridView
			// 
			this->book_copies_dataGridView->AllowUserToAddRows = false;
			this->book_copies_dataGridView->AllowUserToDeleteRows = false;
			this->book_copies_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->book_copies_dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open_profile });
			this->book_copies_dataGridView->Location = System::Drawing::Point(12, 12);
			this->book_copies_dataGridView->MultiSelect = false;
			this->book_copies_dataGridView->Name = L"book_copies_dataGridView";
			this->book_copies_dataGridView->ReadOnly = true;
			this->book_copies_dataGridView->RowHeadersWidth = 62;
			this->book_copies_dataGridView->RowTemplate->Height = 28;
			this->book_copies_dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->book_copies_dataGridView->Size = System::Drawing::Size(696, 340);
			this->book_copies_dataGridView->TabIndex = 24;
			this->book_copies_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &profile_book::book_copies_dataGridView_CellContentClick);
			// 
			// Open_profile
			// 
			this->Open_profile->HeaderText = L"Profile";
			this->Open_profile->MinimumWidth = 8;
			this->Open_profile->Name = L"Open_profile";
			this->Open_profile->ReadOnly = true;
			this->Open_profile->Text = L"Open";
			this->Open_profile->UseColumnTextForButtonValue = true;
			this->Open_profile->Width = 150;
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(12, 700);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(74, 48);
			this->back_button->TabIndex = 25;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_book::back_button_Click);
			// 
			// numeric_updown_no_copies
			// 
			this->numeric_updown_no_copies->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numeric_updown_no_copies->Location = System::Drawing::Point(1176, 452);
			this->numeric_updown_no_copies->Name = L"numeric_updown_no_copies";
			this->numeric_updown_no_copies->Size = System::Drawing::Size(120, 26);
			this->numeric_updown_no_copies->TabIndex = 26;
			this->numeric_updown_no_copies->Visible = false;
			// 
			// profile_book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1392, 760);
			this->Controls->Add(this->numeric_updown_no_copies);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->book_copies_dataGridView);
			this->Controls->Add(this->confirm_change_button);
			this->Controls->Add(this->update_profile_button);
			this->Controls->Add(this->delete_profile_button);
			this->Controls->Add(this->book_profile_group);
			this->Name = L"profile_book";
			this->Text = L"LMS: Book Profile";
			this->Load += gcnew System::EventHandler(this, &profile_book::profile_book_Load);
			this->book_profile_group->ResumeLayout(false);
			this->book_profile_group->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->book_copies_dataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_updown_no_copies))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		/// <summary>
		/// System::Void function to load the form
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void profile_book_Load(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to toggle into Update Mode to update the file
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void update_profile_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Delete Profile
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to toggle into Read Mode and Send the Confirmed Changes
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick cell in the Data Grid
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled by the Data Grid.
		/// </param>
		System::Void book_copies_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

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
		System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
