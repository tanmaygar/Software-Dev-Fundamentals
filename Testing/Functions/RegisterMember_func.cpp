#include "pch.h"
#include "RegisterMember_func.h"
#include "connection_sql_func.h"


/// <summary>
/// Registers Student/Faculty/Alumini with given arugments/details
/// </summary>
bool LMS::dbInteract::RegisterMember_func(int& memberId, String^ Name, String^ DOB, String^ Address, String^ EmailId, \
	String^ MobileNo, String^ Profession, String^ Gender, String^ Password)
{
	String^ hashedPassword;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//Insert command for registering a member
	MySqlCommand^ MemberDataInsertQuery = gcnew MySqlCommand("INSERT INTO library_system_db.member_data (member_name, \
			member_dob, member_address, member_email, \
			member_mobile, member_profession, member_gender) \
			VALUES('" + Name + "',\
			'" + DOB + "',\
			'" + Address + "',\
			'" + EmailId + "',\
			" + MobileNo + ",\
			'" + Profession + "',\
			'" + Gender + "')	;", conDataBase);

	//Selecting details of the member added
	MySqlCommand^ GetIdSelectQuery = gcnew MySqlCommand("SELECT * FROM library_system_db.member_data \
			WHERE member_email = '" + EmailId + "';", conDataBase);

	MySqlDataReader^ myReader;
	conDataBase->Open();

	MemberDataInsertQuery->ExecuteNonQuery();

	myReader = GetIdSelectQuery->ExecuteReader();

	if (myReader->Read())
	{
		// Reading ID of the member registered in the current transcation
		memberId = myReader->GetInt32("member_id");
	}
	myReader->Close();

	//Encrypting password by hash method
	hashedPassword = sql_connection_func::password_hasher(memberId.ToString(), Password);

	//Insert query for adding login details of member registered into database
	MySqlCommand^ UserPassInsertQuery = gcnew MySqlCommand("USE library_system_db;INSERT INTO user_pass (member_id, user_password) \
			VALUES((SELECT member_id FROM member_data WHERE member_email = '" + EmailId + "'), '" + hashedPassword + "');", conDataBase);

	UserPassInsertQuery->ExecuteNonQuery();

	//Closing current session with the database
	conDataBase->Close();
	if (memberId != -1)
		return true;
}

