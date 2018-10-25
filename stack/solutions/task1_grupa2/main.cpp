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

