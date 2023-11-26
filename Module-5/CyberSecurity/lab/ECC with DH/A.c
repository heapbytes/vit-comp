#include <stdio.h>
#include <math.h>

int powmod(int base, int exponent, int mod)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result = (result * base) % mod;
    }
    return result;
}

int main()
{
    int G, P, privateKey, publicKeyA, publicKeyB, sharedKeyA, sharedKeyB;
    printf("Enter value of P: ");
    scanf("%d", &P);
    printf("Enter value of G: ");
    scanf("%d", &G);

    printf("Enter private key: ");
    scanf("%d", &privateKey);

    publicKeyB = powmod(G, privateKey, P);
    printf("Public key of A is: %d\n", publicKeyB);
    printf("Enter public key of the other party (B): ");
    scanf("%d", &publicKeyA);
    sharedKeyA = powmod(publicKeyA, privateKey, P);
    printf("Shared key for A is: %d\n", sharedKeyA);
    
    return 0;
}
