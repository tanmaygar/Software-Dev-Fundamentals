#include "pch.h"
#include "borrow_history_page.h"

///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of history of Book Borrowing
///@see InitializeComponent(), filling_datagrid::fill_datagrid_borrow_history()
LMS::borrow_history_page::borrow_history_page(void)
{
	InitializeComponent();
	LMS::dbInteract::fill_datagrid_borrow_history(borrow_history_dataGridView, is_librarian, transfer_id);
}

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of history of Book Borrowing
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent(), filling_datagrid::fill_datagrid_borrow_history()
LMS::borrow_history_page::borrow_history_page(String^ input_transfer_id, bool is_librarian_input)
{
	transfer_id = input_transfer_id;
	is_librarian = is_librarian_input;
	InitializeComponent();
	LMS::dbInteract::fill_datagrid_borrow_history(borrow_history_dataGridView, is_librarian, transfer_id);
}

LMS::borrow_history_page::~borrow_history_page()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::borrow_history_page::back_button_borrow_his_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}



/// <summary>
/// It loads the Form in full screen mode
/// </summary>
System::Void LMS::borrow_history_page::borrow_history_page_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->list_detail_search_order->SelectedIndex = 0;
}

/// <summary>
/// Button OnClick function to Open Profile of Book Borrowed and Book Borrower along with their details
/// </summary>
System::Void LMS::borrow_history_page::borrow_history_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{

		//=======================================================
		//This section converts the ID from the second column to String form to open profile
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->borrow_history_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================

		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Order ID along with it
		LMS::profile_order^ profile_order_f = gcnew LMS::profile_order(str);
		this->Hide();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_order_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			LMS::dbInteract::fill_datagrid_borrow_history(borrow_history_dataGridView, is_librarian, transfer_id);
		}

	}
}

/// <summary>
/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
/// </summary>
/// @see filling_datagrid::fill_datagrid_borrow_history_filtered()
System::Void LMS::borrow_history_page::search_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Converting the Item in the list chosen to String with suitable keyword to send to the function for filtering the result
	String^ str_list_detail_search_order;
	if (this->list_detail_search_order->Text == "Order ID")
	{
		str_list_detail_search_order = "order_id";
	}
	if (String::Equals(this->list_detail_search_order->Text, "Member ID"))
	{
		str_list_detail_search_order = "member_id";
	}
	if (String::Equals(this->list_detail_search_order->Text, "Book ID"))
	{
		str_list_detail_search_order = "book_id";
	}

	//Calls the filtering function to fill the datagrid with required search results
	LMS::dbInteract::fill_datagrid_borrow_history_filtered(str_list_detail_search_order, this->search_bar->Text, borrow_history_dataGridView, is_librarian, transfer_id);
}

/// <summary>
/// Clear Search Results function and present original default data.
/// </summary>
/// @see search_button_Click()
System::Void LMS::borrow_history_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Clears the text in the search bar and calls the search button function to display all the data
	this->search_bar->Text = "";
	search_button_Click(sender, e);
}

/// <summary>
/// Exit Button Function to Exit the application from the current Form
/// </summary>
System::Void LMS::borrow_history_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}