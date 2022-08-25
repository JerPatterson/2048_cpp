#include <iostream>
#include "game.h"

using namespace std;


const int SIDE_LENGTH = 4;


int main() {
	//Grid gameGrid = Grid::getInstance();

	Square firstSquare = Square(1, 3);
	Square sencondSquare = Square(1, 2);
	Square thirdSquare = Square(4, 3);

	cout << firstSquare.getRank() << ' ' 
		<< sencondSquare.getRank() << ' ' 
		<< thirdSquare.getRank() << endl;

	cout << firstSquare.isPossibleToMerge(sencondSquare) << ' '
		<< firstSquare.isPossibleToMerge(thirdSquare);


	return 0;
}

Grid::Grid() {
	gridContent_.resize(16);
}


Square::Square(int x, int y) :
	horizontalPosition_(x),
	verticalPosition_(y)
{
}

int Square::getRank() {
	return SIDE_LENGTH * (verticalPosition_ - 1) + horizontalPosition_;
}


bool Square::isPossibleToMerge(Square other) {
	if (*this != other) {
		if (isOnTheSameLine(other)) {
			return true;
		}
		
	}

	return false;
}

bool Square::operator!=(Square other) {
	return getRank() != other.getRank();
}

bool Square::isOnTheSameLine(Square other) {
	int rank = getRank();
	int otherRank = other.getRank();


	if (abs(rank - otherRank) % SIDE_LENGTH == 0) {
		return true;
	}

	else if (abs(rank - otherRank) < SIDE_LENGTH) {
		if (rank / SIDE_LENGTH == otherRank / SIDE_LENGTH) {
			return true;
		}
		else {
			return max(rank, otherRank) % SIDE_LENGTH == 0;
		}
	}

	return false;
}