#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

void clearKeyboard(void) {
    while (getchar() != '\n') {
    }
}

void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

int getInt(void) {
    char nl = 'x';
    int value = 0;
    while (nl != '\n') {
        scanf("%d%c", &value, &nl);
        if (nl != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

int getIntInRange(int min, int max) {
    int a = getInt();
    while (a > max || a < min) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        a = getInt();
    }
    return a;
}

int yes(void) {
    char nl = 'x';
    char choice = 'x';
    while (nl != '\n') {
        scanf("%c%c", &choice, &nl);
        if (nl != '\n') {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        } else if (choice == 'y' || choice == 'Y') {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

int menu(void) {
    printf("Contact Management System");
    printf("\n-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    int choice = getIntInRange(0, 6);
    return choice;
}

void contactManagerSystem(void) {
    struct Contact con[MAXCONTACTS] =
            {{{"Rick",   {'\0'}, "Grimes"},   {11, "Trailer Park",  0, "A7A 2J2", "King City"},    {"4161112222", "4162223333", "4163334444"}},
             {{"Maggie", "R.",   "Greene"},   {55, "Hightop House", 0, "A9A 3K3", "Bolton"},       {"9051112222", "9052223333", "9053334444"}},
             {{"Morgan", "A.",   "Jones"},    {77, "Cottage Lane",  0, "C7C 9Q9", "Peterborough"}, {"7051112222", "7052223333", "7053334444"}},
             {{"Sasha",  {'\0'}, "Williams"}, {55, "Hightop House", 0, "A9A 3K3", "Bolton"},       {"9052223333", "9052223333", "9054445555"}}};

    int cms = 1;
    int a = 0;
    int choice = 0;
    while (cms != 0) {
        a = menu();
        switch (a) {
            case 1:
                displayContacts(con, MAXCONTACTS);
                pause();
                printf("\n");
                break;
            case 2:
                addContact(con, MAXCONTACTS);
                pause();
                printf("\n");
                break;
            case 3:
                updateContact(con, MAXCONTACTS);
                pause();
                printf("\n");
                break;
            case 4:
                deleteContact(con, MAXCONTACTS);
                pause();
                printf("\n");
                break;
            case 5:
                searchContacts(con, MAXCONTACTS);
                pause();
                printf("\n");
                break;
            case 6:
                printf("\n<<< Feature to sort is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 0:
                printf("\nExit the program? (Y)es/(N)o: ");
                choice = yes();
                printf("\n");
                if (choice == 1) {
                    printf("Contact Management System: terminated\n");
                    cms = 0;
                }
                break;
            default:
                break;
        }
    }
}

void getTenDigitPhone(char phoneNum[]) {
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10[0-9]s", phoneNum);
        clearKeyboard();

        if (strlen(phoneNum) == 10) {
            needInput = 0;
        } else {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
    int i;
    int comp;
    for (i = 0; i < size; i++) {
        comp = strcmp(contacts[i].numbers.cell, cellNum);
        if (comp == 0) {
            return i;
        }
    }
    return -1;
}

void displayContactHeader(void) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

void displayContact(const struct Contact *contact) {
    if (contact->name.middleInitial[0] != '\0') {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    } else {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home,
           contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0) {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

void displayContacts(const struct Contact contacts[], int size) {
    int i = 0;
    int c = 0;
    printf("\n");
    displayContactHeader();
    while (i < size) {
        if (strlen(contacts[i].numbers.cell) > 0) {
            displayContact(&contacts[i]);
            c++;
        }
        i++;
    }
    displayContactFooter(c);
}

void searchContacts(const struct Contact contacts[], int size) {
    printf("\nEnter the cell number for the contact: ");
    char phoneNum[11];
    getTenDigitPhone(phoneNum);
    int c = 0;
    c = findContactIndex(contacts, size, phoneNum);
    if (c == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\n");
        displayContact(&contacts[c]);
        printf("\n");
    }
}

void addContact(struct Contact contacts[], int size) {
    char phoneNum[11] = {};
    int loc = 0;
    loc = findContactIndex(contacts, size, phoneNum);
    if (loc == -1) {
        printf("\n*** ERROR: The contact list is full! ***\n");
        printf("\n");
    } else {
        printf("\n");
        getContact(&contacts[loc]);
        printf("--- New contact added! ---\n");
        printf("\n");
    }
}

void updateContact(struct Contact contacts[], int size) {
    char findNum[11];
    int loc = 0;
    printf("\n");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(findNum);
    loc = findContactIndex(contacts, size, findNum);
    if (loc > -1) {
        printf("\n");
        printf("Contact found:");
        printf("\n");
        displayContact(&contacts[loc]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        int c = 0;
        c = yes();
        if (c == 1) {
            contacts[loc].name.middleInitial[0] = '\0';
            getName(&contacts[loc].name);
        }
        printf("Do you want to update the address? (y or n): ");
        c = yes();
        if (c == 1) {
            contacts[loc].address.apartmentNumber = 0;
            getAddress(&contacts[loc].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        c = yes();
        if (c == 1) {
            contacts[loc].numbers.home[0] = '\0';
            contacts[loc].numbers.business[0] = '\0';
            getNumbers(&contacts[loc].numbers);
        }
        printf("--- Contact Updated! ---\n");
        printf("\n");
    } else {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
}

void deleteContact(struct Contact contacts[], int size) {
    char phoneNum[11];
    int loc;
    printf("\n");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    loc = findContactIndex(contacts, size, phoneNum);
    if (loc == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    } else {
        printf("\n");
        printf("Contact found:");
        printf("\n");
        displayContact(&contacts[loc]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        int c;
        c = yes();
        if (c == 1) {
            contacts[loc].numbers.cell[0] = '\0';
            contacts[loc].numbers.home[0] = '\0';
            contacts[loc].numbers.business[0] = '\0';
            printf("--- Contact deleted! ---\n\n");
        } else {
            printf("\n");
        }
    }
}

void sortContacts(struct Contact contacts[], int size) {
}
