#include <stdio.h>
#include "contactHelpers.h"

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
        }
    }
    return (choice == 'y' || choice == 'Y');
}

int menu(void) {
    printf("Contact Management System\n");
    printf("-------------------------\n");
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
    int cms = 1;
    int a = 0;
    int choice = 0;
    while (cms != 0) {
        a = menu();
        switch (a) {
            case 1:
                printf("\n<<< Feature 1 is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 2:
                printf("\n<<< Feature 2 is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 3:
                printf("\n<<< Feature 3 is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 4:
                printf("\n<<< Feature 4 is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 5:
                printf("\n<<< Feature 5 is unavailable >>>\n\n");
                pause();
                printf("\n");
                break;
            case 6:
                printf("\n<<< Feature 6 is unavailable >>>\n\n");
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
