#include "pch.h"
#include "ReturnBook.h"

/// <summary>
///Constructor calls for functions to Initialize all the components of the form
///@see InitializeComponent()
/// </summary>
LMS::ReturnBook::ReturnBook(void)
{
	InitializeComponent();
}

LMS::ReturnBook :: ~ReturnBook()
{
	if (components)
	{
		delete components;
	}
}


/// <summary>
/// It loads the Form in full screen mode 
/// </summary>
System::Void LMS::ReturnBook::ReturnBook_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
}


/// <summary>
/// Function to return Book by checking order_id and borrow_Status of Book
/// </summary>
System::Void LMS::ReturnBook::return_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{
		int Order_id = Convert::ToInt32(this->order_id_txt->Text);

		int Book_Id;

		int Member_ID;

		String^ Borrow_status;

		String^ Profession;

		LMS::dbInteract::Get_data_Order(Order_id, Member_ID, Book_Id, Borrow_status, Profession);

		


		if (Borrow_status)
		{

			if (Borrow_status == "BORROWED")
			{

				LMS::dbInteract::Update_Book_data_Returned(Book_Id);

				LMS::dbInteract::Updata_Borrow_history_data(Order_id);

				int fine = fine_func::calculate_fine(Order_id, Member_ID, Profession);

				LMS::dbInteract::Update_Borrow_history_fine(Order_id, fine);

				LMS::dbInteract::Update_Member_data_Returned(Member_ID);

				LMS::dbInteract::Message_Return_Successfully(Order_id, Book_Id, Member_ID);

			}

			else if (Borrow_status == "RETURNED")
			{
				MessageBox::Show("Book with given Order Id is already returned.");
			}

			else if (Borrow_status == "LOST")
			{
				MessageBox::Show("Book with given Order Id is Lost.");
			}

		}

		else
		{
			MessageBox::Show("Order with given Order Id Not found.");
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
System::Void LMS::ReturnBook::Back_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
