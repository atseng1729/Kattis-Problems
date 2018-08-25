#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
long N, W, H, MAX, TEMP;

int main() {
    cin >> N >> W >> H;
    MAX = W * W + H * H;
    FOR(i,0,N) {
        cin >> TEMP;
        cout << ((TEMP * TEMP <= MAX) ? "DA" : "NE") << endl;
    }
}
