
#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node<T>* next;
};

template <class T>
class LinkedStack{
	node<T> *top;

	public:
	//function prototypes
		LinkedStack();
		bool isEmpty();
		void push(T&);
		T pop();
		T peek();
		void destroylist();

		~LinkedStack();
};

//function implementations

//constructor
template <class T>
LinkedStack<T>::LinkedStack(){
	top = NULL;
}

//check the stack for empty-condition
template <class T>
bool LinkedStack<T>::isEmpty(){
	return top == NULL;
}

//add to the stack
template <class T>
void LinkedStack<T>::push(T& item){
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = top;
	top = newnode;
}

//remove from the stack and return value
template <class T>
T LinkedStack<T>::pop(){
	node<T> *tempnode = top;
	T data = tempnode->data;
	top = top->next;
	delete tempnode;
	return data;
}

//check the current element in the stack and return value
template <class T>
T LinkedStack<T>::peek(){
	return top->data;
}


template <class T>
void LinkedStack<T>::destroylist(){
	node<T> *tempnode;
	while(top != NULL){
		tempnode = top;
		top = top->next;
		delete tempnode;
	}
}

//destructor
template <class T>
LinkedStack<T>::~LinkedStack(){
	destroylist();
}



#endif /* LINKEDSTACK_H_ */
