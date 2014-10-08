#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

#define NUMBOFELEMENTS 10
typedef int T;

//Generall functions for the tasks!
int GenerateRandomNumber(int size) {
	return rand() % size + 1;
}

void FillVector(int numbOfElements, vector<T> &container) {
	for (int i = 0; i != numbOfElements; i++) {
		int r = GenerateRandomNumber(numbOfElements);
		container.push_back(r);
	}
}

void PrintVector(const vector<T> container) {
	for (const auto i : container) {
		cout << i << " " << endl;
	}
}
//End.

//Task1.
bool IsEven(int i) {
	return (i % 2 != 0);
}

void RemoveEvenNumbers(vector<T> &container) {
	container.erase(std::remove_if(std::begin(container), std::end(container), IsEven), std::end(container));
}

void HandleTask1(vector<T> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "Task 1" << endl;
	PrintVector(container); // 2
	cout << "\nEvent numbers: " << endl;

	RemoveEvenNumbers(container); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End.

//Task2.
template <class ForwardIterator>
void ForwardSort(ForwardIterator &begin, ForwardIterator &end) {
	//BubbleSort!
	for (auto it = begin; it != end; it++) {
		for (auto it2 = begin; it2 != it; it2++) {
			if (*it < *it2) {
				std::swap(*it, *it2);
			}
		}
	}
}

void HandleTask2(vector<T> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "Task 2" << endl;
	PrintVector(container); // 2
	cout << "\nLinear sorted values: " << endl;

	ForwardSort(container.begin(), container.end()); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}

//End.

//Task3a.
void ReverseOrder(vector<T> &container) {
	std::vector<T>::reverse_iterator rit = container.rbegin();
	std::vector<T>::reverse_iterator rnd = container.rend();
	vector<T> tempContainer;

	while (rit != rnd) {
		if (*rit < *rnd) {
			std::swap(*rit, *rnd);
		}
		tempContainer.push_back(*rit);
		++rit;
	}

	container = tempContainer;
}

void HandleTask3A(vector<T> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "\nTask 3A" << endl;
	PrintVector(container); // 2
	cout << "\nSorted in reverse order: " << endl;
	//InsertSort(container);
	ReverseOrder(container); // 3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End.

//Task3b
template <typename Predicate>
void ReverseSort(vector<T> container, Predicate pred) {

	//&(*begin) - 1;
	//
	//// begin+1 är sorterade delen.
	//for (auto i = begin + 1; i != end; ++i) {

	//	auto element = *i;


	//	for (auto j = end - 1; &(*j) != &(*begin) - 1; --j) {

	//		if (pred(element, *j)) {
	//			//*(j + 1) = *j;
	//		} else {
	//			//*j = element;
	//		}
	//	}
	//}
}
void InsertSort(vector<T> &container) {
	T temp;
	auto it1 = container.begin();

	for (int it1 = 1; it1 != container.size(); it1++) {
		temp = container[it1];
		auto it2 = it1 - 1;

		while (it2 >= 0 && container[it2] > temp) {
			container[it2 + 1] = container[it2];
			it2 = it2 - 1;
		}
		container[it2 + 1] = temp;
	}
}


void HandleTask3B(vector<T> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "\nTask 3B" << endl;
	PrintVector(container); // 2
	//ReverseSort(container.rbegin(), container.rend(), [](T x, T y) {return x > y; });
	PrintVector(container);
	cout << "--------------------------\n" << endl;

}
//End.


//Task4.
template <typename Predicate>
void Sort(vector<T> &container, Predicate pred) {
	std::sort(container.begin() + 4, container.end(), pred); //sort after index 4 and to the end of the vector.
}

void HandleTask4(vector<T> container) {
	FillVector(NUMBOFELEMENTS, container); // 1
	cout << "\nTask 4" << endl;
	PrintVector(container); // 2

	cout << "\nSorted with std::sort: " << endl;
	Sort(container, [](T i, T k) { return (i < k); }); //3
	PrintVector(container); // 4
	cout << "--------------------------\n" << endl;
}
//End.

int main() {
	srand(time(NULL)); /*sets the seed in random generator*/

	vector<T> container;

	//HandleTask1(container); //OK!
	//HandleTask2(container); // OK!
	HandleTask3A(container);
	//HandleTask3B(container);
	//HandleTask4(container); //OK!

	system("pause");
	return 0;
}