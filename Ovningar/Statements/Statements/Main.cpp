#include <iostream>

using namespace std;

void WhileLoop()
{
	int startNumber = 50;
	int sum = 0;

	while(startNumber <= 100)
	{
		sum = sum + startNumber;
		++startNumber;
		cout<<"The sum is: "<<sum<<endl;
	}
	

	cout<<"----------------------------------------------------"<<endl;
	int lownumber = 1;
	int lownumber2 = 10;

	while( lownumber <= lownumber2)
	{
		lownumber++;
		cout<<lownumber<<endl;
	}
}

void ForLoop()
{
	//sum from -100 to 100
	int sum = 0;
	for(int val = -100; val <= 100; ++val)
	{
		sum = sum + val;
		cout<<sum<<endl<<endl;
	}

	cout<<"----------------------------------------------------"<<endl;
	//sum from 50 to 100
	int number = 0;
	for(int i = 50; i <= 100; ++i)
	{
		number = number + i;
		cout<<number<<endl;
	}

	cout<<"----------------------------------------------------"<<endl;
	//sum from 10 to 0,
	int lownumber = 0;
	for( int i = 10; i >= 0; --i)
	{
		lownumber = lownumber + i;
		cout<<lownumber<<endl;
	}

	cout<<"----------------------------------------------------"<<endl;
	// counting down from 10 to 0
	for(int i = 10; i >= 0; --i)
	{
		cout<<i<<endl;
	}

	cout<<"----------------------------------------------------"<<endl;
	//counting upp from 0 to 10
	for(int i = 0; i <= 10; ++i)
	{
		cout<<i<<endl;
	}
}

void InputCin()
{
	//calculate(+) input.
	int number = 0;
	int number2 = 0;

	while(cin>>number)
	{
		number2 = number2 + number;
		cout<<"The sum is: "<<number2<<endl;
	}
}

void IfState()
{
	int currval = 0;
	int val = 0;

	if(cin>>currval)
	{
		int cnt = 1;
		while(cin>>val)
		{
			if(val == currval)
			{
				++cnt;
			}
			else
			{
				cout<<currval<<"occurs"
					<<cnt<<"times"<<endl;
				currval = val;
				cnt = 1;
			}
		}
		cout<<currval<<"occurs"
			<<cnt<<"times"<<endl;
	}
}

int main()
{
	ForLoop();
	//WhileLoop();
	//InputCin();
	/*IfState();*/

	system("pause");
	return 0;
}

