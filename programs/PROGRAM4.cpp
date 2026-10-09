#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%99s", key);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            int shift = toupper(key[j % strlen(key)]) - 'A';

            if(isupper(text[i]))
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';

            j++;
        }
    }

    printf("Ciphertext: %s", text);

    return 0;
}
