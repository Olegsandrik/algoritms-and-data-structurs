void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j), void (*swap)(unsigned long i, unsigned long j)){
    int left=0, right=nel-1, end=0; 
    while ((end<nel/2)){ 
        for (int i=left; i<right; i++){ 
            if(compare(i, i+1)== 1){ 
                swap(i,i+1);
            }
        }
        right-=1;
        for (int j=right; j>left; j--) { 
            if (compare(j, j-1) == -1) { 
                swap(j, j-1);
            }
        }
        left+=1;
        end++;
    }
}
