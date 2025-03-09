#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct Contact{
    char name[30];
    char address[256];
    int phoneNumber;
    char email[50];
};
struct Contact contacts[100];
int contactCount = 0;

void PrintHelperMessage(){

    printf("0 - Quit\n1 - List Contacts\n2 - Add Contact\n3 - Remove Contact\n");

}
int GetAction(){
    int action;
    scanf("%d", &action);
    getchar();
    return action;
}
//Function to clear the screen
void ClearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void ListAllContacts(){
    ClearScreen();
    if(contactCount == 0){
        printf("Please create your first contact.\n");
    }
    else{
        for(int i = 0; i < contactCount; i++){
            printf("%d. %s", i, contacts[i].name);
        }
    }
    PrintHelperMessage();
}
int AddContact(char name[], int phoneNumber, char address[], char email[]){
    
    strcpy(contacts[contactCount].name, name);
    contacts[contactCount].phoneNumber = phoneNumber;
    strcpy(contacts[contactCount].address, address);
    strcpy(contacts[contactCount].email, email);
    contactCount = contactCount + 1;
    //returning 0 means the contact was created without error.
    //returning -1 means there was an error
    return 0;
}
int main(){
    ClearScreen();
    printf("Welcome to the totally awesome contact book or phone book thats totally not outdated at all and will totally still be a revolutionary invention if it came out in 2025.\n\n");
    PrintHelperMessage();
    //0 - Quit
    //1 - List Contacts
    //2 - Add Contacts
    //3 - Remove Contact
    bool running = true;
    while(running){
        int action = GetAction();

        if(action == 0){
            running = false;
            ClearScreen();
            printf("Goodbye.\n");
        }
        else if(action == 1){
            ListAllContacts();
        }
        else if(action == 2){
            //List contact
            //Name, number, address, email
            char name[30];
            int phoneNumber;
            char address[256];
            char email[50];
            ClearScreen();
            printf("Enter the contacts name: ");
            fgets(name, 30, stdin);
            printf("\nEnter the contacts phone number: ");
            scanf("%d", &phoneNumber);
            getchar();
            printf("\nEnter the contacts address: ");
            fgets(address, 256, stdin);
            printf("\nEnter the contacts email: ");
            fgets(email, 50, stdin);
            ClearScreen();
            AddContact(name, phoneNumber, address, email);
            printf("Contact Added Successfully.\n");
            PrintHelperMessage();
        }
        else if(action == 3){

        }
        else{
            ClearScreen();
            printf("That ain't no command weirdo.\n");
            PrintHelperMessage();
        }
    }
    return 0;
}
