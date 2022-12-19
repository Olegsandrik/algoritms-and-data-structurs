#include <stdio.h>
int main(int argc, char **argv){
    unsigned long long arr[92];
    int flag=0;
    arr[0]=1;
    arr[1]=2;
    for (int i=2; i<92; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    long long x;
    scanf("%lld", &x);
    for (int i=91; i>=0; i--){
        if(arr[i]<x){
            //О нашли число, которое можно вычесть
            x-=arr[i];
            printf("1");
            flag=1;
        }
        else {
            if (flag){
                printf("0");
            }
        }
    }
    return 0;
}
