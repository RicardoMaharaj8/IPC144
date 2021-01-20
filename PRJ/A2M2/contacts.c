#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name *name) {
    char c, nl;
    printf("Please enter the contact's first name: ");
    fgets(name->firstName, 31, stdin);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's middle initial(s): ");
        fgets(name->middleInitial, 7, stdin);
    }

    printf("Please enter the contact's last name: ");
    fgets(name->lastName, 36, stdin);
}

void getAddress(struct Address *address) {
    char c, nl;
    printf("Please enter the contact's street number: ");
    scanf("%u%c", &address->streetNumber, &nl);

    printf("Please enter the contact's street name: ");
    fgets(address->street, 41, stdin);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's apartment number: ");
        scanf("%u%c", &address->apartmentNumber, &nl);
    }

    printf("Please enter the contact's postal code: ");
    fgets(address->postalCode, 8, stdin);

    printf("Please enter the contact's city: ");
    fgets(address->city, 41, stdin);
}

void getNumbers(struct Numbers *numbers) {
    char c, nl;
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's cell phone number: ");
        scanf("%s%c", &numbers->cell, &nl);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's home phone number: ");
        scanf("%s%c", &numbers->home, &nl);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's business phone number: ");
        scanf("%s%c", &numbers->business, &nl);
    }
}

void getContact(struct Contact *contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
