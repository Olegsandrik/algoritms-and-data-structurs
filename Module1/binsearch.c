#include <stdio.h>
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) {
    int right=nel, left=1, middle;
    while((right-left)>1){
        middle=(right+left)/2;
        if (compare(middle)==1){ // двигаем тогда лево до середины
            left=middle;
        }
        else{
            right=middle;
        }
    }
    if (compare(right)==-1){
        return left;
    }
    if (compare(left)==1){
        return right;
    }
    return nel;
}
int main(int argc, char **argv){
    return 0;
}


