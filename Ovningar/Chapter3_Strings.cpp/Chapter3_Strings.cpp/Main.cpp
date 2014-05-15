#include <iostream>
#include <string>

using namespace std;

int main()
{
	//// skriver ut 100 c.
	//string string(100, 'c');
	//cout<<string<<endl;
	//cout<<string.size()<<endl; // skriver ut antalet char i string.

	//// skriver ut alla karaktärer användaren skriver in
	//string word;
	//while(cin>>word)
	//{
	//	cout<<word<<endl;
	//}

	//// skriver även ut mellanslag.
	//string line;
	//while(getline(cin, line))
	//{
	//	cout<<line<<endl;
	//}

	//// om den inmatade texten innehåller fler än 80 karaktärer.
	//string line;
	//while(getline(cin, line))
	//	if(line.size() > 80)
	//		cout<<line<<endl;

	/*string line;
	while(getline(cin, line))
	{
		cout<<line<<endl;
	}*/

	/*string word;
	while(cin>>word)
	{
		cout<<word<<endl;
	}*/

	//// jämnför s1 och s2.
	//string s1;
	//string s2;
	//cin>>s1>>s2; // retunerar cin.
	//if(s1 == s2)
	//{
	//	cout<<"lika stora"<<endl;
	//}
	//else if(s1 < s2)
	//{
	//	cout<<"S2 är större"<<endl;
	//}
	//else if(s1 > s2)
	//{
	//	cout<<"S1 är större"<<endl;
	//}

	//// läser in 2 strängar sätter ihop dem i en gemensam variabel och delar på dem med
	//// ett mellanslag.
	//string s1;
	//string s2;
	//string largeString;
	//cin>>s1>>s2;
	//largeString = s1 +" "+ s2;

	//cout<<largeString<<endl;

	////range for, skriver ut varje karaktär på en egen rad.
	//string str("some string");
	//for (auto character : str)
	//	cout<<character<<endl;

	//// Räknar punkterna i hello world.
	//string s(".He..llo Wo.rld...");
	//decltype(s.size()) counter = 0;
	//for(auto character : s)
	//	if(ispunct(character))
	//		++counter;
	//cout<<counter
	//	<<": punctation character in "<<s<<endl;

	//// Gör om karaktärerna i stringen till stora bokstäver.
	//string str("hello johan");
	//for(auto &character : str)
	//	character = toupper(character); // character är en referens.

	//cout<<str<<endl;

	 //ändra en liten bokstav till stor.
	//string str("some random string");
	//if(!str.empty())
	//	str[0] = toupper(str[0]); // Ändra första nollan för att ändra vilken bokstav som ska toupper.

	//cout<<str<<endl;

	////ändra ett ord till stora bokstäver.
	//string str("some very random string");
	//for(decltype(str.size()) index = 0;
	//	index != str.size() && !isspace(str[index]); ++index)
	//	str[index] = toupper(str[index]);
	//
	//cout<<str<<endl;

	/*const string hexdigits = "0123456789ABCDEF";
	cout<<"Enter a series of numbers between 0-15 "
		<<"Separated by space, hit ENTER when finished: "
		<<endl;

	string  result;
	string::size_type input;
	while(cin >> input)
		if(input < hexdigits.size())
			result += hexdigits[input];
	cout<<"Your hex number is: "<<result<<endl;*/

	// //för varje tecken som skrivs in byts den ut mot ett x.
	//string input;
	//cin>>input;
	//for(auto character : input)
	//{
	//	character = 'X';
	//	cout<<character<<endl;
	//}
	
	//// För varje tecken som skrivs byts den ut mot ett x.
	//string s;
	//cin>>s;
	//for(int i = 0; i < s.length();++i)
	//{
	//	s[i] = 'X';
	//}
	//cout<<s<<endl;
	
	/*string str;
	getline(cin, str);
	for(auto&c : str)
	{
		cout<<str<<endl;
	}*/

	/*cout<<"Write a string"<<endl;
	string str;
	cin>>str;
	for(auto c : str)
	{
		if(ispunct(c))
		{
			c = ' ';
		}
		cout<<c<<endl;
	}*/

	system("pause");
	return 0;
}