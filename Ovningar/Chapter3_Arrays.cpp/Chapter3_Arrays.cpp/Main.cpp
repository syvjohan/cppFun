#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

//int Hej()
//{
//	return 5;
//}


int main()
{
	#pragma warning(disable: 4996)
	//int /*const*/ buf = 1024;
	//int ia[buf];
	//int ib[4 * 6 -7];
	//int ic[Hej()];
	//char st[11] = "nisse";

	//// cout each int in the array.
	//int arr[9] = {1,2,3,4,5,6,7,8,9};
	//for(auto a : arr)
	//{
	//	cout<<a;
	//}

	//// itererar igenom arrayn och sätter dess element till 0.
	//int arr[5] = {1,2,3,4,5}; // skapar arrayn
	//int *parr;
	//parr = arr;
	//for(int n = 0; n < arr[n]; ++n)
	//{
	//	*parr = 0;	
	//	++parr;
	//	cout<<arr[n]<<endl;
	//}

	//// Compare two arrays.
	//int arr1[5] = {1,2,3,4,5};
	//int arr2[5] = {1,2,3,4,5};

	//for(int i = 0; i < 5; i++)
	//{
	//	arr1[i] = arr2[i];
	//}
	

	//// Compare two vectors.
	//vector<int> v1(100);
	//vector<int> v2(10);
	//
	

	/*vector<int> v1;
	for (int i = 1; i < 10; ++i)
	{
		v1.push_back(i);
		cout<<i<<endl;
	}

	vector<int> v2;
	for (int i = 11; i < 20; ++i)
	{
		v2.push_back(i);
		cout<<i<<endl;
	}*/

	//// Compare two strings.
	//string s1 = "hej";
	//string s2 = "hej";
	//if(s1.compare(s2) == 0) 
	//{
	//	cout<<"match"<<endl;
	//}
	//else
	//{
	//	cout<<"no match"<<endl;
	//}
	
	//Compare strings C-style
	char c1[10];
	char c2[10];
	int compareLimit = 100;
	int result;

	scanf_s("%s", &c1[10]);
	scanf_s("%s", &c2[10]);
	result = strncmp(c1, c2, compareLimit);

	if(result > 0)
	{
		printf("c1 > c2\n");
	}
	else if(result < 0)
	{
		printf("c2 > c1\n");
	}
	else
	{
		printf("c1 = c2\n");
	}
	getchar(); // makes the program wait for an key to be pressed before closing.
	
	//// c-style sammanfogar två text strängar.
	//char c1[10] = "hej";
	//char c2[10] = "då";
	//char collect[100] = "Collect";
	// strcpy(collect, c1); // concatenates.
	// strcat(collect, " "); // adds a space at the end
	// strcat(collect, c2);

	// cout<<collect<<endl;

	//// Store an array into another array.
	//int array1[] =  { 1, 2, 3, 4, 5, 6, 7 };
	//int array2[8];
	//for (int i = 0; i < 8; ++i)
	//{
	//	array2[i] = array1[i];
	//}

	////Kopiera en array in i en annan array
	//memcpy(array2, array1, sizeof(int) * 8);
	
	system("PAUSE");
	return 0;
}