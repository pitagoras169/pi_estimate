#include <iostream>
#include <string.h>

#define sqrt2 1.41421356237


double potencia (double base, int exponente){
	int i;
	double output = 1;
	for(i=0;i<exponente;i++){
		output *= base;
	}
	return output;
} 

double calcular_pi(int iteraciones){
	int i;
	int j;
	double output = sqrt2/2;
	double temp_num;
	double temp_den;


	for (i = 1 ; i <= iteraciones ; i++){
		temp_num = 1;
		temp_den = 1;
		for (j = 1 ; j <= i ; j++){
			temp_num *= 2*j -1;
			temp_den *= 2*j;
		}
		output += temp_num * potencia(sqrt2/2, 2*i+1) / (temp_den * (2*i + 1));

	}

	return 4 * output;
}



int main(){
	double valor_pi;

	valor_pi = calcular_pi(10);
	std::string valor_pi_string = std::to_string(valor_pi);
	std::cout << valor_pi_string <<"\n";





}