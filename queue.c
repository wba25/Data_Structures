#include <stdio.h>
#define MAX 100

typedef struct queue{
	int arr[MAX];
	int head;
	int tail;
}queue;

int emptyqueue(queue *q){
	if(q->tail == q->head) return 1;
	return 0;
}

void buildqueue(queue *q){
	q->head = 0;
	q->tail = 0;
}

void enqueue(queue *q, int x){
	q->arr[q->tail] = x;
	q->tail++;
}

int dequeue(queue *q){
	int temp = q->arr[q->head] ;
	q->head++;
	return temp;
}

int main(){
	queue q;
	int in;
	buildqueue(&q);
	while(scanf("%d",&in)&& in != -1){
		enqueue(&q, in);
	}
	while(!emptyqueue(&q)){
		printf("%d - ",dequeue(&q));
	}
	return 0;
}
