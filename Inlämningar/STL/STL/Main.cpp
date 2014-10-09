#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

#define NUMBOFELEMENTS 10

template <int N> struct C {
	float value;
	int a[N];
};

//Generall functions for the tasks!
int GenerateRandomNumber(int size) {
	return rand() % size + 1;
}

void FillVector(int numbOfElements, vector<C<NUMBOFELEMENTS>> &container) {
	for (int i = 0; i != numbOfElements; i++) {
		C<NUMBOFELEMENTS> c;
		c.value = GenerateRandomNumber(numbOfElements);
		container.push_back(c);
	}
}

void PrintVector(const vector<C<NUMBOFELEMENTS>> &container) {
	for (const auto &i : container) {
		cout << i.value << " " << endl;
	}
}

template <typename ForwardIterator, typename Predicate>
void ForwardSort(ForwardIterator &begin, ForwardIterator &end, Predicate pred) {
	for (auto it = begin; it != end; it++) {
		for (auto it2 = begin; it2 != it; it2++) {
			if (pred(*it, *it2)) {
				std::swap(*it, *it2);
			}
		}
	}
}
//End generall functions.

//Task1.
bool IsOdd(int i) {
	return ((int)i % 2 != 1);
}

void RemoveOddNumbers(vector<C<NUMBOFELEMENTS>> &container) {
	container.erase(std::remove_if(std::begin(container), std::end(container), IsOdd), std::end(container) );
}

void HandleTask1(vector<C<NUMBOFELEMENTS>> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "Task 1" << endl;
	PrintVector(container); // 2
	cout << "\nOdd numbers: " << endl;

	RemoveOddNumbers(container); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End task1.

//Task2.
template <class ForwardIterator>
void ForwardSort(ForwardIterator &begin, ForwardIterator &end) {
	ForwardSort(begin, end, [](C<NUMBOFELEMENTS> i, C<NUMBOFELEMENTS> k) {return i.value < k.value; });
}

void HandleTask2(vector<C<NUMBOFELEMENTS>> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "Task 2" << endl;
	PrintVector(container); // 2
	cout << "\nSorted values: " << endl;

	ForwardSort(container.begin(), container.end()); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End task2.

//Task3A.
void HandleTask3A(vector<C<NUMBOFELEMENTS>> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "\nTask 3A" << endl;
	PrintVector(container); // 2
	cout << "\nSorted in reverse order: " << endl;
	ForwardSort(container.rbegin(), container.rend());  // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End task3A.

//Task3B
void HandleTask3B(vector<C<NUMBOFELEMENTS>> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "\nTask 3B" << endl;
	PrintVector(container); // 2
	cout << "\nSorted in reverse order: " << endl;
	ForwardSort(container.begin(), container.end(), [](C<NUMBOFELEMENTS> i, C<NUMBOFELEMENTS> k) {return i.value > k.value; }); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End task3B.

//Task4.
void FillPContainer(int numbOfElements, vector<C<NUMBOFELEMENTS>*> &pcontainer) {
	for (int i = 0; i != numbOfElements; ++i) {
		C<NUMBOFELEMENTS> *ptr = new C<NUMBOFELEMENTS>();
		ptr->value = GenerateRandomNumber(numbOfElements);
		pcontainer.push_back(ptr);
	}
}

void PrintPContainer(const vector<C<NUMBOFELEMENTS>*> pcontainer) {
	for (const auto i : pcontainer) {
		cout << i->value << " " << endl;
	}
}

void HandleTask4() {
	vector<C<NUMBOFELEMENTS>*> pcontainer;
	FillPContainer(NUMBOFELEMENTS, pcontainer); // 1
	cout << "\nTask 4" << endl;
	PrintPContainer(pcontainer); // 2
	cout << "\nSorted with std::sort: " << endl;
	std::sort(pcontainer.begin(), pcontainer.end(), [](C<NUMBOFELEMENTS> *i, C<NUMBOFELEMENTS> *k) {return i->value < k->value; });
	PrintPContainer(pcontainer); // 4
	cout << "--------------------------\n" << endl;
}
//End task4.

int main() {
	srand(time(NULL)); /*sets the seed in random generator*/

	vector<C<NUMBOFELEMENTS>> container;
	
	//HandleTask1(container); //OK!
	//HandleTask2(container); // OK!
	//HandleTask3A(container); //OK!
	//HandleTask3B(container);
	//HandleTask4(); //OK!

	system("pause");
	return 0;
}