#include "pch.h"
#include "RegisterMember.h"
#include "written_functions/connection_sql_func.h"
#include "written_functions/RegisterMember_func.h"

namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	RegisterMember::RegisterMember(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	RegisterMember::RegisterMember(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}

	RegisterMember::~RegisterMember()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays TextBoxes for user input
	/// </summary>
	System::Void RegisterMember::RegisterMember_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	/// <summary>
	/// Button OnClick To Validate Member's details and confirm registration process
	/// </summary>
	System::Void RegisterMember::RegisterMember_Click(System::Object^ sender, System::EventArgs^ e) {
		int memberId = -1;
		try 
		{
			//Checks if profession is empty string and throws warning
			if (this->profession_comboBox->Text == "")
			{
				MessageBox::Show(this, "Select your profession from the drop-down list",
					"Null value Exception", MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return;
			}

			//Compares two password text fields whether they are matching or not
			if (!String::Equals(this->password_txt->Text, this->re_password_txt->Text))
			{
				MessageBox::Show("Re-enter same password");
				this->password_txt->Text = "";
				this->re_password_txt->Text = "";
				return;
			}

			bool result = LMS::dbInteract::RegisterMember_func(memberId, this->name_txt->Text, this->dateTimePicker->Text, this->address_txt->Text, \
				this->email_id_txt->Text, this->mobile_no_txt->Text, this->profession_comboBox->Text, Gender, this->password_txt->Text);

			if (result)
			{
				MessageBox::Show("Registered " + this->profession_comboBox->Text + " successfully!");
				MessageBox::Show("Your id is " + memberId);
			}
			this->name_txt->Text = "";
			this->dateTimePicker->Text = "";
			this->address_txt->Text = "";
			this->email_id_txt->Text = "";
			this->mobile_no_txt->Text = "";
			this->profession_comboBox->Text = nullptr;
			this->password_txt->Text = "";
			this->re_password_txt->Text = "";
			this->male_rbtn->Checked = false;
			this->female_rbtn->Checked = false;

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

	/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
	System::Void RegisterMember::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
