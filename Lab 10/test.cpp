#include <iostream>
#include <cstdlib>
#include <ctime>

int randomnumber(int a, int b){
    std::srand(static_cast<unsigned>(std::time(0)));
    return (std::rand() % (b - a + 1)) + a;
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random number between 8 and 30
    int randomNumber = randomnumber(8, 30);

    std::cout << "Random number between 8 and 30: " << randomNumber << std::endl;

    return 0;
}
