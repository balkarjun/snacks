#include <stdio.h>

// Problem 1: Multiples of 3 or 5
int main() {
    int sum = 0;
    for (int n = 1; n < 1000; n++) {
        if (n%3 == 0 || n%5 == 0) {
            sum += n;
        }
    }

    printf("%d\n", sum);
}
