#include <iostream>
#include <string>
using namespace std;

string s;
int OUTPUT[] = {2, 22, 222, 3, 33, 333, 4, 44, 444, 5, 55, 555, 6, 66, 666, 7, 77, 777, 7777, 8, 88, 888, 9, 99, 999, 9999, 0};

int main() {
    int n, i, j, length, prev, cur;
    cin >> n;
    getline(cin, s);
    for (i = 1; i < (n + 1); i++) {
        getline(cin, s);
        length = s.length();
        prev = -1;
        cout << "Case #" << i << ": ";
        for (j = 0; j < length; j++) {
            cur = s[j] - 'a';
            if (cur < 0) cur = 26;
            cur = OUTPUT[cur];
            if (prev % 10 == cur % 10) cout << ' ';
            cout << cur;
            prev = cur;
        }
        cout << '\n';
    }
}
