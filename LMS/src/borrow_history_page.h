#pragma once
#include "profile_order.h"
#include "written_functions/filling_datagrid.h"
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
	/// Summary for borrow_history_page
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class borrow_history_page : public System::Windows::Forms::Form
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
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		borrow_history_page(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_id_transfer">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		borrow_history_page(String^ input_transfer_id, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~borrow_history_page();

	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button_borrow_his;
	private:
		/// <summary>
		/// Data Grid to present the General details of Book Borrowed and Book Borrower.
		/// </summary>
		/// @see Open_profile
		System::Windows::Forms::DataGridView^ borrow_history_dataGridView;
	private:
		/// <summary>
		/// A dedicated button inside the Data Grid to open the profile of Borrow History with more details
		/// </summary>
		/// @see borrow_history_dataGridView
		System::Windows::Forms::DataGridViewButtonColumn^ Open_profile;
	private:
		/// <summary>
		/// TextBox for the Search Bar
		/// </summary>
		/// @see search_button, list_detail_search_order, clear_all_button
		System::Windows::Forms::TextBox^ search_bar;
	private:
		/// <summary>
		/// Drop Down List to filter the list based on different attributes of Borrow History.
		/// </summary>
		System::Windows::Forms::ComboBox^ list_detail_search_order;
	private:
		/// <summary>
		/// Search Button to show search results based on input in the Search Bar and Drop Down List
		/// </summary>
		/// @see search_bar, list_detail_search_order, clear_all_button
		System::Windows::Forms::Button^ search_button;
	private:
		/// <summary>
		/// Clear All Search Results Button to show default data
		/// </summary>
		/// @see search_bar, list_detail_search_order, search_button
		System::Windows::Forms::Button^ clear_all_button;
	private:
		/// <summary>
		/// Exit Button to exit the application
		/// </summary>
		System::Windows::Forms::Button^ exit_button;

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
			this->back_button_borrow_his = (gcnew System::Windows::Forms::Button());
			this->borrow_history_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->Open_profile = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->search_bar = (gcnew System::Windows::Forms::TextBox());
			this->list_detail_search_order = (gcnew System::Windows::Forms::ComboBox());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->clear_all_button = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borrow_history_dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// back_button_borrow_his
			// 
			this->back_button_borrow_his->Image = Image::FromFile("images\\back-icon.png");
			this->back_button_borrow_his->Location = System::Drawing::Point(12, 12);
			this->back_button_borrow_his->Name = L"back_button_borrow_his";
			this->back_button_borrow_his->Size = System::Drawing::Size(89, 51);
			this->back_button_borrow_his->TabIndex = 1;
			this->back_button_borrow_his->UseVisualStyleBackColor = true;
			this->back_button_borrow_his->Click += gcnew System::EventHandler(this, &borrow_history_page::back_button_borrow_his_Click);
			// 
			// borrow_history_dataGridView
			// 
			this->borrow_history_dataGridView->AllowUserToAddRows = false;
			this->borrow_history_dataGridView->AllowUserToDeleteRows = false;
			this->borrow_history_dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->borrow_history_dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->borrow_history_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->borrow_history_dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open_profile });
			this->borrow_history_dataGridView->Location = System::Drawing::Point(174, 198);
			this->borrow_history_dataGridView->MultiSelect = false;
			this->borrow_history_dataGridView->Name = L"borrow_history_dataGridView";
			this->borrow_history_dataGridView->ReadOnly = true;
			this->borrow_history_dataGridView->RowHeadersWidth = 62;
			this->borrow_history_dataGridView->RowTemplate->Height = 28;
			this->borrow_history_dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->borrow_history_dataGridView->Size = System::Drawing::Size(1060, 483);
			this->borrow_history_dataGridView->TabIndex = 1;
			this->borrow_history_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &borrow_history_page::borrow_history_dataGridView_CellContentClick);
			// 
			// Open_profile
			// 
			this->Open_profile->HeaderText = L"Profile";
			this->Open_profile->MinimumWidth = 8;
			this->Open_profile->Name = L"Open_profile";
			this->Open_profile->ReadOnly = true;
			this->Open_profile->Text = L"Open";
			this->Open_profile->UseColumnTextForButtonValue = true;
			// 
			// search_bar
			// 
			this->search_bar->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_bar->Location = System::Drawing::Point(254, 12);
			this->search_bar->Name = L"search_bar";
			this->search_bar->Size = System::Drawing::Size(427, 26);
			this->search_bar->TabIndex = 3;
			// 
			// list_detail_search_order
			// 
			this->list_detail_search_order->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->list_detail_search_order->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_detail_search_order->DropDownWidth = 133;
			this->list_detail_search_order->FormattingEnabled = true;
			this->list_detail_search_order->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Order ID", L"Member ID", L"Book ID" });
			this->list_detail_search_order->Location = System::Drawing::Point(687, 12);
			this->list_detail_search_order->Name = L"list_detail_search_order";
			this->list_detail_search_order->Size = System::Drawing::Size(133, 28);
			this->list_detail_search_order->TabIndex = 4;
			// 
			// search_button
			// 
			this->search_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_button->Location = System::Drawing::Point(826, 10);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(133, 40);
			this->search_button->TabIndex = 4;
			this->search_button->Text = L"Search";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &borrow_history_page::search_button_Click);
			// 
			// clear_all_button
			// 
			this->clear_all_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_all_button->Location = System::Drawing::Point(965, 10);
			this->clear_all_button->Name = L"clear_all_button";
			this->clear_all_button->Size = System::Drawing::Size(133, 40);
			this->clear_all_button->TabIndex = 4;
			this->clear_all_button->Text = L"Clear Search";
			this->clear_all_button->UseVisualStyleBackColor = true;
			this->clear_all_button->Click += gcnew System::EventHandler(this, &borrow_history_page::clear_all_button_Click);
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
			this->exit_button->Click += gcnew System::EventHandler(this, &borrow_history_page::exit_button_Click);
			// 
			// borrow_history_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1401, 874);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->clear_all_button);
			this->Controls->Add(this->search_button);
			this->Controls->Add(this->list_detail_search_order);
			this->Controls->Add(this->search_bar);
			this->Controls->Add(this->borrow_history_dataGridView);
			this->Controls->Add(this->back_button_borrow_his);
			this->MinimumSize = System::Drawing::Size(1414, 907);
			this->Name = L"borrow_history_page";
			this->Text = L"LMS: Borrow History";
			this->Load += gcnew System::EventHandler(this, &borrow_history_page::borrow_history_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->borrow_history_dataGridView))->EndInit();
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
		System::Void back_button_borrow_his_Click(System::Object^ sender, System::EventArgs^ e);

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
		System::Void borrow_history_page_Load(System::Object^ sender, System::EventArgs^ e);

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
		System::Void borrow_history_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

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
		System::Void search_button_Click(System::Object^ sender, System::EventArgs^ e);

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
	};
}
