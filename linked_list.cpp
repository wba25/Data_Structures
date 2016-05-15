#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node{
	T value;
	Node<T>* next;
	public:
		
		Node(){}
		
		Node(T value, Node<T>* next){
			this->setValue(value);
			this->setNext(next);
		}
		
		Node<T>* getNext(){
			return this->next;
		}
		
		void setNext(Node<T>* next){
			this->next = next;
		}
		
		int getValue(){
			return this->value;
		}
		
		void setValue(T value){
			this->value = value;
		}
		
};

template <class T>
class Linked_list{
	int size;
	public:
		Node<T>* create_list();
		bool is_empty(Node<T>* head);
		void add_end(Node<T>* head, T value);
		void remove(Node<T>* head, T value);
		void print_list(Node<T>* head);
		int getSize();
};

template <class T>
Node<T>* Linked_list<T>::create_list(){
	Node<T>* head = new Node<T>; 
	head->setNext(NULL);
	this->size = 0;
	return head;
}

template <class T>
bool Linked_list<T>::is_empty(Node<T>* head){
	if(head->getNext()==NULL) return true;
	return false;
}

template <class T>
void Linked_list<T>::add_end(Node<T>* head, T value){
	Node<T>* new_node = new  Node<T>;
	
	new_node->setNext(NULL);
	new_node->setValue(value);
	
	if(this->is_empty(head)){
		head->setNext(new_node);
	}
	else{	
		Node<T>* temp = head->getNext();
		for(int i = 1; i < this->size; i++ ){
			temp = temp->getNext();
		}
		temp->setNext(new_node);
	}
	this->size++;
}

template <class T>
void Linked_list<T>::print_list(Node<T>* head){
	if(this->is_empty(head)) cout << "Lista vazia!" << endl;
	else{
		Node<T>* temp = head->getNext();
		for(int i=0; i<this->size;i++){
			cout << i+1 << " - " << temp->getValue() << endl;
			temp = temp->getNext();
		}
	}
}

int main(){
	Linked_list<int> list;
	Node<int>* head = list.create_list();
	/*
	list.add_end(head,10);
	list.add_end(head,20);
	list.add_end(head,30);
	list.add_end(head,40);
	*/
	list.print_list(head);
	
	return 0;
}
