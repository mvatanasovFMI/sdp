#include "stdafx.h"
#include "StaticStack.h"

#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int main() {
	ifstream file("data.txt");
	
	stack<char> standardStack;
	char tmp;
	while (file.get(tmp)) {
		standardStack.push(tmp);
	}

	while (!standardStack.empty()) {
		cout << standardStack.top();
		standardStack.pop();
	}

	file.close();

	// A better idea would be to move the get pointer to the beginning, but yolo.
	ifstream newFile("data.txt");

	StaticStack<char> customStack;
	while (newFile.get(tmp)) {
		customStack.push(tmp);
	}

	while (!customStack.empty()) {
		cout << customStack.pop();
	}

	newFile.close();
    return 0;
}

