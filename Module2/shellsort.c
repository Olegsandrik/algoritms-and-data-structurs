#include <stdio.h>
#include <malloc.h>
int compare(unsigned long i, unsigned long j);

void swap(unsigned long i, unsigned long j);
void shellsort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    int fiber1 = 1;
    int fiber2 = 1;
    int kolichestvo = 0;
    while(fiber2<nel){
        int mysor=fiber2;
        fiber2 = fiber1 +fiber2;
        fiber1 = mysor;
        kolichestvo+=1;
    }
    fiber1=1, fiber2=1;
    int *fibers = calloc(kolichestvo, sizeof(int));
    int k = 0;
    while (fiber2<nel){
        int mysor = fiber2;
        fiber2 = fiber1 + fiber2;
        fiber1 = mysor;
        fibers[k]=fiber1;
        k++;
    }
    int i = kolichestvo-1;
    while (i>=0){
        int s = fibers[i];
        int j = 0;
        while (j<nel){
            int k = j-s;
            while (k>=0 && compare(k,k+s)>=1){
                swap(k, k+s);
                k-=s;
            }
            j++;
        }
        i--;
    }
    free(fibers);
}
int *arr;
int main(int argc, char **argv){
    int n;
    scanf("%d", &n);
    arr = (int*)calloc(n, sizeof(int));
    for (int j = 0; j<n; j++){
        scanf("%d", &arr[j]);
    }
    shellsort(n,compare,swap);
    for (int j = 0; j<n ; j++){
            printf("%d ", arr[j]);
    }
    free(arr);
    return 0;
}
int compare(unsigned long i, unsigned long j){
    return (arr[i] - arr[j]);
}
void swap(unsigned long i, unsigned long j){
    int mysor = arr[i];
    arr[i]=arr[j];
    arr[j]=mysor;
}
