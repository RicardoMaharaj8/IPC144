#include <stdio.h>

#define NUMS 4

int main(void) {
    int high, low, i;
    int hot = 0;
    int cold = 0;
    int hotday = 0;
    int colday = 0;
    int day = 0;
    float lowa, higha, avg;
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
        lowa += low;
        higha += high;
        avg += high;
        avg += low;
        if (high > hot) {
            hot = high;
            hotday = day;
        }
        if (low < cold) {
            cold = low;
            colday = day;
        }
    }
    printf("\nThe average (mean) temperature was: %.2f", avg / 8);
    printf("\nThe highest temperature was %d, on day %d", hot, hotday);
    printf("\nThe lowest temperature was %d, on day %d\n", cold, colday);
    return 0;
}
