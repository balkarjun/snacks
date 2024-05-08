#include <stdio.h>

#define ArrayLength(a) (sizeof(a)/sizeof(a[0]))

int main() {
    int array[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = ArrayLength(array);

    // After the first round, the largest element will be in the correct position
    // After k rounds, the k largest elements will be in the correct positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            // Swap if elements are in wrong order
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for (int value: array) {
        printf("%d ", value);
    }
    printf("\n");
}
