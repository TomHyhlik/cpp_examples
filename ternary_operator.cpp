#include <iostream>

int main(void)
{
	int a = 10;
	int b = 12;

	int c = (a > b) ? 20 : 22;

	std::cout << "val: " << c << std::endl;

	std::string rank = (a < b) ? "low" : "high";


	std::cout << "rank: " << rank << std::endl;


	return 0;
}