#include "mandelbrotgrid.h"

void mandelbrotGrid::resolutionToMandelbrotGrid() {
    // Preventing nonsense dimensions
    if (_rBound <= _lBound) {
        _rBound = _lBound + 1;
    }
    int horIterations = _resolution.first;
    int verIterations = _resolution.second;

    // We will use algebra to calculate the lower
    // bound of the grid

    _dBoundUnknown = _uBound - ((_rBound - _lBound) * (_resolution.second / _resolution.first));

    vector<mandelbrotCoordinate> rowOfCoordinates;
    vector<int> rowOfSpecVals;
    double horDistance = _rBound - _lBound;
    double verDistance = _uBound - _dBoundUnknown;
    double rightStep = _lBound;
    double downStep = _rBound;
    for (int i = 0; i < verIterations; i++) {
        rowOfCoordinates.clear();
        rowOfSpecVals.clear();
        _mandelbrotGridData.push_back(rowOfCoordinates);
        _spectrumGrid.push_back(rowOfSpecVals);
        for (int j = 0; j < horIterations; j++) {
            mandelbrotCoordinate currPoint(rightStep, downStep);
            currPoint.iterateUntilEnd();
            _mandelbrotGridData[i].push_back(currPoint);
            _spectrumGrid[i].push_back(currPoint.getSpectrumVal());
            rightStep += horDistance / horIterations;
            // DEBUG: cout << currPoint << endl << endl;
            // DEBUG:
            /*
            if (currPoint.getDivergence()) {
                cout << '#';
            }
            else {
                cout << ' ';
            }
            */
             
        }
        // DEBUG: cout << "---------------------------------" << endl;
        // DEBUG: cout << endl;
        rightStep = _lBound;
        downStep -= horDistance / horIterations;
    }





}

void mandelbrotGrid::setUBound(double imagInput) {
    _uBound = imagInput;
}

void mandelbrotGrid::setLBound(double realInput) {
    _lBound = realInput;
}

void mandelbrotGrid::setRBound(double realInput) {
    _rBound = realInput;
}

void mandelbrotGrid::writeToPPM() {
    ofstream outFS;
    outFS.open(_fileName + '_' + to_string(_resolution.first) + 'x' + to_string(_resolution.second) + ".ppm");
    outFS << "P3" << endl;
    outFS << _resolution.first << " " << _resolution.second << endl;
    outFS << "255" << endl;
    for (auto row : _spectrumGrid) {
        for (auto specVal : row) {
            outFS << "0" << endl;
            outFS << "0" << endl;
            outFS << to_string(int(specVal)) << endl;
        }
    }
}

mandelbrotGrid::mandelbrotGrid() {
    _resolution.first = 1800;
    _resolution.second = 1200;
    resolutionToMandelbrotGrid();
    writeToPPM();
}