#include<iostream>
#include"Fibo.h"

using namespace std;

int main()
{
	Fibo fib;
	int n = 0;
	cout << "Enter the number of terms of Fibonacci series you want" << endl;
	cin >> n;
	
	fib.CalCulateFibo(n);

	int *arr = fib.GetFiboNumbers();
	int *pi;
	pi = arr;
	for (pi; pi != (arr + n); pi++) {
		cout << "First " << *pi << " terms of Fibonacci series are :- " << endl;
	}
	


	system("pause");
	return 0;
}
