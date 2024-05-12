#include <stdio.h>

#define ArrayLength(a) (sizeof(a)/sizeof(a[0]))

// returns index of target if found, else returns -1
int bsearch(int array[], int length, int target) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int array[] = { 1, 2, 2, 3, 5, 6, 8, 9 };
    int length = ArrayLength(array);

    int target = 5;
    int index = bsearch(array, length, target);
    
    if (index == -1) {
        printf("%d was not found in the array\n", target);
    } else {
        printf("%d was found at index %i in the array\n", target, index);
    }
}
