#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int factors[500015];
vector<int> primes;

int isPrime(int a)
{
    for (auto prime: primes) {
        if (a % prime == 0) return 0;
        if (2 * prime >= a) return 1;
    }
    return 1;
}

void initPrimes()
{
    primes.push_back(2);
    primes.push_back(3);
    for (int i = 6; i < 500010; i += 6) {
        if (isPrime(i - 1)) primes.push_back(i - 1);
        if (isPrime(i + 1)) primes.push_back(i + 1);
    }
}

int main()
{
    initPrimes();
    cout
    return 0;
}
