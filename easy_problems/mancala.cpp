#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int P, K, N, BOARDS[2005][80], DIGITS[2005];

void solution(int n)
{
    if (DIGITS[n]) DIGITS[n];
    solution(n - 1);
    FOR(i,0,DIGITS[n-1]) BOARDS[n][i] = BOARDS[n][i-1];
    DIGITS[n] = DIGITS[n - 1];
    int zero = 0;
    FOR(i,0,DIGITS[n]) if (BOARDS[n][i] == 0) zero = i;
    if (zero == 0) BOARDS[n][0] = 1;
    else { FOR(j,0,zero) BOARDS[n][j]--; BOARDS[n][zero] = zero; }
    if (zero == DIGITS[n]) DIGITS[n]++;
}

int main() {
    cin >> P;
    int i, j;
    BOARDS[1][0] = 1; DIGITS[1] = 1;
    FOR(i,0,P) {
        cin >> K >> N;
        solution(N);
        cout << K << DIGITS[N] << endl;
        FOR(j,0,DIGITS[N]) cout << BOARDS[N][j] << ' ';
        cout << '\n';
    }
}
