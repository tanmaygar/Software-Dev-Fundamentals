#pragma once
#include "written_functions/fine_function.h"
#include "written_functions/connection_sql_func.h"
#include "written_functions/Return_book_functions.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for ReturnBook
	/// </summary>
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class ReturnBook : public System::Windows::Forms::Form
	{
	public:
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name=""></param>
		ReturnBook(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReturnBook();


	private:
		/// <summary>
		/// Label for Order_id
		/// </summary>
		System::Windows::Forms::Label^ order_id_lbl;

	private:
		/// <summary>
		/// A TextBox  to return Book the book with input  Order_id 
		/// </summary>
		System::Windows::Forms::TextBox^ order_id_txt;

	private:
		/// <summary>
		/// Return button to return a book
		/// </summary>
		System::Windows::Forms::Button^ return_button;

	private:
		/// <summary>
		/// Back button to navigate backward
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
		void InitializeComponent(void)
		{
			this->order_id_lbl = (gcnew System::Windows::Forms::Label());
			this->order_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->return_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// order_id_lbl
			// 
			this->order_id_lbl->AutoSize = true;
			this->order_id_lbl->Location = System::Drawing::Point(459, 197);
			this->order_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->order_id_lbl->Name = L"order_id_lbl";
			this->order_id_lbl->Size = System::Drawing::Size(70, 20);
			this->order_id_lbl->TabIndex = 0;
			this->order_id_lbl->Text = L"Order ID";
			// 
			// order_id_txt
			// 
			this->order_id_txt->Location = System::Drawing::Point(652, 192);
			this->order_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->order_id_txt->Name = L"order_id_txt";
			this->order_id_txt->Size = System::Drawing::Size(148, 26);
			this->order_id_txt->TabIndex = 1;
			// 
			// return_button
			// 
			this->return_button->Location = System::Drawing::Point(552, 428);
			this->return_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->return_button->Name = L"return_button";
			this->return_button->Size = System::Drawing::Size(112, 35);
			this->return_button->TabIndex = 2;
			this->return_button->Text = L"Return ";
			this->return_button->UseVisualStyleBackColor = true;
			this->return_button->Click += gcnew System::EventHandler(this, &ReturnBook::return_button_Click);
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(105, 85);
			this->back_button->Margin = System::Windows::Forms::Padding(2);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(51, 38);
			this->back_button->TabIndex = 16;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &ReturnBook::Back_button_Click);
			// 
			// ReturnBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1144, 834);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->return_button);
			this->Controls->Add(this->order_id_txt);
			this->Controls->Add(this->order_id_lbl);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"ReturnBook";
			this->Text = L"LMS: Return Book";
			this->Load += gcnew System::EventHandler(this, &ReturnBook::ReturnBook_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/// <summary>
		/// System::Void function to load the form
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
	private: System::Void ReturnBook_Load(System::Object^ sender, System::EventArgs^ e);


		/// <summary>
		/// System::Void function to Execute the Function to return the Book Borrowed
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
	private: System::Void return_button_Click(System::Object^ sender, System::EventArgs^ e);

		/// <summary>
		/// System::Void function for OnClick of back button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
	private: System::Void Back_button_Click(System::Object^ sender, System::EventArgs^ e);


	};
}