#include <iostream>
using namespace std;

long long M, P, L, E, R, S, N, temp;

int main() {
    while(cin >> M >> P >> L >> E >> R >> S >> N) {
        for (int i = 0; i < N; i++) {
            temp = M;
            M = P / S;
            P = L / R;
            L = temp * E;
        }
        cout << M << endl;
    }
}
