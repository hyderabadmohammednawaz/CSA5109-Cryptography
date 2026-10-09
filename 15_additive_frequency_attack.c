#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char c[2000];
    int freq[26]={0}, n=0, i, k, order[26], t;
    printf("Enter ciphertext (lowercase/uppercase):\n");
    fgets(c,sizeof(c),stdin);
    for(i=0;c[i];i++) if(isalpha((unsigned char)c[i])) freq[tolower((unsigned char)c[i])-'a']++;
    for(i=0;i<26;i++) order[i]=i;
    for(i=0;i<26;i++) for(k=i+1;k<26;k++)
        if(freq[order[k]]>freq[order[i]]) {t=order[i];order[i]=order[k];order[k]=t;}
    printf("\nLetter frequencies:\n");
    for(i=0;i<26;i++) printf("%c:%d ", 'a'+i, freq[i]);
    printf("\n\nTop 10 Caesar/additive candidates (mapping most frequent to e):\n");
    for(i=0;i<10;i++) {
        int key=(order[i]-('e'-'a')+26)%26;
        printf("%2d. key=%2d : ",i+1,key);
        for(k=0;c[k] && k<100;k++) {
            if(isalpha((unsigned char)c[k])) {
                int x=(tolower((unsigned char)c[k])-'a'-key+26)%26;
                putchar('a'+x);
            } else putchar(c[k]);
        }
        printf("\n");
    }
    return 0;
}
