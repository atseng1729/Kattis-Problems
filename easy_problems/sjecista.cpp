#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SUM(n) ((n)*((n) + 1)/2)
int N, TOTAL;

int main() {
    cin >> N;
    TOTAL = 0;
    FOR(i,1,N-2) TOTAL += (i * SUM(N - 2 - i));
    if (N < 4) cout << 0 << endl;
    else cout << TOTAL << endl;
}
