// Seeding the random number generation

#include <iostream>
#include <random>

int main() {
	// user to input a seed
	std::cout << "Enter the seed : ";
	unsigned int seed{0};
	std::cin >> seed;

	std::default_random_engine engine{seed};
	std::uniform_int_distribution randomDie{1, 6};

	for (int roll{1}; roll <= 10; ++roll) {
		std::cout << randomDie(engine) << " ";
	}
	return 0;
}