#include "Harl.hpp"
#include <iostream>

int main(void) {
	Harl harl;
	
	std::cout << "=== Testing all levels ===" << std::endl;
	std::cout << "\n[DEBUG]" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n[INFO]" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n[WARNING]" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n[ERROR]" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\n[UNKNOWN]" << std::endl;
	harl.complain("UNKNOWN");
	
	return 0;
}
