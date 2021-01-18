#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void merge(int arr[], int tmp[], int left_start, int right_pos, int right_end) {
    int left_end = right_pos - 1;               //right_pos = mid + 1;
    int left_pos = left_start;
    int cur_pos = left_start;

    while ((left_pos <= left_end) && (right_pos <= right_end)) {
        if (arr[left_pos] <= arr[right_pos]) {
            tmp[cur_pos++] = arr[left_pos++];
        } else {
            tmp[cur_pos++] = arr[right_pos++];
        }
    }

    while(left_pos <= left_end) {
        tmp[cur_pos++] = arr[left_pos++];
    }

    while(right_pos <= right_end) {
        tmp[cur_pos++] = arr[right_pos++];
    }

    right_pos = right_end;
    while (right_pos >= left_start) {
        arr[right_pos] = tmp[right_pos];
        right_pos--;
    }
    
}

void merge_sort(int arr[], int tmp[], int left, int right) {
    if (right > left) {
        int mid = (right + left) / 2;

        merge_sort(arr, tmp, left, mid);
        merge_sort(arr, tmp, mid + 1, right);
        merge(arr, tmp, left, mid + 1, right);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int arr[], int l, int r) {
    int pivot_index = r; //pivot na kraju
    //int pivot_index = (l + r) / 2; //pivot na sredini
    swap(&arr[pivot_index], &arr[r]);
    int pivot_value = arr[r];

    //partitioning
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot_value) {
            i++;
            swap(&arr[i], &arr[j]);
        }        
    }
    swap(&arr[++i], &arr[r]);
    

    if (i > l) {
        quick_sort(arr, l, i - 1);
    }

    if (i < r) {
        quick_sort(arr, i + 1, r);
    }
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, *arr, *tmp;

    scanf("%d ", &n);

    arr = malloc(n * sizeof(int));
    //tmp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d ", arr + i);
    }

    //merge_sort(arr, tmp, 0, n-1);   
    quick_sort(arr, 0, n - 1);

    print_array(arr, n);

    free(arr);
    //free(tmp);

    return 0;    
}