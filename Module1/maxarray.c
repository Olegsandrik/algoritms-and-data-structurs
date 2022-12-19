#include <stdio.h>
#include <stdbool.h>
int compare(void *a, void *b){ //функцию писал, чтобы примерно понимать как на каждом из типов данных работает
    if (*(double*)a > *(double*)b){
        return true; // Найден больший, чем б элелемент
    }
    else{
        return false;
    }
}
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    char *max=(char*)base; // указатель на начальный элелемент
    int x=0;
    for (int i=0; i < nel; i++){
        if(compare((void*)(i*width + (char*)base), (void*)max)>0){ // сравнение элементов через указатели на них
            max=(char*)(i*width+(char*)base); // изменение указателя максимума на  указатель большего элемента
            x=i; //итый элемент найден корректно!
        }
    }
    return x; //вернем последний итый элемент, который подошел
}
int main(int argc, char **argv){

}


