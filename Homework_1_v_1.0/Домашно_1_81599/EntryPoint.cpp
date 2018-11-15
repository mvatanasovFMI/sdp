#include <iostream>
#include <chrono>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;
using namespace std::chrono;

//Òàçè ôóíêöèÿ ïàçè âðåìåòî çà èçïúëíåíèå íà âñåêè åäèí îò ìåòîäèòå íà êëàñîâåòå;
//ñúñ ñòàðòèðàíåòî íà ïðîãðàìàòà ñúçäàâà ôàéë, â êîéòî òîâà âðåìå ñå çàïèñâà, çàåäíî ñ òîâà çà êîé ìåòîä ñå îòíàñÿ.
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
	/*cout << a;*/ ///òàçè ôóíêöèÿ èçïîëçâà Pop(), çàòîâà å äîáðå äà å çàêîìåíòèðàíà,
	test_file << a;/// àêî âñå ïàê èñêàìå äà ïàçèì íÿêàêâè åëåìåíòè âúâ ôàéëà
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


