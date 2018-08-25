#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (a - 1); i >= (b); i--)
string s;

int main() {
    int n, len, k, overlap;
    cin >> n;
    FOR(i,0,n) {
        cin >> s;
        len = s.length();
        k = sqrt(len - 1) + 1;
        FOR(j,0,k) FORD(l,k,0) if (j + k * l < len) cout << s[j + k * l];
        cout << '\n';
    }
}
