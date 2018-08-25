#include <iostream>
#include <climits>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int TEAS[1005], TOPPINGS[1005];

int main() {
    int N, M, tea_price, topping_price, num_combos, mini_price = INT_MAX, temp, money;
    cin >> N;
    FOR(i,0,N) cin >> TEAS[i];
    cin >> M;
    FOR(i,0,M) cin >> TOPPINGS[i];
    FOR(i,0,N) {
        cin >> num_combos;
        FOR(j,0,num_combos) {
            cin >> temp;
            mini_price = min(mini_price, TEAS[i] + TOPPINGS[temp - 1]);
        }
    }
    cin >> money;
    cout << max(0, money / mini_price - 1) << endl;
}
