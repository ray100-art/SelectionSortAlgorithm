#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    int arr[100000];   /* Fixed size array instead of variable-length */

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100000) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d number(s):\n", n);
    for (i = 0; i < n; i++) {
        printf("  Element [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;

}

