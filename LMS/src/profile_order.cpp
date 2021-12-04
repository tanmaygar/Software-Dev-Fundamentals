#include "pch.h"
#include "profile_order.h"

///Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
LMS::profile_order::profile_order(void)
{
	InitializeComponent();
}

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
/// </summary>
/// @see transfer_order_id, InitializeComponent()
LMS::profile_order::profile_order(String^ input_for_orderid)
{
	InitializeComponent();
	transfer_order_id = input_for_orderid;
}

LMS::profile_order::~profile_order()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode and fills all the textboxes
/// </summary>
/// @see fill_user_data(), fill_book_data()
System::Void LMS::profile_order::profile_order_Load(System::Object^ sender, System::EventArgs^ e)
{

	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->order_id_txt->Text = transfer_order_id;

	//ENUM for columns in the database
	enum column_id_for_order_history
	{
		column_order_id = 0,
		column_book_id = 1,
		column_member_id = 2,
		column_issue_ = 3,
		column_return_ = 4,
		column_fine_ = 5,
		column_stat_ = 6,
	};

	//Creates connection with database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of Order of that Order ID
	MySqlCommand^ get_order_details_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history\
		WHERE order_id = " + transfer_order_id + ";", conDataBase);

	MySqlDataReader^ myReader;
	//MessageBox::Show(transfer_order_id);

	try {

		//Opens Connection to DataBase
		conDataBase->Open();

		//Execute the function to return details of the Order/Issue from Database
		myReader = get_order_details_cmdDataBase->ExecuteReader();

		while (myReader->Read())
		{
			//Strings to signify each detail which would later inititialize the textboxes
			String^ printing_member_id;
			String^ printing_book_id;
			String^ printing_fine;
			

			MySql::Data::Types::MySqlDateTime print_date_of_issue;
			
			print_date_of_issue = myReader->GetMySqlDateTime("date_issue");
			

			//IF the return column or fine column is empty then it initializes as empty character in the textbox
			//ELSE it shows those details as well
			if (myReader->IsDBNull(column_id_for_order_history::column_return_) || myReader->IsDBNull(column_id_for_order_history::column_fine_))
			{
				this->date_return_txt->Text = "";
				this->order_fine_txt->Text = "";
			}
			else
			{
				MySql::Data::Types::MySqlDateTime print_date_of_return;
				print_date_of_return = myReader->GetMySqlDateTime("date_returned");
				printing_fine = myReader->GetString("borrow_fine");
				this->date_return_txt->Text = print_date_of_return.ToString();
				this->order_fine_txt->Text = printing_fine;
			}

			printing_member_id = myReader->GetString("member_id");
			printing_book_id = myReader->GetString("book_id");
			

			this->member_id_txt->Text = printing_member_id;
			this->book_id_txt->Text = printing_book_id;

			this->date_issue_txt->Text = print_date_of_issue.ToString();
			
		}


	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);

	}

	//Calls the functions to fill data of Member and Book
	fill_user_data();
	fill_book_data();

	//Closes the connection with the Database
	conDataBase->Close();
}

/// <summary>
/// It fills all the required textboxes related to user data with all the data from the database
/// </summary>
void LMS::profile_order::fill_user_data()
{
	//Creates connection with database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of the Member of that Order ID
	MySqlCommand^ get_member_det_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data WHERE member_id = " + this->member_id_txt->Text + ";", conDataBase);
	MySqlDataReader^ myReader;
	try {
		//Opens connection with the DataBase
		conDataBase->Open();

		//Execute the function to return details of the Member from Database
		myReader = get_member_det_cmdDataBase->ExecuteReader();

		while (myReader->Read())
		{
			//Strings to signify each detail which would later inititialize the textboxes
			String^ printing_name;
			
			String^ printing_profession;
			String^ printing_email;
			String^ printing_mobile;
			String^ printing_address;
			
			MySql::Data::Types::MySqlDateTime print_dob;
			printing_name = myReader->GetString("member_name");
			printing_profession = myReader->GetString("member_profession");
			printing_email = myReader->GetString("member_email");
			printing_mobile = myReader->GetString("member_mobile");
			printing_address = myReader->GetString("member_address");
			
			print_dob = myReader->GetMySqlDateTime("member_dob");
			this->name_txt->Text = printing_name;
			
			this->email_id_txt->Text = printing_email;
			this->mobile_no_txt->Text = printing_mobile;
			this->address_txt->Text = printing_address;
			
			this->dob_member_txt->Text = print_dob.ToString();
			this->profession_txt->Text = printing_profession;

		}


	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

	//Closes the Connection with the DataBase
	conDataBase->Close();
}

/// <summary>
/// It fills all the required textboxes related to book data with all the data from the database
/// </summary>
void LMS::profile_order::fill_book_data()
{
	//Creates connection with database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command returns details of the Books of that Order ID
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE book_id = " + this->book_id_txt->Text + ";", conDataBase);
	
	MySqlDataReader^ myReader;
	try {
		//Opens the connection with the database
		conDataBase->Open();

		//Execute the function to return details of the Book from Database
		myReader = cmdDataBase->ExecuteReader();

		while (myReader->Read())
		{

			//Strings to signify each detail which would later inititialize the textboxes
			String^ printing_name;

			String^ printing_author;
			String^ printing_publisher;
			String^ printing_price;
			String^ printing_edition_no;
			String^ printing_book_borrow_stat;
			

			printing_name = myReader->GetString("book_name");
			printing_author = myReader->GetString("book_author");
			printing_publisher = myReader->GetString("book_publisher");
			printing_price = myReader->GetString("book_price");
			printing_edition_no = myReader->GetString("book_edition_no");
			printing_book_borrow_stat = myReader->GetString("book_borrow_status");
			
			this->bookname_txt->Text = printing_name;

			this->author_txt->Text = printing_author;
			this->publisher_txt->Text = printing_publisher;
			this->price_txt->Text = printing_price;
			this->edition_no_txt->Text = printing_edition_no;
			this->borrow_stat_txt->Text = printing_book_borrow_stat;
			

		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}

	//Closes the connection with the database
	conDataBase->Close();
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::profile_order::back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}