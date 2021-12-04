#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Adds new books into library database
	/// </summary>
	/// <param name="Name"></param>
	/// <param name="Author"></param>
	/// <param name="Publisher"></param>
	/// <param name="Category"></param>
	/// <param name="EditionNo"></param>
	/// <param name="NoOfCopies">No of Copies to be added in the Current function call/Transcation</param>
	/// <param name="Price"></param>
	/// <returns>Book Id(integer) of the first book that is being added in the current transaction</returns>
	bool AddBook_func(int& firstBookId, String^ Name, String^ Author, String^ Publisher, \
		String^ Category, const int EditionNo, const int NoOfCopies, const int Price);
}