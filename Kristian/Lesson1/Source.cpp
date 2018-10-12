#include<iostream>
#include<chrono>
#include<ctime>
#pragma warning(disable:4996)

using namespace std;
long Fib(long count)
{
	
	if (count == 1)return 0;
	if (count == 2)return 1;
	return Fib(count -2)+ Fib(count - 1);
}
long FibonachiIter(long count)
{
	if (count == 1)return 0;
	if (count == 2)return 1;
	int*array = new int[count];
	array[0] = 0;
	array[1] = 1;

	for (int i = 2; i <count; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
	return array[count-1];
}
int main()
{
	long broi;
	cin >> broi;
	chrono::time_point<chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	cout << "fib = " << Fib(broi) << '\n';
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);
	cout << "finished computation at " << ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	system("pause");

}
