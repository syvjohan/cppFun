#include <iostream>
#include "Time.h"

using namespace std;

int main() {

	Time time;

	time.setHour(18).setMinute(30).setSecond(22);

	cout << "Universl time: ";
	time.printUniversal();

	cout << "\nStandard Time: ";
	time.printStandard();

	cout << "\nNew standard time: ";
	time.setTime(20, 20, 20).printStandard();
	cout << endl;

	system("pause");
}