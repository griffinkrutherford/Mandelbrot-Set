#ifndef MANDELBROT_GRID_H
#define MANDELBROT_GRID_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <fstream>

#include "grifcomplex.h"
#include "mandelbrot.h"

using namespace std;

class mandelbrotGrid : mandelbrotCoordinate {
public:

    void resolutionToMandelbrotGrid();
    // Taking in location on complex plane as input
    void setUBound(double imagInput);
    void setLBound(double realInput);
    void setRBound(double realInput);
    void writeToPPM();
    mandelbrotGrid();


private:
    pair<int,int> _resolution;
    vector < vector < mandelbrotCoordinate > > _mandelbrotGridData;
    vector < vector < int > > _spectrumGrid;
    struct pixel {
        int red;
        int green;
        int blue;
    };
    vector < vector < pixel > > _rgbTupleVector;
    set<char> _rgbSet;
    double _uBound = 1;
    double _lBound = -2;
    double _rBound = 1;
    double _dBoundUnknown;
    string _fileName = "mandelbrot";
};



#endif