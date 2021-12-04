#include "pch.h"
#include "list_of_books_page.h"

///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Books
///@see InitializeComponent(), filling_datagrid::fill_datagrid_book()
LMS::list_of_books_page::list_of_books_page(void)
{
	InitializeComponent();
	LMS::dbInteract::fill_datagrid_book(list_of_books_dataGridView);
}

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Books
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent(), filling_datagrid::fill_datagrid_book()
LMS::list_of_books_page::list_of_books_page(String^ input_transfer_id, bool is_librarian_input)
{
	transfer_id = input_transfer_id;
	is_librarian = is_librarian_input;
	InitializeComponent();
	LMS::dbInteract::fill_datagrid_book(list_of_books_dataGridView);
}

LMS::list_of_books_page::~list_of_books_page()
{
	if (components)
	{
		delete components;
	}
}


/// <summary>
/// It loads the Form in full screen mode
/// </summary>
System::Void LMS::list_of_books_page::list_of_books_page_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->list_detail_search_book->SelectedIndex = 1;
}

/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
System::Void LMS::list_of_books_page::back_button_book_list_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

/// <summary>
/// Exit Button Function to Exit the application from the current Form
/// </summary>
System::Void LMS::list_of_books_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

/// <summary>
/// Button OnClick function to Open Profile of Books with their details
/// </summary>
System::Void LMS::list_of_books_page::list_of_books_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{
		//=======================================================
		//This section converts the ID from the second column to String form to open profile
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->list_of_books_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================
		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Book ID along with it as well as if the user is librarian or not
		LMS::profile_book^ profile_book_f = gcnew LMS::profile_book(str, is_librarian);
		this->Hide();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			LMS::dbInteract::fill_datagrid_book(list_of_books_dataGridView);
		}

	}

}

/// <summary>
/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
/// </summary>
/// @see filling_datagrid::fill_datagrid_books_filtered()
System::Void LMS::list_of_books_page::search_button_book_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Converting the Item in the list chosen to String with suitable keyword to send to the function for filtering the result
	String^ str_list_detail_search_book;
	if (this->list_detail_search_book->Text == "Title")
	{
		str_list_detail_search_book = "book_name";
	}
	if (String::Equals(this->list_detail_search_book->Text, "ID"))
	{
		str_list_detail_search_book = "book_id";
	}
	if (String::Equals(this->list_detail_search_book->Text, "Author"))
	{
		str_list_detail_search_book = "book_author";
	}
	if (String::Equals(this->list_detail_search_book->Text, "Edition No."))
	{
		str_list_detail_search_book = "book_edition_no";
	}

	//Calls the filtering function to fill the datagrid with required search results
	LMS::dbInteract::fill_datagrid_books_filtered(str_list_detail_search_book, this->search_bar_book->Text, list_of_books_dataGridView);

}

/// <summary>
/// Clear Search Results function and present original default data.
/// </summary>
/// @see search_button_book_Click()
System::Void LMS::list_of_books_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->search_bar_book->Text = "";
	search_button_book_Click(sender, e);
}