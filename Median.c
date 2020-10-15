#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXLEN 1000000

void insertion_sort(int array[MAXLEN], int n){
	for (int i = 0; i < n; ++i) {
		int t = array[i];
		int j = i;
		while (j > 0 && array[j - 1] > t) {
			array[j] = array[j - 1];
			j--;
		}

		array[j] = t;
	}
}

int main() {
    int n, medin;
    int array[MAXLEN];

    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &array[i]);
    }

    medin = n/2 + n % 2 - 1;

    insertion_sort(array, n);

    printf("%d", array[medin]);

    return 0;
}