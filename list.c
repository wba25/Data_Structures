#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Globais
struct node{
	int value;
	struct node *next;
}; 

typedef struct node node;

typedef struct node* list;



//Funções de lista
list* buildlist(){
	list* head = (list*) malloc(sizeof(list));
	if(head != NULL) *head = NULL;	
	return head;
}

void destroylist(list* index){
	if(index!=NULL){//Se não é uma lista não inicializada
		node* element;
		while((*index) != NULL){
			element = *index;
			*index = (*index)->next;
			free(element); 
		}
	}
	free(index);
}

int isempty(list* index){
	if(index==NULL) return -1;//lista não iniciad
	if((*index)==NULL) return 1;//lista vazia
	else return 0;//lista com elementos
}

int inserttop(list* index, int value){
	if(index==NULL) return 0;
	node* noob = (node*) malloc(sizeof(node));
	if(noob == NULL) return 0;//Falhou na alocação
	noob->value = value;
	noob->next = (*index);
	*index = noob;
	return 1;
}

int insertend(list* index, int value){
	if(index==NULL) return 0;
			
	node* noob = (node*) malloc(sizeof(node));
	if(noob == NULL) return 0;//Falhou na alocação
	noob->value = value;
	noob->next = NULL;
	if((*index)==NULL){//lista vazia, o fim é o inicio
		*index = noob;
	}
	else{
		node *temp = (*index);		
		while(temp->next!=NULL){
			temp = temp->next;
		}		
		temp->next = noob;
	}
	return 1;
}

int insertordened(list* index, int value){
	if(index==NULL) return 0;
	if((*index)==NULL){
		inserttop(index, value);
	}
	else{			
		node* noob = (node*) malloc(sizeof(node));
		if(noob == NULL) return 0;//Falhou na alocação
		noob->value = value;		
		
		node *actual, *previous = (*index);
		while( (actual!=NULL) && (actual->value<value) ){
			previous = actual;
			actual = actual->next;
		}
		if(actual==(*index) && (actual->value>value)){
			noob->next = *index;
			*index = noob;
		}
		else{
			noob->next = previous->next;
			previous->next = noob;
		}
		//free(actual);
		//free(previous);
	}
	return 1;
}

/*
node* search(node *list, int k){
	node *x = list;
	while(x!=NULL && x->value!=k){
		x = x->next;
	}
	return x;
}

void insert(node *list, int x, int i){
	int j;
	node *novo = (node*) malloc(sizeof(node));
	node->value = x;
	node *temp = list;
	for(j=1; j<i; j++){
		temp = temp->next;
	}	
	novo->next = temp->next;
	temp->next = novo;
}

void delete(node *list, int x){
	node *ant = list;
	node *del;
	while(ant!=NULL && ant->next->value!=k){
		ant = ant->next;
	}
	if(del==NULL){
		return;//tretou
	}
	del = ant->next;
	ant->next = del->next/
	free(del);
}

void printlist(int *list){
	node *x = list;
	while(x!=NULL && x->value!=k){
		x = x->next;
		printf("%d\n",x->value);
	}
}

*/
int main(){
	list* head;
	int size = -1;
	head = buildlist();
	
	if(!isempty(head)) printf("Lista nao vazia\n");
	size+=insertordened(head,10);
	size+=insertordened(head,20);
	
	printf("A lista tem %d elementos\n",(size+1));
	
	destroylist(head);
	return 0;
}

