#include <stdio.h>

#define Max(a, b) ((a) > (b)) ? (a) : (b)

// Kadane's algorithm for the maximum subarray sum problem
int main() {
    int values[] = { -2, -3, 4, -1, -2, 1, 5, -3 };

    int current = values[0];
    int largest = values[0];

    for (int value: values) {
        // If the sum so far helps us, keep it
        current = Max(current + value, value);
        largest = Max(current, largest);
    }
    
    printf("%d\n", largest);
}
