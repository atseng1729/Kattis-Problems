#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double N, e = 2.71828182845904523536, lower = 0, upper = e, middle;

int main() {
    cin >> N;
    while (upper - lower > .000001) {
        middle = (lower + upper) / 2;
        (pow(middle, N) > N) ? upper = middle : lower = middle;
    }
    cout << setprecision(10) << lower << endl;
}
