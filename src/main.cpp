#include <iostream>
#include <string.h>

#define sqrt2 1.41421356237



double power (double base, int exponent){
	int i;
	double output = 1;
	for(i=0;i<exponent;i++){
		output *= base;
	}
	return output;
} 

double calculate_pi(int iterations){
	int i;
	int j;
	double output = sqrt2/2;
	double temp_num;
	double temp_den;


	for (i = 1 ; i <= iterations ; i++){
		temp_num = 1;
		temp_den = 1;
		for (j = 1 ; j <= i ; j++){
			temp_num *= 2*j -1;
			temp_den *= 2*j;
		}
		output += temp_num * power(sqrt2/2, 2*i+1) / (temp_den * (2*i + 1));

	}

	return 4 * output;
}



int main(){
	double value_pi;

	value_pi = calculate_pi(10);
	std::string value_pi_string = std::to_string(value_pi);
	std::cout << value_pi_string <<"\n";





}