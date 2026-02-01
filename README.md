# Address Book Application (C)

## Overview
A console-based Address Book application written in C that allows users to store and manage contact information with persistent storage using a CSV file.

## Features
- Add new contacts
- Search contacts by name, phone number, or email
- Edit existing contact details
- Delete contacts
- View all saved contacts
- Uses a CSV file (`database.csv`) for permanent storage

## How to Run

### Clone the repository
```bash
git clone https://github.com/gayathrikarasi-dev/address-book-c.git
cd address-book-c
Compile the program
gcc src/*.c -I include -o addressbook

Run the program
# Linux / Mac
./addressbook

# Windows
addressbook.exe
## Dependencies
- GCC or any standard C compiler

## Notes
- The program reads and writes data to `database.csv`.
- Ensure `database.csv` is in the same directory as the executable.
- You can manually edit the CSV file to add more contacts.

## Screenshots

### Add Contact
Add Contact

### Edit Contact
Edit Contact

### Search Contact
Search Contact

### List Contacts
List Contacts

### Delete Contact
Delete Contact

## Exit
Select the **Exit** option from the menu to close the application.
