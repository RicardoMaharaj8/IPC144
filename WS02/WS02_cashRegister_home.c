#include <stdio.h>

int main(void) {
    float amount;
    printf("Please enter the amount to be paid: $");
    scanf("%f", &amount);
    printf("GST: 1.13\n");
    amount *= 1.13;
    printf("Balance owing: $%.2f\n", amount);
    printf("Loonies required: %d, balance owing $%.2f\n", (int) amount, amount - (int) amount);
    amount -= (int) amount;
    int i = amount / .25;
    amount = amount - (i * .25);
    printf("Quarters required: %d, balance owing $%.2f\n", i, amount);
    i = amount / .10;
    amount = amount - (i * .10);
    printf("Dimes required: %d, balance owing $%.2f\n", i, amount);
    i = amount / .05;
    amount = amount - (i * .05);
    printf("Nickels required: %d, balance owing $%.2f\n", i, amount);
    i = 1;
    amount = 0;
    printf("Pennies required: %d, balance owing $%.2f\n", i, amount);
    return 0;
}
