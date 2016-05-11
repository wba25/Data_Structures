#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node node;
typedef struct node* root;

root* buildtree(){
	root* temp = (root*) malloc(sizeof(root));
	if(temp!=NULL){
		*temp = NULL;
	}
	return temp;
}

int search(root* root, int value){
	while(*root != NULL){
		if((*root)->data == value){
			return 1;
		}
		else if((*root)->data < value){
			*root = (*root)->right;
		}
		else{
			*root = (*root)->left;
		}
	}
	//Caso não encontre
	return 0;
}

int insert(root* root, int newvalue){
	if(root==NULL) return 0;
	
	node* newnode = (node*) malloc(sizeof(node));
	if(newnode == NULL) return 0;
	
	newnode->data = newvalue;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if((*root)==NULL){
		*root = newnode;
		return 1;
	}
	
	node* temp = *root;
	node* last = NULL;
	while(temp != NULL){
		last = temp;
		if(temp->data == newnode->data){
			//já existe
			free(newnode);
			return 0;
		}
		else if(temp->data < newnode->data){
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	
	if(newnode->data > last->data){
		last->right = newnode;
	}
	else{
		last->left = newnode;
	}
	return 1;
}

node* removeactual(node* select){
	node* substitute = NULL;
	node* last = NULL;
	//Caso seja folha ou só tenha um filho
	if(select->left == NULL){
		substitute = select->right;
		free(select);
	}
	else if(select->right == NULL){
		substitute = select->left;
		free(select);		
	}
	//Caso tenha dois filhos
	else{
		//Busca-se o filho mais a direita do filho a esquerda
		last = select;
		substitute = select->left;
		while(substitute->right != NULL){
			last = substitute;
			substitute = substitute->right;
		}
		if(last!=select){
			last->right = substitute->left;
			substitute->left = select->left;
		}
		substitute->right = select->right;				
		
		free(select);		
	}
	return substitute;
}

int remove(root* root, int del){
	node* last = NULL;
	node* temp = *root;
	//busca
	while(temp != NULL){
		if(temp->data == del){
			if(last == NULL){//Remove na raiz
				temp = removeactual(temp);
			}
			else if(last->right == temp){
				last->right = removeactual(temp);
			}
			else{
				last->left = removeactual(temp); 
			}
		}
		last = temp;
		if(temp->data < del){
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	//Caso seja uma arvore vazia
	return 0;
}

//imprime

void inorder(root* root){
	if((*root) != NULL){
		inorder(&((*root)->left));
		printf("%d\n",(*root)->data);
		inorder(&((*root)->right));
	}
}

void preordem(root* root){
	if(root == NULL) return;
	if(*root != NULL){
		printf("%d    ",(*root)->data);
		preordem(&((*root)->left));
		preordem(&((*root)->right));
	}
}

/*
void inorder(node* root){
	if(!root) return;
	
	inorder(root->left);
	if(root->data) printf("%d ",root->data);
	inorder(root->right);
}
*/

int main(){
	root* root = buildtree();
	insert(root, 10);
	insert(root, 30);
	insert(root, 4);
	insert(root, 70);
	insert(root, 2);
	insert(root, 7);
	insert(root, 80);
	puts("Pre-ordem: ");
	preordem(root);	
	puts("\n");
	remove(root, 10);
	puts("Pre-ordem: ");
	preordem(root);	
	puts("\n");
	//printf("%d\n",root->data);
	return 0;
}






