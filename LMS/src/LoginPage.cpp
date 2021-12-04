#include "pch.h"
#include "LoginPage.h"
#include "HomePage.h"
//#include "login_to_librarian_db.h"
//#include "connection_sql_func.h"
#include "written_functions/login_to_librarian_db.h"
#include "written_functions/connection_sql_func.h"
namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	LoginPage::LoginPage(void)
	{
		InitializeComponent();
	}

	LoginPage::~LoginPage()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// Button OnClick To Authenticate user details and logging in
	/// </summary>
	System::Void LoginPage::LoginButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (connection_to_librarian_db::is_librarian(this->username_txt->Text, this->password_txt->Text) == true)
		{
			MessageBox::Show("Username and password is correct");

			LMS::HomePage^ f2 = gcnew LMS::HomePage(this->username_txt->Text, true);
			this->Hide();
			if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->username_txt->Text = "";
				this->password_txt->Text = "";
				this->Show();
			}
		}
		else
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			/*MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from library_system_db.user_pass WHERE \
				member_id='" + this->username_txt->Text + "' and user_password = '" + this->password_txt->Text + "' ;", conDataBase);*/
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from library_system_db.user_pass WHERE \
				member_id='" + this->username_txt->Text + "' and user_password = '" + sql_connection_func::password_hasher(this->username_txt->Text, this->password_txt->Text) + "' ;", conDataBase);

			MySqlDataReader^ myReader;
			try {
				conDataBase->Open();
				myReader = cmdDataBase->ExecuteReader();
				int count = 0;
				while (myReader->Read())
				{
					count += 1;
				}
				if (count == 1)
				{
					MessageBox::Show("Username and password is correct");

					LMS::HomePage^ f2 = gcnew LMS::HomePage(this->username_txt->Text, false);
					this->Hide();
					if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{
						this->username_txt->Text = "";
						this->password_txt->Text = "";
						this->Show();

					}
				}
				else if (count == 0)
					MessageBox::Show("Username and password is incorrect ...Please try again");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays TextBoxes for user input
	/// </summary>
	System::Void LoginPage::LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;

		sql_connection_func::InitializeConstring();
	}
}

