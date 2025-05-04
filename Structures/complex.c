#include <stdio.h>
typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real + c2->real;
    result.imag = c1->imag + c2->imag;
    return result;
}

Complex subtract(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real - c2->real;
    result.imag = c1->imag - c2->imag;
    return result;
}


Complex multiply(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real * c2->real - c1->imag * c2->imag;
    result.imag = c1->real * c2->imag + c1->imag * c2->real;
    return result;
}

int main() {
    Complex num1, num2, result;

    printf("Enter real and imaginary parts of first complex number (a + ib): ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    printf("Enter real and imaginary parts of second complex number (x + iy): ");
    scanf("%lf %lf", &num2.real, &num2.imag);
    
    result = add(&num1, &num2);
    printf("Addition: %.2f + %.2fi\n", result.real, result.imag);

    result = subtract(&num1, &num2);
    printf("Subtraction: %.2f + %.2fi\n", result.real, result.imag);

    result = multiply(&num1, &num2);
    printf("Multiplication: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
