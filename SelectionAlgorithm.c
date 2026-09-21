#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 10000000

/*
 * Selection sort, ascending.
 * On each pass, find the smallest element in the unsorted part and swap it
 * to the front. O(n^2) comparisons, at most n - 1 swaps, sorts in place.
 */
void selectionSort(int arr[], int n) {
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

void printArray(const int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int n, i;
    int *arr;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_ELEMENTS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_ELEMENTS);
        return 1;
    }

    /* Heap allocation: a 10-million-int array on the stack would overflow it. */
    arr = malloc((size_t)n * sizeof *arr);
    if (arr == NULL) {
        printf("Not enough memory for %d elements.\n", n);
        return 1;
    }

    printf("Enter %d number(s):\n", n);
    for (i = 0; i < n; i++) {
        printf("  Element [%d]: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid number.\n");
            free(arr);
            return 1;
        }
    }

    printf("\nUnsorted array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    free(arr);
    return 0;
}
