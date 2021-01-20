#include <stdio.h>
#include "contacts.h"

void clear(void) {
    while (getchar() != '\n') {
    }
}

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

int main(void) {
    struct Contact contact = {{0}};

    printf("Contact Management System\n");
    printf("=========================\n");

    getName(&contact.name);

    getAddress(&contact.address);

    getNumbers(&contact.number);

    printf("\nContact Details\n");
    printf("===============\n");
    printf("Name Details\n");
    printf("------------\n");
    printf("First name: %s", contact.name.firstName);
    printf("Middle initial(s): %s", contact.name.middleInitial);
    printf("Last name: %s", contact.name.lastName);
    printf("\n");
    printf("Address Details\n");
    printf("---------------\n");
    printf("Street number: %u\n", contact.address.streetNumber);
    printf("Street name: %s", contact.address.street);
    printf("Apartment: %u\n", contact.address.apartmentNumber);
    printf("Postal code: %s\n", contact.address.postalCode);
    printf("City: %s\n", contact.address.city);
    printf("Phone Numbers\n");
    printf("-------------\n");
    printf("Cell phone number: %s\n", contact.number.cell);
    printf("Home phone number: %s\n", contact.number.home);
    printf("Business phone number: %s\n", contact.number.business);
    printf("\nStructure test for Contact using functions done!\n");
    return 0;
}
