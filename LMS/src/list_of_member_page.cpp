#include "pch.h"
#include "list_of_member_page.h"

///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Members.
///@see InitializeComponent(), filling_datagrid::fill_datagrid_member()
LMS::list_of_member_page::list_of_member_page(void)
{
	InitializeComponent();
	//sql_connection_func::fill_datagrid_member(list_of_member_dataGridView);
	LMS::dbInteract::fill_datagrid_member(list_of_member_dataGridView);
}

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Members
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent(), filling_datagrid::fill_datagrid_member()
LMS::list_of_member_page::list_of_member_page(String^ input_id_transfer, bool is_librarian_input)
{
	InitializeComponent();
	transfer_id = input_id_transfer;
	is_librarian = is_librarian_input;
	LMS::dbInteract::fill_datagrid_member(list_of_member_dataGridView);
}

LMS::list_of_member_page::~list_of_member_page()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::list_of_member_page::back_button_member_list_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

/// <summary>
/// Button OnClick function to Open Profile of Non-Librarin User with their details
/// </summary>
System::Void LMS::list_of_member_page::list_of_member_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	//if the cell selected is the first cell of the row then it carries out the following process
	if (e->ColumnIndex == 0)
	{
		//=======================================================
		//This section converts the ID from the second column to String form to open profile
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->list_of_member_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		//=======================================================

		MessageBox::Show("Your id is " + str);

		//Constructing profile form by passing the Member ID along with it as well as if the user is librarian or not
		LMS::profile_member^ profile_member_f = gcnew LMS::profile_member(str, is_librarian);
		this->Hide();

		//Hiding the current Form and opening the profile form and waits till the time the user clicks on back button
		if (profile_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//When user clicks the back button in the Profile Form it closes that and then shows this form again and fills loads the form
			this->Show();
			LMS::dbInteract::fill_datagrid_member(list_of_member_dataGridView);
		}

	}
}

/// <summary>
/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
/// </summary>
/// @see filling_datagrid::fill_datagrid_members_filtered()
System::Void LMS::list_of_member_page::search_button_member_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Converting the Item in the list chosen to String with suitable keyword to send to the function for filtering the result
	String^ str_list_detail_search_member;
	if (this->list_detail_search_member->Text == "Name")
	{
		str_list_detail_search_member = "member_name";
	}
	if (String::Equals(this->list_detail_search_member->Text, "ID"))
	{
		str_list_detail_search_member = "member_id";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Phone"))
	{
		str_list_detail_search_member = "member_mobile";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Email"))
	{
		str_list_detail_search_member = "member_email";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Number of books borrowed currently"))
	{
		str_list_detail_search_member = "member_no_book_stat";
	}

	//Calls the filtering function to fill the datagrid with required search results
	LMS::dbInteract::fill_datagrid_members_filtered(str_list_detail_search_member, this->search_bar_member->Text, list_of_member_dataGridView);

}

/// <summary>
/// Clear Search Results function and present original default data.
/// </summary>
/// @see search_button_member_Click()
System::Void LMS::list_of_member_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->search_bar_member->Text = "";
	search_button_member_Click(sender, e);
}

/// <summary>
/// Exit Button Function to Exit the application from the current Form
/// </summary>
System::Void LMS::list_of_member_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

/// <summary>
/// It loads the Form in full screen mode
/// </summary>
System::Void LMS::list_of_member_page::list_of_member_page_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->list_detail_search_member->SelectedIndex = 1;
}

