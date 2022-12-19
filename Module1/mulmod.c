#include <stdio.h>
int main(int argc, char **argv){
    unsigned long long a, b, m;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &m);

    // переведем б в двоичку
    int arr[64]={0};
    int i=0;
    while(b>0) {
        arr[i] += b % 2;
        b = b / 2;
        i++;
    }
    // получили перевернутый масссив, где i-тый элемент - начало числа
    long long result;
    
    
    int k=0;
    while(k < (i-1)){
        result=(result%m)*2;
        result=(result%m)+(a%m)*(arr[i-k-2]%m);
        k++;
    }
    printf("%lld", result%m);
    return 0;
}
