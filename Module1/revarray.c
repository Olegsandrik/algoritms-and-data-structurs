#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void revarray(void *base, unsigned long long nel, unsigned long long width){
    for (int j=nel-1; j>=(nel/2); j--){ // бежим вниз по массиву до половинки, чтобы все спапать как адский спавальшик
        void *tmp;
        tmp = calloc( 1, sizeof(width)); // Ну получается, мусор для свапа в массиве, получается, который объявлен нуликом :-)
        memmove(tmp, (j * width + (char*)base), (width)); //Засунул в мусор элемент из массива
        memmove(((j * width + (char*)base)), ((nel-j-1)*width + (char*)base), (width)); //свапнул элемент с конца на элемент начала
        memmove(((nel-j-1)*width + (char*)base), tmp, width); //свапнул элемент с начала и мусор
        free(tmp);
    }
}
int main(int argc, char **argv) {
    char arr[] = "Hello, Aleksandr Vladimirivich!";
    printf("Test na char'ax\n");
    for (int i = 0; i < 33; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    revarray(arr, 33, sizeof(char));
    for (int i = 2; i < 33; i++) {
        printf("%c", arr[i]);
    }
    printf("\nTest na int'ax\n");
    int arr1[7] = {0, 1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 7; i++) {
        printf("%d", arr1[i]);
    }
    printf("\n");
    revarray(arr1, 7, sizeof(int));
    for (int i = 0; i < 7; i++) {
        printf("%d", arr1[i]);
    }
    return 0;
}    
