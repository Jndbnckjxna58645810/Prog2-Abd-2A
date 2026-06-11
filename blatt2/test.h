// TODO:
//  Entfernt die Kommentar-Zeichen (//) für Aufgaben, die erledigt sind und getestet werden sollen:

#define TEST_AUFGABE_2 // TODO Aufgabe 2
#define TEST_AUFGABE_5 // TODO Aufgabe 5
#define TEST_AUFGABE_6 // TODO Aufgabe 6
#define TEST_AUFGABE_7 // TODO Aufgabe 7


#include <iostream>
#include <string>
using std::string;
#include "euroCheck.h"

bool test_getEuroSerialNumberVersion() {
#ifdef TEST_AUFGABE_2
    // Bedingung: 
    // - je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
    // - (Gültige Seriennummern hier müssen auch den anderen Formatvorgaben von Aufgabe 7 entsprechen, damit dieser Test hier nicht fehlschlägt, wenn getEuroSerialNumberVersion() in Aufgabe 7 angepasst wird.)
    
    // - Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
    for (string serialNumber : {"X00000000001", "U00000000001", "P12345678909"}) {
        if (getEuroSerialNumberVersion(serialNumber) != 2002) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (Seriennummern mit einem Anfangsbuchstaben sollten 2002 zurückgeben) - Aufgabe 2" << std::endl;
            return false;
        }
    }
    
    // - Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.
    for (string serialNumber : {"AB1234567891", "XY0000000009", "CD1234567891"}) {
        if (getEuroSerialNumberVersion(serialNumber) != 2013) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (Seriennummern mit zwei Anfangsbuchstaben sollten 2013 zurückgeben) - Aufgabe 2" << std::endl;
            return false;
        }
    }

    // Seriennummern die weder als 2002er noch als 2013er Version erkannt werden sollten:
    for (string serialNumber : {"0B000000001", "000000000001", "00ABCDEFGHIJ"}) {
        if (getEuroSerialNumberVersion(serialNumber) != 0) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (Seriennummern im ungültigen Format sollten 0 zurückgeben) - Aufgabe 2" << std::endl;
            return false;
        }
    }
    return true;
#else
    return true;
#endif
}

bool test_checkEuroSerialNumber2002() {
#ifdef TEST_AUFGABE_5
    // Bedingung:
    // - Korrekte Berechnung nach Vorgabe der Aufgabenstellung für die 2002er Version
    
    // Gültige 2002er Seriennummern:
    for (string serialNumber : {"N61137837714", "N67101651876", "X12345678902"}) {
        if (!checkEuroSerialNumber2002(serialNumber)) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (sollte als gültige 2002er Seriennummer erkannt werden) - Aufgabe 5" << std::endl;
            return false;
        }
    }
    // Ungültige 2002er Seriennummern
    for (string serialNumber : {"N61137837717", "N67101651276", "X12345678901"}) {
        if (checkEuroSerialNumber2002(serialNumber)) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (sollte als ungültige 2002er Seriennummer erkannt werden) - Aufgabe 5" << std::endl;
            return false;
        }
    }
    return true;
#else
    return true;
#endif
}

bool test_checkEuroSerialNumber2013() {
#ifdef TEST_AUFGABE_6
    // Bedingung:
    // - Korrekte Berechnung nach Vorgabe der Aufgabenstellung für die 2013er Version

    // Gültige 2013er Seriennummern:
    for (string serialNumber : {"NA3509770816", "NA3408351535", "XA1234567899"}) {
        if (!checkEuroSerialNumber2013(serialNumber)) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (sollte als gültige 2013er Seriennummer erkannt werden) - Aufgabe 6" << std::endl;
            return false;
        }
    }
    // Ungültige 2013er Seriennummern
    for (string serialNumber : {"NA3509770817", "NA3408351536", "XA1234567891"}) {
        if (checkEuroSerialNumber2013(serialNumber)) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (sollte als ungültige 2013er Seriennummer erkannt werden) - Aufgabe 6" << std::endl;
            return false;
        }
    }
    return true;
#else
    return true;
#endif
}

bool test_checkEuroSerialNumberFormatBonus() {
#ifdef TEST_AUFGABE_7
    // Bedingung: 
    // - Länge = 12
    // - 1-2 Anfangsbuchstaben
    // - danach 9-10 Ziffern
    // - letzte Ziffer ungleich 0

    // Seriennummern die weder als 2002er noch als 2013er Version erkannt werden sollten:
    for (string serialNumber : {"X00000001", "X00000000000", "XY0000000000", "XYZ000000001", "X0000000000Y"}) { 
        if (getEuroSerialNumberVersion(serialNumber) != 0) {
            std::cout << "Fehler bei Seriennummer: " << serialNumber;
            std::cout << " (Seriennummern im ungültigen Format sollten 0 zurückgeben) - Aufgabe 7" << std::endl;
            return false;
        }
    }
    return true;
#else
    return true;
#endif
}

bool testsPassed() {
    bool testResult =
            test_getEuroSerialNumberVersion() &
            test_checkEuroSerialNumber2002() &
            test_checkEuroSerialNumber2013() &
            test_checkEuroSerialNumberFormatBonus();

    if (testResult) {
        std::cout << "Tests OK." << std::endl;
        return true;
    }
    std::cout << "Tests fehlgeschlagen." << std::endl;
    return false;
}