#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/// lagra heltalen i vektorn och skriv därefter ut dessa.
	/*vector<int> store;
	int input;
	while(cin>>input)
	{
		store.push_back(input);
		for(int i = 0; i < store.size(); ++i)
		{
			cout<<store[i]<<endl;
		}
	}*/

	/// lagra text strängarna i vektorn och skriv därefter ut dessa.
	/*vector<string> store;
	string str;
	while(cin>>str)
	{
		store.push_back(str);
		for(int i = 0; i < store.size(); ++i)
		{
			cout<<store[i]<<endl;
		}
	}*/
	
	//// count the number of grades by clusters of ten: 0--9, 10--19, . .. 90--99, 100
	//vector<unsigned> scores(11, 0);
	//unsigned grade;
	//while(cin>>grade)
	//{
	//	if(grade <= 100)
	//	{
	//		++scores[grade/10];
	//	}
	//	
	//}

	//vector<string>store;
	//string str;
	//while(cin>>str)
	//{
	//	for(auto &character : str)
	//	{
	//		character = toupper(character); // character är en referens.
	//	}
	//	store.push_back(str);
	//	cout<<str<<endl;
	//}

	//// Makes the first letter in the string to a uppercase.
	//string s("some string");
	//// make sure s is not empty
	//if (s.begin() != s.end())
	//{ 
	//	auto it = s.begin(); // it denotes the first character in s
	//	*it = toupper(*it);// make that character uppercase
	//	cout<<s<<endl;
	//}

	/*vector<int> v;
	for (int i = 1; i < 10; ++i)
	{
		v.push_back(i);
		cout<<i<<endl;
	}*/

	

	system("pause");
	return 0;
}