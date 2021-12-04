#pragma once

#include "list_of_member_page.h"
#include "list_of_books_page.h"
#include "borrow_history_page.h"
#include "profile_member.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "AddBook.h"
#include "RegisterMember.h"
#include "RegisterLibrarian.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for HomePage
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class HomePage : public System::Windows::Forms::Form
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
		HomePage(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_transfer_id">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		HomePage(String^ input_transfer_id, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~HomePage();

	private:
		/// <summary>
		/// Button to Exit Appilcation
		/// </summary>
		System::Windows::Forms::Button^ exit_button;
	private:
		/// <summary>
		/// Button to view Books List
		/// </summary>
		System::Windows::Forms::Button^ booklist_btn;
	private:
		/// <summary>
		/// Button to view Member List
		/// </summary>
		System::Windows::Forms::Button^ member_list_btn;
	private:
		/// <summary>
		/// Button to Navigate to Add Book page
		/// </summary>
		System::Windows::Forms::Button^ addbook_btn;
	private:
		/// <summary>
		/// Button to Navigate to Member Registration page
		/// </summary>
		System::Windows::Forms::Button^ register_member_btn;
	private:
		/// <summary>
		/// Button to view Borrow History
		/// </summary>
		System::Windows::Forms::Button^ borrowhistory_btn;
	private:
		/// <summary>
		/// Button to Navigate to Borrow Book page
		/// </summary>
		System::Windows::Forms::Button^ borrowbook_btn;
	private:
		/// <summary>
		/// Button to Navigate to Return Book page
		/// </summary>
		System::Windows::Forms::Button^ returnbook_btn;
	private:
		/// <summary>
		/// Button to Logout user
		/// </summary>
		System::Windows::Forms::Button^ logout_button;
	private:
		/// <summary>
		/// Button to Navigate to Librarian Registration page
		/// </summary>
		System::Windows::Forms::Button^ registerlibrarian_btn;
	private:
		/// <summary>
		/// Button to View Profile of the Member
		/// </summary>
		System::Windows::Forms::Button^ view_profile_member_btn;

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
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->booklist_btn = (gcnew System::Windows::Forms::Button());
			this->member_list_btn = (gcnew System::Windows::Forms::Button());
			this->addbook_btn = (gcnew System::Windows::Forms::Button());
			this->register_member_btn = (gcnew System::Windows::Forms::Button());
			this->borrowhistory_btn = (gcnew System::Windows::Forms::Button());
			this->borrowbook_btn = (gcnew System::Windows::Forms::Button());
			this->returnbook_btn = (gcnew System::Windows::Forms::Button());
			this->logout_button = (gcnew System::Windows::Forms::Button());
			this->registerlibrarian_btn = (gcnew System::Windows::Forms::Button());
			this->view_profile_member_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exit_button
			// 
			this->exit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exit_button->Location = System::Drawing::Point(913, 11);
			this->exit_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(188, 69);
			this->exit_button->TabIndex = 0;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &HomePage::exit_button_Click);
			// 
			// booklist_btn
			// 
			this->booklist_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->booklist_btn->Location = System::Drawing::Point(468, 186);
			this->booklist_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->booklist_btn->Name = L"booklist_btn";
			this->booklist_btn->Size = System::Drawing::Size(182, 68);
			this->booklist_btn->TabIndex = 1;
			this->booklist_btn->Text = L"List of Books";
			this->booklist_btn->UseVisualStyleBackColor = true;
			this->booklist_btn->Click += gcnew System::EventHandler(this, &HomePage::booklist_btn_Click);
			// 
			// member_list_btn
			// 
			this->member_list_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->member_list_btn->Location = System::Drawing::Point(468, 335);
			this->member_list_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->member_list_btn->Name = L"member_list_btn";
			this->member_list_btn->Size = System::Drawing::Size(182, 68);
			this->member_list_btn->TabIndex = 2;
			this->member_list_btn->Text = L"List of Members";
			this->member_list_btn->UseVisualStyleBackColor = true;
			this->member_list_btn->Click += gcnew System::EventHandler(this, &HomePage::member_list_btn_Click);
			// 
			// addbook_btn
			// 
			this->addbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addbook_btn->Location = System::Drawing::Point(760, 335);
			this->addbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addbook_btn->Name = L"addbook_btn";
			this->addbook_btn->Size = System::Drawing::Size(182, 68);
			this->addbook_btn->TabIndex = 3;
			this->addbook_btn->Text = L"Add Book to Library";
			this->addbook_btn->UseVisualStyleBackColor = true;
			this->addbook_btn->Click += gcnew System::EventHandler(this, &HomePage::addbook_btn_Click);
			// 
			// register_member_btn
			// 
			this->register_member_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_member_btn->Location = System::Drawing::Point(189, 495);
			this->register_member_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->register_member_btn->Name = L"register_member_btn";
			this->register_member_btn->Size = System::Drawing::Size(182, 68);
			this->register_member_btn->TabIndex = 4;
			this->register_member_btn->Text = L"Register a Member";
			this->register_member_btn->UseVisualStyleBackColor = true;
			this->register_member_btn->Click += gcnew System::EventHandler(this, &HomePage::register_member_btn_Click);
			// 
			// borrowhistory_btn
			// 
			this->borrowhistory_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowhistory_btn->Location = System::Drawing::Point(760, 186);
			this->borrowhistory_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->borrowhistory_btn->Name = L"borrowhistory_btn";
			this->borrowhistory_btn->Size = System::Drawing::Size(182, 68);
			this->borrowhistory_btn->TabIndex = 5;
			this->borrowhistory_btn->Text = L"Borrow History";
			this->borrowhistory_btn->UseVisualStyleBackColor = true;
			this->borrowhistory_btn->Click += gcnew System::EventHandler(this, &HomePage::borrowhistory_btn_Click);
			// 
			// borrowbook_btn
			// 
			this->borrowbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowbook_btn->Location = System::Drawing::Point(189, 186);
			this->borrowbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->borrowbook_btn->Name = L"borrowbook_btn";
			this->borrowbook_btn->Size = System::Drawing::Size(182, 68);
			this->borrowbook_btn->TabIndex = 7;
			this->borrowbook_btn->Text = L"Borrow A Book";
			this->borrowbook_btn->UseVisualStyleBackColor = true;
			this->borrowbook_btn->Click += gcnew System::EventHandler(this, &HomePage::borrowbook_btn_Click);
			// 
			// returnbook_btn
			// 
			this->returnbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->returnbook_btn->Location = System::Drawing::Point(189, 335);
			this->returnbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->returnbook_btn->Name = L"returnbook_btn";
			this->returnbook_btn->Size = System::Drawing::Size(182, 68);
			this->returnbook_btn->TabIndex = 8;
			this->returnbook_btn->Text = L"Return A Book";
			this->returnbook_btn->UseVisualStyleBackColor = true;
			this->returnbook_btn->Click += gcnew System::EventHandler(this, &HomePage::returnbook_btn_Click);
			// 
			// logout_button
			// 
			this->logout_button->Location = System::Drawing::Point(12, 14);
			this->logout_button->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->logout_button->Name = L"logout_button";
			this->logout_button->Size = System::Drawing::Size(146, 66);
			this->logout_button->TabIndex = 9;
			this->logout_button->Text = L"Logout";
			this->logout_button->UseVisualStyleBackColor = true;
			this->logout_button->Click += gcnew System::EventHandler(this, &HomePage::logout_button_Click);
			// 
			// registerlibrarian_btn
			// 
			this->registerlibrarian_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerlibrarian_btn->Location = System::Drawing::Point(468, 495);
			this->registerlibrarian_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->registerlibrarian_btn->Name = L"registerlibrarian_btn";
			this->registerlibrarian_btn->Size = System::Drawing::Size(182, 68);
			this->registerlibrarian_btn->TabIndex = 10;
			this->registerlibrarian_btn->Text = L"Register a Librarian";
			this->registerlibrarian_btn->UseVisualStyleBackColor = true;
			this->registerlibrarian_btn->Click += gcnew System::EventHandler(this, &HomePage::registerlibrarian_btn_Click);
			// 
			// view_profile_member_btn
			// 
			this->view_profile_member_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->view_profile_member_btn->Location = System::Drawing::Point(205, 186);
			this->view_profile_member_btn->Name = L"view_profile_member_btn";
			this->view_profile_member_btn->Size = System::Drawing::Size(182, 68);
			this->view_profile_member_btn->TabIndex = 11;
			this->view_profile_member_btn->Text = L"View Profile";
			this->view_profile_member_btn->UseVisualStyleBackColor = true;
			this->view_profile_member_btn->Visible = false;
			this->view_profile_member_btn->Click += gcnew System::EventHandler(this, &HomePage::view_profile_member_btn_Click);
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1113, 712);
			this->Controls->Add(this->view_profile_member_btn);
			this->Controls->Add(this->registerlibrarian_btn);
			this->Controls->Add(this->logout_button);
			this->Controls->Add(this->returnbook_btn);
			this->Controls->Add(this->borrowbook_btn);
			this->Controls->Add(this->borrowhistory_btn);
			this->Controls->Add(this->register_member_btn);
			this->Controls->Add(this->addbook_btn);
			this->Controls->Add(this->member_list_btn);
			this->Controls->Add(this->booklist_btn);
			this->Controls->Add(this->exit_button);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(1120, 722);
			this->Name = L"HomePage";
			this->Text = L"LMS: Home Page";
			this->Load += gcnew System::EventHandler(this, &HomePage::HomePage_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		/// <summary>
		/// System::Void function to Navigate to BorrowBook page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void borrowbook_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to Books List page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void booklist_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to Borrow History page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void borrowhistory_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to Return Book page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void returnbook_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:

		/// <summary>
		/// System::Void function to Navigate to Member List page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void member_list_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to AddBook page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void addbook_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to Register Member page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void register_member_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Navigate to Register Librarian page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void registerlibrarian_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to View Member Profile page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		/// This function works only when the User is not a Librarian but a Member
		System::Void view_profile_member_btn_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Exit the Application
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function Logout user
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void logout_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to load the Home Page
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void HomePage_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
