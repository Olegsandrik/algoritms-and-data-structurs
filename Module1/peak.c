#include <stdio.h>
unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    if (nel==0){
        return 0;
    }
    for (unsigned long k=nel-1; k>=0; k--){
        if (k==0){
            if (less(k+1, k) || k+1==k){
                return k;
            }
        }
        if (k==nel-1){
            if (less(k-1, k) || k-1==k){
                return k;
            }
        }
        if (((less(k+1, k) || k==k+1)&&(less(k-1,k) || k==k-1))){
            return k;
        }
    }
}
int main(int argc, char **argv){
    return 0;
}
