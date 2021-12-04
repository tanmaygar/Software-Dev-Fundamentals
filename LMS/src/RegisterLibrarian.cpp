#include "pch.h"
#include "RegisterLibrarian.h"
#include "written_functions/connection_sql_func.h"
#include "written_functions/RegisterLibrarian_func.h"
namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	RegisterLibrarian::RegisterLibrarian(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	RegisterLibrarian::RegisterLibrarian(String^ input_transfer_id, bool is_librarian_input)
	{
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
		InitializeComponent();
	}

	RegisterLibrarian::~RegisterLibrarian()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays TextBoxes for user input
	/// </summary>
	System::Void RegisterLibrarian::RegisterLibrarian_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	/// <summary>
	/// Button OnClick To Validate Librarian's details and confirm registration process
	/// </summary>
	System::Void RegisterLibrarian::RegisterLibrarian_Click(System::Object^ sender, System::EventArgs^ e) {

		try 
		{
			//Compares two password text fields whether they are matching or not
			if (!String::Equals(this->password_txt->Text, this->re_password_txt->Text))
			{
				MessageBox::Show("Re-enter same password");
				this->password_txt->Text = "";
				this->re_password_txt->Text = "";
				return;
			}

			bool result = LMS::dbInteract::RegisterLibrarian_func(this->librarian_username_txt->Text, this->password_txt->Text, this->name_txt->Text, \
				this->dateTimePicker->Text, this->address_txt->Text, this->email_id_txt->Text, this->mobile_no_txt->Text, Gender);

			if (result)
			{
				MessageBox::Show("Librarian registered successfully!");
				MessageBox::Show("Your username is " + this->librarian_username_txt->Text);
			}

			this->name_txt->Text = "";
			this->librarian_username_txt->Text = "";
			this->dateTimePicker->Text = "";
			this->address_txt->Text = "";
			this->email_id_txt->Text = "";
			this->mobile_no_txt->Text = "";
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
	System::Void RegisterLibrarian::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

