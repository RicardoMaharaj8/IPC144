#include <stdio.h>

#define SIZE 4

struct Employee {
    int id;
    int age;
    double wage;
};

int main(void) {
    int option = 0;
    int i = 0;
    int x = 0;
    int e = 0;
    struct Employee emp[SIZE] = {{0}};

    printf("---=== EMPLOYEE DATA ===---\n\n");
    do {
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 0:
                printf("Exiting Employee Data Program. Good Bye!!!\n");
                break;
            case 1:
                printf("EMP ID  EMP AGE EMP SALARY\n");
                printf("======  ======= ==========\n");
                for (i = 0; i < SIZE; i++) {
                    printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].wage);
                }

                printf("\n");

                break;
            case 2:
                printf("Adding Employee\n");
                printf("===============\n");
                if (x > SIZE) {
                    printf("ERROR!!! Maximum Number of Employees Reached\n");
                    printf("\n");
                } else {
                    printf("Enter Employee ID: ");
                    scanf("%d", &emp[x].id);
                    printf("Enter Employee Age: ");
                    scanf("%d", &emp[x].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf", &emp[x].wage);
                    x++;
                    printf("\n");
                }
                break;
            case 3:
                printf("Update Employee Salary\n");
                printf("======================\n");
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &e);
                    for (i = 0; i < SIZE; i++) {
                        if (e != emp[i].id) {
                            printf("err\n");
                        }
                    }
                } while (e != 0);
                break;
            case 4:
                printf("Remove Employee\n");
                printf("===============\n");
                break;
            default:
                printf("ERROR: Incorrect Option: Try Again\n\n");
        }
    } while (option != 0);
    return 0;
}
