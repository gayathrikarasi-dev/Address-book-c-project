/*Name : K.Gayathri
  Date :  06-jan-2026
  Description: Address Book */
#include "addressbook.h"
int main() 
{
    int choice;
    struct AddressBook addressBook;
	pull_file_data(&addressBook,"database.csv");
    addressBook.ir_size = 0;
    do 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);

	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook); // Add contact
		break;
	    case 2:
		search_contact(&addressBook);  // Search contact
		break;
	    case 3:
		edit_contact(&addressBook);    // Edit contact

		break;
	    case 4:
		delete_contact(&addressBook); // Delete contact
		break;
	    case 5:
		list_contacts(&addressBook); // List all contacts
		break;
	    case 6:
		printf("Saving and Exiting...\n");  // Save data to file
		push_data_to_file(&addressBook, "database.csv");
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);

    return 0;
}
