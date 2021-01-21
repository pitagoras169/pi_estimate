#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
#include "pi_estimates.hpp"


int main(){
	//Calculate PI's value up to 10 decimal places
	long double value_pi_taylor;
	long double value_pi_integral;
	int nb_decimals = 15;

	value_pi_taylor = calculate_pi_taylor(nb_decimals);
	value_pi_integral = calculate_pi_integral(nb_decimals);

	std::cout << std::fixed;
    std::cout << std::setprecision(nb_decimals);
    std::cout << "Result Taylor = " << value_pi_taylor <<"\n";
	std::cout << "Result Integr = " << value_pi_integral <<"\n";
	std::cout << "Reference val = " << PI_100 << "\n";

}