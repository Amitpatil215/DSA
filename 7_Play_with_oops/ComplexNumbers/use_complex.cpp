#include <iostream>
#include "ComplexNumber.cpp"
using namespace std;

int main(){
ComplexNumber ComplexNumber1=ComplexNumber(2,1);
ComplexNumber ComplexNumber2 = ComplexNumber(3, 2);
ComplexNumber1.add(ComplexNumber2);
ComplexNumber1.print();

ComplexNumber1.multiply(ComplexNumber2);
ComplexNumber1.print();
return 0;
}