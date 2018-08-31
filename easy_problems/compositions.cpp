#include <iostream>
#include <list>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int dp[35];

int solution(list<int> compositions, int count, int sum)
{
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (dp[sum]) return dp[sum];
    for (auto comp: compositions) {
        count += solution(compositions, 0, sum - comp);
        if (comp >= sum) break;
    }
    return dp[sum] = count;
}

int main()
{
    int cases;
    cin >> cases;
    FOR(i,0,cases) {
        int caseNum, n, m, k;
        cin >> caseNum >> n >> m >> k;
        list<int> compositions;
        FOR(j,1,n + 1) if (j % k != m) compositions.push_back(j);
        FOR(j,0,35) dp[j] = 0;
        cout << caseNum << ' ' << solution(compositions, 0, n) << endl;
    }
}
