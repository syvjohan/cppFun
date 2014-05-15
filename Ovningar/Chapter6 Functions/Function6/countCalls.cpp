#include "chapter6.h"

int flagg = 0;

//6.7
size_t countCalls()
{
    static size_t ctr = 0;  // value will persist across calls
    return ++ctr;
}

//6.7
int func() {

	if (flagg == 0) {
		flagg = 1;
		return 0;
	}

	for (size_t i = 0; i != 10; ++i)
	{
        cout << countCalls() << endl;
    }
}