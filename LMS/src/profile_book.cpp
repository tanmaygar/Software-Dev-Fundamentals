#include "pch.h"
#include "profile_book.h"
#include "written_functions/delete_profile_func.h"
#include "written_functions/update_profile_func.h"
#include "written_functions/fine_function.h"

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
/// </summary>
///@see InitializeComponent()
LMS::profile_book::profile_book(void)
{
	InitializeComponent();
}

/// <summary>
///Constructor calls for functions to Initialize all the components of the form and make buttons visible based on the User being a librarian or not
/// </summary>
/// @see transfer_id_book, transfer_isLibrarian, InitializeComponent()
LMS::profile_book::profile_book(String^ label_book_id, bool isLibrarian)
{
	InitializeComponent();
	transfer_id_book = label_book_id;
	transfer_isLibrarian = isLibrarian;

	//IF statement to check if the User is a librarian or not
	if (transfer_isLibrarian == false)
	{
		//IF not then the buttons for Update and Delete Profile are made invisible
		this->update_profile_button->Visible = false;
		this->delete_profile_button->Visible = false;
	}
}

LMS::profile_book::~profile_book()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode and fills all the textboxes and fill the Data Grid
/// </summary>
/// @see filling_datagrid::fill_datagrid_book_profile()
System::Void LMS::profile_book::profile_book_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of Book of that Book ID
	MySqlCommand^ fill_data_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data\
		WHERE book_id = " + transfer_id_book + ";", conDataBase);
	MySqlDataReader^ myReader;

	try {
		//Opens the Database connection
		conDataBase->Open();

		//Execute the function to return details of the Book from Database
		myReader = fill_data_cmdDataBase->ExecuteReader();

		//Strings to signify each detail which would later inititialize the textboxes
		String^ printing_name;
		String^ printing_id;
		String^ printing_author;
		String^ printing_publisher;
		String^ printing_price;
		String^ printing_edition_no;
		String^ printing_book_borrow_stat;
		String^ printing_category;
		
		//While loop to read the details from the Reader
		while (myReader->Read())
		{
			//Getting the details in String Form
			printing_id = myReader->GetString("book_id");
			printing_name = myReader->GetString("book_name");
			printing_author = myReader->GetString("book_author");
			printing_publisher = myReader->GetString("book_publisher");
			printing_price = myReader->GetString("book_price");
			printing_edition_no = myReader->GetString("book_edition_no");
			printing_book_borrow_stat = myReader->GetString("book_borrow_status");
			printing_category = myReader->GetString("category");

			//Initialzing the Text Box
			this->bookname_txt->Text = printing_name;
			this->book_id_txt->Text = printing_id;
			this->author_txt->Text = printing_author;
			this->publisher_txt->Text = printing_publisher;
			this->price_txt->Text = printing_price;
			this->edition_no_txt->Text = printing_edition_no;
			this->borrow_stat_txt->Text = printing_book_borrow_stat;
			this->category_txt->Text = printing_category;

		}
		

		//Calls the function to fill datagrid with IDs of the copies of the book
		LMS::dbInteract::fill_datagrid_book_profile(this->bookname_txt->Text, book_copies_dataGridView, this->edition_no_txt->Text);

		//Counts the Number of rows to calculate the number of copies
		int num_row = this->book_copies_dataGridView->RowCount;
		this->no_copies_txt->Text = num_row.ToString();

	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

	//Close the connection to DataBase
	conDataBase->Close();

	//Initializes the numeric Up Down as 0
	this->numeric_updown_no_copies->Value = 0;
}

/// <summary>
/// Button OnClick To Switch into Update Mode and make some Read-Only Fields as Re-Writable
/// </summary>
System::Void LMS::profile_book::update_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Update Profile");
	//When Updating the profile it makes "Confirm Changes" and "Numeric Up Down" buttons as visible and original 
	//"Update Profile" button as invisible
	this->numeric_updown_no_copies->Visible = true;
	this->confirm_change_button->Visible = true;
	this->update_profile_button->Visible = false;
}

/// <summary>
/// Button OnClick To Switch the particular copy to Lost and removed from showing in the list
/// </summary>
/// @see delete_profile_func::delete_book_profile(), fine_func::calculate_fine_lost_book()
System::Void LMS::profile_book::delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Delete Profile");
	//IF block to give warning to User that Profile will be deleted
	if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
	{

		//IF is YES then the profile will be deleted which actually means the book is now technically Lost
		
		//Initializes the fine as price of book
		int total_fine = Int32::Parse(this->price_txt->Text);

		//Calculates the total fine to be paid by calling the function
		int fine_paid_lost_book = fine_func::calculate_fine_lost_book(total_fine);

		//IF block which checks that if the delete book profile function returns true then it shows message to pay the fine
		//ELSE it shows an error message
		if (LMS::dbInteract::delete_book_profile(this->book_id_txt->Text, this->borrow_stat_txt->Text, System::Convert::ToString(fine_paid_lost_book)) == true)
		{
			MessageBox::Show("Profile is deleted");
			MessageBox::Show("Pay Fine for the book: Rs " + System::Convert::ToString(fine_paid_lost_book));
		}
		else
		{
			MessageBox::Show("SOME ERROR HAS OCCURED IN DELETING BOOK PROFILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		//Closes the form and goes back to previous page
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	else
	{
		//do nothing
	}
}

/// <summary>
/// Button OnClick function to switch back into Read-Only Mode and updating the profile of the Book and changing it in the databse as well
/// </summary>
/// @see update_profile_func::update_book_profile()
System::Void LMS::profile_book::confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Previuosly made visible elements are now made invisible and vice versa
	this->numeric_updown_no_copies->Visible = false;
	this->confirm_change_button->Visible = false;
	this->update_profile_button->Visible = true;

	
	

	//IF the number of books to be added is less than or equal to 0 then it shows message and nothing else
	if ((int)this->numeric_updown_no_copies->Value <= 0)
	{
		MessageBox::Show("" + (int)this->numeric_updown_no_copies->Value + "");
	}
	else
	{
		MessageBox::Show("" + (int)this->numeric_updown_no_copies->Value + "");
		//IF the update profile book successfully updates the profile of the book then it shows message of success
		//ELSE it shows Error
		if (LMS::dbInteract::update_book_profile(this->book_id_txt->Text, (int)this->numeric_updown_no_copies->Value) == true)
		{
			MessageBox::Show("New copies are added");
		}
		else
		{
			MessageBox::Show("SOME ERROR HAS OCCURED IN UPDATING BOOK PROFILE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	//Reload the form to show new additions if there are any
	profile_book_Load(sender, e);
}

/// <summary>
/// Button OnClick function to Open Profile of other copy of the book with more details
/// </summary>
System::Void LMS::profile_book::book_copies_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{
		//=======================================================
		//This section converts the ID from the second column to String form to open profile

		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->book_copies_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================

		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Book ID along with it as well as if the user is librarian or not
		LMS::profile_book^ profile_book_f = gcnew LMS::profile_book(str, transfer_isLibrarian);
		this->Hide();
		//profile_book_f->ShowDialog();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			LMS::dbInteract::fill_datagrid_book_profile(this->bookname_txt->Text, book_copies_dataGridView, this->edition_no_txt->Text);
		}

	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::profile_book::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

