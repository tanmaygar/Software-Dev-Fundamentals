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
	/// Summary for RegisterMember
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class RegisterMember : public System::Windows::Forms::Form
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
		RegisterMember(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_transfer_id">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		RegisterMember(String^ input_transfer_id, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~RegisterMember();

	public:
		/// <summary>
		/// Public variable for storing Gender
		/// </summary>
		String^ Gender;

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
		/// Label for 'E-mail ID' of the Member
		/// </summary>
		System::Windows::Forms::Label^ email_id_lbl;

	private:
		/// <summary>
		/// Label for Contact Number of the Member
		/// </summary>
		System::Windows::Forms::Label^ mobile_no_lbl;

	private:
		/// <summary>
		/// Label for member's address
		/// </summary>
		System::Windows::Forms::Label^ address_lbl;

	private:
		/// <summary>
		/// Input TextBox for name of the Member
		/// </summary>
		System::Windows::Forms::TextBox^ name_txt;


	private:
		/// <summary>
		/// Input TextBox for E-mail ID of the Member
		/// </summary>
		System::Windows::Forms::TextBox^ email_id_txt;
	private:
		/// <summary>
		/// Input TextBox for Contact number of the Member
		/// </summary>
		System::Windows::Forms::TextBox^ mobile_no_txt;
	private:
		/// <summary>
		/// Input TextBox for address of the Member
		/// </summary>
		System::Windows::Forms::TextBox^ address_txt;
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
		/// A Date-Time Picker for choosing Date of Birth
		/// </summary>
		System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private:
		/// <summary>
		/// A mechanism to group all the required labels and textboxes
		/// </summary>
		System::Windows::Forms::GroupBox^ register_member_grp_box;


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
		/// Input TextBox for re-enter Password
		/// </summary>
		System::Windows::Forms::TextBox^ re_password_txt;

	private:
		/// <summary>
		/// Input TextBox for Re-entering Password
		/// </summary>
		System::Windows::Forms::TextBox^ password_txt;

	private:
		/// <summary>
		/// Label for Password
		/// </summary>
		System::Windows::Forms::Label^ password_lbl;
	private:
		/// <summary>
		/// Label for Re-entering Password
		/// </summary>
		System::Windows::Forms::Label^ re_password_lbl;

	private:
		/// <summary>
		/// ComboBox for Profession
		/// </summary>
		/// Accepted Professions : Faculty, Alumini, Student
		System::Windows::Forms::ComboBox^ profession_comboBox;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterMember::typeid));
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->profession_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->register_member_grp_box = (gcnew System::Windows::Forms::GroupBox());
			this->profession_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->re_password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->re_password_lbl = (gcnew System::Windows::Forms::Label());
			this->female_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->male_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->register_member_grp_box->SuspendLayout();
			this->SuspendLayout();
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(54, 125);
			this->name_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(51, 20);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(54, 223);
			this->dob_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(99, 20);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(54, 394);
			this->profession_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(84, 20);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(54, 460);
			this->email_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(66, 20);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(54, 526);
			this->mobile_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(83, 20);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(54, 594);
			this->address_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(68, 20);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(255, 125);
			this->name_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->name_txt->Name = L"name_txt";
			this->name_txt->Size = System::Drawing::Size(148, 26);
			this->name_txt->TabIndex = 6;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(256, 455);
			this->email_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->Size = System::Drawing::Size(148, 26);
			this->email_id_txt->TabIndex = 9;
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(258, 522);
			this->mobile_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->Size = System::Drawing::Size(148, 26);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(258, 589);
			this->address_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->address_txt->Name = L"address_txt";
			this->address_txt->Size = System::Drawing::Size(148, 26);
			this->address_txt->TabIndex = 11;
			// 
			// register_button
			// 
			this->register_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_button->Location = System::Drawing::Point(939, 428);
			this->register_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(176, 49);
			this->register_button->TabIndex = 12;
			this->register_button->Text = L"Register";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &RegisterMember::RegisterMember_Click);
			// 
			// back_button
			// 
			this->back_button->Image = Image::FromFile("images\\back-icon.png");
			this->back_button->Location = System::Drawing::Point(52, 51);
			this->back_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(56, 52);
			this->back_button->TabIndex = 15;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &RegisterMember::BackButton_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Checked = false;
			this->dateTimePicker->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(256, 223);
			this->dateTimePicker->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(146, 26);
			this->dateTimePicker->TabIndex = 16;
			// 
			// register_member_grp_box
			// 
			this->register_member_grp_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_member_grp_box->Controls->Add(this->profession_comboBox);
			this->register_member_grp_box->Controls->Add(this->re_password_txt);
			this->register_member_grp_box->Controls->Add(this->password_txt);
			this->register_member_grp_box->Controls->Add(this->password_lbl);
			this->register_member_grp_box->Controls->Add(this->re_password_lbl);
			this->register_member_grp_box->Controls->Add(this->female_rbtn);
			this->register_member_grp_box->Controls->Add(this->male_rbtn);
			this->register_member_grp_box->Controls->Add(this->dateTimePicker);
			this->register_member_grp_box->Controls->Add(this->name_lbl);
			this->register_member_grp_box->Controls->Add(this->dob_lbl);
			this->register_member_grp_box->Controls->Add(this->profession_lbl);
			this->register_member_grp_box->Controls->Add(this->email_id_lbl);
			this->register_member_grp_box->Controls->Add(this->mobile_no_lbl);
			this->register_member_grp_box->Controls->Add(this->address_txt);
			this->register_member_grp_box->Controls->Add(this->address_lbl);
			this->register_member_grp_box->Controls->Add(this->mobile_no_txt);
			this->register_member_grp_box->Controls->Add(this->name_txt);
			this->register_member_grp_box->Controls->Add(this->email_id_txt);
			this->register_member_grp_box->Location = System::Drawing::Point(352, 78);
			this->register_member_grp_box->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->register_member_grp_box->Name = L"register_member_grp_box";
			this->register_member_grp_box->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->register_member_grp_box->Size = System::Drawing::Size(500, 877);
			this->register_member_grp_box->TabIndex = 17;
			this->register_member_grp_box->TabStop = false;
			this->register_member_grp_box->Text = L"Register Member";
			// 
			// profession_comboBox
			// 
			this->profession_comboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->profession_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->profession_comboBox->FormattingEnabled = true;
			this->profession_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Alumini" });
			this->profession_comboBox->Location = System::Drawing::Point(255, 389);
			this->profession_comboBox->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->profession_comboBox->Name = L"profession_comboBox";
			this->profession_comboBox->Size = System::Drawing::Size(180, 28);
			this->profession_comboBox->TabIndex = 24;
			// 
			// re_password_txt
			// 
			this->re_password_txt->Location = System::Drawing::Point(258, 814);
			this->re_password_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->re_password_txt->Name = L"re_password_txt";
			this->re_password_txt->PasswordChar = '*';
			this->re_password_txt->Size = System::Drawing::Size(148, 26);
			this->re_password_txt->TabIndex = 23;
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(258, 737);
			this->password_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(148, 26);
			this->password_txt->TabIndex = 22;
			// 
			// password_lbl
			// 
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(54, 742);
			this->password_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(107, 20);
			this->password_lbl->TabIndex = 21;
			this->password_lbl->Text = L"Set Password";
			// 
			// re_password_lbl
			// 
			this->re_password_lbl->AutoSize = true;
			this->re_password_lbl->Location = System::Drawing::Point(54, 818);
			this->re_password_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->re_password_lbl->Name = L"re_password_lbl";
			this->re_password_lbl->Size = System::Drawing::Size(145, 20);
			this->re_password_lbl->TabIndex = 20;
			this->re_password_lbl->Text = L"Re-enter Password";
			// 
			// female_rbtn
			// 
			this->female_rbtn->AutoSize = true;
			this->female_rbtn->Location = System::Drawing::Point(255, 314);
			this->female_rbtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->female_rbtn->Name = L"female_rbtn";
			this->female_rbtn->Size = System::Drawing::Size(87, 24);
			this->female_rbtn->TabIndex = 19;
			this->female_rbtn->Text = L"Female";
			this->female_rbtn->UseVisualStyleBackColor = true;
			this->female_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterMember::female_rbtn_CheckedChanged);
			// 
			// male_rbtn
			// 
			this->male_rbtn->AutoSize = true;
			this->male_rbtn->Location = System::Drawing::Point(81, 314);
			this->male_rbtn->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->male_rbtn->Name = L"male_rbtn";
			this->male_rbtn->Size = System::Drawing::Size(68, 24);
			this->male_rbtn->TabIndex = 18;
			this->male_rbtn->Text = L"Male";
			this->male_rbtn->UseVisualStyleBackColor = true;
			this->male_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterMember::male_rbtn_CheckedChanged);
			// 
			// RegisterMember
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 974);
			this->Controls->Add(this->register_member_grp_box);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->register_button);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(1274, 994);
			this->Name = L"RegisterMember";
			this->Text = L"LMS: Register Member";
			this->Load += gcnew System::EventHandler(this, &RegisterMember::RegisterMember_Load);
			this->register_member_grp_box->ResumeLayout(false);
			this->register_member_grp_box->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		/// <summary>
		/// System::Void function to Register Member considering the details provided 
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void RegisterMember_Click(System::Object^ sender, System::EventArgs^ e);
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
		System::Void RegisterMember_Load(System::Object^ sender, System::EventArgs^ e);

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
