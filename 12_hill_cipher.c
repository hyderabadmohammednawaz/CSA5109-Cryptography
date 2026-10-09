#include <stdio.h>
#include <ctype.h>
#include <string.h>

int invmod(int a) {
    int x;
    a = (a % 26 + 26) % 26;
    for (x = 1; x < 26; ++x)
        if ((a * x) % 26 == 1) return x;
    return -1;
}

void clean(char *s) {
    char t[1000]; int i, j = 0;
    for (i = 0; s[i]; ++i)
        if (isalpha((unsigned char)s[i]))
            t[j++] = (char)tolower((unsigned char)s[i]);
    if (j % 2) t[j++] = 'x';
    t[j] = '\0';
    strcpy(s, t);
}

void process(const char *in, char *out, int enc) {
    int a=9,b=4,c=5,d=7,i,j;
    int det=(a*d-b*c)%26, inv=invmod(det);
    int m[2][2]={{a,b},{c,d}}, im[2][2];
    int n=(int)strlen(in), p[2], r[2];
    if (inv < 0) { out[0]=0; return; }
    if (!enc) {
        im[0][0]= d*inv%26; im[0][1]= -b*inv%26;
        im[1][0]= -c*inv%26; im[1][1]= a*inv%26;
        for(i=0;i<2;i++) for(j=0;j<2;j++) im[i][j]=(im[i][j]+26)%26;
    }
    for(i=0;i<n;i+=2) {
        p[0]=in[i]-'a'; p[1]=in[i+1]-'a';
        if(enc){r[0]=(m[0][0]*p[0]+m[0][1]*p[1])%26;
                r[1]=(m[1][0]*p[0]+m[1][1]*p[1])%26;}
        else {r[0]=(im[0][0]*p[0]+im[0][1]*p[1])%26;
              r[1]=(im[1][0]*p[0]+im[1][1]*p[1])%26;}
        out[i]=r[0]+'a'; out[i+1]=r[1]+'a';
    }
    out[n]='\0';
}

int main(void) {
    char p[1000]="meet me at the usual place at ten rather than eight oclock";
    char c[1000], d[1000];
    clean(p);
    process(p,c,1); process(c,d,0);
    printf("Key = [9 4; 5 7]\n");
    printf("Plaintext : %s\n",p);
    printf("Ciphertext: %s\n",c);
    printf("Decrypted : %s\n",d);
    return 0;
}
