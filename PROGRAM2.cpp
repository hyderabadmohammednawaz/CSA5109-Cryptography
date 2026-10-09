#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100];
    char key[27];
    int i;

    printf("Enter substitution key (26 letters): ");
    scanf("%26s", key);

    getchar();

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = toupper(key[text[i] - 'A']);

        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = tolower(key[text[i] - 'a']);
    }

    printf("Ciphertext: %s", text);

    return 0;
}
