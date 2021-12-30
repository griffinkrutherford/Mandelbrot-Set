#include "mandelbrot.h"

complexNumber mandelbrotCoordinate::getCoordinates() const {
    return _c;
}

int mandelbrotCoordinate::getIterationEnd() const {
    return _iterationEnd;
}

long double mandelbrotCoordinate::getDivergentMag() const {
    return _divergentMag;
}

bool mandelbrotCoordinate::getDivergence() const {
    return _diverged;
}

double mandelbrotCoordinate::getSpectrumVal() const {
    return _spectrumVal;
}

void mandelbrotCoordinate::setZ(complexNumber z) {
    _z.setR(z.getR());
    _z.setI(z.getI());
}

void mandelbrotCoordinate::iterateOnce() {
    _z = _z * _z + _c;
    // DEBUG: cout << "z: " << _z << endl;
    // DEBUG: cout << "c: " << _c << endl;
    // DEBUG: cout << "m: " << _z.getMag() << endl;
    // DEBUG: cout << endl;
    _spectrumVal++;
    if (_spectrumVal > _maxSpectrumVal) {
        _maxSpectrumVal = _spectrumVal;
    }
    _finalCoordinateMag = _z.getMag();
}

// This function returns the spectrum value of the current
// coordinate on the Mandelbrot set
void mandelbrotCoordinate::iterateUntilEnd() {
    int end = _iterationEnd;

    // DEBUG: cout << "z: " << _z << endl;
    // DEBUG: cout << "c: " << _c << endl;
    // DEBUG: cout << "m: " << _z.getMag() << endl;
    // DEBUG: cout << endl;
    _finalCoordinateMag = _z.getMag();

    for (int i = 0; i < end; i++) {
        iterateOnce();
        if (_finalCoordinateMag >= _divergentMag) {
            break;
        }
    }
    if (_finalCoordinateMag >= _divergentMag) {
        // DEBUG: cout << _finalCoordinateMag << " >= " << _divergentMag << endl << endl;
        _diverged = true;
    }
    else {
        // DEBUG: cout << _finalCoordinateMag << " < " << _divergentMag << endl << endl;
        _diverged = false;
        _spectrumVal = _maxSpectrumVal;
    }
}


mandelbrotCoordinate::mandelbrotCoordinate() {
    _coordinatePair.first = 0.0;
    _coordinatePair.second = 0.0;
    iterateUntilEnd();
}

mandelbrotCoordinate::mandelbrotCoordinate(long double r, long double i) {
    _coordinatePair.first = r;
    _coordinatePair.second = i;
    _c.setR(_coordinatePair.first);
    _c.setI(_coordinatePair.second);
    iterateUntilEnd();
}

mandelbrotCoordinate::mandelbrotCoordinate(complexNumber c) {
    _coordinatePair.first = c.getR();
    _coordinatePair.second = c.getI();
    _c.setR(_coordinatePair.first);
    _c.setI(_coordinatePair.second);
    iterateUntilEnd();
}

ostream & operator<<(ostream & out, mandelbrotCoordinate currPoint) {
    complexNumber currNum = currPoint.getCoordinates();
    string divergeOrNot;
    if (currPoint.getDivergence()) {
        divergeOrNot = "diverges";
    }
    else {
        divergeOrNot = "does not diverge";
    }
    out << "The point " << currNum << " " << divergeOrNot << "." << endl;
    out << "On a scale of 0 to 255 measuring the divergence of" << endl;
    out << "the magnitude of the complex number after " << currPoint.getIterationEnd() << endl;
    out << "iterations is " << currPoint.getSpectrumVal() << ".";
    return out;
}