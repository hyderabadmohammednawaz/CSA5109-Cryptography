#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int modInverse(int a)
{
    int i;

    for(i = 1; i < 26; i++)
    {
        if((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    if(gcd(a, 26) != 1)
    {
        printf("Invalid value of a.\n");
        printf("a must be relatively prime to 26.\n");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a * (text[i]-'A') + b) % 26) + 'A';

        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a * (text[i]-'a') + b) % 26) + 'a';
    }

    printf("Ciphertext: %s", text);

    return 0;
}
