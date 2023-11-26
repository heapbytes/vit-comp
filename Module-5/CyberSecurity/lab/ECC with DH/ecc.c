#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int power(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool isPrimitiveRoot(int root, int prime) {
    int* remainders = malloc((prime - 1) * sizeof(int));
    for (int i = 0; i < prime - 1; i++) {
        remainders[i] = 0;
    }

    for (int i = 1; i < prime; i++) {
        int mod = power(root, i, prime);
        if (remainders[mod - 1] == 1) {
            free(remainders);
            return false;
        }
        remainders[mod - 1] = 1;
    }

    free(remainders);
    return true;
}

int findPrimitiveRoot(int prime) {
    for (int i = 2; i < prime; i++) {
        if (isPrimitiveRoot(i, prime)) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int P;
    printf("Enter value of P (prime number): ");
    scanf("%d", &P);

    int primitiveRoot = findPrimitiveRoot(P);
    if (primitiveRoot != -1) {
        printf("Primitive root modulo %d is: %d\n", P, primitiveRoot);
    } else {
        printf("No primitive root found modulo %d\n", P);
    }

    return 0;
}
