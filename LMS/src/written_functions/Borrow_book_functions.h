#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Function to Check whether Book exists and it is available, with given Book Id in Book data table
	/// </summary>
	/// <param name="Book_Id">
	/// Input is Book Id of Book , which we want to check
	/// </param>
	/// <returns>
	/// returns true if there exists a book with given Book_Id in book data table
	/// </returns>
	bool Check_book(String^ Book_Id);

	/// <summary>
	/// Function to Check whether Member exists with Active Membership status ,with given Member Id in Member data table
	/// </summary>
	/// <param name="Member_Id">
	/// Input is Member Id of Member ,which we want to check
	/// </param>
	/// <returns>
	/// returns true if there exists a member with Active Membership ,with given Member_Id
	/// </returns>
	bool Check_Memeber(String^ Member_Id);

	/// <summary>
	/// Function to Update Book data , when Book is Borrowed succesfully
	/// </summary>
	/// <param name="Book_Id">
	/// Input is Book Id of Book ,which is Borrowed
	/// </param>
	void Update_Book_data_Borrowed(String^ Book_Id);

	/// <summary>
	/// Function to Update Member data ,when Book is Borrowed succesfully
	/// </summary>
	/// <param name="Member_id">
	/// Input is Member Id of Member ,who borrowed the book
	/// </param>
	void Update_member_data_Borrowed(String^ Member_id);

	/// <summary>
	/// Function to Update Borrow History ,When Book is Borrowed succesfully
	/// </summary>
	/// <param name="Book_Id">
	/// Input is Book Id of book ,which is Borrowed
	/// </param>
	/// <param name="Member_Id">
	/// Input is Member Id of Member, who borrowed the book with book id Book_ID
	/// </param>
	void Take_New_order(String^ Book_Id, String^ Member_Id);

	/// <summary>
	/// function to show a message in a boc that Book is borrowed successfully
	/// </summary>
	/// <param name="Book_Id">
	/// Input is Book Id of book ,which is Borrowed
	/// </param>
	/// <param name="Member_Id">
	/// Input is Member Id of Member, who borrowed the book with book id Book_ID
	/// </param>
	void Message_Borrowed_succesfully(String^ Book_Id, String^ Member_Id);

	/// <summary>
	/// Function to check other copies of a book , when specific copy of the book is not available
	/// </summary>
	/// <param name="Book_Id">
	/// Input is Book Id of book , which we want to check 
	/// </param>
	void Check_copies_available(String^ Book_Id);

}