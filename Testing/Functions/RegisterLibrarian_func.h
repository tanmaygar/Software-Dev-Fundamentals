#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Registers new librarian with the given arguments/details
	/// </summary>
	/// <param name="username">Unique identifier for a librarian</param>
	/// <param name="password">Password String</param>
	/// <param name="Name">Name of the Librarian</param>
	/// <param name="DOB">Date of Birth of Librarian</param>
	/// <param name="Address">Address of the Librarian</param>
	/// <param name="Email">Email of the Librarian</param>
	/// <param name="Mobile">Mobile No of the Librarian</param>
	/// <param name="Gender">Gender of the Librarian</param>
	/// <returns>True, if Librarian registration is successful., else false</returns>
	bool RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
		String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender);
}