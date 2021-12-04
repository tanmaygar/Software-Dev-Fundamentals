#pragma once

namespace LMS {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for RegisterLibrarian
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class RegisterLibrarian : public System::Windows::Forms::Form
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
		RegisterLibrarian(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_transfer_id">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		RegisterLibrarian(String^ input_transfer_id, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~RegisterLibrarian();
	public:
		/// <summary>
		/// Public variable for storing Gender
		/// </summary>
		String^ Gender;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private:
		/// <summary>
		/// Input TextBox for re-enter Password
		/// </summary>
		System::Windows::Forms::TextBox^ re_password_txt;
	private:
		/// <summary>
		/// Input TextBox for Password
		/// </summary>
		System::Windows::Forms::TextBox^ password_txt;
	private:
		/// <summary>
		/// Label for Password
		/// </summary>
		System::Windows::Forms::Label^ password_lbl;
	private:
		/// <summary>
		/// Label for re-enter Password
		/// </summary>
		System::Windows::Forms::Label^ re_password_lbl;
	private:
		/// <summary>
		/// Radio Button for Gender = Female
		/// </summary>
		System::Windows::Forms::RadioButton^ female_rbtn;
	private:
		/// <summary>
		/// Radio Button for Gender = Male
		/// </summary>
		System::Windows::Forms::RadioButton^ male_rbtn;

	private:
		/// <summary>
		/// A Date-Time Picker for choosing Date of Birth
		/// </summary>
		System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private:
		/// <summary>
		/// Label for Name of the Librarian
		/// </summary>
		System::Windows::Forms::Label^ name_lbl;

	private:
		/// <summary>
		/// Label for Date of Birth of the Librarian
		/// </summary>
		System::Windows::Forms::Label^ dob_lbl;


	private:
		/// <summary>
		/// Label for 'E-mail ID' of the Librarian
		/// </summary>
		System::Windows::Forms::Label^ email_id_lbl;

	private:
		/// <summary>
		/// Label for Contact Number of the Librarian
		/// </summary>
		System::Windows::Forms::Label^ mobile_no_lbl;

	private:
		/// <summary>
		/// Input TextBox for address of the Librarian
		/// </summary>
		System::Windows::Forms::TextBox^ address_txt;
	private:
		/// <summary>
		/// Label for address of the Librarian
		/// </summary>
		System::Windows::Forms::Label^ address_lbl;
	private:
		/// <summary>
		/// Input TextBox for Contact number of the Librarian
		/// </summary>
		System::Windows::Forms::TextBox^ mobile_no_txt;
	private:
		/// <summary>
		/// Input TextBox for name of the Librarian
		/// </summary>
		System::Windows::Forms::TextBox^ name_txt;
	private:
		/// <summary>
		/// Input TextBox for E-mail ID of the Librarian
		/// </summary>
		System::Windows::Forms::TextBox^ email_id_txt;
	private:
		/// <summary>
		/// Button to validate Registration
		/// </summary>
		System::Windows::Forms::Button^ register_button;
	private:
		/// <summary>
		/// Button for navigating to HomePage
		/// </summary>
		System::Windows::Forms::Button^ back_button;
	private:
		/// <summary>
		/// Input TextBox for Librarian's username
		/// </summary>
		System::Windows::Forms::TextBox^ librarian_username_txt;
	private:
		/// <summary>
		/// Label for Librarian's username
		/// </summary>
		System::Windows::Forms::Label^ librarian_username_lbl;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterLibrarian::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->re_password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->re_password_lbl = (gcnew System::Windows::Forms::Label());
			this->female_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->male_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->librarian_username_lbl = (gcnew System::Windows::Forms::Label());
			this->librarian_username_txt = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->librarian_username_txt);
			this->groupBox1->Controls->Add(this->librarian_username_lbl);
			this->groupBox1->Controls->Add(this->re_password_txt);
			this->groupBox1->Controls->Add(this->password_txt);
			this->groupBox1->Controls->Add(this->password_lbl);
			this->groupBox1->Controls->Add(this->re_password_lbl);
			this->groupBox1->Controls->Add(this->female_rbtn);
			this->groupBox1->Controls->Add(this->male_rbtn);
			this->groupBox1->Controls->Add(this->dateTimePicker);
			this->groupBox1->Controls->Add(this->name_lbl);
			this->groupBox1->Controls->Add(this->dob_lbl);
			this->groupBox1->Controls->Add(this->email_id_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_lbl);
			this->groupBox1->Controls->Add(this->address_txt);
			this->groupBox1->Controls->Add(this->address_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_txt);
			this->groupBox1->Controls->Add(this->name_txt);
			this->groupBox1->Controls->Add(this->email_id_txt);
			this->groupBox1->Location = System::Drawing::Point(239, 57);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(333, 570);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Register Librarian";
			// 
			// re_password_txt
			// 
			this->re_password_txt->Location = System::Drawing::Point(172, 519);
			this->re_password_txt->Name = L"re_password_txt";
			this->re_password_txt->PasswordChar = '*';
			this->re_password_txt->Size = System::Drawing::Size(100, 20);
			this->re_password_txt->TabIndex = 23;
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(172, 477);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(100, 20);
			this->password_txt->TabIndex = 22;
			// 
			// password_lbl
			// 
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(36, 480);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(72, 13);
			this->password_lbl->TabIndex = 21;
			this->password_lbl->Text = L"Set Password";
			// 
			// re_password_lbl
			// 
			this->re_password_lbl->AutoSize = true;
			this->re_password_lbl->Location = System::Drawing::Point(36, 522);
			this->re_password_lbl->Name = L"re_password_lbl";
			this->re_password_lbl->Size = System::Drawing::Size(97, 13);
			this->re_password_lbl->TabIndex = 20;
			this->re_password_lbl->Text = L"Re-enter Password";
			// 
			// female_rbtn
			// 
			this->female_rbtn->AutoSize = true;
			this->female_rbtn->Location = System::Drawing::Point(170, 204);
			this->female_rbtn->Name = L"female_rbtn";
			this->female_rbtn->Size = System::Drawing::Size(59, 17);
			this->female_rbtn->TabIndex = 19;
			this->female_rbtn->Text = L"Female";
			this->female_rbtn->UseVisualStyleBackColor = true;
			this->female_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterLibrarian::female_rbtn_CheckedChanged);
			// 
			// male_rbtn
			// 
			this->male_rbtn->AutoSize = true;
			this->male_rbtn->Location = System::Drawing::Point(54, 204);
			this->male_rbtn->Name = L"male_rbtn";
			this->male_rbtn->Size = System::Drawing::Size(48, 17);
			this->male_rbtn->TabIndex = 18;
			this->male_rbtn->Text = L"Male";
			this->male_rbtn->UseVisualStyleBackColor = true;
			this->male_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterLibrarian::male_rbtn_CheckedChanged);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Checked = false;
			this->dateTimePicker->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(171, 145);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(99, 20);
			this->dateTimePicker->TabIndex = 16;
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(36, 81);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(35, 13);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(36, 145);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(66, 13);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(36, 256);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(44, 13);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(36, 318);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(58, 13);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(172, 367);
			this->address_txt->Name = L"address_txt";
			this->address_txt->Size = System::Drawing::Size(100, 20);
			this->address_txt->TabIndex = 11;
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(36, 370);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(45, 13);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(172, 315);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->Size = System::Drawing::Size(100, 20);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(170, 81);
			this->name_txt->Name = L"name_txt";
			this->name_txt->Size = System::Drawing::Size(100, 20);
			this->name_txt->TabIndex = 6;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(170, 256);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->Size = System::Drawing::Size(100, 20);
			this->email_id_txt->TabIndex = 9;
			// 
			// register_button
			// 
			this->register_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_button->Location = System::Drawing::Point(630, 284);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(117, 32);
			this->register_button->TabIndex = 18;
			this->register_button->Text = L"Register";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &RegisterLibrarian::RegisterLibrarian_Click);
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(55, 39);
			this->back_button->Margin = System::Windows::Forms::Padding(1);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(37, 34);
			this->back_button->TabIndex = 20;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &RegisterLibrarian::BackButton_Click);
			// 
			// librarian_username_lbl
			// 
			this->librarian_username_lbl->AutoSize = true;
			this->librarian_username_lbl->Location = System::Drawing::Point(36, 426);
			this->librarian_username_lbl->Name = L"librarian_username_lbl";
			this->librarian_username_lbl->Size = System::Drawing::Size(72, 13);
			this->librarian_username_lbl->TabIndex = 24;
			this->librarian_username_lbl->Text = L"Set username";
			// 
			// librarian_username_txt
			// 
			this->librarian_username_txt->Location = System::Drawing::Point(172, 423);
			this->librarian_username_txt->Name = L"librarian_username_txt";
			this->librarian_username_txt->Size = System::Drawing::Size(100, 20);
			this->librarian_username_txt->TabIndex = 25;
			// 
			// RegisterLibrarian
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(890, 671);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->register_button);
			this->Name = L"RegisterLibrarian";
			this->Text = L"LMS: Register Librarian";
			this->Load += gcnew System::EventHandler(this, &RegisterLibrarian::RegisterLibrarian_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
		System::Void RegisterLibrarian_Load(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function to Register Librarian considering the details provided 
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void RegisterLibrarian_Click(System::Object^ sender, System::EventArgs^ e);

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

	private:
		/// <summary>
		/// System::Void function to Check Gender = 'Male'
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void male_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			Gender = "Male";
		}

	private:
		/// <summary>
		/// System::Void function to Check Gender = 'Female'
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void female_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		{
			Gender = "Female";
		}

	};
}
