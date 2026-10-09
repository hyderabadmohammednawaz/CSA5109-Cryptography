#include <stdio.h>

/* Demonstration of recovering a 2x2 Hill key from two plaintext/ciphertext
   column pairs. Values use A=0,...,Z=25. */
int invmod(int a) {
    int x;
    a=(a%26+26)%26;
    for(x=1;x<26;x++) if((a*x)%26==1) return x;
    return -1;
}
int main(void) {
    /* Example pairs: plaintext columns [1,2], [3,5].
       Ciphertext generated with K=[3 2; 5 7]. */
    int P[2][2]={{1,3},{2,5}}, C[2][2]={{7,15},{19,9}};
    int det=(P[0][0]*P[1][1]-P[0][1]*P[1][0])%26;
    int inv=invmod(det), Pinv[2][2], K[2][2], i,j,k;
    if(inv<0){printf("Chosen plaintext matrix is not invertible mod 26.\n");return 0;}
    Pinv[0][0]=P[1][1]*inv%26; Pinv[0][1]=-P[0][1]*inv%26;
    Pinv[1][0]=-P[1][0]*inv%26; Pinv[1][1]=P[0][0]*inv%26;
    for(i=0;i<2;i++) for(j=0;j<2;j++) Pinv[i][j]=(Pinv[i][j]+26)%26;
    for(i=0;i<2;i++) for(j=0;j<2;j++){
        K[i][j]=0;
        for(k=0;k<2;k++) K[i][j]=(K[i][j]+C[i][k]*Pinv[k][j])%26;
    }
    printf("Recovered Hill key matrix:\n");
    printf("[%d %d]\n[%d %d]\n",K[0][0],K[0][1],K[1][0],K[1][1]);
    printf("A known-plaintext attack works when enough independent pairs are available.\n");
    return 0;
}
