include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int cap;
	int top;
	int *data;
};

void InitStack(struct Stack *s, int n)
{
	s->data = (int*)malloc(sizeof(int) * n);
	s->cap = n;
	s->top = 0;
}

int StackEmpty(struct Stack s)
{
	return s.top == 0;
}

void Push(struct Stack *s, int x)
{
	if (s->top == s->cap) printf("Переполнение");
	else
	{
	s->data[s->top] = x;
	s->top++;
	}
}

int Pop(struct Stack *s)
{
	s->top--;
	return s->data[s->top];

}

enum Comands {
    CONST, ADD, SUB, MUL, DIV, MAX, MIN, NEG, DUP, SWAP
};

int GetCMD(char *cmd) {
    char comands[10][6] = {"CONST", "ADD", "SUB", "MUL", "DIV", "MAX", "MIN", "NEG", "DUP", "SWAP"};
    for (int i = 0; i < 10; i++) {
        if (strcmp(cmd, comands[i]) == 0) return i;
    }
    return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	char action[10];
	struct Stack s;
	InitStack(&s, n);
	for(int i = 0; i < n; i++){
		scanf("%s", action);
        enum Comands res = GetCMD(action);

		int a, b, x;
		switch(res){
			case CONST:
				scanf("%d", &x);
				Push(&s, x);
				break;
			case ADD:
				a = Pop(&s);
				b = Pop(&s);
				Push(&s, a + b);
				break;
			case SUB:
				a = Pop(&s);
				b = Pop(&s);
				Push(&s, a - b);
				break;
			case MUL:
				a = Pop(&s);
				b = Pop(&s);
				Push(&s, a * b);
				break;
			case DIV:
				a = Pop(&s);
				b = Pop(&s);
				Push(&s, a / b);
				break;
			case MAX:
				a = Pop(&s);
				b = Pop(&s);
				if(a > b)
					Push(&s, a);
				else
					Push(&s, b);
				break;
			case MIN:
				a = Pop(&s);
				b = Pop(&s);
				if(a < b)
					Push(&s, a);
				else
					Push(&s, b);
				break;
			case NEG:
				a = Pop(&s);
				Push(&s, -a);
				break;
			case DUP:
				a = Pop(&s);
				Push(&s, a);
				Push(&s, a);
				break;
			case SWAP:
				a = Pop(&s);
				b = Pop(&s);
				Push(&s, a);
				Push(&s, b);
				break;
		}
	}
	printf("%i\n", Pop(&s));
	free(s.data);
}
