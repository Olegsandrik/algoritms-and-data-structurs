#include <stdio.h>
#include <string.h>
#include <iso646.h>
void delta1(char *s, unsigned long long lenS, int *pi){
    int a = 0;
    int size=sizeof(*pi)/sizeof(pi[0]);
    while( a < size) {
        pi[a] = (int)lenS;
        a++;
    }
    int j = 0;
    while ( j < lenS){
        pi[(int)s[j]] = (int)lenS - j;
        j++;
    }
}
int SimpleBMSubst(char *S, char *T){
    int pi[127], lenT = strlen(T), lenS = strlen(S);
    delta1(S, lenS, pi);
    int i=lenS-1;
    while (i < lenT ) {
        int j = lenS - 1;
        int k = i;
        while (j >= 0 and T[k]==S[j]) {
            k--;
            j--;
        }
        if(j>=0){
            i += pi[(int)S[j]];
        }
        else {
            printf("%d ",k+1);
            i += pi[(int)T[k+1]];
        }
    }
}
int main(int argc, char** argv) {
    //char S[100000], T[100000];
    //scanf("%s", &S);
    //scanf("%s", &T);
    //aab aacaaabcd
    char *S = argv[1];
    char *T = argv[2];
    SimpleBMSubst(S, T);
    return 0;
}
