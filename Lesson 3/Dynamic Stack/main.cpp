//имплементация на стек чрез свързан списък
//прочитане на данни от файл, записване в стека и сортиране с вътрешна за стека функция sort()
#include <iostream>
#include <fstream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main() {
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

