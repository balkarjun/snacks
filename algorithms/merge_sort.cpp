#include <stdio.h>
#include <stdlib.h>

#define ArrayLength(a) (sizeof(a)/sizeof(a[0]))

void msort(int array[], int low, int high) {
    if (high <= low) return;

    int mid = low + (high - low)/2;
    // recursively sort left half
    msort(array, low, mid);
    // recursively sort right half
    msort(array, mid + 1, high);
    /* merge results */
    // create a temporary array to merge into
    int *sorted = (int*)malloc((high - low + 1)*sizeof(int));
    int i = low;
    int j = mid + 1;
    int count = 0;
    // append the smaller element from the left/right halves
    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            sorted[count] = array[i];
            count++;
            i++;
        } else {
            sorted[count] = array[j];
            count++;
            j++;
        }
    }
    // append any remaining elements
    while (i <= mid) {
        sorted[count] = array[i];
        count++;
        i++;
    }
    while (j <= high) {
        sorted[count] = array[j];
        count++;
        j++;
    }
    // copy elements into original array
    for (int i = 0; i < count; i++) {
        array[low + i] = sorted[i];
    }

    free(sorted);
}

int main() {
    int array[] = { 1, 3, 8, 2, 9, 2, 5, 6, -1 };
    int n = ArrayLength(array);

    msort(array, 0, n - 1);

    for (int value: array) {
        printf("%d ", value);
    }
    printf("\n");
}
