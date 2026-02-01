# Address Book Application using C

## Overview
Address Book is a console-based application developed in C that allows users to store, manage, and maintain contact information efficiently. The application supports adding, searching, editing, deleting, and listing contacts with persistent storage using a CSV file.

This project demonstrates strong fundamentals of C programming, including file handling, structures, pointers, and menu-driven program design.

---

## Features
- Add new contacts
- Search contacts by name, phone number, or email
- Edit existing contact details
- Delete contacts
- View all saved contacts
- Persistent storage using a CSV file (`database.csv`)

---

## Technologies Used
- C Programming
- File Handling
- Structures and Pointers
- CSV File Processing
- GCC Compiler

---

## How to Run

### Clone the repository
```bash
Compile the program
gcc src/*.c -I include -o addressbook

Run the program
# Linux / Mac
./addressbook

# Windows
addressbook.exe


After running, follow the on-screen menu to add, edit, search, delete, or list contacts.

Usage

Choose options from the menu to perform operations

Enter contact details as prompted

Data is automatically saved to the CSV file

Notes

The program reads and writes data to database.csv.

Ensure database.csv is present in the same directory as the executable.

You can manually edit the CSV file to add or modify sample contacts.

Changes made through the application are saved permanently.

Skills Learned

C programming with real-world file handling

Working with structures and pointers

Menu-driven application design

CSV-based persistent data storage

Debugging and input validation

Dependencies

GCC or any standard C compiler

Screenshots
Add Contact

Add Contact

Edit Contact

Edit Contact

Search Contact

Search Contact

List Contacts

List Contacts

Delete Contact

Delete Contact

Exit

Select the Exit option from the menu to safely close the application.
git clone https://github.com/gayathrikarasi-dev/address-book-c.git
cd address-book-c
