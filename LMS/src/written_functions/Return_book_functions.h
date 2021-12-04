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
	/// Function to get data of Member id , Book id ,Borrow status of the given Order Id and to get 
	/// profession of the member who borrowed the book with given Order id 
	/// </summary>
	/// <param name="Order_Id">
	/// Input is Order Id of the Order of which we want to get data 
	/// </param>
	/// <param name="Member_Id">
	/// Input is variable in which we want to store the Member Id of the Order
	/// with given Order_Id
	/// </param>
	/// <param name="Book_Id">
	/// Input is variable into Which we want to store the Book Id of the Order
	/// with given Order_Id
	/// </param>
	/// <param name="Borrow_status">
	/// Input is variable into which we want to store the Borrow status of the Order with given Order_Id
	/// </param>
	/// <param name = "Profession">
	/// Input is variable into which we wnat to store the profession of member , who borrowed book with 
	/// given Order_Id
	/// </param>
	void Get_data_Order(int Order_Id, int& Member_Id, int& Book_Id, String^& Borrow_status, String^& Profession);


	/// <summary>
	/// Function to update data of the book returned ,in book data table
	/// </summary>
	/// <param name="Book_Id">
	/// Input is book id of returned book
	/// </param>
	void Update_Book_data_Returned(int Book_Id);

	/// <summary>
	/// Function to Update Borrow satus and Return Date in Borrow History table 
	/// </summary>
	/// <param name="Order_Id">
	/// Input is Order Id of the Order in which Borrow status and Return date should be updated
	/// </param>
	void Updata_Borrow_history_data(int Order_Id);

	/// <summary>
	/// Function to Update Fine in Borrow History table
	/// </summary>
	/// <param name="Order_Id">
	/// Input is Order Id of the Order in which fine has to be updated
	/// </param>
	/// <param name="fine">
	/// Input is the value of fine.
	/// </param>
	void Update_Borrow_history_fine(int Order_Id, int fine);

	/// <summary>
	/// Function to Update Member data table
	/// </summary>
	/// <param name="Member_Id">
	/// Input is the Member Id of the Member, Who returned the book 
	/// </param>
	void Update_Member_data_Returned(int Member_Id);

	/// <summary>
	///  Function to Show Message that Book is Returned Successfully with given Order Id 
	/// </summary>
	/// <param name="Order_id">
	/// Input is the Order Id of the Order , which is returned
	/// </param>
	/// <param name="Book_Id">
	/// Input is the Book ID of the book , which is retuned
	/// </param>
	/// <param name="Member_Id">
	/// Input is the Member Id of Member Who returned the Book
	/// </param>
	void Message_Return_Successfully(int Order_id, int Book_Id, int Member_Id);


}
