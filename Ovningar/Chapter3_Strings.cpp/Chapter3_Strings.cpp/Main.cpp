#include <iostream>
#include <string>

using namespace std;

int main()
{
	//// skriver ut 100 c.
	//string string(100, 'c');
	//cout<<string<<endl;
	//cout<<string.size()<<endl; // skriver ut antalet char i string.

	//// skriver ut alla karakt�rer anv�ndaren skriver in
	//string word;
	//while(cin>>word)
	//{
	//	cout<<word<<endl;
	//}

	//// skriver �ven ut mellanslag.
	//string line;
	//while(getline(cin, line))
	//{
	//	cout<<line<<endl;
	//}

	//// om den inmatade texten inneh�ller fler �n 80 karakt�rer.
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

	//// j�mnf�r s1 och s2.
	//string s1;
	//string s2;
	//cin>>s1>>s2; // retunerar cin.
	//if(s1 == s2)
	//{
	//	cout<<"lika stora"<<endl;
	//}
	//else if(s1 < s2)
	//{
	//	cout<<"S2 �r st�rre"<<endl;
	//}
	//else if(s1 > s2)
	//{
	//	cout<<"S1 �r st�rre"<<endl;
	//}

	//// l�ser in 2 str�ngar s�tter ihop dem i en gemensam variabel och delar p� dem med
	//// ett mellanslag.
	//string s1;
	//string s2;
	//string largeString;
	//cin>>s1>>s2;
	//largeString = s1 +" "+ s2;

	//cout<<largeString<<endl;

	////range for, skriver ut varje karakt�r p� en egen rad.
	//string str("some string");
	//for (auto character : str)
	//	cout<<character<<endl;

	//// R�knar punkterna i hello world.
	//string s(".He..llo Wo.rld...");
	//decltype(s.size()) counter = 0;
	//for(auto character : s)
	//	if(ispunct(character))
	//		++counter;
	//cout<<counter
	//	<<": punctation character in "<<s<<endl;

	//// G�r om karakt�rerna i stringen till stora bokst�ver.
	//string str("hello johan");
	//for(auto &character : str)
	//	character = toupper(character); // character �r en referens.

	//cout<<str<<endl;

	 //�ndra en liten bokstav till stor.
	//string str("some random string");
	//if(!str.empty())
	//	str[0] = toupper(str[0]); // �ndra f�rsta nollan f�r att �ndra vilken bokstav som ska toupper.

	//cout<<str<<endl;

	////�ndra ett ord till stora bokst�ver.
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

	// //f�r varje tecken som skrivs in byts den ut mot ett x.
	//string input;
	//cin>>input;
	//for(auto character : input)
	//{
	//	character = 'X';
	//	cout<<character<<endl;
	//}
	
	//// F�r varje tecken som skrivs byts den ut mot ett x.
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