#pragma once


namespace sql_connection_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::Security::Cryptography;
	using namespace System::Xml;
	using namespace System::IO;

	/// <summary>
	/// Function for setting username password to establish connection to MySQL server
	/// </summary>
	/// <returns>
	/// String for connection to sql database with username and password to database
	/// </returns>
	String^ sql_user_pass_string();

	/// <summary>
	/// Function to implement for the password to be stored in a hashed format
	/// </summary>
	/// <param name="input_id">
	/// String for ID of the user
	/// </param>
	/// <param name="input_pass">
	/// String for Password that needs to be hashed
	/// </param>
	/// <returns>
	/// Hashed String
	/// </returns>
	String^ password_hasher(String^ input_id, String^ input_pass);

	/// <summary>
	/// This Function initializes the connection string used to connect to MySQL Database
	/// </summary>
	void InitializeConstring();

	/// <summary>
	/// Summary for Global class
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	/// This Class stores the connection string, Username, Password of MySQL Database
	public ref class Global
	{
	public:
		/// <summary>
		/// Static String for Connection String
		/// </summary>
		static System::String^ constring;

		/// <summary>
		/// Static String for UserName
		/// </summary>
		static System::String^ username;

		/// <summary>
		/// Static String for Password
		/// </summary>
		static System::String^ password;

	public:

		/// <summary>
		/// Static Function to read LMS.xml which stores Username and Password in simple encrypted form
		/// </summary>
		/// <returns>
		/// Connection String for MySQL Database
		/// </returns>
		static String^ read_xml_return_constring();

		/// <summary>
		/// Static Function to create LMS.xml when User installs the application first time
		/// </summary>
		/// <param name="username_in">
		/// Username of MySQL Database from User
		/// </param>
		/// <param name="password_in">
		/// Password of MySQL Database from User
		/// </param>
		static void create_xml(String^ username_in, String^ password_in);
	};

	/// <summary>
	/// This function checks if LMS.xml file is present in Application Folder or not
	/// </summary>
	/// <returns>
	/// True if file exists else False
	/// </returns>
	bool is_xml_file_exist();
	
	
	/// <summary>
	/// Summary for Global class
	/// </summary>
	/// This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	/// This is a Class which contains all functions related to encryption and decryption
	public ref class my_encdec {
	public:
		/// <summary>
		/// Enum Class for encryption and decryption
		/// </summary>
		enum class MyEnum
		{
			USER, PASS
		};

		/// <summary>
		/// Encrypt String based on the String being for Username or Password
		/// </summary>
		/// <param name="str">
		/// String to be encrypted
		/// </param>
		/// <param name="num">
		/// Enum class to specify whether it is a Username or Password
		/// </param>
		/// <returns>
		/// Encrypted String
		/// </returns>
		String^ enc_str(String^ str, MyEnum num);

		/// <summary>
		/// Encrypts a number which denotes the length of the string based on being Username or Password
		/// </summary>
		/// <param name="str">
		/// String whose length needs to be encrypted
		/// </param>
		/// <param name="num">
		///  Enum class to specify whether it is a Username or Password
		/// </param>
		/// <returns>
		/// encrypted number which is some other number
		/// </returns>
		int enc_num(String^ str, MyEnum num);

		/// <summary>
		///  Decrypts a number which denotes the length of the string based on being Username or Password
		/// </summary>
		/// <param name="str"></param>
		/// <param name="num"></param>
		/// <returns>
		/// Decrypted Number in String Form
		/// </returns>
		String^ dec_num(String^ str, MyEnum num);

		/// <summary>
		/// Decrypt String based on the String being for Username or Password
		/// </summary>
		/// <param name="str">
		///  String to be decrypted
		/// </param>
		/// <param name="length">
		/// Length of the original String
		/// </param>
		/// <returns>
		/// Derypted String
		/// </returns>
		String^ dec_str(String^ str, int length);
	};

}