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

    publicKeyA = powmod(G, privateKey, P);
    printf("Public key of B is: %d\n", publicKeyA);
    printf("Enter public key of the other party (A): ");
    scanf("%d", &publicKeyB);
    sharedKeyA = powmod(publicKeyB, privateKey, P);
    printf("Shared key for B is: %d\n", sharedKeyA);
    
    return 0;
}
