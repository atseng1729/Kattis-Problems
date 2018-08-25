#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int POS[9], n;
double SUM;

double dist(int a, int b)
{
    return sqrt(((a % 3) - (b % 3)) * ((a % 3) - (b % 3))
        + (((int) a / 3) - ((int) b / 3)) * (((int) a / 3) - ((int) b / 3)));
}

int main() {
    FOR(i,0,9) { cin >> n; POS[n - 1] = i; }
    FOR(i,0,8) SUM += dist(POS[i], POS[i + 1]);
    cout << setprecision(10) << SUM << endl;
}
