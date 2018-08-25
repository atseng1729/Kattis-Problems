#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int X, Y, N, MOVES[55], ACTUAL_MOVE;
string s;

int dest()
{
    int orient = 0, x = 0, y = 0;
    for (int i = 0; i < N; i++) {
        switch (MOVES[i]) {
            case -1:
                if (--orient < 0) orient += 4;
                break;
            case 0:
                switch (orient) {
                    case 0: { y++; break; }
                    case 1: { x++; break; }
                    case 2: { y--; break; }
                    case 3: { x--; break; }
                }
                break;
            case 1:
                orient = (orient + 1) % 4;
                break;
        }
    }
    return (X == x && Y == y) ? 1 : 0;
}

int main() {
    cin >> X >> Y >> N;
    string instructions[] = {"Left", "Forward", "Right"};
    int found_correct = 0;

    FOR(i,0,N) { cin >> s; MOVES[i] = (s == "Forward") ? 0 : ((s == "Right") ? 1 : -1); }

    FOR(i,0,N) {
        ACTUAL_MOVE = MOVES[i];
        FOR(j,-1,2) {
            MOVES[i] = j;
            if (j != ACTUAL_MOVE && dest()) {
                cout << i + 1 << ' ' << instructions[j + 1];
                found_correct = 1;
                break;
            }
        }
        if (found_correct == 1) break;
        MOVES[i] = ACTUAL_MOVE;
    }
}
