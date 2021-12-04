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
	/// Function to delete profile of a member
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the member whose profile needs to be deleted
	/// </param>
	/// <returns>
	/// Returns true if it is successful in deleting
	/// </returns>
	bool delete_member_profile(String^ input_id);

	/// <summary>
	/// Function to delete profile of a book
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the book whose profile needs to be deleted
	/// </param>
	/// <param name="borrow_status_input">
	/// String input for checking the status of Book being borrowed or not
	/// </param>
	/// <param name="final_fine">
	/// String input for Fine on the Book upon being Lost
	/// </param>
	/// <returns>
	/// Returns true if it is successful in deleting
	/// </returns>
	bool delete_book_profile(String^ input_id, String^ borrow_status_input, String^ final_fine);

}