#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
int compare (char *a, char *b){
    int ans1=(strlen(a)==strlen(b))? 0: 1;
    int ans2=(strlen(a)>=strlen(b))? 0: 2;
    int ans=ans1-ans2;
    return ans;
}
void csort(char *src, char *dest) {
    char** b = calloc(10000,sizeof(char*));
    char** d = calloc(10000,sizeof(char*));
    int j=-1;
    unsigned long long n=strlen(src);
    bool konecstr=true;
    int counter=0;
    for(int q = 0 ; q < n; q++){
        if(src[q]==' '){
            konecstr=true;
            continue;
        }
        if(konecstr){
            j++;
            b[j]=calloc(10000,sizeof(char));
            counter=0;
            konecstr=false;
        }
        b[j][counter]=src[q];
        counter++;
    }
    int *count=calloc(j+1, sizeof(int));
    int N=j+1;
    int i=N-1;
    while(i>=1){
        int j=i-1;
        while (j>=0){
            if (compare(b[i],b[j])<0){
                count[j]=count[j]+1;
            }
            else{
                count[i]=count[i]+1;
            }
            j--;
        }
        i--;
    }
    int e=0;
    while (e < N){
        d[count[e]] = b[e];
        e++;
    }
    int k=0;
    int s=0;
    while (s<N){
        int j=0;
        while (j<strlen(d[s])){
            dest[k]=d[s][j];
            k++;
            j++;
        }
        dest[k]=' ';
        k++;
        s++;
    }
    free(b);
    free(d);
}
int main(int argc, char **argv){
    char* dest=calloc(10000,sizeof(char));
    char* src=calloc(10000,sizeof(char));
    gets(src);
    csort(src,dest);
    printf("%s\n",dest);
    free(dest);
    free(src);
    return 0;
}
