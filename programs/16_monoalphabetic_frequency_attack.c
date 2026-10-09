#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Heuristic frequency attack. It ranks substitutions using English
   frequency order. It is intentionally non-interactive. */
int main(void) {
    char cipher[3000], freq[]="etaoinshrdlucmfwypvbgkjqxz";
    int count[26]={0}, rank[26], i,j,t;
    printf("Enter monoalphabetic-substitution ciphertext:\n");
    fgets(cipher,sizeof(cipher),stdin);
    for(i=0;cipher[i];i++)
        if(isalpha((unsigned char)cipher[i])) count[tolower((unsigned char)cipher[i])-'a']++;
    for(i=0;i<26;i++) rank[i]=i;
    for(i=0;i<26;i++) for(j=i+1;j<26;j++)
        if(count[rank[j]]>count[rank[i]]) {t=rank[i];rank[i]=rank[j];rank[j]=t;}
    printf("\nFrequency mapping used:\n");
    for(i=0;i<26;i++) printf("%c -> %c\n",'a'+rank[i],freq[i]);
    printf("\nCandidate plaintext:\n");
    for(i=0;cipher[i];i++) {
        if(isalpha((unsigned char)cipher[i])) {
            int x=tolower((unsigned char)cipher[i])-'a', pos=0;
            while(pos<26 && rank[pos]!=x) pos++;
            putchar(pos<26?freq[pos]:'?');
        } else putchar(cipher[i]);
    }
    printf("\n\nThis is a heuristic ranking, not guaranteed to recover every key.\n");
    return 0;
}
