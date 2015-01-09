#include <iostream>


template<typename T>
bool Search(T arr[], T &obj) {
	for (int i = 0; i < sizeof(arr); i++) {
		if (arr[i] == obj) {
			return true;
		}
	}
	return false;
}

int main() {

	int arrInt[3] = { 1, 2, 3 };
	int objInt = 2;

	char arrChar[3] = { 'd', 'e', 'p' };
	char objChar = 'p';

	float arrFloat[3] = { 3.14, 4.56, 7.89 };
	float objFloat = 3.14;

	bool v = Search(arrChar, objChar);
	std::cout << v <<"\n" << objChar;

	system("pause");
	return 0;
}

