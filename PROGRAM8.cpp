#include <stdio.h>
#include <ctype.h>

int main()
{
    char key[100];
    char cipher[26];
    int used[26] = {0};
    int i, n = 0;

    printf("Enter keyword: ");
    scanf("%99s", key);

    /* Add keyword letters */
    for(i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if(ch >= 'A' && ch <= 'Z' && !used[ch-'A'])
        {
            cipher[n++] = ch;
            used[ch-'A'] = 1;
        }
    }

    /* Add remaining alphabet letters */
    for(i = 0; i < 26; i++)
    {
        if(!used[i])
            cipher[n++] = 'A' + i;
    }

    printf("\nPlain : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");

    printf("Cipher: ");

    for(i = 0; i < 26; i++)
        printf("%c", cipher[i]);

    printf("\n");

    return 0;
}
