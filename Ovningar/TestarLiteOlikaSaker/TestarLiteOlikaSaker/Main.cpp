#include <iostream>

using namespace std;

int main()
{

	decltype

	//double dval;
	//double *pk = &dval; // ok: initializer is the address of a double
	//double *pd2 = pk; // ok: initializer is a pointer to double
	//int *pi = pk; // error: types of pi and pd differ
	//pi = &dval; //

	/*int i, &ri = i;
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;*/

	/*int i = 0, &r1 = i; double d = 0, &r2 = d;
	r2 = 3.14;
	r2 = r1;
	i = r2;
	r1 = d;*/

	/*int i = 20, sum = 0;
	for(int i = 0; i != 10; ++i)
		sum += i;
	cout<<""<<i<<endl<<sum<<endl;*/
	/*unsigned u = 10, u2 = 42;

	cout<< u2 - u<<endl;
	cout<< u - u2<<endl;

	int i = 10, i2 = 42;

	cout<< i2 - i<<endl;
	cout<< i - i2<<endl;

	cout<< i - u<<endl;
	cout<< u - i<<endl;*/

	system("pause");
	return 0;
}