/*Name : K.Gayathri
  Date :  06-jan-2026
  Description: Address Book */
#include "addressbook.h"  //user-defined header file
#include<string.h> //string cpy,strcmp,strlen, strstr
void pull_file_data(struct AddressBook *addressBook ,char * file_name)
{
    FILE *fp = fopen(file_name,"r"); // open file in read mode
    int i =0, res;
    addressBook ->contactCount =0; // reset contact count
    fseek(fp,0,SEEK_END);  // move file pointer to end
    if((res = ftell(fp)) != 0) // get file size
    {
        rewind(fp); // move pointer to start
        while(!feof(fp))  // read until end of file
        {
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);  // read name,phone,email
            i++; // next contact
        }  
    }
    printf("%d\n", res); // print file size
    addressBook->contactCount = i; // update count
}
void add_contact(struct AddressBook *addressBook)
{
     char name[50];
     printf("Enter the name: ");
     scanf(" %[^\n]",name); // read string with spaces
     char phone[15];
     printf("Enter the phone number: ");
     scanf("%s",phone); // read the phone
     int flag =1;
     while(flag) // validate the phone number
     {
        if(mobile_verify(phone)) // check verification
        {
            flag =0;
        }
        else
        {
            printf("Enter the valid mobile number\n");
            scanf("%s",phone);
        }
     }
     char email[50];
     printf("Enter the mail id: ");
     scanf("%s",email);
     flag =1;
     while(flag)  // validate the  email
     {
        if(email_verify(email) == 1) // check verification
        {
            flag = 0;
        }
        else
        {
            printf("Enter the valid email\n");
            scanf("%s",email);
        }
     }
     int i= addressBook->contactCount;
     strcpy(addressBook->contacts[i].name,name);
     strcpy(addressBook->contacts[i].phone,phone);
     strcpy(addressBook->contacts[i].email,email);
     i++;
     addressBook->contactCount++;
}
int mobile_verify(char phone[])
{
    for (int i = 0;i<strlen(phone);i++)
    {
        if((strlen(phone) ==10) && ((phone[0] >'5') && (phone[0] <='9')) && ((phone [i+1] >= '0') && (phone[i+1] <='9'))) // must be 10 digits,start with 6-9 and  digits only.
        {
            return 1; //valid
        }
        else
        {
            return 0; //invalid
        }
    }
}
int email_verify(char email[])
{
    for(int j = 0;j<strlen(email);j++)
    {
        if((email[0] != '@') || (email[0] != ' ') || (email[0] != ' '))
        {
            char str[10] = "@gmail.com";
            char *ptr = strstr(email,str); //substring
            if( ptr )
            {
                if(strcmp(ptr,str) == 0) //match
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
} 
void search_contact(struct AddressBook *addressBook)
{
    int choice;
    
        printf("\n Search Menu\n");
        printf("1.Search by Name\n");
        printf("2.Search by Phone\n");
        printf("3.Search by Email\n");
        printf("4.Exit\n");

        printf("Enter the option: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: // search by name
            char name[50];
            printf("Enter the Name: ");
            scanf(" %[^\n]",name);
            for(int i =0;i<addressBook->contactCount;i++)
            {
                if(strcmp(name,addressBook->contacts[i].name) == 0)
                {
                    addressBook->index_record[addressBook->ir_size]=i;
                    addressBook->ir_size++;
                }
            }
            if(addressBook->ir_size == 0)
            {
                printf("Name not found\n");
            }
            for(int j =0;j<addressBook->ir_size;j++)
            {
                int k = addressBook->index_record[j];
                printf("%d %s,%s,%s\n",j+1,addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
            }
            break;
            case 2: // search by phone
            char phone[15];
            printf("Enter the phone number: ");
            scanf(" %[^\n]",phone);
            int i =0;
            if(mobile_verify(phone))
            {
                for( i =0;i<addressBook->contactCount;i++)
                {
                        if(strcmp(phone,addressBook->contacts[i].phone) == 0)
                        {
                            addressBook->index_record[addressBook->ir_size]=i;
                            printf("%d%s,%s,%s\n",1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                        }
                        
                }
            }
            else
            {
                printf("Enter Valid number: ");
                scanf("%s",phone);
            }
            break;

            case 3: // search by email
            char email[50];
            printf("Enter the email ID: ");
            scanf(" %[^\n]",email);
            int k=0;
            if(email_verify(email))
            {
                for(k =0;k<addressBook->contactCount;k++)
                {
                    if(strcmp(email,addressBook->contacts[k].email) == 0)
                    {
                        addressBook->index_record[addressBook->ir_size]=k;
                        printf("%d %s,%s,%s\n",1,addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
                    }
        
                }
            }
            else
            {
                printf("Enter the valid email\n");
                scanf("%s",email);
            }
            break;
            
            case 4:
            printf("Exiting...\n");
            push_data_to_file(addressBook ,"database.csv");
            break;
            default:
            printf("Invalid choice. Please try again.\n");
        }

}
void edit_contact(struct AddressBook *addressBook)
{
    search_contact(addressBook);

    if (addressBook->ir_size == 0)
    {
        printf("No contact to edit\n");
        return;
    }

    int sno;
    printf("Enter s.no to edit: ");
    scanf("%d", &sno);
    if (sno < 1 || sno > addressBook->ir_size)
    {
        printf("Invalid number\n");
        return;
    }
    int index = addressBook->index_record[sno - 1];
    int choice;
    do
    {
        printf("\n Edit Menu\n");
        printf("1.Edit Name\n");
        printf("2.Edit Phone\n");
        printf("3.Edit Email\n");
        printf("4.Exit\n");

        printf("Enter the option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char name[50];
            printf("Enter the Name: ");
            scanf(" %[^\n]", name);
            strcpy(addressBook->contacts[index].name, name);

            printf("%s,%s,%s\n",addressBook->contacts[index].name,addressBook->contacts[index].phone,addressBook->contacts[index].email);
            printf("Name updated success\n");
            break;
        }

        case 2:
        {
            char phone[15];
            printf("Enter the phone number: ");
            scanf(" %s", phone);
            if (mobile_verify(phone))
            {
                strcpy(addressBook->contacts[index].phone, phone);
                printf("Phone updated success\n");
            }
            else
            {
                printf("Invalid phone number\n");
            }
            break;
        }

        case 3:
        {
            char email[50];
            printf("Enter the email ID: ");
            scanf(" %[^\n]", email);
            if (email_verify(email))
            {
                strcpy(addressBook->contacts[index].email, email);
                printf("Email updated success\n");
            }
            else
            {
                printf("Invalid email\n");
            }
            break;
        }

        case 4:
            printf("Exiting edit...\n");
            push_data_to_file(addressBook, "database.csv");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);
}


void delete_contact(struct AddressBook *addressBook)
{
    int sno;

    if (addressBook->contactCount == 0)
    {
        printf("No contacts to delete\n");
        return;
    }

    search_contact(addressBook);

    printf("Enter S.No to delete: ");
    scanf("%d", &sno);

    if (sno < 1 || sno > addressBook->contactCount)
    {
        printf("Invalid S.No\n");
        return;
    }

    for (int i = sno - 1; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    push_data_to_file(addressBook, "database.csv");

    printf("Contact deleted success\n");
}

void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf("No Data available\n");
    }
    else
    {
        for (int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s,",addressBook->contacts[i].name);
            printf("%s,",addressBook->contacts[i].phone);
            printf("%s\n",addressBook->contacts[i].email);
        }
    }

}
void push_data_to_file(struct AddressBook *addressBook, char *file_name)
{
    FILE *fp =fopen(file_name,"w"); // open file in the write mode
    
    
    for (int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,",addressBook->contacts[i].name);
        fprintf(fp,"%s,",addressBook->contacts[i].phone);
        fprintf(fp,"%s\n",addressBook->contacts[i].email);
    }
    fclose(fp); // close file
}
