#include "rational.h"
using namespace std;

Rational::Rational(int numerator, int denominator)
{
    numer = numerator;
    denom = denominator;
}

Rational::Rational(const Rational& copy)
{
    numer = copy.numer;
    denom = copy.denom;
}

Rational Rational::operator*(const Rational& other) const
{
    int n = numer * other.numer;// (this -> numer)//(r1*r2 =r1.*operator)
    int d = denom * other.denom;
    Rational r1 (n,d);
    return r1;

    // return Rational{number * other.numer, denom * other.denom};
}

Rational operator+(int i, const Rational& r)
{
    // cout << "i : " << i << endl;
    // cout << "numer: " << r.numerator() << ", denom: " << r.denominator() << endl;
    // int n = (i * r.denominator()) + r.numerator();
    // int d = r.denominator();
    return Rational{(i * r.denominator()) + r.numerator(), r.denominator()};

    //return Rational{0};   
}

Rational Rational:: operator-(const Rational& other) const
{
    return Rational{numer*other.denom-denom*other.numer,denom*other.denom};
}

Rational Rational::operator+(const Rational& other) const
{
    return Rational{numer*other.denom + denom * other.numer,denom*other.denom};
}

Rational Rational:: operator/(const Rational& other) const
{
    return Rational{ numer*other.denom,denom*other.numer};
}

Rational operator+(const Rational& r,int i)
{
    return Rational{r.numerator()+i*r.denominator(),r.denominator()};
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    os << rational.numer << "/" << rational.denom;
    return os;
}
