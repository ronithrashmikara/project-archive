// Rolling a random dice with a random seed and intro to enum class

#include <iostream>
#include <random>
#include <format>
using namespace std;

int rolldice();

int main() {
	enum class Status {keeprolling, won, lost};
	using enum Status;
	Status gamestatus{keeprolling};


	int mypoint{0};

	// first roll of the  2 dice
	switch (int roll {rolldice()}) {
	case 7:
	case 11:
		gamestatus = won;
		std::cout << "The dice sum is " << roll << "\n";
		break;
	case 2:
	case 3:
	case 12:
		gamestatus = lost;
		std::cout << "The dice sum is " << roll << "\n";
		break;
	default :
		mypoint = roll;
		std::cout << "The point to be made " << mypoint << "\n" ;

	}


	while (gamestatus == keeprolling) {
		int roll2{rolldice()};
		if (roll2 == mypoint) {
			gamestatus = won;
			std::cout << "The rerolls outcome is " << roll2 << "\n";
			std::cout << "The point of " << mypoint << " was made \n ";
			break;
		}
		else if (roll2 == 7) {
			gamestatus = lost;
			std::cout << "The rerolls outcome is 7  \n";
			break;
		}
		std::cout << "The rerolls outcome is " << roll2 << "\n";

	}



	if (gamestatus == won) {
		std::cout << "The player won!";
	}
	else if (gamestatus == lost)
	{
		std::cout << "The player lost!";
	}

	return 0;

}

int rolldice()
{
	static random_device rd;
	static default_random_engine engine{rd()};
	static uniform_int_distribution randomDie{1, 6};

	const int die1 {randomDie(engine)};
	const int die2 {randomDie(engine)};
	const int sum {die1 + die2};
	return sum;
}