#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

#include "grifcomplex.h"

using namespace std;

// complexNumber is a parent class of mandelbrotCoordinate
class mandelbrotCoordinate : complexNumber {
public:
    complexNumber getCoordinates() const;
    int getIterationEnd() const;
    long double getDivergentMag() const;
    bool getDivergence() const;
    double getSpectrumVal() const;
    void setZ(complexNumber z);
    void iterateOnce();
    void iterateUntilEnd();
    mandelbrotCoordinate();
    mandelbrotCoordinate(long double r, long double i);
    mandelbrotCoordinate(complexNumber c);

private:
    complexNumber _c;
    complexNumber _z;
    pair<long double, long double> _coordinatePair;
    long double _iterationEnd = 10000;
    long double _divergentMag = 10000;
    bool _diverged = true;
    int _spectrumVal = 0;
    int _maxSpectrumVal = -1;
    long double _finalCoordinateMag;
};

ostream & operator<<(ostream & out, mandelbrotCoordinate currPoint);

#endif