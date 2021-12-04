#include "pch.h"
#include "AddBook_func.h"
#include "connection_sql_func.h"

/// <summary>
/// Adds new books into library database
/// </summary>
bool LMS::dbInteract::AddBook_func(int& firstBookId, String^ Name, String^ Author, String^ Publisher, \
	String^ Category, const int EditionNo, const int NoOfCopies, const int Price)
{
	//Database connection command
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	//Insert command to add books into library database
	MySqlCommand^ BookDataInsertQuery = gcnew MySqlCommand("INSERT INTO library_system_db.book_data \
		(book_name, book_author, book_publisher, book_price,book_edition_no,category) \
		VALUES('" + Name + "',\
		'" + Author + "',\
		'" + Publisher + "',\
		'" + Price + "',\
		'" + EditionNo + "',\
		'" + Category + "');", conDataBase);

	MySqlCommand^ BookIdSelectQuery = gcnew MySqlCommand("SELECT * FROM library_system_db.book_data WHERE (book_name = '" + Name + "' \
		AND book_edition_no = " + EditionNo + ");", conDataBase);

	MySqlDataReader^ myReader;

	conDataBase->Open();

	int copies_no = System::Convert::ToInt32(NoOfCopies);
	for (int i = 0; i < copies_no; i++)
		BookDataInsertQuery->ExecuteNonQuery();

	myReader = BookIdSelectQuery->ExecuteReader();
	if (myReader->Read())
	{
		//Reads ID of first book added in the current transcation
		firstBookId = myReader->GetInt32("book_id");
	}
	myReader->Close();

	//Closing current session with the database
	conDataBase->Close();

	if (firstBookId != -1)
		return true;
}
