#include <chrono>  
#include <iostream>
using namespace std;



	void func(int n)
	{
		int a = 1;
		int b = 1;
		int c;
		for (int i = 0; i < n - 2; i++)
		{
			c = b;
			b = a + b;
			a = c;
		}

		cout << b;
	}
	

	int fib(int n)
	{
		if (n < 3)return 1;
		else return  fib(n - 1) + fib(n - 2); 
	}

int main()
{

	int n;
	cin >> n;


	auto start = chrono::steady_clock::now();

	func(n);
	
	//cout << fib(n) << endl;

	auto end = chrono::steady_clock::now();

	  auto diff = end - start;

	  cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;

	  cout << chrono::duration <double, nano>(diff).count() << " ns" << endl;

	  system("pause");
	  return 0;

}