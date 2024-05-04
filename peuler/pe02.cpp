#include <stdio.h>

// Problem 2: Even Fibonacci Numbers
int main() {
    int prev = 1;
    int curr = 2;

    int sum = 0;
    while (curr <= 4000000) {
        if (curr%2 == 0) sum += curr;

        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }

    printf("%d\n", sum);
}
