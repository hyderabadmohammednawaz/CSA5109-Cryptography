#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[500];
    int freq[26] = {0};
    int i, j;
    char temp;

    printf("Enter ciphertext:\n");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            freq[ch - 'A']++;
        }
    }

    printf("\nFrequency:\n");

    for(i = 0; i < 26; i++)
        printf("%c : %d\n", 'A' + i, freq[i]);

    printf("\nMost frequent letters:\n");

    for(i = 0; i < 26; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(freq[j] > freq[i])
            {
                int t = freq[i];
                freq[i] = freq[j];
                freq[j] = t;

                temp = 'A' + i;
                /* Frequency sorting only */
            }
        }
    }

    return 0;
}
