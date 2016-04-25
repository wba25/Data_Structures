#include <stdio.h>
#define MAX 100

typedef struct stack{
	int arr[MAX];
	int top;
}stack;

void buildstack(stack *st){
	st->top = -1;
}


int stackempty(stack *st){
	if(st->top==-1) return 1;
	return 0;
}

void push(stack *st, int x){
	if(st->top == MAX-1){
		puts("stack overflow\n");
		return 0;
	}
	st->top++;
	st->arr[st->top] = x;
}

int pop(stack *st){
	if(stackempty(st)){
		puts("stack underflow\n");
		return 0;
	}
	int temp = st->top;
	st->top--;
	return st->arr[temp];
}

int main(){
	stack st;
	int in;
	buildstack(&st);
	while(scanf("%d",&in)&& in != -1){
		push(&st, in);
	}
	while(!stackempty(&st)){
		printf("%d - ",pop(&st));
	}
	return 0;
}
