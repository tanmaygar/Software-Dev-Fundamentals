#include "pch.h"
#include "Return_book_functions.h"
#include "connection_sql_func.h"


void LMS::dbInteract::Get_data_Order(int Order_Id, int& Member_Id, int& Book_Id, String^& Borrow_status, String^& Profession)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;


	try
	{
		conDataBase->Open();

		MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT * FROM library_system_db.borrow_history WHERE\
                     order_id = '" + Order_Id + "';", conDataBase);

		myReader = Order_data->ExecuteReader();

		while (myReader->Read())
		{
			Member_Id = myReader->GetInt32("member_id");
			Book_Id = myReader->GetInt32("book_id");
			Borrow_status = myReader->GetString("borrow_status");
		}
		myReader->Close();

		MySqlCommand^ Member_data = gcnew MySqlCommand("SELECT member_profession FROM library_system_db.member_data WHERE\
                          member_id = '" + Member_Id + "';", conDataBase);

		myReader = Member_data->ExecuteReader();

		while (myReader->Read())
		{
			Profession = myReader->GetString("member_profession");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

	}
	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}




void LMS::dbInteract::Updata_Borrow_history_data(int Order_Id)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	try
	{
		conDataBase->Open();

		MySqlCommand^ Update_date_Borrow_status = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       date_returned = CURDATE(),borrow_status = 'RETURNED'\
		               WHERE order_id = '" + Order_Id + "';", conDataBase);

		Update_date_Borrow_status->ExecuteNonQuery();

		//Close the connection to DataBase
		conDataBase->Close();
	}
	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}


void LMS::dbInteract::Update_Borrow_history_fine(int Order_Id, int fine)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	try
	{
		conDataBase->Open();

		MySqlCommand^ Update_borrow_history_fine = gcnew MySqlCommand("UPDATE library_system_db.borrow_history set \
                       borrow_fine= '" + fine + "'\
		               WHERE order_id = '" + Order_Id + "';", conDataBase);


		//Below Query Updates fine coloumn in borrow_history by using fine function
		Update_borrow_history_fine->ExecuteNonQuery();

		//Close the connection to DataBase
		conDataBase->Close();

	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}

}


void LMS::dbInteract::Update_Member_data_Returned(int Member_Id)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	try
	{
		conDataBase->Open();

		MySqlCommand^ Update_books_borrowed = gcnew MySqlCommand("UPDATE  library_system_db.member_data\
                       set member_no_book_stat = member_no_book_stat - 1\
                       WHERE member_id ='" + Member_Id + "';", conDataBase);


		Update_books_borrowed->ExecuteNonQuery();

		//Close the connection to DataBase
		conDataBase->Clone();
	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}


void LMS::dbInteract::Update_Book_data_Returned(int Book_Id)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	try
	{
		conDataBase->Open();

		MySqlCommand^ Update_book_borrow_status = gcnew MySqlCommand("UPDATE library_system_db.book_data set\
                       book_borrow_status = 'AVAILABLE'\
                       WHERE book_id = " + Book_Id + " ;", conDataBase);

		Update_book_borrow_status->ExecuteNonQuery();

		//Close the connection to DataBase
		conDataBase->Close();
	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}


void LMS::dbInteract::Message_Return_Successfully(int Order_id, int Book_Id, int Member_Id)
{
	try
	{
		MessageBox::Show("Returned book successfully! \nBook_id = " + Book_Id + " \nMember_id = " + Member_Id + " \nOrder_id = " + Order_id + " ");
	}
	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}

/*

String^ LMS::dbInteract::Get_Profession(int Member_Id)
{
	String^ Profession;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;


	try
	{
		conDataBase->Open();
		MySqlCommand^ Member_data = gcnew MySqlCommand("SELECT member_profession FROM library_system_db.member_data WHERE\
						  member_id = '" + Member_Id + "';", conDataBase);

		myReader = Member_data->ExecuteReader();

		while (myReader->Read())
		{
			Profession = myReader->GetString("member_profession");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

		return Profession;
	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}

}


String^ LMS::dbInteract::Get_Borrow_status(int Order_Id)
{
	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;

	String^ Borrow_status;

	try
	{
		conDataBase->Open();

		MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT borrow_status FROM library_system_db.borrow_history WHERE\
					 order_id = '" + Order_Id + "';", conDataBase);

		myReader = Order_data->ExecuteReader();

		while (myReader->Read())
		{
			Borrow_status = myReader->GetString("borrow_status");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

		return Borrow_status;
	}
	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}

}



bool LMS::dbInteract::check_Order_Id(int Order_Id)
{

	bool return_value = false;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;

	String^ Borrow_status;

	try
	{
		conDataBase->Open();

		MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT borrow_status FROM library_system_db.borrow_history WHERE\
					 order_id = '" + Order_Id + "';", conDataBase);

		myReader = Order_data->ExecuteReader();

		while (myReader->Read())
		{
			Borrow_status = myReader->GetString("borrow_status");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

		if (Borrow_status == "BORROWED" || Borrow_status == "RETURNED" || Borrow_status == "LOST")
		{
			return_value = true;
		}

		return return_value;
	}
	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}
}

int LMS::dbInteract::Get_Member_Id(int Order_Id)
{
	int Member_Id;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;

	try
	{
		conDataBase->Open();
		MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT member_id FROM library_system_db.borrow_history WHERE\
						  order_id = '" + Order_Id + "';", conDataBase);

		myReader = Order_data->ExecuteReader();

		while (myReader->Read())
		{
			Member_Id = myReader->GetInt32("member_id");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

		return Member_Id;

	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}

}


int LMS::dbInteract::Get_Book_Id(int Order_Id)
{
	int Book_Id;

	//Creating a connection to database
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlDataReader^ myReader;

	try
	{
		conDataBase->Open();
		MySqlCommand^ Order_data = gcnew MySqlCommand("SELECT book_id FROM library_system_db.borrow_history WHERE\
						  order_id = '" + Order_Id + "';", conDataBase);

		myReader = Order_data->ExecuteReader();

		while (myReader->Read())
		{
			Book_Id = myReader->GetInt32("book_id");
		}
		myReader->Close();

		//Close the connection to DataBase
		conDataBase->Close();

		return Book_Id;

	}

	catch (Exception^ ex)
	{
		//If any exception occurs then show messagebox
		MessageBox::Show(ex->Message);
	}

}

*/