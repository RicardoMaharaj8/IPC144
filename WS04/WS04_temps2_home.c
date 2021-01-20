#include <stdio.h>

float average(int a, int b) {
    float c;
    c = (float) a + (float) b;
    c /= 2;
    return c;
}

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
    float avg[days];
    float sum;
    int l, h, hd, ld;
    printf("\n");

    for (i = 0; i < days; i++) {
        printf("Day %d - High: ", i + 1);
        scanf("%d", &high[i]);
        if (high[i] > h) {
            h = high[i];
            hd = i;
        }
        printf("Day %d - Low: ", i + 1);
        scanf("%d", &low[i]);
        if (low[i] < l) {
            l = low[i];
            ld = i;
        }
    }
    printf("\nDay  Hi  Low\n");
    for (i = 0; i < days; i++) {
        printf("%d    %d    %d\n", i + 1, high[i], low[i]);
    }
    printf("\nThe highest temperature was %d, on day %d", h, hd + 1);
    printf("\nThe lowest temperature was %d, on day %d", l, ld + 1);
    printf("\n");
    printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
    scanf("%d", &days);

    while (days >= 0) {
        while (days < 1 || days > 5) {
            printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
            scanf("%d", &days);
        }
        while (days <= 5 && days >= 1) {
            sum = 0;
            for (i = 0; i < days; i++) {
                avg[i] = average(high[i], low[i]);
                sum += avg[i];
            }
            printf("\nThe average temperature up to day %d is: %.2f\n", days, sum / days);
            printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
            scanf("%d", &days);
        }
    }
    printf("\nGoodbye!");
    return 0;
}
