//имплементация на стек чрез масив
//прочитане на данни от файл, записване в стека и сортиране с вътрешна за стека функция sort()
#include <iostream>
#include <fstream>
using namespace std;

int size() {
    ifstream file("stackData.txt");
    if(!file){
        cerr << "Problem with file!" << endl;
    }
    
    int count;
    double number;
    while(file >> number) {
        count++;
    }
    file.close();
    return count;
}

template <typename T>
class Stack {
        int top;
        T* arr = new T[size()];
        
    public:
        Stack<T> () { this->top = -1;}
        
        void push(T element) {
             if(!full()){
                 top++;
                 arr[top] = element;
             }
             else {
                 cout <<"Stack is full!"<<endl;
                 exit(1);
             }
        }
        void pop(T& element) {
            if (!empty()) {
                element = arr[top];
                top--;
            } 
                
            else {
                cout << "The stack is empty." << endl;
                exit(1);
            }
        }
        bool empty() const {    return this->top == -1; } 
        bool full() const { return this->top == size() - 1; } 
        void peek(T& element){
            this->pop(element);
            this->push(element);
        }
        
        void sort() {
            if (!empty()) {
                T element; 
                this->pop(element);
                this->sort();
                this->insert(element);
            }
        }

        void insert(T x) {
            if (!empty()) {  
                T y; this->peek(y);
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
        
        void print() {
            while(!empty()){
                T element; this->pop(element);
                cout << element << endl;
            }
        }
};



int main()
{
    Stack<double> a;
    
    ifstream file("stackData.txt");
    if(!file){
        cerr << "Problem with file!" << endl;
    }
    
    double number;
    while(file >> number) {
        a.push(number);
    }
    
    a.sort();
    a.print();
    
    file.close();
	return 0;
}

