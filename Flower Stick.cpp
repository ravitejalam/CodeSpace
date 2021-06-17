#include "bits/stdc++.h"

using namespace std;

vector<int> flowerStick(vector<int> flowerStick, int random)
{
    sort(flowerStick.begin(), flowerStick.begin() + random);
    sort(flowerStick.begin() + random, flowerStick.end(), greater<int>());
    return flowerStick;
}

