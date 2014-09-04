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
			//Initialize nextIndex
			nextIndex = i + 1;
			while (nextIndex != size) {
				//move upp the elements +1.
				reg[i].number = reg[nextIndex].number;
				reg[i].name = reg[nextIndex].name;
				i = nextIndex;
				nextIndex++;
			}
			// Shrink the array.	
			int newSize = size / 2;
			reg[newSize];
			return;
		}
	}
}

void TeleReg::RemoveName(const std::string &number, const std::string &name) {
	//Check if name exist.
	for (int i = 0; i != size; i++) {
		if (reg[i].name == name) {
			reg[i].name = "";
			if ((reg[i].number == "") && (reg[i].name == "")) {
				//Initialize nextIndex
				nextIndex = i + 1;
				while (nextIndex != size) {
					//move upp the elements +1.
					reg[i].number = reg[nextIndex].number;
					reg[i].name = reg[nextIndex].name;
					i = nextIndex;
					nextIndex++;
				}
				// Shrink the array.	
				int newSize = size / 2;
				reg[newSize];
			}
		}
	}
}

void TeleReg::RemoveNumber(const std::string &number, const std::string &name) {
	//Check if name exist.
	for (int i = 0; i != size; i++) {
		if (reg[i].number == number) {
			reg[i].number = "";
			if (reg[i].number == "" && reg[i].name == "") {
				//Initialize nextIndex
				nextIndex = i + 1;
				while (nextIndex != size) {
					//move upp the elements +1.
					reg[i].number = reg[nextIndex].number;
					reg[i].name = reg[nextIndex].name;
					i = nextIndex;
					nextIndex++;
				}
				// Shrink the array.	
				int newSize = size / 2;
				reg[newSize];
			}
		}
	}
}

bool TeleReg::FindName(const std::string &number, const std::string &name) const {
	for (int i = 0; i != size; i++) {
		if (reg[i].number == "4" && reg[i].name == name) {
			return true;
		}
	}
	return false;
}

void TeleReg::PrintReg() {

	for (int i = 0; i != size; ++i) {
		printf("%s\n", reg[i].name.c_str());
		printf("%s\n", reg[i].number.c_str());
	}

}