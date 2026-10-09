#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char p[]="send money", key[]="9017231521141111289";
    char c[100], k2[100]; int i,j=0,n=(int)strlen(p), shift;
    printf("Plaintext: %s\nKey stream: %s\n",p,key);
    for(i=0;i<n;i++) {
        if(isalpha((unsigned char)p[i])) {
            shift=key[j++]-'0';
            c[i]=(char)('a'+((tolower((unsigned char)p[i])-'a'+shift)%26));
        } else c[i]=p[i];
    }
    c[n]='\0';
    printf("Ciphertext: %s\n",c);
    /* For a chosen plaintext and ciphertext, the required key is C-P mod 26. */
    printf("A possible key for plaintext 'cash not needed' is computed below.\n");
    strcpy(p,"cash not needed"); n=(int)strlen(p); j=0;
    for(i=0;i<n;i++) {
        if(isalpha((unsigned char)p[i])) {
            /* Example target ciphertext, chosen to illustrate many possible keys. */
            int cp = "dbti!opu!offefe"[i] % 26;
            int pp = tolower((unsigned char)p[i])-'a';
            k2[j++]=(char)('0'+((cp-pp+26)%26));
        } else k2[j++]=p[i];
    }
    k2[j]='\0';
    printf("Illustrative key stream: %s\n",k2);
    return 0;
}
