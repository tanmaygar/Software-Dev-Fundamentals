#include "pch.h"
#include "login_to_librarian_db.h"
#include "connection_sql_func.h"

namespace connection_to_librarian_db {

	/// <summary>
	/// This function returns a boolean value for the user being a librarian or not by checking in the database
	/// </summary>
	bool is_librarian(String^ username_input, String^ password_input)
	{
		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		//This command find whether the user is a librarian or not
		MySqlCommand^ is_librarian_cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system_db.library_user_pass WHERE \
		library_username='" + username_input + "' and library_password = '" + sql_connection_func::password_hasher(username_input, password_input) + "' ;", conDataBase);

		MySqlDataReader^ myReader;
		try {

			//Open Database
			conDataBase->Open();
			myReader = is_librarian_cmdDataBase->ExecuteReader();
			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				//
				//	IN Login Page IF THIS IS TRUE THEN OPEN Home Page WITH ALL BUTTONS ALLOWED FOR LIBRARAIN
				//
				MessageBox::Show("You are librarian");

				//Return True if the user is a librarian
				return true;
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

		//Close the connection to DataBase
		conDataBase->Close();

		//Return false if user is not a librarian
		return false;
	}
}
