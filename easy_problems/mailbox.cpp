#include <iostream>
#include <climits>
#include <time.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define SUM(a,b) (b - a + 1) * (a + b) / 2
int N, K, M, dp[100][100][10];

int solution(int lower, int upper, int iterations)
{
    if (lower == upper) return lower;
    if (upper - lower == 1) return (lower + upper);
    if (iterations <= 1) return SUM(lower,upper);
    if (dp[lower][upper][iterations] != 0) return dp[lower][upper][iterations];
    int mini = INT_MAX;
    FOR(i,lower + 1, upper) {
        mini = min(mini, max(solution(lower, i - 1, iterations - 1)
            , solution(i + 1, upper, iterations)) + i);
    }
    return (dp[lower][upper][iterations] = mini);
}

int main() {
    cin >> N;
    FOR(i,0,N) {
        cin >> K >> M;
        cout << solution(1, M, K) << endl;
        FOR(j,0,100) FOR(k,j,100) FOR(l,1,10) dp[j][k][l] = 0;
    }
}
