#include <iostream>
#include <string.h>
#include <iomanip>

#define sqrt2 1.414213562373095048801688724209698078569671875376948073176679737990732478462107038850387534327641572735013846230912297024924836055850737212644121497099935831
#define PI_100 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679




double power (double base, int exponent){
	int i;
	double output = 1;
	for(i=0;i<exponent;i++){
		output *= base;
	}
	return output;
} 

double abs_val (double a){
	if(a < 0){
		return -a;
	}else{
		return a;
	}
}

double calculate_pi_taylor(int nb_decimal_places){
	int iter;
	int iter_max = 1000;
	int i;
	int j;
	double output;
	double temp_num;
	double temp_den;
	double resolution = power(0.1,nb_decimal_places+1);



	for (iter = 1 ; iter < iter_max ; iter++){
		output = sqrt2/2;
		temp_num = 1;
		temp_den = 1;
		for (i = 1 ; i <= iter ; i++){
			temp_num *= 2 * i - 1;
			temp_den *= 2 * i;
			output += temp_num * power(sqrt2/2, 2*i+1) / (temp_den * (2*i + 1));
		}
		output *= 4;
		//Check if the resolution is OK
		if (abs_val(output - PI_100) < resolution){
			break;
		}
	}

	return output;
}



int main(){
	//Calculate PI's value up to 10 decimal places
	double value_pi;
	int nb_decimals = 10;

	value_pi = calculate_pi_taylor(nb_decimals);
	std::cout << std::fixed;
    std::cout << std::setprecision(nb_decimals);
	std::cout << "Result Taylor = " << value_pi <<"\n";
	std::cout << "Reference val = " << PI_100 << "\n";

}