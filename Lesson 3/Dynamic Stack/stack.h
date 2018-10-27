#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

template <typename T>
struct node {
    
  T data;
  node<T>* next;   
  
};

template <typename T>
class Stack {
    
       node<T>* top;
       void deleteStack();
       void copyStack(const Stack<T>&);
        
    public:
        Stack(); 
        Stack(const Stack<T> &);                //Copy constructor...
        Stack& operator= (const Stack<T> &);    //Copy assignment operator...
        ~Stack();
        
        void push(T const&); 
        void pop(T&); 
        bool empty() const; 
        T peek();
        void print();
        void insert(T);
        void sort();
};

#endif
