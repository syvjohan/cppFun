#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	//int sum = 0, val = 1;
	//// keep executing the while as long as val is less than or equal to 10
	//while (val <= 10,(sum += val), ++val, cout<< "Sum of 1 to 10 inclusive is "<<sum<<endl) 

	/*string s = "hej";
	string::iterator iter;
	while( iter != s.end()) {}*/

	//string word = "hej";
	//bool status = false;
	//while (status = word.find("h")) { /* . . . */ }
	//if (!status) { /* . . . */ }


	////Generate letter grade from a numeric grade.
	//
	//const char *c[] = {"F", "D", "C", "B", "A", "A++"};
	//vector<string>scores(c, end(c));
	//string lettergrade;
	//int grade = 0;

	//if(grade < 60)
	//{
	//	lettergrade = scores[0];
	//} 
	//else
	//{
	//	lettergrade = scores[(grade - 50)/10];
	//}
	//cout<<lettergrade<<endl;

	////Switch Count vowels amd more
	////5.9
	//char sentence;
	//int countLetters = 0;
	//int countS = 0;
	//int countString = 0;

	//cout<<"enter a sentence: "<<endl;
	//cin.get(sentence);

	//cout<<"Vowels, strings and other characters: ";
	//while(sentence != '\n')
	//{
	//	cin.get(sentence);
	//	switch (toupper(sentence))
	//	{
	//		case 'A': cout<<sentence<< ", ";
	//			countLetters ++;
	//			break;
	//		case 'E': cout<<sentence<< ", ";
	//			countLetters ++;
	//			break;
	//		case 'I': cout<<sentence<< ", ";
	//			countLetters ++;
	//			break;
	//		case 'O': cout<<sentence<< ", ";
	//			countLetters ++;
	//			break;
	//		case 'U': cout<<sentence<< ", ";
	//			countLetters ++;
	//			break;
	//	}
	//	switch (sentence)
	//	{
	//		case ' ': cout<<sentence<< ", ";
	//			countS++;
	//			break;
	//		case '\t': cout<<sentence<< ", ";
	//			countS++;
	//			break;
	//		case '\n': cout<<sentence<< ", ";
	//			countS++;
	//			break;
	//	}

	//	if (sentence == 'ff'|| 'fi' || 'fl')
	//	{
	//		countString++;
	//	}
	//}
	//cout<<"\n\nThere where a total of "<<countLetters<<" vowels in your sentence.\n";
	//cout<<"\n\nThere where a total of "<<countS<<" other characters in your sentence.\n";
	//cout<<"\n\nThere where a total of "<<countString / 2<<" strings in your sentence.\n\n";
	
	///// 5.14 Duplicated words

	//int maxDupCount = 1; // maximum repetion count
	//string max_duplicated_word; // word that was repeated maximum times

	//int running_dup_count = 1; // repetition count for the word just read
	//string previous_word; // the word that was just previous to the current one

	//string word;
	//while (cin>>word) // for each word that is read
	//{
	//	if (word == previous_word) // if it is the same as the previous word
	//	{
	//		++running_dup_count; // increment repetition count for the word just read
	//	}
	//	else // it is different from the previous word
	//	{
	//		if (running_dup_count > maxDupCount) // if the dup count is the largest so far
	//		{
	//			// update max_dup_count, max_duplicated_word
	//			maxDupCount = running_dup_count;
	//			max_duplicated_word = previous_word;
	//		}

	//		running_dup_count = 1; // new word, reset count
	//		previous_word = word; // and this becomes the previous word now
	//	}
	//}

	///* one last check outside the loop that 
	//will catch the last set of repeated words, if any */
	//if (running_dup_count > maxDupCount) 
	//{
	//	// update max_dup_count, max_duplicated_word
	//	maxDupCount = running_dup_count;
	//	max_duplicated_word = previous_word;
	//}

	//if (maxDupCount > 1)
	//{
	//	cout<<"word '"<<max_duplicated_word<<"' was repeated "
	//		<<maxDupCount << " times.\n"<<endl;
	//}
	//else
	//{
	//	cout<<"no word was repeated.\n"<<endl;
	//}
	
	/*/// Compare the size (number of elements) of the two vectors.
	vector<int> v1;
	vector<int> v2;

	srand (time(NULL));
	for (int i = 0; i <= 10; i++)
	{
		int r1 = rand() % 1000000 + 1;
		v1.push_back(r1);
		
	}
	for (auto &m : v1)
		{
			cout<<"Values in v1 are: "<<m<<endl;
		
	}

	cout<<"---------------------------------------------------------------"<<endl;
	for (int k = 0; k <= 10; k++)
	{
		int r2 = rand() % 1000000 + 1;
		v2.push_back(r2);
		
	}
	for (auto &n : v2)
		{
			cout<<"Values in v2 are: "<<n<<endl;
		}

	if (v1.size() == v2.size())
	{
		cout<<"The two Vectors is equal"<<endl;
	}
	else
	{
		cout<<"The tqo Vectors is not equal"<<endl;
	}*/

	//// sum two numbers
	//string s;
	//do {
	//	int v1, v2;
	//	cout << "Please enter two numbers to sum:" ;
	//	if (cin >> v1 >> v2)
	//	cout << "Sum is: " << v1 + v2 << endl;
	//} while (cin>>s);

	//// Compare two strings.
	//string input;
	//do {
	//	string s1, s2;
	//	cout<<"Please enter two string to compare"<<endl;
	//	if (cin>>s1>>s2)
	//	{
	//		if (s1.size() > s2.size())
	//		{
	//			cout<<"String: "<<s1<<" is longer"<<endl;
	//		}
	//		else if (s1.size() < s2.size())
	//		{
	//			cout<<"String: "<<s2<<" is longer"<<endl;
	//		}
	//		else 
	//		{
	//			cout<<"Strings are equal"<<endl;
	//		}
	//	}
	//} while (cin>>input);

	////Insert integer input into vector and print it out.
	//int input;
	//vector<int> v;
	//while(cin >> input)
	//{
	//	v.push_back(input);
	//}

	//for(int i = 0; i<v.size(); i++)
	//{
	// cout<< v[i] <<endl;
	//}


	//// using iterator to print out input.
	//string input;
	//
	//while (cin>>input)
	//{
	//	string::iterator it;

	//	for (it = input.begin(); it < input.end(); it++)
	//	{
	//		cout<<*it;
	//	}
	//}

	

	system("PAUSE");
}