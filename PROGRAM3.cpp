#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int r = 0, c = 0, i;
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
        for(j = 0; j < 5; j++)
            if(matrix[i][j] == ch)
            {
                *r = i;
                *c = j;
                return;
            }
}

int main()
{
    char key[50], text[200], clean[200];
    int i, n = 0;
    int r1, c1, r2, c2;

    printf("Enter key: ");
    scanf("%49s", key);

    getchar();

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for(i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);

            if(ch == 'J')
                ch = 'I';

            clean[n++] = ch;
        }
    }

    if(n % 2 != 0)
        clean[n++] = 'X';

    clean[n] = '\0';

    printf("Ciphertext: ");

    for(i = 0; i < n; i += 2)
    {
        findPosition(clean[i], &r1, &c1);
        findPosition(clean[i+1], &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c",
                   matrix[r1][(c1+1)%5],
                   matrix[r2][(c2+1)%5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
                   matrix[(r1+1)%5][c1],
                   matrix[(r2+1)%5][c2]);
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
