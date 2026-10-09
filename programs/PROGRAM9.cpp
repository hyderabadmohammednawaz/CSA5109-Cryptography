#include <stdio.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int r = 0, c = 0;
    int i;
    char ch;

    for(i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if(ch == 'J')
            ch = 'I';

        if(ch >= 'A' && ch <= 'Z' && !used[ch-'A'])
        {
            matrix[r][c++] = ch;
            used[ch-'A'] = 1;

            if(c == 5)
            {
                c = 0;
                r++;
            }
        }
    }

    for(ch = 'A'; ch <= 'Z'; ch++)
    {
        if(ch == 'J')
            continue;

        if(!used[ch-'A'])
        {
            matrix[r][c++] = ch;
            used[ch-'A'] = 1;

            if(c == 5)
            {
                c = 0;
                r++;
            }
        }
    }
}

void findPosition(char ch, int *r, int *c)
{
    int i, j;

    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(matrix[i][j] == ch)
            {
                *r = i;
                *c = j;
                return;
            }
        }
    }
}

int main()
{
    char key[50];
    char cipher[500];
    int i;
    int r1, c1, r2, c2;

    printf("Enter Playfair key: ");
    scanf("%49s", key);

    getchar();

    printf("Enter ciphertext:\n");
    fgets(cipher, sizeof(cipher), stdin);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    printf("\nDecrypted text: ");

    char clean[500];
    int n = 0;

    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
            clean[n++] = toupper(cipher[i]);
    }

    for(i = 0; i < n; i += 2)
    {
        findPosition(clean[i], &r1, &c1);
        findPosition(clean[i+1], &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c",
                   matrix[r1][(c1+4)%5],
                   matrix[r2][(c2+4)%5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
                   matrix[(r1+4)%5][c1],
                   matrix[(r2+4)%5][c2]);
        }
        else
        {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }

    return 0;
}
