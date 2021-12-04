#include "pch.h"
#include "delete_profile_func.h"
#include "connection_sql_func.h"

/// <summary>
/// This function simply deactivates the membership of a member instead of completetly removing from the database
/// </summary>
/// If the book was orginally borrowed by a member then it updates the Borrow History with fine and changes Borrow Status to 'LOST'
bool LMS::dbInteract::delete_member_profile(String^ input_id)
{
	//Intitializing a boolean value to be returned
	bool return_value = false;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	
	//This command updates the Membership Status to 'DEACTIVATED'
	MySqlCommand^ update_member_stat_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data set member_id = " + input_id + ", membership_stat = 'DEACTIVATED' WHERE member_id = " + input_id + ";", conDataBase);
	
	//This command deletes username and password of the member from the UserName Password Database
	MySqlCommand^ delete_user_pass_cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system_db.user_pass WHERE member_id = " + input_id + ";", conDataBase);

	try {

		//Open Database
		conDataBase->Open();

		//Execute the SQL Commands
		update_member_stat_cmdDataBase->ExecuteNonQuery();
		delete_user_pass_cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Profile is deleted");
		
		//Return true if everything is done
		return_value = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);

		//If any exception occurs return value is made false
		return_value = false;
	}

	//Close the connection to DataBase
	conDataBase->Close();

	//Return the required return value based on success or fail
	return return_value;
}

/// <summary>
/// This function simply changes the status of the book as lost instead of completetly removing from the database
/// </summary>
bool LMS::dbInteract::delete_book_profile(String^ input_id, String^ borrow_status_input, String^ final_fine)
{
	//Intitializing a boolean value to be returned
	bool return_val = false;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	
	//This command updates the Book Borrow Status as 'LOST'
	MySqlCommand^ update_lost_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.book_data SET book_borrow_status = 'LOST' WHERE book_id = " + input_id + ";", conDataBase);

	//This command updates the Last Issue/Order in which the particular book was borrowed and Sets the fine and Returned Date and changes Status to 'LOST'
	MySqlCommand^ update_last_borrow_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.borrow_history SET borrow_fine = '"+ final_fine+"', date_returned = CURDATE(), borrow_status = 'LOST' WHERE order_id = (SELECT order_id FROM (SELECT * FROM library_system_db.borrow_history WHERE book_id = '"+ input_id+ "' ORDER BY order_id DESC Limit 1) as X);", conDataBase);
	
	//This command updates the number of Books Borrowed currently by the Member
	MySqlCommand^ update_member_book_stat_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data SET member_no_book_stat = member_no_book_stat - 1 WHERE member_id = (SELECT member_id FROM(SELECT * FROM library_system_db.borrow_history WHERE book_id = '" + input_id + "' ORDER BY order_id DESC Limit 1) as X);", conDataBase);

	try {
		//Open Database
		conDataBase->Open();

		//Execute SQL Commands
		update_lost_cmdDataBase->ExecuteNonQuery();
		

		//This IF block is there to check if the Book was borrowed or not
		if (borrow_status_input == "BORROWED")
		{
			//IF the book was borrowed then it updates the Last Order along with the fine
			update_last_borrow_cmdDataBase->ExecuteNonQuery();
			update_member_book_stat_cmdDataBase->ExecuteNonQuery();
		}

		//MessageBox::Show("Profile is deleted");

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
