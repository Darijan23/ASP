#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXLEN 100000

int maxsum(int array[MAXLEN], int n) {
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += array[k];
            }

            if (sum > max_sum) {
                max_sum = sum;
            } 
        }
    }

    return max_sum;
}

int main() {
    int n;
    int array[MAXLEN];

    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &array[i]);
    }
    
    printf("%d", maxsum(array, n));
}