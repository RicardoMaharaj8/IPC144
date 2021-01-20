#include <stdio.h>
#include "contacts.h"

int main(void) {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
    char c, nl;

    printf("Contact Management System\n");
    printf("-------------------------\n");

    printf("Please enter the contact's first name: ");
    fgets(name.firstName, 31, stdin);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's middle initial(s): ");
        fgets(name.middleInitial, 7, stdin);
    }

    printf("Please enter the contact's last name: ");
    fgets(name.lastName, 36, stdin);

    printf("Please enter the contact's street number: ");
    scanf("%u%c", &address.streetNumber, &nl);

    printf("Please enter the contact's street name: ");
    fgets(address.street, 41, stdin);

    printf("Do you want to enter an apartment number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's apartment number: ");
        scanf("%u%c", &address.apartmentNumber, &nl);
    }

    printf("Please enter the contact's postal code: ");
    fgets(address.postalCode, 8, stdin);

    printf("Please enter the contact's city: ");
    fgets(address.city, 41, stdin);

    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's cell phone number: ");
        scanf("%s%c", numbers.cell, &nl);
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's home phone number: ");
        scanf("%s%c", numbers.home, &nl);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    scanf("%c%c", &c, &nl);
    if (c == 'y') {
        printf("Please enter the contact's business phone number: ");
        scanf("%s%c", numbers.business, &nl);
    }

    printf("\nContact Details\n");
    printf("---------------\n");
    printf("Name Details\n");
    printf("First name: %s", name.firstName);
    printf("Middle initial(s): %s", name.middleInitial);
    printf("Last name: %s", name.lastName);
    printf("\n");
    printf("Address Details\n");
    printf("Street number: %u\n", address.streetNumber);
    printf("Street name: %s", address.street);
    printf("Apartment: %u\n", address.apartmentNumber);
    printf("Postal code: %s\n", address.postalCode);
    printf("City: %s", address.city);
    printf("\n");
    printf("Phone Numbers:\n");
    printf("Cell phone number: %s\n", numbers.cell);
    printf("Home phone number: %s\n", numbers.home);
    printf("Business phone number: %s\n", numbers.business);
    printf("\nStructure test for Name, Address, and Numbers Done!\n");
    return 0;
}
