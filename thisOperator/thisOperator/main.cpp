#include <iostream>
using namespace std;

class Test {
public:
	Test(int i = 0);
	void print() const;
private:
	int x;
};

Test::Test(int value) : x(value) 
{}

//Equalient to:
/*
Test::Test(int value) {
	x = value;
*/

void Test::print() const {
	// implicitly use the this pointer to access the member x
	cout << "   x = " << x;

	// explicitly use the this pointer and the arrow operator
	//to access the member x.
	cout << "\n   x = " << this->x;

	// explicitly use the dereferenced this pointer and
	// the dot operator to access the member x
	cout << "\n   x = " << (*this).x;
}

int main() {
	Test testObj(12);

	testObj.print();
	system("pause");
}