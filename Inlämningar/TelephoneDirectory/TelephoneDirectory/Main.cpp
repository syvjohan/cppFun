#include <iostream>
#include <string.h>
#include "TelephoneReg.h"

using namespace std;

int main() {

	TeleReg teleReg(10); // tio platser i telefon registret....

	teleReg.AddContact("6666", "johan");
	teleReg.AddContact("333", "nisse");
	teleReg.AddContact("5555", "lisa");
	teleReg.AddContact("8888", "rune");
	teleReg.AddContact("9999", "peter");
	teleReg.AddContact("000", "emma");
	teleReg.AddContact("2222" ,"mia");

	//teleReg.DelContact("333", "nisse");
	//teleReg.DelContact("6666" , "johan");
	teleReg.RemoveName("", "la");

	teleReg.PrintReg();

	system("pause");
	return 0;
}

