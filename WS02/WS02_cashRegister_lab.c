#include <stdio.h>

int main(void) {
    double paid;
    printf("Please enter the amount to be paid: $");
    scanf("%lf", &paid);
    int loonies = paid;
    printf("Loonies required: %d, balance owing $%.2lf\n", loonies, paid - loonies);
    int quart = ((paid - loonies) / 0.25);
    printf("Quarters required: %d, balance owing $%.2lf\n", quart, 0.18);
    return 0;
}
