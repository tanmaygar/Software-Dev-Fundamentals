#include "pch.h"
#include "update_profile_func.h"
#include "connection_sql_func.h"


/// <summary>
/// This function updates details such as Profession, email, mobile number and address of the member whose ID is given as inout
/// </summary>
bool LMS::dbInteract::update_member_profile(String^ input_id, String^ profession_input, String^ email_input, String^ mobile_input, String^ address_input)
{
	//Intitializing a boolean value to be returned
	bool return_val = false;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command updates the Profession, Email, Mobile, Address of the Member of that Memeber ID
	MySqlCommand^ update_det_member_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data set member_profession = '" + profession_input + "', member_email='" + email_input + "', member_mobile=" + mobile_input + ", member_address = '" + address_input + "'WHERE member_id = " + input_id + ";", conDataBase);

	try {
		//Open Database
		conDataBase->Open();

		//Execute the SQL Commands
		update_det_member_cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Profile is updated");

		//Return true if everything is done
		return_val = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);

		//If any exception occurs return value is made false
		return_val = false;
	}

	//Close the connection to DataBase
	conDataBase->Close();
	//Return the required return value based on success or fail
	return return_val;
}

/// <summary>
/// This function adds new copies to the database for the particular Book ID
/// </summary>
bool LMS::dbInteract::update_book_profile(String^ input_id, int num_copies)//, String^ book_name_input, String^ book_edition_input)
{
	//Intitializing a boolean value to be returned
	bool return_val = false;

	//MessageBox::Show("" + num_copies + "");

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//This command duplicates the entire row with new Book ID
	MySqlCommand^ duplicate_book_copies_cmdDataBase = gcnew MySqlCommand("INSERT INTO library_system_db.book_data (book_name, book_author, book_publisher, book_price, book_edition_no, category)\
		SELECT  book_name, book_author, book_publisher, book_price, book_edition_no, category\
		FROM library_system_db.book_data\
		WHERE book_id = '" + input_id + "'; ", conDataBase);


	try {

		//Open Database
		conDataBase->Open();

		//Execute SQL Commands based on number of copies to be added
		for (int i = 0; i < num_copies; i++)
		{
			duplicate_book_copies_cmdDataBase->ExecuteNonQuery();
		}

		//Return true if everything is done
		return_val = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);

		//If any exception occurs return value is made false
		return_val = false;
	}

	//Close the connection to DataBase
	conDataBase->Close();

	//Return the required return value based on success or fail
	return return_val;

}

/// <summary>
/// This function updates the password of the member by taking Password in hashed form as an input and ID of the member
/// </summary>
bool LMS::dbInteract::change_pass_member(String^ input_id, String^ new_pass_input)
{

	//Intitializing a boolean value to be returned
	bool return_val = false;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	//MySqlCommand^ change_pass_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.user_pass set member_id = " + this->member_id_txt->Text + ", user_password = "+ this->new_pass_txt->Text +" WHERE member_id = " + this->member_id_txt->Text + ";", conDataBase);

	//This command updates the Password of the Member
	MySqlCommand^ change_pass_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.user_pass set member_id = ' " + input_id + " ', user_password = '" + new_pass_input + "' WHERE member_id =' " + input_id + " ';", conDataBase);
	try 
	{

		//Open Database
		conDataBase->Open();

		//Execute SQL Commands
		change_pass_cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Password is updated");

		//Return true if everything is done
		return_val = true;
	}

	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);

		//If any exception occurs return value is made false
		return_val = false;
	}

	//Close the connection to DataBase
	conDataBase->Close();

	//Return the required return value based on success or fail
	return return_val;
}
