#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, i;
string stat, name;
set<string> names;

int main() {
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> stat >> name;
        if (stat == "entry") {
            cout << name << " entered";
            if (names.find(name) != names.end()) cout << " (ANOMALY)";
            else names.insert(name);
        } else {
            cout << name << " exited";
            if (names.find(name) == names.end()) cout << " (ANOMALY)";
            else names.erase(name);
        }
        cout << "\n";
    }
}
