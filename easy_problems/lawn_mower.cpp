#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int nx, ny;
double w, coords[1005];

int isMowed()
{
    int isPossible = 1;
    FOR(i,0,nx) cin >> coords[i];
    sort(coords, coords + nx);
    if (75 - coords[nx - 1] > w / 2 || coords[0] > w / 2) isPossible = 0;
    double prev = coords[0];
    FOR(i,1,nx) {
        if (coords[i] - prev > w) isPossible = 0;
        prev = coords[i];
    }

    FOR(i,0,ny) cin >> coords[i];
    sort(coords, coords + ny);
    if (100 - coords[ny - 1] > w / 2 || coords[0] > w / 2) isPossible = 0;
    prev = coords[0];
    FOR(i,1,ny) {
        if (coords[i] - prev > w) isPossible = 0;
        prev = coords[i];
    }
    return isPossible;
}

int main()
{
    while (cin >> nx >> ny >> w && nx != 0 && ny != 0) {
        cout << ((isMowed()) ? "YES" : "NO") << endl;
    }
}
