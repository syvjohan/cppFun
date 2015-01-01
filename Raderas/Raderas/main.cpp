#include <iostream>
#include <string>


int main() {

	std::string input = "hej pa dig gammle van";
	std::string key = "hej";
	int len = key.length();
	std::string k = input.substr(len+1, input.length() - len -1);
	std::cout << k;

	system("pause");
		return 0;
}