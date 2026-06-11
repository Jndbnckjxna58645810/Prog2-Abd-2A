#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>

// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
int getEuroSerialNumberVersion(std::string & serialNumber);

bool checkEuroSerialNumber2002(std::string & serialNumber);
bool checkEuroSerialNumber2013(std::string & serialNumber);

#endif //BLATT2_EUROCHECK_H
