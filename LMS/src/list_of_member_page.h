#pragma once
#include "written_functions/connection_sql_func.h"
#include "profile_member.h"
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
	/// Summary for list_of_member_page
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class list_of_member_page : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Public variable for transfering the ID of the user
		/// </summary>
		/// It transfers the ID of the user as String which is part of the public ref class and a member of System.
		String^ transfer_id;
		/// <summary>
		/// Public variables for transfering whether the user is a librarian or not
		/// </summary>
		/// It transfers a boolean value with true representing the user is a librarian and false if the user is not a librarian
		bool is_librarian;
	public:
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		list_of_member_page(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_id_transfer">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		list_of_member_page(String^ input_id_transfer, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~list_of_member_page();

	private:
		/// <summary>
		/// TextBox for the Search Bar
		/// </summary>
		/// @see search_button_member, list_detail_search_member, clear_all_button
		System::Windows::Forms::TextBox^ search_bar_member;
	private:
		/// <summary>
		/// Data Grid to present the General details of Members which includes Students, Faculty and Alumni.
		/// </summary>
		/// @see Open_Profile
		System::Windows::Forms::DataGridView^ list_of_member_dataGridView;
	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button_member_list;

	private:
		/// <summary>
		/// A dedicated button inside the Data Grid to open the profile of Members with more details
		/// </summary>
		/// @see list_of_member_dataGridView
		System::Windows::Forms::DataGridViewButtonColumn^ Open_Profile;
	private:
		/// <summary>
		/// Search Button to show search results based on input in the Search Bar and Drop Down List
		/// </summary>
		/// @see search_bar_member, list_detail_search_member, clear_all_button
		System::Windows::Forms::Button^ search_button_member;
	private:
		/// <summary>
		/// Drop Down List to filter the list based on different attributes of Members.
		/// </summary>
		System::Windows::Forms::ComboBox^ list_detail_search_member;
	private:
		/// <summary>
		/// Exit Button to exit the application
		/// </summary>
		System::Windows::Forms::Button^ exit_button;
	private:
		/// <summary>
		/// Clear All Search Results Button to show default data
		/// </summary>
		/// @see search_bar_member, list_detail_search_member, search_button_member
		System::Windows::Forms::Button^ clear_all_button;
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
			this->list_of_member_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Open_Profile = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->search_bar_member = (gcnew System::Windows::Forms::TextBox());
			this->back_button_member_list = (gcnew System::Windows::Forms::Button());
			this->search_button_member = (gcnew System::Windows::Forms::Button());
			this->list_detail_search_member = (gcnew System::Windows::Forms::ComboBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->clear_all_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_of_member_dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// list_of_member_dataGridView
			// 
			this->list_of_member_dataGridView->AllowUserToAddRows = false;
			this->list_of_member_dataGridView->AllowUserToDeleteRows = false;
			this->list_of_member_dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->list_of_member_dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->list_of_member_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->list_of_member_dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open_Profile });
			this->list_of_member_dataGridView->Location = System::Drawing::Point(174, 198);
			this->list_of_member_dataGridView->MultiSelect = false;
			this->list_of_member_dataGridView->Name = L"list_of_member_dataGridView";
			this->list_of_member_dataGridView->ReadOnly = true;
			this->list_of_member_dataGridView->RowHeadersWidth = 62;
			this->list_of_member_dataGridView->RowTemplate->Height = 28;
			this->list_of_member_dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->list_of_member_dataGridView->Size = System::Drawing::Size(1060, 483);
			this->list_of_member_dataGridView->TabIndex = 1;
			this->list_of_member_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &list_of_member_page::list_of_member_dataGridView_CellContentClick);
			// 
			// Open_Profile
			// 
			this->Open_Profile->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Open_Profile->HeaderText = L"Profile";
			this->Open_Profile->MinimumWidth = 8;
			this->Open_Profile->Name = L"Open_Profile";
			this->Open_Profile->ReadOnly = true;
			this->Open_Profile->Text = L"Open";
			this->Open_Profile->UseColumnTextForButtonValue = true;
			// 
			// search_bar_member
			// 
			this->search_bar_member->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_bar_member->Location = System::Drawing::Point(240, 12);
			this->search_bar_member->Name = L"search_bar_member";
			this->search_bar_member->Size = System::Drawing::Size(427, 26);
			this->search_bar_member->TabIndex = 3;
			// 
			// back_button_member_list
			// 
			this->back_button_member_list->Image = Image::FromFile("images\\back-icon.png");
			this->back_button_member_list->Location = System::Drawing::Point(12, 12);
			this->back_button_member_list->Name = L"back_button_member_list";
			this->back_button_member_list->Size = System::Drawing::Size(89, 51);
			this->back_button_member_list->TabIndex = 1;
			this->back_button_member_list->UseVisualStyleBackColor = true;
			this->back_button_member_list->Click += gcnew System::EventHandler(this, &list_of_member_page::back_button_member_list_Click);
			// 
			// search_button_member
			// 
			this->search_button_member->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_button_member->Location = System::Drawing::Point(956, 10);
			this->search_button_member->Name = L"search_button_member";
			this->search_button_member->Size = System::Drawing::Size(133, 40);
			this->search_button_member->TabIndex = 4;
			this->search_button_member->Text = L"Search";
			this->search_button_member->UseVisualStyleBackColor = true;
			this->search_button_member->Click += gcnew System::EventHandler(this, &list_of_member_page::search_button_member_Click);
			// 
			// list_detail_search_member
			// 
			this->list_detail_search_member->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->list_detail_search_member->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_detail_search_member->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Name", L"Phone", L"Email",
					L"Number of books borrowed currently"
			});
			this->list_detail_search_member->Location = System::Drawing::Point(673, 12);
			this->list_detail_search_member->Name = L"list_detail_search_member";
			this->list_detail_search_member->Size = System::Drawing::Size(277, 28);
			this->list_detail_search_member->TabIndex = 4;
			// 
			// exit_button
			// 
			this->exit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exit_button->Location = System::Drawing::Point(1160, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(75, 40);
			this->exit_button->TabIndex = 2;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &list_of_member_page::exit_button_Click);
			// 
			// clear_all_button
			// 
			this->clear_all_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_all_button->Location = System::Drawing::Point(1095, 10);
			this->clear_all_button->Name = L"clear_all_button";
			this->clear_all_button->Size = System::Drawing::Size(133, 40);
			this->clear_all_button->TabIndex = 4;
			this->clear_all_button->Text = L"Clear Search";
			this->clear_all_button->UseVisualStyleBackColor = true;
			this->clear_all_button->Click += gcnew System::EventHandler(this, &list_of_member_page::clear_all_button_Click);
			// 
			// list_of_member_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1401, 874);
			this->Controls->Add(this->clear_all_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->list_detail_search_member);
			this->Controls->Add(this->search_button_member);
			this->Controls->Add(this->back_button_member_list);
			this->Controls->Add(this->search_bar_member);
			this->Controls->Add(this->list_of_member_dataGridView);
			this->MinimumSize = System::Drawing::Size(1414, 907);
			this->Name = L"list_of_member_page";
			this->Text = L"LMS: Member List";
			this->Load += gcnew System::EventHandler(this, &list_of_member_page::list_of_member_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->list_of_member_dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
		System::Void back_button_member_list_Click(System::Object^ sender, System::EventArgs^ e);

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
		System::Void list_of_member_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick Search Button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void search_button_member_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick Clear All Search Results
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void clear_all_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick Exit Button
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
		/// System::Void function to load the form
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void list_of_member_page_Load(System::Object^ sender, System::EventArgs^ e);

	
	};

	
}
