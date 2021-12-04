#pragma once
#include "written_functions/connection_sql_func.h"
#include "profile_order.h"
#include "written_functions/filling_datagrid.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	// <summary>
	/// Summary for profile_member
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class profile_member : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Public variable for transfering the ID of the member
		/// </summary>
		/// It transfers the ID of the member as String which is part of the public ref class and a member of System.
		String^ transfer_id;

		/// <summary>
		/// Public variable to denote number of books currently borrowed by the Member
		/// </summary>
		int member_no_book_stat;
	public:

		/// <summary>
		/// Public variables for transfering whether the user is a librarian or not
		/// </summary>
		/// It transfers a boolean value with true representing the user is a librarian and false if the user is not a librarian
		bool is_librarian;

		/// <summary>
			/// Constructor function for the form
			/// </summary>
			/// <param name="void"></param>
		profile_member(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_id_transfer">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		profile_member(String^ input_id_transfer, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~profile_member();

	private:
		/// <summary>
		/// Label for ID of the Member
		/// </summary>
		System::Windows::Forms::Label^ member_id_lbl;
	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes
		/// </summary>
		System::Windows::Forms::GroupBox^ member_profile_group;
	private:
		/// <summary>
		/// A Read-Only TextBox with Status of Membership
		/// </summary>
		System::Windows::Forms::TextBox^ member_stat_text;
	private:
		/// <summary>
		/// A Date-Time Picker for choosing Date of Birth
		/// </summary>

	private:
		/// <summary>
		/// Label for Name of the Member
		/// </summary>
		System::Windows::Forms::Label^ name_lbl;
	private:
		/// <summary>
		/// Label for Date of Birth of the Member
		/// </summary>
		System::Windows::Forms::Label^ dob_lbl;
	private:
		/// <summary>
		/// Label for Profession of the Member
		/// </summary>
		System::Windows::Forms::Label^ profession_lbl;
	private:
		/// <summary>
		/// Label for Membership Status of the Member
		/// </summary>
		System::Windows::Forms::Label^ member_stat_label;
	private:
		/// <summary>
		/// Label for Email of the Member
		/// </summary>
		System::Windows::Forms::Label^ email_id_lbl;
	private:
		/// <summary>
		/// Label for Mobile Number of the Member
		/// </summary>
		System::Windows::Forms::Label^ mobile_no_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Address of Member
		/// </summary>
		System::Windows::Forms::TextBox^ address_txt;
	private:
		/// <summary>
		/// Label for Address of the Member
		/// </summary>
		System::Windows::Forms::Label^ address_lbl;
	private:
		/// <summary>
		/// A Read-Only TextBox with Mobile Number of Member
		/// </summary>
		System::Windows::Forms::TextBox^ mobile_no_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Name of Member
		/// </summary>
		System::Windows::Forms::TextBox^ name_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Email of Member
		/// </summary>
		System::Windows::Forms::TextBox^ email_id_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Profession of Member
		/// </summary>
		System::Windows::Forms::TextBox^ profession_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with User ID of Member
		/// </summary>
		System::Windows::Forms::TextBox^ member_id_txt;
	private:
		/// <summary>
		/// A Read-Only TextBox with Date of Birth of Member
		/// </summary>
		System::Windows::Forms::TextBox^ dob_member_txt;
	private:
		/// <summary>
		/// Button to delete profile of the User
		/// </summary>
		System::Windows::Forms::Button^ delete_profile_button;
	private:
		/// <summary>
		/// Button to Initiate Update Profile Mode
		/// </summary>
		System::Windows::Forms::Button^ update_profile_button;
	private:
		/// <summary>
		/// Button to Confirm the Changes made to the profile
		/// </summary>
		System::Windows::Forms::Button^ confirm_change_button;
	private:
		/// <summary>
		/// A drop down list to choose Profession of the User between Student, Faculty, Alumni
		/// </summary>
		System::Windows::Forms::ComboBox^ profession_selector;
	private:
		/// <summary>
		/// Data Grid to present the General Data of the Books Borrowed by the User
		/// </summary>
		/// @see Open_profile
		System::Windows::Forms::DataGridView^ member_borrow_history_dataGridView;
	private:
		/// <summary>
		/// A dedicated button inside the Data Grid to open the profile of Borrow History with more details
		/// </summary>
		/// @see member_borrow_history_dataGridView
		System::Windows::Forms::DataGridViewButtonColumn^ Open_profile;
	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button;

	private:
		/// <summary>
		/// Change Password of the Member
		/// </summary>
		System::Windows::Forms::Button^ change_pass_btn;

	private: 
		/// <summary>
		/// TextBox for entering new Password
		/// </summary>
		System::Windows::Forms::TextBox^ new_pass_txt;

	private:
		/// <summary>
		/// Label of New Password
		/// </summary>
		System::Windows::Forms::Label^ new_pass_lbl;

	private: 
		/// <summary>
		/// Confirm new password button 
		/// </summary>
		System::Windows::Forms::Button^ confirm_newpass_btn;

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
			this->member_id_lbl = (gcnew System::Windows::Forms::Label());
			this->member_profile_group = (gcnew System::Windows::Forms::GroupBox());
			this->new_pass_txt = (gcnew System::Windows::Forms::TextBox());
			this->new_pass_lbl = (gcnew System::Windows::Forms::Label());
			this->member_stat_text = (gcnew System::Windows::Forms::TextBox());
			this->member_stat_label = (gcnew System::Windows::Forms::Label());
			this->profession_selector = (gcnew System::Windows::Forms::ComboBox());
			this->dob_member_txt = (gcnew System::Windows::Forms::TextBox());
			this->member_id_txt = (gcnew System::Windows::Forms::TextBox());
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
			this->delete_profile_button = (gcnew System::Windows::Forms::Button());
			this->update_profile_button = (gcnew System::Windows::Forms::Button());
			this->confirm_change_button = (gcnew System::Windows::Forms::Button());
			this->member_borrow_history_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Open_profile = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->change_pass_btn = (gcnew System::Windows::Forms::Button());
			this->confirm_newpass_btn = (gcnew System::Windows::Forms::Button());
			this->member_profile_group->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->member_borrow_history_dataGridView))->BeginInit();
			this->SuspendLayout();
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
			// member_profile_group
			// 
			this->member_profile_group->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->member_profile_group->Controls->Add(this->new_pass_txt);
			this->member_profile_group->Controls->Add(this->new_pass_lbl);
			this->member_profile_group->Controls->Add(this->member_stat_text);
			this->member_profile_group->Controls->Add(this->member_stat_label);
			this->member_profile_group->Controls->Add(this->profession_selector);
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
			this->member_profile_group->Location = System::Drawing::Point(141, 14);
			this->member_profile_group->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->member_profile_group->Name = L"member_profile_group";
			this->member_profile_group->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->member_profile_group->Size = System::Drawing::Size(598, 793);
			this->member_profile_group->TabIndex = 18;
			this->member_profile_group->TabStop = false;
			this->member_profile_group->Text = L"Member Profile";
			// 
			// new_pass_txt
			// 
			this->new_pass_txt->Location = System::Drawing::Point(343, 667);
			this->new_pass_txt->Name = L"new_pass_txt";
			this->new_pass_txt->PasswordChar = '*';
			this->new_pass_txt->Size = System::Drawing::Size(141, 26);
			this->new_pass_txt->TabIndex = 23;
			this->new_pass_txt->Visible = false;
			// 
			// new_pass_lbl
			// 
			this->new_pass_lbl->AutoSize = true;
			this->new_pass_lbl->Location = System::Drawing::Point(135, 667);
			this->new_pass_lbl->Name = L"new_pass_lbl";
			this->new_pass_lbl->Size = System::Drawing::Size(113, 20);
			this->new_pass_lbl->TabIndex = 22;
			this->new_pass_lbl->Text = L"New Password";
			this->new_pass_lbl->Visible = false;
			// 
			// member_stat_text
			// 
			this->member_stat_text->Location = System::Drawing::Point(343, 586);
			this->member_stat_text->Name = L"member_stat_text";
			this->member_stat_text->ReadOnly = true;
			this->member_stat_text->Size = System::Drawing::Size(142, 26);
			this->member_stat_text->TabIndex = 21;
			// 
			// member_stat_label
			// 
			this->member_stat_label->AutoSize = true;
			this->member_stat_label->Location = System::Drawing::Point(101, 582);
			this->member_stat_label->Name = L"member_stat_label";
			this->member_stat_label->Size = System::Drawing::Size(147, 20);
			this->member_stat_label->TabIndex = 20;
			this->member_stat_label->Text = L"Membership Status";
			// 
			// profession_selector
			// 
			this->profession_selector->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->profession_selector->FormattingEnabled = true;
			this->profession_selector->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Alumni" });
			this->profession_selector->Location = System::Drawing::Point(430, 228);
			this->profession_selector->Name = L"profession_selector";
			this->profession_selector->Size = System::Drawing::Size(146, 28);
			this->profession_selector->TabIndex = 19;
			this->profession_selector->Visible = false;
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
			// delete_profile_button
			// 
			this->delete_profile_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->delete_profile_button->Location = System::Drawing::Point(932, 66);
			this->delete_profile_button->Name = L"delete_profile_button";
			this->delete_profile_button->Size = System::Drawing::Size(202, 45);
			this->delete_profile_button->TabIndex = 19;
			this->delete_profile_button->Text = L"DELETE PROFILE";
			this->delete_profile_button->UseVisualStyleBackColor = true;
			this->delete_profile_button->Click += gcnew System::EventHandler(this, &profile_member::delete_profile_button_Click);
			// 
			// update_profile_button
			// 
			this->update_profile_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->update_profile_button->Location = System::Drawing::Point(932, 9);
			this->update_profile_button->Name = L"update_profile_button";
			this->update_profile_button->Size = System::Drawing::Size(206, 49);
			this->update_profile_button->TabIndex = 20;
			this->update_profile_button->Text = L"UPDATE PROFILE";
			this->update_profile_button->UseVisualStyleBackColor = true;
			this->update_profile_button->Click += gcnew System::EventHandler(this, &profile_member::update_profile_button_Click);
			// 
			// confirm_change_button
			// 
			this->confirm_change_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->confirm_change_button->Location = System::Drawing::Point(932, 118);
			this->confirm_change_button->Name = L"confirm_change_button";
			this->confirm_change_button->Size = System::Drawing::Size(202, 68);
			this->confirm_change_button->TabIndex = 21;
			this->confirm_change_button->Text = L"MAKE CHANGES";
			this->confirm_change_button->UseVisualStyleBackColor = true;
			this->confirm_change_button->Visible = false;
			this->confirm_change_button->Click += gcnew System::EventHandler(this, &profile_member::confirm_change_button_Click);
			// 
			// member_borrow_history_dataGridView
			// 
			this->member_borrow_history_dataGridView->AllowUserToAddRows = false;
			this->member_borrow_history_dataGridView->AllowUserToDeleteRows = false;
			this->member_borrow_history_dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->member_borrow_history_dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->member_borrow_history_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->member_borrow_history_dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open_profile });
			this->member_borrow_history_dataGridView->Location = System::Drawing::Point(12, 12);
			this->member_borrow_history_dataGridView->MultiSelect = false;
			this->member_borrow_history_dataGridView->Name = L"member_borrow_history_dataGridView";
			this->member_borrow_history_dataGridView->ReadOnly = true;
			this->member_borrow_history_dataGridView->RowHeadersWidth = 62;
			this->member_borrow_history_dataGridView->RowTemplate->Height = 28;
			this->member_borrow_history_dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->member_borrow_history_dataGridView->Size = System::Drawing::Size(576, 558);
			this->member_borrow_history_dataGridView->TabIndex = 20;
			this->member_borrow_history_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &profile_member::member_borrow_history_dataGridView_CellContentClick);
			// 
			// Open_profile
			// 
			this->Open_profile->HeaderText = L"Profile";
			this->Open_profile->MinimumWidth = 8;
			this->Open_profile->Name = L"Open_profile";
			this->Open_profile->ReadOnly = true;
			this->Open_profile->Text = L"Open";
			this->Open_profile->UseColumnTextForButtonValue = true;
			this->Open_profile->Width = 59;
			// 
			// back_button
			// 
			this->back_button->Location = System::Drawing::Point(12, 890);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(81, 45);
			this->back_button->TabIndex = 22;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_member::back_button_Click);
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			// 
			// change_pass_btn
			// 
			this->change_pass_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->change_pass_btn->Location = System::Drawing::Point(935, 214);
			this->change_pass_btn->Name = L"change_pass_btn";
			this->change_pass_btn->Size = System::Drawing::Size(198, 57);
			this->change_pass_btn->TabIndex = 23;
			this->change_pass_btn->Text = L"CHANGE PASSWORD";
			this->change_pass_btn->UseVisualStyleBackColor = true;
			this->change_pass_btn->Click += gcnew System::EventHandler(this, &profile_member::change_pass_btn_Click);
			// 
			// confirm_newpass_btn
			// 
			this->confirm_newpass_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->confirm_newpass_btn->Location = System::Drawing::Point(941, 296);
			this->confirm_newpass_btn->Name = L"confirm_newpass_btn";
			this->confirm_newpass_btn->Size = System::Drawing::Size(191, 55);
			this->confirm_newpass_btn->TabIndex = 24;
			this->confirm_newpass_btn->Text = L"CONFIRM NEW PASSWORD";
			this->confirm_newpass_btn->UseVisualStyleBackColor = true;
			this->confirm_newpass_btn->Visible = false;
			this->confirm_newpass_btn->Click += gcnew System::EventHandler(this, &profile_member::confirm_newpass_btn_Click);
			// 
			// profile_member
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1149, 909);
			this->Controls->Add(this->confirm_newpass_btn);
			this->Controls->Add(this->change_pass_btn);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->member_borrow_history_dataGridView);
			this->Controls->Add(this->confirm_change_button);
			this->Controls->Add(this->update_profile_button);
			this->Controls->Add(this->delete_profile_button);
			this->Controls->Add(this->member_profile_group);
			this->Name = L"profile_member";
			this->Text = L"LMS: Member Profile";
			this->Load += gcnew System::EventHandler(this, &profile_member::profile_member_Load);
			this->member_profile_group->ResumeLayout(false);
			this->member_profile_group->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->member_borrow_history_dataGridView))->EndInit();
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
		System::Void profile_member_Load(System::Object^ sender, System::EventArgs^ e);

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
		/// System::Void function for OnClick of back button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e);

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
		System::Void member_borrow_history_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private: 
		/// <summary>
		/// System::Void function for OnClick of change password
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void change_pass_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private:
		/// <summary>
		/// System::Void function for OnClick of confirm new password
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void confirm_newpass_btn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
