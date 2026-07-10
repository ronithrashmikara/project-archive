// Rnadom number generation in C++ (for functions) : PART 01
#include <iostream>
#include <format>
#include <random>


int main () {
	// setting up random number generation
	std::default_random_engine engine{};
	std::uniform_int_distribution<int> randomDie{1, 6}; // range
	// variable for keeping track of frequency of 1,2,3,4,5,6
	int freq1{0};
	int freq2{0};
	int freq3{0};
	int freq4{0};
	int freq5{0};
	int freq6{0};
	// using a switch case statement

	for (int roll{1} ; roll <= 99; ++roll) {
		const int face {randomDie(engine)};
		switch (face) {
		case 1:
			freq1++;
			break;
		case 2:
			freq2++;
			break;
		case 3:
			freq3++;
			break;
		case 4:
			freq4++;
			break;
		case 5:
			freq5++;
			break;
		case 6:
			freq6++;
			break;
		default :
			std::cout << "The program must not have been here";
			break;
		}
	}
	// printing the values

	std::cout << std::format ("{:>7} {:>15}\n", "Number", "Frequency" );
	std::cout << std::format ("{:>7} {:>15}\n", "1", freq1 );
	std::cout << std::format ("{:>7} {:>15}\n", "2", freq2);
	std::cout << std::format ("{:>7} {:>15}\n", "3", freq3 );
	std::cout << std::format ("{:>7} {:>15}\n", "4", freq4 );
	std::cout << std::format ("{:>7} {:>15}\n", "5", freq5 );
	std::cout << std::format ("{:>7} {:>15}\n", "6", freq6 );


	std::cin.get();

	return 0;
}