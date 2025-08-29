// Problem 11
#include <bits/stdc++.h>
using namespace std;

int minLengthAfterDeletions(const string &s) {
    int R=0,L=0,U=0,D=0;
    for(char c: s){
        if(c=='R') R++;
        else if(c=='L') L++;
        else if(c=='U') U++;
        else if(c=='D') D++;
    }
    return abs(R-L) + abs(U-D);
}

// usage example (not required in submission):
// cout << minLengthAfterDeletions("RLUUDD") << endl;
