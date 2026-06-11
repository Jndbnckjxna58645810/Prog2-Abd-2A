#include <iostream>
#include "test.h"

// TODO Aufgabe 3:
//  Inkludiert die Funktionen aus den `euroCheck.h/cpp`-Dateien.
#include "euroCheck.h"

using std::string;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.
string inputNextSerialNumber() {
    string n;
    std::cin >> n;
    return n;
}

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.
void checkSerialNumberAndPrintResult(string & serialNumber) {
    switch (getEuroSerialNumberVersion(serialNumber)) {
        case 2002:
            std::cout << (checkEuroSerialNumber2002(serialNumber) ? "Gueltig" : "Ungueltig") << std::endl;
            break;
        case 2013:
            std::cout << (checkEuroSerialNumber2013(serialNumber) ? "Gueltig" : "Ungueltig") << std::endl;
            break;
        default: std::cout << "Ungueltig" << std::endl; break;
    }
}

int main() {
    if (!testsPassed()) {
        return 1;
    }

    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.
    string serialNumber;
    do {

        // TODO Aufgabe 1:
        //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.
        serialNumber = inputNextSerialNumber();

        // TODO Aufgabe 4:
        //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.
        if (serialNumber == "fertig") { break; }

        checkSerialNumberAndPrintResult(serialNumber);
    } while (true);

    return 0;
}
