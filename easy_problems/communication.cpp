#include <iostream>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
unordered_map<int,int> vals;

int main() {
    int n, b;
    cin >> n;
    FOR(i,0,256) vals.insert({((i ^ (i << 1)) % 256), i});
    FOR(i,0,n) { cin >> b; cout << (vals.find(b) -> second) << ((i != n - 1) ? ' ' : '\n'); }
}
