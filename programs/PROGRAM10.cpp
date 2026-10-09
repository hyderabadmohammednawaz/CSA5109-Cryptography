#include <stdio.h>
#include <ctype.h>

int main()
{
    char matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[] = "MUST SEE YOU OVER CADOGAN WEST COMING AT ONCE";
    char p[100];
    int i, j, n = 0;
    int r1, c1, r2, c2;

    /* Remove spaces */
    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            p[n++] = toupper(text[i]);
        }
    }

    if(n % 2 != 0)
        p[n++] = 'X';

    printf("Ciphertext: ");

    for(i = 0; i < n; i += 2)
    {
        /* Find first character */
        for(r1 = 0; r1 < 5; r1++)
            for(c1 = 0; c1 < 5; c1++)
                if(matrix[r1][c1] == p[i])
                    goto first;

        first:

        /* Find second character */
        for(r2 = 0; r2 < 5; r2++)
            for(c2 = 0; c2 < 5; c2++)
                if(matrix[r2][c2] == p[i + 1])
                    goto second;

        second:

        /* Same row */
        if(r1 == r2)
        {
            printf("%c%c ",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }

        /* Same column */
        else if(c1 == c2)
        {
            printf("%c%c ",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        }

        /* Rectangle rule */
        else
        {
            printf("%c%c ",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }

    return 0;
}
