// Dice game CRAP

#include <iostream>
#include <format>
#include <random>
using namespace std;

int rolldice(); // rolls the two dice and gives the sum as return

int main () {

	// there is a data type now called Status and have constants
	enum class Status {keeprolling, won, lost};
	using enum Status;

	int mypoint{0}; // for if first roll not lost or won
	Status gameStatus{keeprolling};

	switch (const int sumofDice {rolldice()}) {
	case 7:
	case 11:
		gameStatus = won;
		std::cout << "The player won! \n ";
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = lost;
		std::cout << "The player lost ! \n";
		break;
	default:
		mypoint = sumofDice;
		gameStatus = keeprolling;
		std::cout << "The point to be made " << sumofDice << "\n";
		break;
	}


	while (gameStatus == keeprolling) {
		int sumofDice{rolldice()};
		if (sumofDice == mypoint) {
			std::cout << "Player Won! \n";
			break;
		}
		else if (sumofDice == 7) {
			std::cout << "Player lost! \n";
			break;
		}
		else {
			continue;
		}
	}


	return 0;
}


int rolldice() {
	static random_device rd;
	static default_random_engine engine{rd()};
	static uniform_int_distribution <int> randomDie{1, 6};

	const int die1{randomDie(engine)};
	const int die2{randomDie(engine)};
	const int sum{die1 + die2};

	std::cout << "The sum of the rolled die : " << sum << "\n";
	return sum;
}
