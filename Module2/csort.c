#include <stdio.h>
#include <string.h>
#include <iso646.h>
#include <malloc.h>
#include <stdbool.h>
int compare (char *a, char *b){
    int ans1=(strlen(a)==strlen(b))? 0: 1;
    int ans2=(strlen(a)>=strlen(b))? 0: 2;
    int ans=ans1-ans2;
    return ans;
}
void csort(char *src, char *dest){
    char** b = calloc(10000,sizeof(char*));
    char** d = calloc(10000,sizeof(char*));
    int k=-1;
    unsigned long long n=strlen(src);
    bool konecstr=true;
    int counter=0;
    for(int q = 0 ; q < n; q++){
        if(src[q]==' '){
            konecstr=true;
            continue;
        }
        if(konecstr){
            k++;
            b[k]=calloc(10000,sizeof(char));
            counter=0;
            konecstr=false;
        }
        b[k][counter]=src[q];
        counter++;
    }
    int *count=calloc(k+1, sizeof(int));
    int N=k+1;
    int j=N-1;
    while (j>0){
        int i=j-1;
        while (i>-1){
            if (compare(b[i],b[j])) {
                count[j]=count[j]+1;
            }
            else{
                count[i]=count[i]+1;
            }
            i--;
        }
        j--;
    }
    for (int i=0; i < N ; i ++){
        d[count[i]] = b[i];
    }
    int q=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<strlen(d[i]);j++){
            dest[k]=d[i][j];
            q++;
        }
        dest[q]=' ';
        q++;
    }
    dest[q-1]='\0';
    for(int i=0;i<N;i++){
        free(d[i]);
    }
    free(b);
    free(d);
    free(count);
}
int main(int argc, char** argv) {
    char* dest=malloc(10000*sizeof(char));
    char* src=malloc(10000*sizeof(char));
    gets(src);
    csort(src,dest);
    printf("%s",dest);
    free(dest);
    free(src);
    return 0;
}
