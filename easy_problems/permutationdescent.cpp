#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int P, K, N, V, MODU = 1001113;
long long PDC[105][105];

long long pdc(int n, int v)
{
    if (v == 0 || v == n - 1) return 1;
    if (PDC[n][v]) return PDC[n][v];
    return PDC[n][v] = ((n - v) * pdc(n - 1, v - 1) + (v + 1) * pdc(n - 1, v)) % MODU;
}

int main() {
    cin >> P;
    FOR(i,0,P) { cin >> K >> N >> V; cout << K << " " << pdc(N, V) << endl; };
    return 0;
}
