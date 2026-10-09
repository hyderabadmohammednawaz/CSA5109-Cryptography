#include <stdio.h>
#include <ctype.h>

int main()
{
    char cipher[500];
    char key[27];
    int i;

    printf("Enter substitution key:\n");
    printf("Cipher alphabet: ");
    scanf("%26s", key);

    getchar();

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            for(int j = 0; j < 26; j++)
            {
                if(toupper(key[j]) == cipher[i])
                {
                    cipher[i] = 'A' + j;
                    break;
                }
            }
        }
    }

    printf("\nDecrypted text:\n%s", cipher);

    return 0;
}
