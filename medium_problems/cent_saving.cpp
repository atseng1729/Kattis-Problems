#include <iostream>
#include <climits>
using namespace std;

#define ROUND(x) ((((x) + 5) / 10) * 10)

int N, D, prices[2000],dp[21], minimum;

int main() {
    int i, j;
    cin >> N >> D;
    for (i = 0; i < N; i++) cin >> prices[i];

    for (i = 1; i <= D; i++) dp[i] = INT_MAX / 2;
    dp[0] = 0;

    for (i = 0; i < N; i++) {
        for (j = D; j > 0; j--) {
            dp[j] = min(dp[j] + prices[i], ROUND(dp[j - 1] + prices[i]));
        }
        dp[0] += prices[i];
    }

    minimum = INT_MAX / 2;
    for (i = 0; i < D + 1; i++) minimum = min(minimum, dp[i]);
    cout << ROUND(minimum) << endl;

    return 0;
}
