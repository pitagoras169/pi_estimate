#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>

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

double calculate_pi_integral(int nb_decimal_places){
	double resolution = power(0.1,nb_decimal_places+1);
	int nb_segments = 100;
	int i;
	int nb_seg_max = 1000000000;
	int iteration;
	double sum;
	double delta_x;
	double x_1;
	double x_2;
	double y_1;
	double y_2;

	for (nb_segments = 100 ; nb_segments <= nb_seg_max ; nb_segments = nb_segments*10){
		sum = 0;
		delta_x = 2.0 / nb_segments;
		for(i = 0 ; i < nb_segments ; i++){
			x_1 = -1 + i * delta_x;
			x_2 = x_1 + delta_x;
			y_1 = sqrt(1 - x_1*x_1);
			y_2 = sqrt(1 - x_2*x_2);
			sum += (y_1 + y_2) * delta_x;
		}
		//Check if the resolution is OK
		if (abs_val(sum - PI_100) < resolution){
			break;
		}
	}
	return sum;
}


int main(){
	//Calculate PI's value up to 10 decimal places
	double value_pi_taylor;
	double value_pi_integral;
	int nb_decimals = 10;

	value_pi_taylor = calculate_pi_taylor(nb_decimals);
	value_pi_integral = calculate_pi_integral(nb_decimals);

	std::cout << std::fixed;
    std::cout << std::setprecision(nb_decimals);
    std::cout << "Result Taylor = " << value_pi_taylor <<"\n";
	std::cout << "Result Integr = " << value_pi_integral <<"\n";
	std::cout << "Reference val = " << PI_100 << "\n";

}