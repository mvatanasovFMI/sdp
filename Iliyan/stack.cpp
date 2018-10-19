#include<iostream>
#include<fstream>
using namespace std;
const int NUM=100;
class Stack {
public:
    Stack();
    float top ();
    void pop ();
    void push (float);
    bool empty ();
    void sort ();
private:
    float a[NUM];
    int len;
};
Stack::Stack () {
    len=0;
}
float Stack::top () {
    return a[len-1];
}
void Stack::pop () {
    len--;
}
void Stack::push (float num) {
    a[len++]=num;
}
bool Stack::empty () {
    if (len==0) return true;
    return false;
}
void Stack::sort () {
     int i,j,fl,old;
     float min1;
     Stack temp;
     for (i=0; i<len-1; i++) {
         min1=top();
         old=len;
         for (j=1; j<=old-i; j++) {
             min1=min(min1,top());
             temp.push(top());
             pop();
             }
         push(min1);
         fl=0;
         for (j=1; j<=old-i; j++) {
             if (temp.top()==min1) {
                if (fl==1) push(temp.top());
                fl++;
                }
             else push(temp.top());
             temp.pop();
             }
         }
}
int main () {
    fstream myfile ("stackData.txt",ios_base::in);
    Stack s,temp;
    float a;
    int n,min1;
    while (myfile >> a) {
          s.push(a);
          }
    s.sort();
    for (;;) {
        if (s.empty()==1) break;
        cout << s.top() << " ";
        s.pop();
        }
    cout << endl ;
    return 0;
}
