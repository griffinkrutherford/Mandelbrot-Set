#include "grifcomplex.h"

long double complexNumber::getR() const {
    return _r;
}

long double complexNumber::getI() const {
    return _i;
}

long double complexNumber::getMag() const {
    return _mag;
}

void complexNumber::setMag(long double r, long double i) {
    double magSqr = (_r * _r) + (_i * _i);
    _mag = pow(magSqr, 0.5);
}

void complexNumber::setR(long double r) {
    _r = r;
    setMag(_r, _i);
}

void complexNumber::setI(long double i) {
    _i = i;
    setMag(_r, _i);
}

string complexNumber::complexToString() {
    string output = to_string(_r) + " + " + to_string(_i) + "i";
    return output;
}

string complexNumber::complexToString(complexNumber c) {
    string output = to_string(c._r) + " + " + to_string(c._i) + "i";
    return output;
}

string complexNumber::magToString() {
    string output = to_string(_mag);
    return output;
}

complexNumber::complexNumber() {
    _r = 0.0;
    _i = 0.0;
    setMag(_r, _i);
}

complexNumber::complexNumber(long double r, long double i) {
    setR(r);
    setI(i);
    setMag(_r, _i);
}

ostream & operator<<(ostream & out, complexNumber c) {
    out << c.getR() << " + " << c.getI() << "i";
    return out;
}

complexNumber operator+(complexNumber lhs, complexNumber rhs) {
    double newR = lhs.getR() + rhs.getR();
    double newI = lhs.getI() + rhs.getI();
    complexNumber output(newR, newI);
    return output;
}

complexNumber operator-(complexNumber lhs, complexNumber rhs) {
    double newR = lhs.getR() - rhs.getR();
    double newI = lhs.getI() - rhs.getI();
    complexNumber output(newR, newI);
    return output;
}

complexNumber operator*(complexNumber lhs, complexNumber rhs) {
    // This function does a FOIL operation with two complex numbers
    double fTerm = lhs.getR() * rhs.getR();
    double midTerms = (lhs.getR() * rhs.getI()) + (rhs.getI() * lhs.getR());
    double lTerm = lhs.getI() * rhs.getI();
    double newR = fTerm + lTerm * -1;
    double newI = midTerms;
    complexNumber output(newR, newI);
    return output;
}


