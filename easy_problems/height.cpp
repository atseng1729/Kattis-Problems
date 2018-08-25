#include <iostream>
#include <list>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {
    int N, val;
    cin >> N;
    FOR(i,0,N) {
        list<int> prev_vals;
        int steps = 0;
        cin >> val;
        cout << val << ' ';
        FOR(j,0,20) {
            cin >> val;
            for (auto i: prev_vals) if (i > val) steps++;
            prev_vals.push_back(val);
        }
        cout << steps << endl;
    }
}
