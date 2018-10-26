#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int NUM=100;
class Stack {
public:
    Stack();
    char top ();
    void pop ();
    void push (char);
    void push (char*);
    bool empty ();
    void print ();
private:
    char a[NUM];
    int len;
};
Stack::Stack () {
    len=0;
}
char Stack::top () {
    return a[len-1];
}
void Stack::pop () {
    len--;
}
void Stack::push (char num) {
    a[len++]=num;
}
void Stack::push (char* word) {
    int n=strlen(word),i;
    for (i=0; i<n; i++) {
        push(word[i]);
        }
}
bool Stack::empty () {
    if (len==0) return true;
    return false;
}
void Stack::print () {
    while (!empty()) {
          cout << top() ;
          pop();
          }
    cout << " ";
}
int main () {
    fstream myfile ("text.txt",ios_base::in);
    Stack s,temp;
    char a[100];
    int n,min1;
    while (myfile >> a) {
          s.push(a);
          s.print();
          }
    cout << endl ;
    return 0;
}
