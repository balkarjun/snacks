// Problem 3: Largest Prime Factor
#include <stdio.h>
#include <stdint.h>

typedef uint64_t u64;

// Idea: If a number x is not prime, it must have a prime factor <= sqrt(x)
bool is_prime(u64 n) {
    for (u64 i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }

    return true;
}

// Idea: To find factors of a number x, we only need to look from 1 to sqrt(x)
int main() {
    const u64 target = 600851475143;

    u64 largest = 1;
    for (u64 i = 2; i*i <= target; i++) {
        if (target%i == 0) {
            u64 a = i;
            u64 b = target/i;

            if (is_prime(a)) largest = (a > largest) ? a : largest;
            if (is_prime(b)) largest = (b > largest) ? b : largest;
        }
    }

    printf("%llu\n", largest);
}
