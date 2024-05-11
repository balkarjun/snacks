#include <stdio.h>
#include <stdlib.h>

#define ArrayLength(a) (sizeof(a)/sizeof(a[0]))
#define Max(a, b) ((a) > (b)) ? (a) : (b)

bool csort(int array[], int length) {
    if (length <= 1) return true;
    // Ensure that the array contains only non-negative integers
    for (int i = 0; i < length; i++) {
        if (array[i] < 0) {
            printf("[ERROR] Could not sort array, since it contains negative integers\n");
            return false;
        }
    }
    // Find the largest integer in the array
    int largest = array[0];
    for (int i = 0; i < length; i++) {
        largest = Max(array[i], largest);
    }
    // Create a bookkeeping array
    int *counts = (int*)calloc(largest+1, sizeof(int));
    for (int i = 0; i < length; i++) {
        int value = array[i];
        counts[value]++;
    }
    // Construct the sorted array
    int index = 0;
    for (int value = 0; value < largest+1; value++) {
        while (counts[value] > 0) {
            array[index] = value;
            index++;
            counts[value]--;
        }
    }

    free(counts);
    return true;
}

int main() {
    int array[] = { 1, 3, 8, 2, 9, 2, 5, 6 };
    int length = ArrayLength(array);

    csort(array, length);

    for (int value: array) {
        printf("%d ", value);
    }
    printf("\n");
}
