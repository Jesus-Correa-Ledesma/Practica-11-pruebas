#include "complex.h"

int main() {
    Complex complejo1(4, 5), complejo2(7, -8);
    Complex resultado;
    resultado = Complex::Add(complejo1, complejo2);
    resultado.print();
    resultado = Complex::Sub(complejo1, complejo2);
    resultado.print();
	return 0;
}