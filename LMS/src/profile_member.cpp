#include "pch.h"
#include "profile_member.h"
#include "written_functions/delete_profile_func.h"
#include "written_functions/update_profile_func.h"

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
/// </summary>
///@see InitializeComponent()
LMS::profile_member::profile_member(void)
{
	InitializeComponent();
}

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent()
LMS::profile_member::profile_member(String^ input_id_transfer, bool is_librarian_input)
{
	InitializeComponent();
	transfer_id = input_id_transfer;
	is_librarian = is_librarian_input;
}

LMS::profile_member::~profile_member()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode and fills all the textboxes and fill the Data Grid
/// </summary>
/// @see filling_datagrid::fill_datagrid_member_profile()
System::Void LMS::profile_member::profile_member_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;

	//IF block to check if User is a librarian or not
	if (is_librarian == false)
	{
		//IF NOT then delete profile button is made invisible
		this->delete_profile_button->Visible = false;
	}
	else
	{
		//IF YES then delete profile button is made visible
		this->delete_profile_button->Visible = true;
	}

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of Book of that Member ID
	MySqlCommand^ fill_data_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data\
		WHERE member_id = " + transfer_id + ";", conDataBase);

	MySqlDataReader^ myReader;

	try {

		//Opens the Database connection
		conDataBase->Open();

		//Execute the function to return details of the Member from Database
		myReader = fill_data_cmdDataBase->ExecuteReader();

		//Strings to signify each detail which would later inititialize the textboxes
		String^ printing_name;
		String^ printing_id;
		String^ printing_profession;
		String^ printing_email;
		String^ printing_mobile;
		String^ printing_address;
		//String^ printing_dob;
		String^ printing_member_stat;

		//While loop to read the details from the Reader
		while (myReader->Read())
		{
			//Getting the details in String Form
			printing_id = myReader->GetString("member_id");
			printing_name = myReader->GetString("member_name");
			printing_profession = myReader->GetString("member_profession");
			printing_email = myReader->GetString("member_email");
			printing_mobile = myReader->GetString("member_mobile");
			printing_address = myReader->GetString("member_address");
			printing_member_stat = myReader->GetString("membership_stat");
			member_no_book_stat = myReader->GetInt32("member_no_book_stat");

			MySql::Data::Types::MySqlDateTime new_dob;
			new_dob = myReader->GetMySqlDateTime("member_dob");

			//Initialzing the Text Box
			this->name_txt->Text = printing_name;
			this->member_id_txt->Text = printing_id;
			this->email_id_txt->Text = printing_email;
			this->mobile_no_txt->Text = printing_mobile;
			this->address_txt->Text = printing_address;
			this->member_stat_text->Text = printing_member_stat;
			this->profession_txt->Text = printing_profession;
			this->dob_member_txt->Text = new_dob.ToString();

			
		}
		
		//Calls the function to fill the datagrid with Borrow History of the Member
		LMS::dbInteract::fill_datagrid_member_profile(this->member_id_txt->Text, member_borrow_history_dataGridView);

	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

	//Closes the connection
	conDataBase->Close();
}

/// <summary>
/// Button OnClick To Switch into Update Mode and make some Read-Only Fields as Re-Writable
/// </summary>
System::Void LMS::profile_member::update_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Update profile");
	//When Updating the profile it makes "Confirm Changes" button as visible and original "Update Profile" button as invisible
	
	this->update_profile_button->Visible = false;
	this->confirm_change_button->Visible = true;
	
	//Other required elements are now made Editable and drop down for profession is also made visible
	this->profession_txt->ReadOnly = true;
	this->email_id_txt->ReadOnly = false;
	this->mobile_no_txt->ReadOnly = false;
	this->address_txt->ReadOnly = false;
	this->profession_selector->Visible = true;
	this->profession_selector->Text = this->profession_txt->Text;

}

/// <summary>
/// Button OnClick To Deactivate the Membership of the User, upon passing through checks if the User as returned all the books
/// </summary>
/// @see delete_profile_func::delete_member_profile()
System::Void LMS::profile_member::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//IF number of books borrowed is greater than 0 then shows Error
	//ELSE it moves forward
	if (member_no_book_stat > 0)
	{
		MessageBox::Show("Cannot delete since he/she hasn't returned all the books borrowed.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	MessageBox::Show("Delete Profile");
	if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
	{

		//IF delete profile function return true then it shows message
		//ELSE it shows message error
		if (LMS::dbInteract::delete_member_profile(this->member_id_txt->Text) == true)
		{
			MessageBox::Show("Profile is deleted");
		}
		else
		{
			//Exception^ ex;
			//MessageBox::Show(ex->Message);
			MessageBox::Show("SOME ERROR HAS OCCURED IN DELETING MEMBER PROFILE", "Error", MessageBoxButtons::OK,MessageBoxIcon::Error);
		}

		//Closes the current form and goes back to previous form
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	else
	{
		//Do nothing
	}

}

/// <summary>
/// Button OnClick function to switch back into Read-Only Mode and updating the profile of the User and changing it in the databse as well
/// </summary>
/// @see update_profile_func::update_member_profile()
System::Void LMS::profile_member::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Changes made");


	this->profession_txt->Text = this->profession_selector->Text;
	

	//IF update profile function returns true then it shows message box
	//ELSE it shows error message
	if (LMS::dbInteract::update_member_profile(this->member_id_txt->Text, this->profession_txt->Text, this->email_id_txt->Text, this->mobile_no_txt->Text, this->address_txt->Text) == true)
	{
		MessageBox::Show("Profile is updated");
	}
	else
	{
		MessageBox::Show("SOME ERROR HAS OCCURED IN UPDATING MEMBER PROFILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
	this->update_profile_button->Visible = true;
	this->confirm_change_button->Visible = false;
	this->profession_txt->ReadOnly = true;
	this->email_id_txt->ReadOnly = true;
	this->mobile_no_txt->ReadOnly = true;
	this->address_txt->ReadOnly = true;
	this->profession_selector->Visible = false;
	
	//Reloads the form to show updated profile
	profile_member_Load(sender, e);

}


/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::profile_member::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

/// <summary>
/// Button OnClick function to Open Profile of Book Borrowed and Book Borrower along with their details
/// </summary>
System::Void LMS::profile_member::member_borrow_history_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{
		//=======================================================
		//This section converts the ID from the second column to String form to open profile

		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->member_borrow_history_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================

		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Order ID along with it 
		LMS::profile_order^ profile_order_f = gcnew LMS::profile_order(str);
		this->Hide();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_order_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			LMS::dbInteract::fill_datagrid_member_profile(this->member_id_txt->Text, member_borrow_history_dataGridView);
		}

	}
}

/// <summary>
/// Function to change the password of the Member
/// </summary>
System::Void LMS::profile_member::change_pass_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	//When clicked certain buttons are made invisible and some are made visible
	this->new_pass_lbl->Visible = true;
	this->new_pass_txt->Visible = true;
	this->confirm_newpass_btn->Visible = true;
	this->change_pass_btn->Visible = false;
}

/// <summary>
/// Function to confirm the changes of new password
/// </summary>
/// @see update_profile_func::change_pass_member()
System::Void LMS::profile_member::confirm_newpass_btn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("The password will be changed. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
	{

		//IF change password function return true it shows message box
		//ELSE it shows error message
		if (LMS::dbInteract::change_pass_member(this->member_id_txt->Text, sql_connection_func::password_hasher(this->member_id_txt->Text, this->new_pass_txt->Text)) == true)
		{
			MessageBox::Show("Password is updated");
		}
		else
		{
			MessageBox::Show("SOME ERROR HAS OCCURED IN UPDATING PASSWORD", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Prevously buttons made visible are made invisible and vice versa
		this->new_pass_lbl->Visible = false;
		this->new_pass_txt->Visible = false;
		this->confirm_newpass_btn->Visible = false;
		this->change_pass_btn->Visible = true;
		this->new_pass_txt->Text = "";
	}
	else
	{
		//do nothing
	}
	
}
