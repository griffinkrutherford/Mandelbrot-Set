#ifndef GRIF_COMPLEX_H
#define GRIF_COMPLEX_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class complexNumber {
public:
    long double getR() const;
    long double getI() const;
    long double getMag() const;
    void setMag(long double r, long double i);
    void setR(long double r);
    void setI(long double i);
    string complexToString();
    string complexToString(complexNumber c);
    string magToString();
    complexNumber();
    complexNumber(long double r, long double i);
private:
    long double _r = 0.0;
    long double _i = 0.0;
    long double _mag = 0.0;
};

ostream & operator<<(ostream & out, complexNumber c);
complexNumber operator+(complexNumber lhs, complexNumber rhs);
complexNumber operator-(complexNumber lhs, complexNumber rhs);
complexNumber operator*(complexNumber lhs, complexNumber rhs);


#endif