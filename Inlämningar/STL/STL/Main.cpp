#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

#define NUMBOFELEMENTS 10

//Generall functions for the tasks!
int GenerateRandomNumber(int size) {
	return rand() % size + 1;
}

void FillVector(int size, int numbOfElements, vector<int> &container) {
	for (int i = 0; i != numbOfElements; i++) {
		int r = GenerateRandomNumber(size);
		container.push_back(r);
	}
}

void PrintVector(const vector<int> container) {
	for (const auto i : container) {
		cout << i << " " << endl;
	}
}
//End.

//Task1.
bool IsEven(int i) {
	return (i % 2 != 0);
}

void RemoveEvenNumbers(vector<int> &container) {
	container.erase(std::remove_if(std::begin(container), std::end(container), IsEven), std::end(container));
}

void HandleTask1(vector<int> container) {
	FillVector(10, NUMBOFELEMENTS, container); // 1
	PrintVector(container); // 2
	cout << "\nEvent numbers: " << endl;

	RemoveEvenNumbers(container); // 3
	PrintVector(container); // 4
	printf("\n");
}
//End.

//Task2.
void SortInReverseOrder(vector<int> &container) {

}


void HandleTask2(vector<int> container) {
	FillVector(10, NUMBOFELEMENTS, container); // 1
	PrintVector(container); // 2
	cout << "\nSorted in reverse order: " << endl;



}

//End.

//Task3.

//End.

//Task4.

//End.

int main() {
	srand(time(NULL)); /*sets the seed in random generator*/

	vector<int> container;

	HandleTask1(container);
	HandleTask2(container);

	system("pause");
	return 0;
}