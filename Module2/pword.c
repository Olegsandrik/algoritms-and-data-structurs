#include <stdio.h>
#include <string.h>
int Prefix(char *s, int *pi){
    int lenS = strlen(s);
    int t = 0;
    pi[0] = 0;
    for(int i = 1; i < lenS; i++)
    {
        while(t > 0 && s[t] != s[i])
            t = pi[t-1];

        if(s[t] == s[i]) t++;
        pi[i] = t;
    }
}

int KMPSubst(char *s, char *T){
    int lenS = strlen(s), lenT = strlen(T);
    int pi[lenS];
    Prefix(s, pi);
    int q = 0;
    unsigned long long k=0;
    while(k< lenT){
        while(q > 0 && s[q] != T[k])
            q = pi[q-1];
        if(s[q] == T[k]) {
            q++;
        }
        if(q == 0) {
            return 0;
        }
        if(q == strlen(s))
            k = k+1-lenS;
        k++;
    }
    return 1;
}
int main(int argc,char **argv){
    char S[100000], T[100000];
    scanf("%s", &S);
    scanf("%s", &T);
    if(KMPSubst(S, T)==1) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}
