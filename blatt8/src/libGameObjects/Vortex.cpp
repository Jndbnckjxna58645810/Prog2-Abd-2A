#include "Vortex.h"

#include <list>
using std::list;
#include <vector>
using std::vector;
#include <cmath>
using std::hypot;
#include <algorithm>
using std::transform;
using std::sort;
using std::find;
#include <numeric>
using std::accumulate;

#include "Coordinates.h"
using Sea::Coordinates;
using Sea::FCoordinates;


namespace GameObjects {

    Vortex::Vortex(list<FCoordinates> const & trackerPositions, float newRadius)
    : FCoordinates(meanPosition(trackerPositions)), radius(newRadius)
    {
    }

    FCoordinates Vortex::meanPosition(list<FCoordinates> const & trackerPositions)
    {
        vector<float> Xs, Ys;
        Xs.reserve(trackerPositions.size());
        Ys.reserve(trackerPositions.size());

        // TODO Aufgabe 3:
        //  Zerlegt die `Coordinates` in `trackerPositions`, sodass ihre X- und Y-Werte entsprechend auf die beiden Vektoren `Xs` und `Ys` aufgeteilt werden.
        //  Ruft anschließend `calculatePreciseMeanPosition(..)` für jede der beiden Listen auf, um den jeweiligen Mittelwert zu berechnen.
        transform(trackerPositions.begin(), trackerPositions.end(), std::back_inserter(Xs), [](FCoordinates coord){ return coord.getX(); });
        transform(trackerPositions.begin(), trackerPositions.end(), std::back_inserter(Ys), [](FCoordinates coord){ return coord.getY(); });
        return { calculatePreciseMeanPosition(Xs), calculatePreciseMeanPosition(Ys) };
    }

    float Vortex::calculatePreciseMeanPosition(vector<float> nums)
    {
        // TODO Aufgabe 3:
        //  Berechnet hier für die übergebene Liste möglichst genau den Mittelwert der enthaltenen `float`-Zahlen, ohne den Datentyp `double` zu nutzen.
        //  Hinweis: VL-Video: Einführung und Basics > Basics > Präzision
        std::sort(nums.begin(), nums.end(), [](float a, float b) { return std::abs(a) < std::abs(b); });
        return accumulate(nums.begin(), nums.end(), 0.f) / float(nums.size());
    }

    bool Vortex::checkHit(Coordinates const & coordinates)
    {
        if (inRange(coordinates)) {
            hits.push_back(coordinates);
            return true;
        }
        return false;
    }

    bool Vortex::inRange(Coordinates const & coordinates) const
    {
        auto x2 = float(coordinates.getX()),
             y2 = float(coordinates.getY());
        return hypot(x - x2, y - y2) <= radius;
    }

    bool Vortex::hasHitSomething() const
    {
        return !hits.empty();
    }

    void Vortex::output(OutputGrid & grid) const
    {
        grid.walk2([&](auto & gridCell, Coordinates const & coords) {
            if (inRange(coords)) {
                gridCell.vortex = true;

                if (!gridCell.ship) {
                    // TODO Aufgabe 5:
                    //  Prüft, ob die aktuelle Position in der Trefferliste `hits` enthalten ist.
                    //  Wenn ja, setzt `gridCell.ship` auf `true`.
                    gridCell.ship = find(hits.cbegin(), hits.cend(), coords) != hits.end();
                }
            }
        });
    }

}
