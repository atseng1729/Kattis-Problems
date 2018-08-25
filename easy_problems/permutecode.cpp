#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {
    int x;
    while (cin >> x && x != 0) {
        string S, P, M, C;
        cin >> S >> P >> C;
        M = C; // to set size of M
        int n = C.length();
        int d = ((int) pow(n, 1.5) + x) % n;
        M[d] = P[S.find(C[d])];
        int cur_index;
        FOR(i,1,n) {
            if ((cur_index = (d - i) % n) < 0) cur_index += n;
            M[cur_index] = P[S.find(C[cur_index]) ^ S.find(M[(cur_index + 1) % n])];
        }
        cout << M << endl;
    }
}
