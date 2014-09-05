#include <iostream>
#include <string>
#include "TelephoneReg.h"
#include "Defs.h"

using namespace std;

TeleReg::TeleReg(int maxSize) {
	size = maxSize;

	reg = DBG_NEW contact[size];
}

TeleReg::~TeleReg() {
	delete[] reg;
}

void TeleReg::AddContact(const std::string &number, const std::string &name) {

	if (name == "" || number == "") {
		printf("invalid input");
		return;
	}

	if (nextIndex == size) {
		int newSize = size * 2;
		contact *temp = DBG_NEW contact[newSize];

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
	int index = -1;
	for (int i = 0; i != nextIndex; ++i) {
		if (reg[i].number == number && reg[i].name == name) {
			index = i;
			break;
		}
	}

	// We found the contact?
	if (index >= 0) {
		//if there is only one element in array.
		if (index == 0 && nextIndex == 1) {
			reg[0].name = "";
			reg[0].number = "";
		}
		// Loop from the index up to nextIndex, moving all contacts.
		for (int i = index; i != nextIndex - 1; ++i) {
			reg[i].name = reg[i + 1].name;
			reg[i].number = reg[i + 1].number;
		}
		--nextIndex;
	}
}

void TeleReg::RemoveName(const std::string &name) {
	DelContact(FindNumber(name), name);
}

void TeleReg::RemoveNumber(const std::string &number) {
	DelContact(number, FindName(number));
}

void TeleReg::PrintReg() {
	for (int i = 0; i != nextIndex; ++i) {
		if (reg[i].name.length() > 0 || reg[i].number.length() > 0) {
			printf("%s\n", reg[i].name.c_str());
			printf("%s\n", reg[i].number.c_str());
		}
		
	}
}

std::string TeleReg::FindNumber(const std::string &name) const {
	for (int i = 0; i != nextIndex; ++i) {
		if (reg[i].name == name)
			return reg[i].number;
	}

	return "";
}

std::string TeleReg::FindName(const std::string &number) const {
	for (int i = 0; i != nextIndex; ++i) {
		if (reg[i].number == number)
			return reg[i].name;
	}

	return "";
}