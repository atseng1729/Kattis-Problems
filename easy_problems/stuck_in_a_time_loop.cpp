#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
int N;

int main() {
    cin >> N;
    FOR(i,0,N) cout << (i + 1) << " Abracadabra" << endl;
}
