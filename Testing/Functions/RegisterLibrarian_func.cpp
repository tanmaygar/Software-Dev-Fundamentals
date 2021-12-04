#include "pch.h"
#include "RegisterLibrarian_func.h"
#include "connection_sql_func.h"

/// <summary>
/// Registers new librarian with the given arguments/details
/// </summary>
bool LMS::dbInteract::RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
	String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender)
{
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//Encrypting password by hash method
	password = sql_connection_func::password_hasher(username, password);

	//Insert query for registering librarian
	MySqlCommand^ LibraryUserPassInsertQuery = gcnew MySqlCommand("INSERT INTO library_system_db.library_user_pass \
		VALUES('" + username + "',\
		'" + password + "',\
		'" + Name + "',\
		'" + DOB + "',\
		'" + Address + "',\
		'" + Email + "',\
		'" + Mobile + "',\
		'" + Gender + "')	;", conDataBase);
	conDataBase->Open();

	LibraryUserPassInsertQuery->ExecuteNonQuery();

	//Closing current session with the database
	conDataBase->Close();
	return true;
}
