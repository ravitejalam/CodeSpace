#include <bits/stdc++.h>

using namespace std;

bool overLap(int A, int B, int C, int D, int E, int F, int G, int H){
    if(C<=E or G<=A or B>=H or D<=F)
        return false;
    return true;
}

int solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    if(overLap(A,B,C,D,E,F,G,H))
        return abs(max(A,E)-min(C,G))*abs(max(B,F)-min(D,H));
    return 0;
}