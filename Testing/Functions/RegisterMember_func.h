#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Registers Student/Faculty/Alumini with given arugments/details as a Member of Librarian
	/// </summary>
	/// <param name="Name">Name of Member</param>
	/// <param name="DOB">Date of Birth of Member</param>
	/// <param name="Address">Address of Member</param>
	/// <param name="EmailId">Email of Member</param>
	/// <param name="MobileNo">Mobile No of Member</param>
	/// <param name="Profession">Profession of Member</param>
	/// <param name="Gender">Gender of Member</param>
	/// <param name="Password">Password of Member</param>
	/// <returns>True if registration is successful, else false</returns>
	bool RegisterMember_func(int& memberId, String^ Name, String^ DOB, String^ Address, \
		String^ EmailId, String^ MobileNo, String^ Profession, String^ Gender, String^ Password);
}