#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
typedef struct{ long long value, max;}   node;
//Реализация двустороннего стека, где top1 - обычное начало стека, а top2 - с конца стека идет
typedef struct{node* data;long long top1, top2, cap;} doubleStack;
doubleStack initDoubleStack(long long length){
    doubleStack stack;
    stack.data = (node*)calloc(length, sizeof(node));
    stack.cap = length;
    stack.top1 = 0;
    stack.top2 = length - 1;
    return stack;
}
// Реализация функций по презентации, но переделанные под двойной стек
// Например, чтобы стек был полность пуст, надо, чтобы ни в конце, ни в начале стека не было элементов
char stackEmpty1(doubleStack stack){
    return stack.top1 == 0;
}
char stackEmpty2(doubleStack stack){
    return stack.top2 == stack.cap - 1;
}
char doubleStackEmpty(doubleStack stack){
    return stackEmpty1(stack) and stackEmpty2(stack);
}
void push1(doubleStack *stack, long long value){
    node node = stack->data[stack->top1];
    if((stackEmpty1(*stack)!=1)){
        long long prevmax = stack->data[stack->top1 - 1].max;
        if (value > prevmax){
            node.max = value;
        }
        else{
            node.max = prevmax;
        }
    }
    else {
        node.max = value;
    }
    node.value = value;
    stack->data[stack->top1] = node;
    stack->top1++;
}
void push2(doubleStack *stack, long long value){
    node node = stack->data[stack->top2];
    if((stackEmpty2(*stack))!=0){
        long long prevmax = stack->data[stack->top2 + 1].max;
        if(value > prevmax){
            node.max = value;
        }
        else{
            node.max = prevmax;
        }
    }
    else {
        node.max = value;
    }
    node.value = value;
    stack->data[stack->top2] = node;
    stack->top2--;
}
node pop1(doubleStack *stack){
    stack->top1--;
    return stack->data[stack->top1];
}
node pop2(doubleStack *stack){
    stack->top2++;
    return stack->data[stack->top2];
}
// После реализации дефолтных функций для работы с двусторонним стеком начинаем реализацию функций из задачи
void enqueue(doubleStack *stack, long long value){
    push1(stack, value);
}
node dequeue(doubleStack *stack){
    if(stackEmpty2(*stack)){
        while(!stackEmpty1(*stack)){
            push2(stack, pop1(stack).value);
        }
    }
    return pop2(stack);
}
long long max(long long a, long long b){
    if(a <= b){
        return b;
    } else {
        return a;
    }
}
int main(){
    long long n;
    scanf("%lld", &n);
    doubleStack stack = initDoubleStack(100001);
    int i=0;
    while(i < n){
        char command[7];
        scanf("%s", command);
        if(!strcmp("DEQ", command)) {
            printf("%lld\n", dequeue(&stack).value);
            continue;
        }
        else if(!strcmp("MAX", command)) {
            if(stackEmpty2(stack)) {
                printf("%lld\n", stack.data[stack.top1 - 1].max);
                continue;
            }
            if(!stackEmpty1(stack) and !stackEmpty2(stack)) {
                printf("%lld\n", max(stack.data[stack.top1 - 1].max, stack.data[stack.top2 + 1].max));
                continue;
            }
            else {
                printf("%lld\n", stack.data[stack.top2 + 1].max);
                continue;
            }
        }
        else if(!strcmp("ENQ", command)) {
            long long x;
            scanf("%lld", &x);
            enqueue(&stack, x);
            continue;
        }
        else if(!strcmp("EMPTY", command)) {
            if(doubleStackEmpty(stack)) printf("true\n");
            else printf("false\n");
            continue;
        }

        i++;
    }
    free(stack.data);
}
