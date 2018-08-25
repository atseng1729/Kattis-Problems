#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int UF[102][101], M, N, AMOEBAS;
char C[102][101];

int find(int i)
{
    if (UF[i / N][i % N] > -1) return (UF[i / N][i % N] = find(UF[i / N][i % N]));
    return i;
}

void Union(int x, int y)
{
    int root1 = find(x);
    int root2 = find(y);
    if (root1 == root2) return;
    int root1_val = UF[root1 / N][root1 % N];
    int root2_val = UF[root2 / N][root2 % N];
    if (root1_val == root2_val) {
        UF[root2 / N][root2 % N] = root1;
        UF[root1 / N][root1 % N]--;
    } else if (root1_val < root2_val) {
        UF[root2 / N][root2 % N] = root1;
    } else {
        UF[root1 / N][root1 % N] = root2;
    }

}

int testPrint() {
    FOR(i,1,M+1) {
        FOR(j,0,N) cout << UF[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cin >> M >> N;
    FOR(i,0,102) FOR(j,0,101) { C[i][j] = '.'; UF[i][j] = -1; }
    FOR(i,1,M + 1) FOR(j,0,N) cin >> C[i][j];

    FOR(j,0,N) {
        FOR(i,1,M+1) {
            if (C[i][j] == '#') {
                if (C[i-1][j+1] == '#') Union((i * N + j), ((i - 1) * N + j + 1));
                if (C[i][j+1] == '#') Union((i * N + j), (i * N + j + 1));
                if (C[i+1][j+1] == '#') Union((i * N + j), ((i + 1) * N + j + 1));
                if (C[i+1][j] == '#') Union((i * N + j), ((i + 1) * N + j));
                if (UF[i][j] == -1) UF[i][j]--;
            }
        }
    }
    FOR(i,1,M+1) FOR(j,0,N) if (UF[i][j] < -1) AMOEBAS++;
    cout << AMOEBAS << endl;
}
