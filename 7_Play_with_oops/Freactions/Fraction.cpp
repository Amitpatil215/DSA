#include <iostream>
#include <algorithm>
using namespace std;
class Fraction
{
private:
    int num;
    int den;

public:
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    void print()
    {
        cout << num << "/" << den << endl;
    }

    void add(Fraction const &f2) // const &f2, reference pointer can only read data from f2
                                 // but cannot change/write it
    {
        int lcm = den * f2.den;
        int x = lcm / den;
        int y = lcm / f2.den;
        int num = x * this->num + y * f2.num;
        this->num = num;
        this->den = lcm;
        simplify();
    }

    void multiply(Fraction const &f2){
        num=num*f2.num;
        den=den*f2.den;
    }

    void simplify()
    {
        int gcd = 1;

        ///! Manually find gcd
        // int maxGcd = min(num, den);
        // for (int i = 1; i <= maxGcd; i++)
        // {
        //     if (num % i == 0 && den % i == 0)
        //     {
        //         gcd = i;
        //     }
        // }

        ///! find gcd using inbuild function in the algorithm library
        gcd = __gcd(num, den);
        num = num / gcd;
        den = den / gcd;
    }
};
