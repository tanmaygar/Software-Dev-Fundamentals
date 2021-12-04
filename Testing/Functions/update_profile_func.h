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
	/// Function to update details of the member
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the member
	/// </param>
	/// <param name="profession_input">
	/// String input for profession of the member as STUDENT, FACULTY, ALUMNI
	/// </param>
	/// <param name="email_input">
	/// String input for email of the member
	/// </param>
	/// <param name="mobile_input">
	/// String input for mobile number of the member
	/// </param>
	/// <param name="address_input">
	/// String input for address of the member
	/// </param>
	/// <returns>
	/// Returns true if it is successful in updating
	/// </returns>
	bool update_member_profile(String^ input_id, String^ profession_input, String^ email_input, String^ mobile_input, String^ address_input);

	/// <summary>
	/// Function to update details of the book
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the book
	/// </param>
	/// <param name="num_copies">
	/// String input for number of copies of the book to be added
	/// </param>
	/// <returns>
	/// Returns true if it is successful in updating
	/// </returns>
	bool update_book_profile(String^ input_id, int num_copies);

	/// <summary>
	/// Function to update password of the member
	/// </summary>
	/// <param name="input_id">
	/// String input for ID of the member
	/// </param>
	/// <param name="new_pass_input">
	/// String input for new password of the member in hashed form
	/// </param>
	/// <returns>
	/// Returns true if it is successful in updating
	/// </returns>
	bool change_pass_member(String^ input_id, String^ new_pass_input);

}