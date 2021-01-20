#include <stdio.h>

int main(void) {
    int i;
    printf("---=== IPC Temperature Calculator V2.0 ===---");
    printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
    int days = 0;
    scanf("%d", &days);
    while (days < 3 || days > 10) {
        printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d", &days);
    }
    int high[days];
    int low[days];
    printf("\n");
    for (i = 0; i < days; i++) {
        printf("Day %d - High: ", i + 1);
        scanf("%d", &high[i]);
        printf("Day %d - Low: ", i + 1);
        scanf("%d", &low[i]);
    }
    printf("\nDay  Hi  Low\n");
    for (i = 0; i < days; i++) {
        printf("%d    %d    %d\n", i + 1, high[i], low[i]);
    }
    return 0;
}
