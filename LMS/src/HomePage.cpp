#include "pch.h"
#include "HomePage.h"

namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	HomePage::HomePage(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	HomePage::HomePage(String^ input_transfer_id, bool is_librarian_input)
	{
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
		InitializeComponent();
	}

	HomePage::~HomePage()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// Button OnClick To View BorrowBook page
	/// </summary>
	System::Void HomePage::borrowbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::BorrowBook^ borrowbook_f = gcnew LMS::BorrowBook();
		this->Hide();
		if (borrowbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view Books List
	/// </summary>
	System::Void HomePage::booklist_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::list_of_books_page^ list_of_books_f = gcnew LMS::list_of_books_page(transfer_id, is_librarian);
		this->Hide();
		if (list_of_books_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view Borrow History page
	/// </summary>
	System::Void HomePage::borrowhistory_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::borrow_history_page^ borrow_history_page_f = gcnew LMS::borrow_history_page(transfer_id, is_librarian);
		this->Hide();
		if (borrow_history_page_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view Return Book page
	/// </summary>
	System::Void HomePage::returnbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::ReturnBook^ returnbook_f = gcnew LMS::ReturnBook();
		this->Hide();
		if (returnbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view Member List
	/// </summary>
	System::Void HomePage::member_list_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		LMS::list_of_member_page^ list_of_member_f = gcnew LMS::list_of_member_page(transfer_id, is_librarian);
		this->Hide();
		if (list_of_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view AddBook page
	/// </summary>
	System::Void HomePage::addbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::AddBook^ addbook_f = gcnew LMS::AddBook(transfer_id, is_librarian);
		this->Hide();
		if (addbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view RegisterMember page
	/// </summary>
	System::Void HomePage::register_member_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::RegisterMember^ RegisterMember_f = gcnew LMS::RegisterMember(transfer_id, is_librarian);
		this->Hide();
		if (RegisterMember_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To RegisterLibrarian page
	/// </summary>
	System::Void HomePage::registerlibrarian_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::RegisterLibrarian^ registerlibrarian_f = gcnew LMS::RegisterLibrarian(transfer_id, is_librarian);
		this->Hide();
		if (registerlibrarian_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To view Member Profile page
	/// </summary>
	System::Void HomePage::view_profile_member_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		LMS::profile_member^ profile_member_f = gcnew LMS::profile_member(transfer_id, is_librarian);
		this->Hide();
		if (profile_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}

	/// <summary>
	/// Button OnClick To Logout and view Sign In page
	/// </summary>
	System::Void HomePage::logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays User specific Buttons to Navigate to other Pages
	/// </summary>
	System::Void HomePage::HomePage_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
		if (is_librarian == false)
		{
			this->borrowbook_btn->Visible = false;
			this->member_list_btn->Visible = false;
			this->returnbook_btn->Visible = false;
			this->addbook_btn->Visible = false;
			this->registerlibrarian_btn->Visible = false;
			this->register_member_btn->Visible = false;
			this->view_profile_member_btn->Visible = true;
			
		}
		
	}

	/// <summary>
	/// Function to Exit Application
	/// </summary>
	System::Void HomePage::exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
}