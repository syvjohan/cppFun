#pragma once

class Fibo {
public:

	int *GetFiboNumbers();
	void CalCulateFibo(int n);

private:
	int *arr;
};

int* Fibo::GetFiboNumbers() {
	return arr;
}

void Fibo::CalCulateFibo(int n) {
	int second = 1;
	int first = 0;
	int next, c;

	for (c = 0; c < n; c++)
	{
		if (c <= 1)
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		&arr[next];
	}
}


