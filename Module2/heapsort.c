#include <stdio.h>
#include <string.h>
void change(void *a, void *b, size_t width);
int counter(const char *str){
    int k=strlen(str);
    int summ = 0;
    for(int i = 0; i<k; i++){
        if (str[i] == 'a')
            summ++;
    }
    return summ;
}
int compare (const void * a, const void * b){
    return (counter(a)-counter(b));
}
void Heapify(int (*compare)(const void *a, const void *b), void *base, int i, unsigned long nel, size_t width){
    int loop=1;
    while (loop){
        int l = 2*i + 1;
        int r = l + 1;
        int j = i;
        if (l < nel && (compare((unsigned char*)base + i * width , (unsigned char *)base + l * width) < 0))
            i = l;
        if (r < nel && (compare((unsigned char*)base + i * width, (unsigned char*)base + r * width) < 0))
            i = r;
        if (i == j)
            break;
        change((unsigned char *)base + j * width, (unsigned char *)base + i * width, width);
    }
}
void BuildHeap(int (*compare)(const void *a, const void *b), unsigned long nel, void *base, size_t width) {
    int i=(nel/2-1);
    while(i>=0){
        Heapify(compare, base, i, nel, width);
        i--;
    }
}
void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b)){
    BuildHeap(compare, nel, base, width);
    int i=nel-1;
    while(i>0){
        change(base, (unsigned char *)base + i * width, width);
        Heapify(compare, base, 0, i, width);
        i--;
    }
}
void change(void *a, void *b, size_t width){
    char krash;
    for (int i=0; i < width; i++){
        krash = ((char*)a)[i];
        ((char*)a)[i] = ((char*)b)[i];
        ((char*)b)[i] = krash;
    }
}
int main(int argc, char **argv){
    int n;
    scanf("%d ", &n);
    char answer[n][1001];
    for(int k = 0; k < n; k++)
        scanf("%s", &answer[k]);
    hsort(answer, n, 1001, compare);
    for(int i = 0; i < n; i++)
        printf("%s\n", answer[i]);
    return 0;
}
