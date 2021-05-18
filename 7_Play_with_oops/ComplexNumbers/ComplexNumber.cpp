#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real;
    int imag;

public:
    ComplexNumber(
        int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void add(ComplexNumber const &number)
    {
        real = real + number.real;
        imag = imag + number.imag;
    }

    void multiply(ComplexNumber const &number)
    {
        real = real * number.real - imag * number.imag;
        imag = real * number.imag + imag * number.real;
    }

    void print()
    {
        cout << real << " + " << imag << "(i)" << endl;
    }
};