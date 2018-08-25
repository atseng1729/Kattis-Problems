#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double N, P, S, V, lowerC, upperC, tempLowerC, tempUpperC;
double nOverP, logN, sOverV, sqrt2;

int main() {
    cin >> N >> P >> S >> V;
    lowerC = 0, upperC = 100;
    nOverP = N / P / pow(10, 9);
    logN = log2(N);
    sOverV = S / V;
    sqrt2 = sqrt(2);

    while (upperC - lowerC > .0000000001) {
        tempLowerC = (2 * lowerC + upperC) / 3;
        tempUpperC = (lowerC + 2 * upperC) / 3;
        if (nOverP * pow(logN, tempLowerC * sqrt2) + sOverV * (1 + 1 / tempLowerC)
            > nOverP * pow(logN, tempUpperC * sqrt2) + sOverV * (1 + 1 / tempUpperC)) {
            lowerC = tempLowerC;
        } else {
            upperC = tempUpperC;
        }
    }
    cout << setprecision(14) << (nOverP * pow(logN, lowerC * sqrt2) + sOverV * (1 + 1 / lowerC)) << " ";
    cout << setprecision(14) << lowerC;
    return 0;
}
