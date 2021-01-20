#include <stdio.h>

#define NUMS 3

int main(void) {
    int high, low, i;
    int day = 0;
    printf("---=== IPC Temperature Analyzer ===---");
    for (i = 0; i < NUMS; i++) {
        day++;
        printf("\nEnter the high value for day %d: ", day);
        scanf("%d", &high);
        printf("\nEnter the low value for day %d: ", day);
        scanf("%d", &low);
        while (high > 40 || high < -40 || high < low) {
            printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
            printf("\nEnter the high value for day %d: ", day);
            scanf("%d", &high);
            printf("\nEnter the low value for day %d: ", day);
            scanf("%d", &low);
        }
        while (low < -40 || low > 40 || low > high) {
            printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
            printf("\nEnter the high value for day %d: ", day);
            scanf("%d", &high);
            printf("\nEnter the low value for day %d: ", day);
            scanf("%d", &low);
        }
    }
    return 0;
}
