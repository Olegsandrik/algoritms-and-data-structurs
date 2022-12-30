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
    int N=j+1,i;
    for (i=N-1; i>=1;i--)
        for(j=i-1; j>=0; j--)
            if (compare(b[i],b[j])==-1)
                count[j]++;
            else
                count[i]++;
    for (int i=0; i < N ; i ++){
        d[count[i]] = b[i];
    }
    int k=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<strlen(d[i]);j++){
            dest[k]=d[i][j];
            k++;
        }
        dest[k]=' ';
        k++;
    }
    dest[k-1]='\0';
    for(int i=0;i<N;i++){
        free(d[i]);
    }
    free(b);
    free(d);
}

int main(){
    char* dest=calloc(10000,sizeof(char));
    char* src=calloc(10000,sizeof(char));
    gets(src);
    csort(src,dest);
    printf("%s\n",dest);
    free(dest);
    free(src);
    return 0;
}
