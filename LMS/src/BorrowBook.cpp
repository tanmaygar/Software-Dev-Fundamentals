#include "pch.h"
#include "BorrowBook.h"
#include <written_functions/Borrow_book_functions.h>

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
/// </summary>
LMS::BorrowBook::BorrowBook(void)
{
	InitializeComponent();
}



LMS::BorrowBook :: ~BorrowBook()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// It loads the Form in full screen mode 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
System::Void LMS::BorrowBook::BorrowBook_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
}


/// <summary>
/// It checks 
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
System::Void LMS::BorrowBook::borrow_button_Click(System::Object^ sender, System::EventArgs^ e)
{


	try {

		if (LMS::dbInteract::Check_Memeber(this->member_id_txt->Text) == true)
		{

			if (LMS::dbInteract::Check_book(this->book_id_txt->Text) == true)
			{

				LMS::dbInteract::Update_Book_data_Borrowed(this->book_id_txt->Text);

				LMS::dbInteract::Take_New_order(this->book_id_txt->Text, this->member_id_txt->Text);

				LMS::dbInteract::Update_member_data_Borrowed(this->member_id_txt->Text);

				LMS::dbInteract::Message_Borrowed_succesfully(this->book_id_txt->Text, this->member_id_txt->Text);

			}
			else
			{
				LMS::dbInteract::Check_copies_available(this->book_id_txt->Text);
			}

		}
		else
		{
			MessageBox::Show("No Memeber was found with active membership for given Member ID");
		}

	}
	catch (Exception^ ex)
	{
		MessageBox::Show(ex->Message);
	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::BorrowBook::Back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
