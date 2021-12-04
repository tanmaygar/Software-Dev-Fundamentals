#pragma once
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
	/// Summary for profile_order
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class profile_order : public System::Windows::Forms::Form
	{
		/// <summary>
		/// Public variable for transfering the ID of the Order
		/// </summary>
		/// It transfers the ID of the user as String which is part of the public ref class and a member of System.
		String^ transfer_order_id;

	public:
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		profile_order(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_for_orderid">
		///  It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		profile_order(String^ input_for_orderid);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~profile_order();

	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes for Borrower/User
		/// </summary>
		System::Windows::Forms::GroupBox^ member_profile_group;
	private:
		/// <summary>
		/// A Read-Only TextBox with Date of Birth of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ dob_member_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with User ID of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ member_id_txt;
	private:
		/// <summary>
		/// Label for ID of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ member_id_lbl;

	private:
		/// <summary>
		/// Label for Name of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ name_lbl;
	private:
		/// <summary>
		/// Label for Date of Birth of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ dob_lbl;
	private:
		/// <summary>
		/// Label for Profession of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ profession_lbl;
	private:
		/// <summary>
		/// Label for Email of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ email_id_lbl;
	private:
		/// <summary>
		/// Label for Mobile Number of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ mobile_no_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Address of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ address_txt;
	private:
		/// <summary>
		/// Label for Address of the Non-Librarian User
		/// </summary>
		System::Windows::Forms::Label^ address_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Mobile Number of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ mobile_no_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Name of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ name_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Email of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ email_id_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Profession of Non-Librarian User
		/// </summary>
		System::Windows::Forms::TextBox^ profession_txt;
	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes for book
		/// </summary>
		System::Windows::Forms::GroupBox^ book_profile_group;
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
		/// Label for Date of Issue
		/// </summary>
		System::Windows::Forms::Label^ date_issue_lbl;
	private:
		/// <summary>
		/// Label for Date of Return
		/// </summary>
		System::Windows::Forms::Label^ date_return_lbl;
	private:
		/// <summary>
		/// Label for Fine
		/// </summary>
		System::Windows::Forms::Label^ fine_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Date of Issuing of the Book
		/// </summary>
		System::Windows::Forms::TextBox^ date_issue_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Date of Return
		/// </summary>
		System::Windows::Forms::TextBox^ date_return_txt;

	private:
		/// <summary>
		/// A Read-Only TextBox with Amount of Fine due
		/// </summary>
		System::Windows::Forms::TextBox^ order_fine_txt;
	private:
		/// <summary>
		/// Label for Order ID
		/// </summary>
		System::Windows::Forms::Label^ order_id_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Order ID
		/// </summary>
		System::Windows::Forms::TextBox^ order_id_txt;
	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(profile_order::typeid));
			this->member_profile_group = (gcnew System::Windows::Forms::GroupBox());
			this->dob_member_txt = (gcnew System::Windows::Forms::TextBox());
			this->member_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->member_id_lbl = (gcnew System::Windows::Forms::Label());
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->profession_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->profession_txt = (gcnew System::Windows::Forms::TextBox());
			this->book_profile_group = (gcnew System::Windows::Forms::GroupBox());
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
			this->date_issue_lbl = (gcnew System::Windows::Forms::Label());
			this->date_return_lbl = (gcnew System::Windows::Forms::Label());
			this->fine_lbl = (gcnew System::Windows::Forms::Label());
			this->date_issue_txt = (gcnew System::Windows::Forms::TextBox());
			this->date_return_txt = (gcnew System::Windows::Forms::TextBox());
			this->order_fine_txt = (gcnew System::Windows::Forms::TextBox());
			this->order_id_lbl = (gcnew System::Windows::Forms::Label());
			this->order_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->member_profile_group->SuspendLayout();
			this->book_profile_group->SuspendLayout();
			this->SuspendLayout();
			// 
			// member_profile_group
			// 
			this->member_profile_group->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->member_profile_group->Controls->Add(this->dob_member_txt);
			this->member_profile_group->Controls->Add(this->member_id_txt);
			this->member_profile_group->Controls->Add(this->member_id_lbl);
			this->member_profile_group->Controls->Add(this->name_lbl);
			this->member_profile_group->Controls->Add(this->dob_lbl);
			this->member_profile_group->Controls->Add(this->profession_lbl);
			this->member_profile_group->Controls->Add(this->email_id_lbl);
			this->member_profile_group->Controls->Add(this->mobile_no_lbl);
			this->member_profile_group->Controls->Add(this->address_txt);
			this->member_profile_group->Controls->Add(this->address_lbl);
			this->member_profile_group->Controls->Add(this->mobile_no_txt);
			this->member_profile_group->Controls->Add(this->name_txt);
			this->member_profile_group->Controls->Add(this->email_id_txt);
			this->member_profile_group->Controls->Add(this->profession_txt);
			this->member_profile_group->Location = System::Drawing::Point(88, 86);
			this->member_profile_group->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->member_profile_group->Name = L"member_profile_group";
			this->member_profile_group->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->member_profile_group->Size = System::Drawing::Size(598, 545);
			this->member_profile_group->TabIndex = 19;
			this->member_profile_group->TabStop = false;
			this->member_profile_group->Text = L"Member Profile";
			// 
			// dob_member_txt
			// 
			this->dob_member_txt->Location = System::Drawing::Point(256, 149);
			this->dob_member_txt->Name = L"dob_member_txt";
			this->dob_member_txt->ReadOnly = true;
			this->dob_member_txt->Size = System::Drawing::Size(150, 26);
			this->dob_member_txt->TabIndex = 18;
			// 
			// member_id_txt
			// 
			this->member_id_txt->Location = System::Drawing::Point(256, 42);
			this->member_id_txt->Name = L"member_id_txt";
			this->member_id_txt->ReadOnly = true;
			this->member_id_txt->Size = System::Drawing::Size(146, 26);
			this->member_id_txt->TabIndex = 17;
			// 
			// member_id_lbl
			// 
			this->member_id_lbl->AutoSize = true;
			this->member_id_lbl->Location = System::Drawing::Point(54, 38);
			this->member_id_lbl->Name = L"member_id_lbl";
			this->member_id_lbl->Size = System::Drawing::Size(26, 20);
			this->member_id_lbl->TabIndex = 0;
			this->member_id_lbl->Text = L"ID";
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(54, 89);
			this->name_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(51, 20);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(54, 158);
			this->dob_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(99, 20);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(54, 237);
			this->profession_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(84, 20);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(54, 317);
			this->email_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(66, 20);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(54, 397);
			this->mobile_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(83, 20);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(256, 472);
			this->address_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->address_txt->Name = L"address_txt";
			this->address_txt->ReadOnly = true;
			this->address_txt->Size = System::Drawing::Size(148, 26);
			this->address_txt->TabIndex = 11;
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(54, 477);
			this->address_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(68, 20);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(256, 392);
			this->mobile_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->ReadOnly = true;
			this->mobile_no_txt->Size = System::Drawing::Size(148, 26);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(256, 85);
			this->name_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->name_txt->Name = L"name_txt";
			this->name_txt->ReadOnly = true;
			this->name_txt->Size = System::Drawing::Size(148, 26);
			this->name_txt->TabIndex = 6;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(256, 312);
			this->email_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->ReadOnly = true;
			this->email_id_txt->Size = System::Drawing::Size(148, 26);
			this->email_id_txt->TabIndex = 9;
			// 
			// profession_txt
			// 
			this->profession_txt->Location = System::Drawing::Point(256, 232);
			this->profession_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->profession_txt->Name = L"profession_txt";
			this->profession_txt->ReadOnly = true;
			this->profession_txt->Size = System::Drawing::Size(148, 26);
			this->profession_txt->TabIndex = 8;
			// 
			// book_profile_group
			// 
			this->book_profile_group->Anchor = System::Windows::Forms::AnchorStyles::None;
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
			this->book_profile_group->Location = System::Drawing::Point(724, 95);
			this->book_profile_group->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_profile_group->Name = L"book_profile_group";
			this->book_profile_group->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_profile_group->Size = System::Drawing::Size(434, 554);
			this->book_profile_group->TabIndex = 20;
			this->book_profile_group->TabStop = false;
			this->book_profile_group->Text = L"Book Profile";
			// 
			// borrow_stat_txt
			// 
			this->borrow_stat_txt->Location = System::Drawing::Point(250, 258);
			this->borrow_stat_txt->Name = L"borrow_stat_txt";
			this->borrow_stat_txt->ReadOnly = true;
			this->borrow_stat_txt->Size = System::Drawing::Size(146, 26);
			this->borrow_stat_txt->TabIndex = 23;
			// 
			// borrow_stat_lbl
			// 
			this->borrow_stat_lbl->AutoSize = true;
			this->borrow_stat_lbl->Location = System::Drawing::Point(26, 262);
			this->borrow_stat_lbl->Name = L"borrow_stat_lbl";
			this->borrow_stat_lbl->Size = System::Drawing::Size(110, 20);
			this->borrow_stat_lbl->TabIndex = 22;
			this->borrow_stat_lbl->Text = L"Borrow Status";
			// 
			// book_id_txt
			// 
			this->book_id_txt->Location = System::Drawing::Point(250, 29);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->ReadOnly = true;
			this->book_id_txt->Size = System::Drawing::Size(146, 26);
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
			this->bookname_lbl->Location = System::Drawing::Point(26, 75);
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
			this->author_lbl->Location = System::Drawing::Point(26, 138);
			this->author_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(57, 20);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(250, 483);
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
			this->publisher_lbl->Location = System::Drawing::Point(26, 206);
			this->publisher_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(74, 20);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(250, 328);
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
			this->edition_no_lbl->Location = System::Drawing::Point(26, 332);
			this->edition_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(86, 20);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(250, 202);
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
			this->price_lbl->Location = System::Drawing::Point(27, 488);
			this->price_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(44, 20);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(250, 134);
			this->author_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->author_txt->Name = L"author_txt";
			this->author_txt->ReadOnly = true;
			this->author_txt->Size = System::Drawing::Size(148, 26);
			this->author_txt->TabIndex = 9;
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(250, 71);
			this->bookname_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->ReadOnly = true;
			this->bookname_txt->Size = System::Drawing::Size(148, 26);
			this->bookname_txt->TabIndex = 8;
			// 
			// date_issue_lbl
			// 
			this->date_issue_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_issue_lbl->AutoSize = true;
			this->date_issue_lbl->Location = System::Drawing::Point(1236, 106);
			this->date_issue_lbl->Name = L"date_issue_lbl";
			this->date_issue_lbl->Size = System::Drawing::Size(108, 20);
			this->date_issue_lbl->TabIndex = 26;
			this->date_issue_lbl->Text = L"Date Of Issue";
			// 
			// date_return_lbl
			// 
			this->date_return_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_return_lbl->AutoSize = true;
			this->date_return_lbl->Location = System::Drawing::Point(1236, 229);
			this->date_return_lbl->Name = L"date_return_lbl";
			this->date_return_lbl->Size = System::Drawing::Size(115, 20);
			this->date_return_lbl->TabIndex = 27;
			this->date_return_lbl->Text = L"Date of Return";
			// 
			// fine_lbl
			// 
			this->fine_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->fine_lbl->AutoSize = true;
			this->fine_lbl->Location = System::Drawing::Point(1262, 312);
			this->fine_lbl->Name = L"fine_lbl";
			this->fine_lbl->Size = System::Drawing::Size(40, 20);
			this->fine_lbl->TabIndex = 28;
			this->fine_lbl->Text = L"Fine";
			// 
			// date_issue_txt
			// 
			this->date_issue_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_issue_txt->Location = System::Drawing::Point(1246, 145);
			this->date_issue_txt->Name = L"date_issue_txt";
			this->date_issue_txt->ReadOnly = true;
			this->date_issue_txt->Size = System::Drawing::Size(103, 26);
			this->date_issue_txt->TabIndex = 29;
			// 
			// date_return_txt
			// 
			this->date_return_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_return_txt->Location = System::Drawing::Point(1244, 269);
			this->date_return_txt->Name = L"date_return_txt";
			this->date_return_txt->ReadOnly = true;
			this->date_return_txt->Size = System::Drawing::Size(100, 26);
			this->date_return_txt->TabIndex = 30;
			// 
			// order_fine_txt
			// 
			this->order_fine_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->order_fine_txt->Location = System::Drawing::Point(1246, 365);
			this->order_fine_txt->Name = L"order_fine_txt";
			this->order_fine_txt->ReadOnly = true;
			this->order_fine_txt->Size = System::Drawing::Size(103, 26);
			this->order_fine_txt->TabIndex = 31;
			// 
			// order_id_lbl
			// 
			this->order_id_lbl->AutoSize = true;
			this->order_id_lbl->Location = System::Drawing::Point(405, 38);
			this->order_id_lbl->Name = L"order_id_lbl";
			this->order_id_lbl->Size = System::Drawing::Size(74, 20);
			this->order_id_lbl->TabIndex = 32;
			this->order_id_lbl->Text = L"Order ID:";
			// 
			// order_id_txt
			// 
			this->order_id_txt->Location = System::Drawing::Point(502, 32);
			this->order_id_txt->Name = L"order_id_txt";
			this->order_id_txt->ReadOnly = true;
			this->order_id_txt->Size = System::Drawing::Size(133, 26);
			this->order_id_txt->TabIndex = 33;
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(12, 12);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(74, 45);
			this->back_button->TabIndex = 35;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_order::back_button_Click);
			// 
			// profile_order
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1444, 1018);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->order_id_txt);
			this->Controls->Add(this->order_id_lbl);
			this->Controls->Add(this->order_fine_txt);
			this->Controls->Add(this->date_return_txt);
			this->Controls->Add(this->date_issue_txt);
			this->Controls->Add(this->fine_lbl);
			this->Controls->Add(this->date_return_lbl);
			this->Controls->Add(this->date_issue_lbl);
			this->Controls->Add(this->book_profile_group);
			this->Controls->Add(this->member_profile_group);
			this->Name = L"profile_order";
			this->Text = L"LMS: Order Profile";
			this->Load += gcnew System::EventHandler(this, &profile_order::profile_order_Load);
			this->member_profile_group->ResumeLayout(false);
			this->member_profile_group->PerformLayout();
			this->book_profile_group->ResumeLayout(false);
			this->book_profile_group->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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
		System::Void profile_order_Load(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// Fill textboxes with data of the Borrower/User
		/// </summary>
		void fill_user_data();

	private:
		/// <summary>
		/// Fill textboxes with data of the Book Borrowed
		/// </summary>
		void fill_book_data();

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
