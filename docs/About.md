# Library Management System
## About

This project was made as part of the course CS1023 - Software Development Fundamentals, at the Indian Institute of Technology Hyderabad, taken by our Course Instructor - [Dr. Saurabh Joshi](https://github.com/sbjoshi)

- The Project has been built using Microsoft's Visual Studio Windows Forms Desktop Application in C++
- It uses Graphical User Interface class library provided by Microsoft .NET
- Along with this, MySQL Community Version is also being used for providing a Database Management System to help store information associated with Members, Librarians, Books, and History of Borrowing

## Design and Architecture
The Application is built on a 3 Tier Architecture in collaboration with .NET library which is dynamically linked with source files

The 3 Tiers are:
- Data
- Application
- Presentation

### Data Tier
- In the _Data Tier_, all the **Raw Data** is stored and managed in the MySQL Database Management System
- It processes all the queries sent to it by the _Application Tier_ to modify and return any field from the database
- It communicates with the _Application Tier_ and there is no direct communication with the _Presentation Tier_
- The _Data Tier_ is written completely in C++ and MySQL

### Application Tier
- In the _Application Tier_, the **entire logic** of **operations**, **methods**, and **functions** are written
- It communicates with the _Presentation Tier_ by **taking input** from the User, then it **processes** it and converts it into a suitable type, and sends it to the _Data Tier_ 
- It sends requests to the _Data Tier_ to **add**, **delete** or **modify** the data present in the _Data Tier_ as well as it may also have its own methods to do the same
- It may also **modify** the way the _Presentation Tier_ appears to the User by adjusting the Graphical User Interface (GUI) Elements
- The _Application Tier_ is written completely in C++ as well as using Windows Forms Library to access GUI Elements and MySQL Connector to send SQL Queries

### Presentation Tier
- In the _Presentation Tier_, all the **GUI Elements** are presented
- It **interacts** with the User to take required Input and displays Information to the User
- It **communicates** with the _Data Tier_ to send the required requests and queries that are needed to **add**, **remove**, or **modify** the data to be presented and stored
- The _Presentation Tier_ is written in C++/CLI and Windows Forms Library

## Developing the Application
- The application was developed by thinking _UI / Front End_ and making application as _interactive_ as possible, so the entire development process was more **feature-driven** with every single step being manually **tested** for different situations and cases
- The entire Application is an event-driven application, that is, the flow of the program depends on how the User interacts with the Program such as when and where the user clicks the buttons and what text is being entered in textboxes
- We have tried to implement the Single Responsibility Principle for each element and have separated _UI elements_ with _Non-UI elements_ so that each function and method can be **tested** separately
- All the Form files (_.h_ and _.cpp_) are inside the "**src**" folder and all the other files in which the methods and functions are written are in another folder "**written functions**" which include _.h_ and _.cpp_ files
- Each _.h_ and _.cpp_ file has comments to make the program very readable, as well as there, are _Doxygen style comments_ in each file so that any developer can easily create documentation from source files
- We have also implemented the principles of **MVP** which is a Model-View-Presenter type of Design Pattern that essentially separates all the business logic from the GUI part
- We have also used _Test Framework_ provided by NUnit to help test the functions and forms. The **Testing** project is a separate project inside the Main Solution
- All functions that need to be tested should be a part of **Testing** Project and after successful testing the files should be copied to **LMS** Project

## Schema and Database
- There is 1 schema:  
```sql
 library_system_db
 ```
- There 5 tables inside this schema:
```sql
member_data
user_pass
book_data
borrow_history
library_user_pass
```

For relationship diagram and more details about the table: [Database Description](https://github.com/IITH-CS1023/cs1023-sdf-project-team-4/blob/main/docs/Developer-Manual.md#database-description)
