#include <iostream>

int main()
{
	int weight;
	std::cout << "Enter mom's weight(in kilos)\n";
	std::cin >> weight;
	if (weight > 0)
		std::cout << "ur mom fat";
	else
		std::cout << "ur a liar";
}