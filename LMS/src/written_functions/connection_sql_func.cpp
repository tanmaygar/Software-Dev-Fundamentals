#include "pch.h"
#include "fine_function.h"
#include "connection_sql_func.h"

///	SQL function definitions to connect to database and to hash password

namespace sql_connection_func {

	bool is_xml_file_exist()
	{

		bool return_val = false;
		String^ fileName = "LMS.xml";
		//Tries to find the file if any error then it throws exception
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			return_val = true;
		}
		catch (Exception^ e)
		{
			return_val = false;
		}
		return return_val;
	}

	void Global::create_xml(String^ username_in, String^ password_in)
	{
		//Pointer to Encryption Class
		my_encdec^ encdec;
		XmlTextWriter^ write_xml_file;
		String^ txtFilename = "LMS.xml";

		//Writing into xml File
		write_xml_file = gcnew XmlTextWriter(txtFilename, System::Text::Encoding::UTF8);
		write_xml_file->WriteStartDocument(true);
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteStartElement("Data");
		write_xml_file->WriteWhitespace("\n");

		write_xml_file->WriteElementString("Info23", encdec->enc_str(username_in, my_encdec::MyEnum::USER));
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteStartElement("Redifine10");
		write_xml_file->WriteString(encdec->enc_str(password_in, my_encdec::MyEnum::PASS));
		write_xml_file->WriteEndElement();
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteElementString("Creds8", encdec->enc_num(username_in, my_encdec::MyEnum::USER).ToString());
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteElementString("NoReturn3", encdec->enc_num(password_in, my_encdec::MyEnum::PASS).ToString());
		write_xml_file->WriteWhitespace("\n");
		write_xml_file->WriteEndElement();
		write_xml_file->WriteEndDocument();
		write_xml_file->Close();

		/*MessageBox::Show("File Generated",
			"XML Generation Results",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);*/
	}

	String^ Global::read_xml_return_constring()
	{
		//Pointer to Encryption Class
		my_encdec^ encdec;
		String^ filename = "LMS.xml";
		String^ usrname;
		String^ passwor;
		XmlTextReader^ xreader = gcnew XmlTextReader(filename);
		int count = 0;
		int num_user, num_pass;

		//Read from XML File
		while (xreader->Read())
		{
			switch (xreader->NodeType)
			{
			case XmlNodeType::Text:
				if (count == 3)
				{
					num_pass = Int32::Parse(encdec->dec_num(xreader->Value, my_encdec::MyEnum::PASS));
					count++;
				}
				if (count == 2)
				{
					num_user = Int32::Parse(encdec->dec_num(xreader->Value, my_encdec::MyEnum::USER));
					count++;
				}
				if (count == 1)
				{
					passwor = xreader->Value;
					count++;
				}
				if (count == 0)
				{
					usrname = xreader->Value;
					count++;
				}
			}

		}
		Global::username = encdec->dec_str(usrname, num_user);
		Global::password = encdec->dec_str(passwor, num_pass);
		xreader->Close();

		//Return Constring
		String^ constring = L"datasource=localhost;port=3306;username=" + Global::username + "; password =" + Global::password + "; SslMode = Required";

		return constring;
	}


	//
	//	FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	//
	String^ sql_user_pass_string()
	{
		////String^ constring = L"datasource=localhost;port=3306;username=root;password=lovebcmm**,02";
		////String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234; SslMode=Required";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL; SslMode=Required";
		//return constring;
		return Global::constring;
	}


	/// <summary>
	/// This function hashes the password of the user and also salts it with ID of the user before being hashed
	/// </summary>
	/// The function converts the salted string into byte array then it applies MD5 Hashing method and then converts the byte array back into String
	String^ password_hasher(String^ input_id, String^ input_pass)
	{
		//Salting the required password string with username
		String^ final_password_for_hash = input_pass + input_id;

		//Converting the String into Byte Array Form
		array<Byte>^ byte_array_password = System::Text::Encoding::ASCII->GetBytes(final_password_for_hash);

		//Hashing the byte Array using MD5 
		System::Security::Cryptography::MD5CryptoServiceProvider^ md5_hash_gen = gcnew System::Security::Cryptography::MD5CryptoServiceProvider();
		array<Byte>^ byte_array_hash = md5_hash_gen->ComputeHash(byte_array_password);

		//Convert the Byte Array into String
		return BitConverter::ToString(byte_array_hash);

	}


	void InitializeConstring() //initializeConstring()
	{
		if (!is_xml_file_exist())
		{
			String^ UserAnswer = Microsoft::VisualBasic::Interaction::InputBox("Enter Username ", "MySql connection user credentials", "", 12, 50);
			String^ passAnswer = Microsoft::VisualBasic::Interaction::InputBox("Enter Password : ", "MySql connection user credentials", "", 12, 50);

			Global::create_xml(UserAnswer, passAnswer);
		}

		Global::constring = Global::read_xml_return_constring();
	}


	String^ my_encdec::enc_str(String^ str, MyEnum num)
	{
		//switch case to go through each Enum value
		switch (num)
		{
		case sql_connection_func::my_encdec::MyEnum::USER:
			str = str + "_server_usr";
			break;
		case sql_connection_func::my_encdec::MyEnum::PASS:
			str = str + "$45@";
			break;
		default:
			break;
		}

		//Return String after encryption
		return str;
	}

	int my_encdec::enc_num(String^ str, MyEnum num)
	{
		//switch case to go through each Enum value
		int new_num = str->Length;
		switch (num)
		{
		case sql_connection_func::my_encdec::MyEnum::USER:
			new_num = new_num + 8;
			break;
		case sql_connection_func::my_encdec::MyEnum::PASS:
			new_num = new_num + 12;
			break;
		default:
			break;
		}

		//Return new Number
		return new_num;

	}

	String^ my_encdec::dec_num(String^ str, MyEnum num)
	{
		//switch case to go through each Enum value
		int new_num = Int32::Parse(str);
		switch (num)
		{
		case sql_connection_func::my_encdec::MyEnum::USER:
			new_num = new_num - 8;
			break;
		case sql_connection_func::my_encdec::MyEnum::PASS:
			new_num = new_num - 12;
			break;
		default:
			break;
		}

		//Return Decrypted number in string form
		return new_num.ToString();
	}

	String^ my_encdec::dec_str(String^ str, int length)
	{
		//Removes unnecessary part of string to give original string
		String^ new_str = str;
		new_str = new_str->Remove(length, str->Length - length);


		//MessageBox::Show("Decrypted string : " + new_str);

		//Returns Decrypted string
		return new_str;
	}
}


