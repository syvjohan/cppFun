#include <iostream>
#include <string>
#include "TelephoneReg.h"

using namespace std;

void Menu();
void Start();

int main() {

	Start();
	Menu();

	/*teleReg.AddContact("6666", "johan");
	teleReg.AddContact("333", "nisse");
	teleReg.AddContact("5555", "lisa");
	teleReg.AddContact("8888", "rune");
	teleReg.AddContact("9999", "peter");
	teleReg.AddContact("000", "emma");
	teleReg.AddContact("2222" ,"mia");

	teleReg.DelContact("333", "nisse");
	teleReg.DelContact("6666" , "johan");
	teleReg.DelContact("2222", "mia");

	teleReg.RemoveNumber("5555", "");
	teleReg.RemoveName("", "lisa");*/

	/*teleReg.DelContact("8888", "rune");
	teleReg.DelContact("9999", "peter");
	teleReg.DelContact("000", "emma");
	teleReg.DelContact("5555", "lisa");*/


	//teleReg.PrintReg();
	system("pause");
	return 0;
}

void Start() {
	printf("Welcome to the phone directory, please choose one of the following choices: \n");
	printf("----------------------------------------------------------------------------\n");
	printf("Press 1 to insert a new contact\nPress 2 to delete a contact\nPress 3 to search after a name\n"
		   "Press 4 to remove name\nPress 5 to remove number\nPress 6 to print directory\n"
		   "Press 7 to exit program\n");
}

void Menu() {

	TeleReg teleReg(10); // tio platser i telefon registret....

	string name = "";
	string number = "";
	int choice = 0;

	do {
		cin >> choice;
		switch (choice) {
		case 1:
			printf("\nEnter number and name to add: ");
			cin >> number >> name;
			teleReg.AddContact(number, name);
			break;
		case 2:
			printf("\nEnter name and number to Delete: ");
			cin >> number >> name;
			teleReg.DelContact(number, name);
			break;
		case 3:
			printf("\nEnter name to find: ");
			cin >> number >> name;
			if (teleReg.FindName(number, name) == true) {
				cout << number << endl;
			} else {
				cout << "No name could be found" << endl;
			}
			break;
		case 4:
			printf("\nEnter name to remove: ");
			cin >> name;
			teleReg.RemoveName(number, name);
			break;
		case 5:
			printf("\nEnter number to remove: ");
			cin >> name;
			teleReg.RemoveNumber(number, name);
			break;
		case 6:
			teleReg.PrintReg();
			break;
		case 7:
			exit(0);
			break;
		}
		Start();

	} while (choice != 7);
}