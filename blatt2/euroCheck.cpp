#include "euroCheck.h"
#include <iostream>

using std::string;

bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
int getEuroSerialNumberVersion(string & serialNumber) {
    if (serialNumber.length() != 12) { return 0; }
    if (!isNumber(serialNumber[11])) { return 0; }

    if (toNumber(serialNumber[11]) == 0) { return 0; }

    if (isLetter(serialNumber[0]) && isLetter(serialNumber[1])) {
        for (int i = 2; i < 11; i++) {
            if (!isNumber(serialNumber[i])) { return 0; }
        }
        return 2013;

    } else if (isLetter(serialNumber[0])) {
        for (int i = 1; i < 11; i++) {
            if (!isNumber(serialNumber[i])) { return 0; }
        }
        return 2002;

    } else { return 0; }
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.
bool checkEuroSerialNumber2002(std::string & serialNumber) {
    int p = 0, q = toNumber(serialNumber[11]);
    for (int i = 0; i < 11; i++) {
        p += toNumber(serialNumber[i]);
    }
    p = (8 - (p % 9));
    p = (p == 0) ? 9 : p;
    return p == q;
}

// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(std::string & serialNumber) {
    int p = 0, q = toNumber(serialNumber[11]);
    for (int i = 0; i < 11; i++) {
        p += toNumber(serialNumber[i]);
    }
    p = (7 - (p % 9));
    p = (p == -1) ? 8 : (p == 0 ? 9 : p);
    return p == q;
}


// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}
