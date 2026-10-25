
#include <stdio.h>

int main()
{
    int p, q, n, phi, e, d, i;
    int msg, enc, dec;

    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    for (e = 2; e < phi; e++)
    {
        int a = e, b = phi, r;

        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        if (a == 1)
            break;
    }

    for (d = 1; d < phi; d++)
    {
        if ((d * e) % phi == 1)
            break;
    }

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    printf("User A, enter message number (0 to %d): ", n - 1);
    scanf("%d", &msg);

    enc = 1;
    for (i = 0; i < e; i++)
        enc = (enc * msg) % n;

    printf("Encrypted message sent to User B: %d\n", enc);

    dec = 1;
    for (i = 0; i < d; i++)
        dec = (dec * enc) % n;

    printf("User B decrypts message: %d\n", dec);

    return 0;
}
