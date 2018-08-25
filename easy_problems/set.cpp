#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int NUM[12], i, j, k, CARDS, NOSET;
char SHAPE[12], PAT[12], COLOR[12];

int main() {
    CARDS = 12;
    NOSET = 1;
    FOR(i,0,CARDS) cin >> NUM[i] >> SHAPE[i] >> PAT[i] >> COLOR[i];

    for (i = 0; i < CARDS; i++) {
        for (j = i + 1; j < CARDS; j++) {
            for (k = j + 1; k < CARDS; k++) {
                if ((NUM[i] == NUM[j] && NUM[i] == NUM[k] && NUM[j] == NUM[k])
                    || (NUM[i] + NUM[j] + NUM[k] == 6)) {
                    if ((SHAPE[i] == SHAPE[j] && SHAPE[i] == SHAPE[k] && SHAPE[j] == SHAPE[k])
                        || ((int) (SHAPE[i]+SHAPE[j]+SHAPE[k]) == 230)) {
                        if ((PAT[i] == PAT[j] && PAT[i] == PAT[k] && PAT[j] == PAT[k])
                            || ((int) (PAT[i]+PAT[j]+PAT[k]) == 246)) {
                            if ((COLOR[i] == COLOR[j] && COLOR[i] == COLOR[k] && COLOR[j] == COLOR[k])
                                || ((int) (COLOR[i]+COLOR[j]+COLOR[k]) == 233)) {
                                cout << i + 1<< " " << j + 1 << " " << k + 1 << endl;
                                NOSET = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (NOSET) cout << "no sets" << endl;
}
