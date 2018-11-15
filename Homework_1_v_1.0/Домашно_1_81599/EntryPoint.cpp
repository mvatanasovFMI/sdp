#include <iostream>
#include <chrono>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;
using namespace std::chrono;

//Function keeps track of the execution time of each method of the four data structures classes;
//when the program is run, a file with the respective execution times is created, including the name of the class to which it refers.
void ExecutionTime(DataStructure<int>* p, ofstream& file)
{
	auto start = system_clock::now();
	p->Push(3);
	p->Push(4);
	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	file << "Push execution time: " << duration.count() << '\n';

	start = system_clock::now();
	p->Pop();
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	file << "Pop execution time: " << duration.count() << '\n';

	start = system_clock::now();
	p->Top();
	 end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	file << "Top execution time: " << duration.count() << '\n';

	 start = system_clock::now();
	p->IsEmpty();
	 end = system_clock::now();
	 duration = duration_cast<nanoseconds>(end - start);
	file << "IsEmpty execution time: " << duration.count() << '\n';

	 start = system_clock::now();
	p->IsFull();
	 end = system_clock::now();
	 duration = duration_cast<nanoseconds>(end - start);
	file << "IsFull execution time: " << duration.count() << '\n';
 
	start = system_clock::now();
	p->Length();
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	file << "Lenght execution time: " << duration.count() << '\n';

	file << '\n';
	file.close();
}


int main()
{
	ofstream file;
	ofstream test_file;

	file.open("execution_time.txt", ios::app);
	test_file.open("stack_and_queue_data.txt", ios::app);
	ArrayStack<int> a;
	cin >> a;
	/*cout << a;*/ //operator overloading contains pop function; in order to actually write something to a file
	test_file << a;/// we should not cout the stack;
	DataStructure<int>* pa = &a;
	file << "Array stack: \n";
	ExecutionTime(pa, file);
	test_file.close();

	file.open("execution_time.txt", ios::app);
	test_file.open("stack_and_queue_data.txt", ios::app);
	LinkedStack<int> b;
	cin >> b;
	/*cout << b;*/
	test_file << b;
	DataStructure<int>* pb = &b;
	file << "Linked stack: \n";
	ExecutionTime(pb, file);
	test_file.close();

	file.open("execution_time.txt", ios::app);
	test_file.open("stack_and_queue_data.txt", ios::app);
	ArrayQueue<int> c;
	cin >> c;
	/*cout << c;*/
	test_file << c;
	DataStructure<int>* pc = &c;
	file << "Array queue: \n";
	ExecutionTime(pc, file);
	test_file.close();

	file.open("execution_time.txt", ios::app);
	test_file.open("stack_and_queue_data.txt", ios::app);
	LinkedQueue<int> d;
	cin >> d;
	/*cout << d;*/
	test_file << d;
	DataStructure<int>* pd = &d;
	file << "Linked queue: \n";
	ExecutionTime(pd, file);
	test_file.close();

	
	return 0;
}


