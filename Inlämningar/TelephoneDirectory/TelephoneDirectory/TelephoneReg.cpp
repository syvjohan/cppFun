#include <iostream>
#include <string.h>
#include "TelephoneReg.h"

using namespace std;

TeleReg::TeleReg(int maxSize) {
	size = maxSize;

	reg = new contact[size];
}

TeleReg::~TeleReg() {

}

void TeleReg::AddContact(const std::string &number, const std::string &name) {

	if (name == "" || number == "") {
		printf("invalid input");
		return;
	}

	if (nextIndex == size) {
		int newSize = size * 2;
		contact *temp = new contact[newSize];
	
		for (int i = 0; i != nextIndex; i++) {
			temp[i] = reg[i];
		}
		delete[] reg;
		reg = temp;
		size = newSize;
	}

	//adding data to array.
	reg[nextIndex].name = name;
	reg[nextIndex].number = number;
	++nextIndex;
}

void TeleReg::DelContact(const std::string &number, const std::string &name) {
	for (int i = 0; i != (size - 1); i++) {
		if (reg[i].number == number && reg[i].name == name) {
			nextIndex = i + 1;

			reg[i].number = reg[nextIndex].number;
			reg[i].name = reg[nextIndex].name;

			reg[nextIndex] = reg[(size - 1)];
			reg[nextIndex] = reg[nextIndex + 1]; //move upp the elements +1.
			//int newSize = size / 2;
			//reg[newSize]; // Shrink the array.	
		}
	}
}

void TeleReg::RemoveName(const std::string &number, const std::string &name) {
	int count = size;
	for (int i = 0; i != size; i++) {
		count++;
		if (reg[i].name == name) {
			count--;
			reg[i].name = "No name!";
		} else if (count == size) {
			printf("No names was removed!\n");
		} else {
			int num = count - size;
			printf("%i number of names that was removed: ", num);
		}

		
	}
}

void TeleReg::RemoveNumber(const std::string &number, const std::string &name) {

}

bool TeleReg::FindName(const std::string &number, std::string &name) const {
	return false;
}

void TeleReg::PrintReg() {

	for (int i = 0; i != size; ++i) {
		printf("%s\n", reg[i].name.c_str());
		printf("%s\n", reg[i].number.c_str());
	}

}