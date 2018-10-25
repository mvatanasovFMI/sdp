#include "stack.h"
#include <cassert>

template <typename T>
void Stack<T>::deleteStack() {
    node<T> *t;     //t as temporarily
    while(top != nullptr) {
        t = top;
        top = top->next;
        delete t;
    }
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& basic_stack){
    
    if(basic_stack.top != nullptr) {
        node<T> *i = basic_stack.top, *t = nullptr, *n = nullptr; 
            //i as index for next cell in linked list
            //t as temporarily 
            //n as new cell in linked list on new stack 
        top = new node<T>;
        assert(top != nullptr);
        top->data = i->data;
        top->next = t;
        t = top;
        i = i->next;
        while(i != nullptr) {
            n = new node<T>;
            assert(n != nullptr);
            n->data = i->data;
            t->next = n;
            t = n;
            i = i->next;
        }
        t->next = nullptr;
    }
    
    else {
        top = nullptr;
    }
    
}

template <typename T>
Stack<T>::Stack () {
    
    //cout << "\nDefault constructor\n";
    top = nullptr;

}

template <typename T>
Stack<T>::Stack(Stack<T> const& new_stack) {
    
    //cout << "\nCopy costructor\n";  
    copyStack(new_stack);
	
}

template <typename T>
Stack<T> & Stack<T>::operator= (const Stack<T> & basic_stack) {
    
	//cout << "\nCopy assignment operator\n";
	if (this != &basic_stack) {
        deleteStack();
        copyStack(basic_stack);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() {
    deleteStack();
}

template <typename T>
void Stack<T>::push(const T& new_data) {
    
   node<T> *t = top;   
   top = new node<T>;
   assert(top != nullptr);
   top->data = new_data;
   top->next = t ;
   
}

template <typename T>
void Stack<T>::pop(T& old_data) {
    
    if(top != nullptr) {
        old_data = top->data;
        node<T>* t = top;
        top = top->next;
        delete t;
    }
    
    else {
        cout << "\nThe stack is empty\n";
    }
    
}

template <typename T>
bool Stack<T>::empty() const {
    return top == nullptr;
}

template <typename T>
T Stack<T>::peek() {
    return top->data;
}

template <typename T>
void Stack<T>::print() {
    
    while(top != nullptr){
        cout << top->data << endl;
        top = top->next; 
    }
 
    /* int x;
    while(empty() != 0) {
        pop(x);
        cout << x << " ";
    }*/
    
    cout<< endl;
    
}

template <typename T>
void Stack<T>::sort() {
    if (!empty()) {
        T element; 
        this->pop(element);
        this->sort();
        this->insert(element);
    }
}

template <typename T>
void Stack<T>::insert(T x) {
    if (!empty()) {  
        T y = this->peek();
        if (x < y) {
            T z; this->pop(z);
            this->insert(x);
            this->push(y);
        } 
        else {
            this->push(x);
        }
    } 
    else {
        this->push(x); 
    }
}
