#include <iostream>
using namespace std;

int M, N, count, cur, step;
char vals[405];
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

void updateStep(char c)
{
    if (c == '/') {
        if (abs(step) == 1) step *= -M;
        else step /= -M;
    } else if (c == '\\') {
        if (abs(step) == 1) step *= M;
        else step /= M;
    }
}

void addExit()
{
    // determine initial direction
    if (cur < M) step = M;
    else if (cur % M == 0) step = 1;
    else if (cur > N * M - M) step = -M;
    else step = -1;

    while (vals[cur] != 'x') {
        cur += step;
        updateStep(vals[cur]);
    }

    vals[cur] = '&';
}

void printHouse()
{
    cout << "HOUSE " << count << endl;
    FOR(i,0,N) {
        FOR(j,0,M) cout << vals[i * M + j];
        cout << '\n';
    }
}

int main() {
    while (cin >> M >> N && M != 0 && N != 0) {
        count++;
        FOR(i,0,M*N) { cin >> vals[i]; if (vals[i] == '*') cur = i; }
        addExit();
        printHouse();
    }
}
