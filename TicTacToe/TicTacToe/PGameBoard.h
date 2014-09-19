#pragma once

class PGameBoard {
public:

	void Reset() {
		//memset(mBoard, 0, sizeof(int)* 9);
	}

	int CheckForWinner() {

	}

	int Update(int row, int col, int newValue) {

	}



private:
	int mBoard[3][3];
};