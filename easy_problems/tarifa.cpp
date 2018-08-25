#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
int monthly_usage, months, total, temp;

int main() {
    cin >> monthly_usage;
    cin >> months;
    total = (months + 1) * monthly_usage;
    FOR(i,0,months) {
        cin >> temp;
        total -= temp;
    }
    cout << total << endl;
    return 0;
}
