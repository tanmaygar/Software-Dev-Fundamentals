#include "pch.h"
#include "fine_function.h"
#include  "connection_sql_func.h"

//
//	FINE FUNCTION DEFINITION
//
namespace fine_func {

	/// <summary>
	/// This function calculates the fine that the borrower needs to pay after returning the book depending upon the profession
	/// </summary>
	int calculate_fine(int order_id_input, int member_id_input, String^ borrow_profession_input)
	{
		//Initializing the fine to 0
		int value_fine = 0;
		int num_date_difference = 0;

		//Deafult number of days allowed for each type of member
		int default_student_allowance = 7, default_faculty_allowance = 14, default_alumni_allowance = 10;

		//Fine per day for each type of member
		int perday_student = 10, perday_faculty = 20, perday_alumni = 20;

		//Creating a connection to database
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

		//This command calculates the difference between the dates of issue and return from borrow_history table
		MySqlCommand^ datediff_cmdDataBase = gcnew MySqlCommand("SELECT DATEDIFF(date_returned, date_issue) AS fine_column FROM library_system_db.borrow_history WHERE order_id = " + order_id_input + ";", conDataBase);

		MySqlDataReader^ myReader;
		try {

			//Open Database
			conDataBase->Open();
			myReader = datediff_cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				num_date_difference = myReader->GetInt16("fine_column");
				//MessageBox::Show(""+num_date_difference);
			}
			myReader->Close();

			//IF blocks check for each profession of the member and calculates fine based on that
			if (borrow_profession_input == "Student")
			{
				if (num_date_difference <= default_student_allowance)
				{
					MessageBox::Show("No of days overdue = 0 \n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_student_allowance;
					value_fine = num_date_difference * perday_student;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_profession_input == "Faculty")
			{
				if (num_date_difference <= default_faculty_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_faculty_allowance;
					value_fine = num_date_difference * perday_faculty;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrow_profession_input == "Alumni")
			{
				if (num_date_difference <= default_alumni_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_alumni_allowance;
					value_fine = num_date_difference * perday_alumni;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrow_profession_input + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}

		//Close the connection to DataBase
		conDataBase->Close();
		return 0;
	}

	/// <summary>
	/// This function finds the value of Fine to be paid when the book is lost and is made to be 2 times the price of the book
	/// </summary>
	int calculate_fine_lost_book(int price_book_input)
	{
		int fine = price_book_input * 2;
		return fine;
	}
}