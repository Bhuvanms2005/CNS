
#include <stdio.h>

int main()
{
    int p, g, a, b;
    int x, y, ka, kb, i;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter primitive root g: ");
    scanf("%d", &g);

    printf("Enter private key of client: ");
    scanf("%d", &a);

    printf("Enter private key of server: ");
    scanf("%d", &b);

    x = 1;
    for (i = 0; i < a; i++)
        x = (x * g) % p;

    y = 1;
    for (i = 0; i < b; i++)
        y = (y * g) % p;

    printf("Client public key: %d\n", x);
    printf("Server public key: %d\n", y);

    ka = 1;
    for (i = 0; i < a; i++)
        ka = (ka * y) % p;

    kb = 1;
    for (i = 0; i < b; i++)
        kb = (kb * x) % p;

    printf("Client shared key: %d\n", ka);
    printf("Server shared key: %d\n", kb);

    if (ka == kb)
        printf("Secure shared key established!\n");
    else
        printf("Key exchange failed!\n");

    return 0;
}
