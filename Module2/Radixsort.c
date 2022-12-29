void RadixSort(int q, int m, union Int32 *array1, int n){
    int i = 0;
    while (i <= q-1){
        DistributionSort(i, m, array1, n);
        i--;
    }
}
