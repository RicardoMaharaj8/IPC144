#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name *name) {
    printf("Please enter the contact's first name: ");
    scanf("%30[0-9a-zA-Z ]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[a-zA-Z. ]", name->middleInitial);
        clearKeyboard();
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[a-zA-Z ]", name->lastName);
    clearKeyboard();
}

void getAddress(struct Address *address) {
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    if (address->streetNumber < 0) {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[0-9a-zA-Z. ]s", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        if (address->apartmentNumber < 0) {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[0-9a-zA-Z ]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[0-9a-zA-Z ]", address->city);
    clearKeyboard();
}

void getNumbers(struct Numbers *numbers) {
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
}

void getContact(struct Contact *contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
