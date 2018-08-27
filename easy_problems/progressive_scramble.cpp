#include <iostream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

void encrypt(string s)
{
    int u = 0, length = s.length();
    FOR(i,0,length) {
        if (s[i] != ' ') { u += s[i] - 'a' + 1; u %= 27; }
        if (u == 0) cout << ' ';
        else cout << (char) ((u + 'a' - 1));
    }
    cout << '\n';
}

void decrypt(string s)
{
    int u = 0, length = s.length();
    FOR(i,0,length) {
        
    }
}

int main() {
    int cases;
    cin >> cases;

    string temp;
    getline(cin, temp);

    FOR(i,0,cases) {
        string temp;
        getline(cin, temp);
        if (temp[0] == 'e') encrypt(temp.substr(2));
    }
}
