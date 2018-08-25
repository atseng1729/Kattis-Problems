#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int dp[1000005], arr[105], stones, n;

int batchets(int stones)
{
    if (stones < 0) return 1;
    if (stones == 0) return 2;
    if (dp[stones] != 0) return dp[stones];
    FOR(i,0,n)
        if (batchets(stones - arr[i]) == 2) return dp[stones] = 1;
    return dp[stones] = 2;
}

int main()
{
    while(cin >> stones >> n)
    {
        FOR(i,0,n) cin >> arr[i];
        FOR(i,0,1000000) dp[i] = 0;
        cout << ((batchets(stones) == 1) ? "Stan wins" : "Ollie wins") << endl;
    }
}
