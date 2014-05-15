#include <iostream>
#include <string>

using namespace std;

int main()
{
	//int n = 39;
	//int i = 42;
	//int *pi = &i;
	//*pi = 0;
	//pi = &n;
	//// pi == i; *pi == &i;
	//cout<<*pi<<endl;

	string value = "Värde";
	string anotherValue = "AnnatVärde";
	string *pvalue = &value;
	cout<<pvalue<<endl;

	/*int k = 42;
	int *p1 = &k;
	*p1 = *p1 * *p1;
	cout<<*p1<<endl;*/

	system("pause");
	return 0;

}