#pragma once


namespace connection_to_librarian_db {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Bool function to check if user is a librarian or not
	/// </summary>
	/// <param name="username_input">
	/// String username that has been passed as an argument
	/// </param>
	/// <param name="password_input">
	/// String password that has been passed as an argument
	/// </param>
	/// <returns>
	/// boolean value is true if the user is a librarian else false
	/// </returns>
	bool is_librarian(String^ username_input, String^ password_input);

}