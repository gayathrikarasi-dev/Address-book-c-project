#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <stdio.h>
/* ---------- data structures ---------- */
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
    int index_record[100];
    int ir_size;
};
/* ---------- File functions ---------- */
void pull_file_data(struct AddressBook *addressBook, char *file);
void push_data_to_file(struct AddressBook *addressBook, char *file);

/* ---------AddressBook operations ---------- */
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);

/* ---------- Validation--------- */
int mobile_verify(char *phone);
int email_verify(char *email);
#endif
