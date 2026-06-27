// TODO:
//  Entfernt die Kommentar-Zeichen (//) fuer Aufgaben, die erledigt sind und getestet werden sollen:


#define TEST_AUFGABE_3 // TODO Aufgabe 3


#include "test.h"

#include <cmath>
using std::abs;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "Vortex.h"
using GameObjects::Vortex;

#include "utils.h"
using Utils::n_endl;


bool testPassed()
{
    bool testResult =
            testCalculatePreciseMeanPosition();

    if (testResult) {
        cout << "Test OK." << n_endl(2);
        return true;
    }
    cout << "Test fehlgeschlagen." << n_endl(2);
    return false;
}

bool testCalculatePreciseMeanPosition()
{
#ifdef TEST_AUFGABE_3
    constexpr unsigned int numOnes = 10'000;
    constexpr float large = 1'000'000'000.f;

    // fill with `large + 1 + ... + 1 - large`
    vector<float> nums = { large };
    for (unsigned int i = 0; i < numOnes; ++i) nums.push_back(1.f);
    nums.push_back(-large);

    // arithmetically, large ... -large cancel out, and only numOnes * 1.0 remain
    float expected = float(numOnes) / float(nums.size());

    // naive mean loses 1.0 values, because the intermediate sum is at large.
    float naiveSum = 0.f;
    for (float num : nums) naiveSum += num;
    float naiveMean = naiveSum / nums.size();

    float preciseMean = Vortex::calculatePreciseMeanPosition(nums);

    bool betterThanNaive = abs(preciseMean - expected) < abs(naiveMean - expected);

    if (!betterThanNaive) {
        cout << "Aufgabe 3: Durchschnitt nicht präziser berechnet." << endl;
        cout << "  Erwartet: " << expected << endl;
        cout << "  Naiv:" << naiveMean << endl;
        cout << "  Berechnet: " << preciseMean << endl;
    }
    return betterThanNaive;
#else
    return true;
#endif
}