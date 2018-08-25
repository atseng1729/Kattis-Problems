#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (a - 1); i >= (b); i--)
#define COMP(d1, d2, r2) ((d1) * (d1) + (d2) * (d2) <= (r2))
double C, N, X[100], Y[100], V[100], M, x1, y1, PI = 3.141592653589, COLOR;
string colors[100];

int main() {
    cin >> C;
    FOR(i,0,C) {
        cin >> N;
        FOR(j,0,N) cin >> X[j] >> Y[j] >> V[j] >> colors[j];
        cin >> M;
        FOR(j,0,M) {
            cin >> x1 >> y1;
            COLOR = -1;
            FORD(k,N,0) {
                if (COMP(x1 - X[k], y1 - Y[k], V[k] / PI)) {cout << colors[k] << endl; COLOR = 0; break;}
            }
            if (COLOR == -1) cout << "white" << endl;
        }
        FOR(j,0,N) {X[j] = 0; Y[j] = 0; V[j] = 0;}
    }
}
