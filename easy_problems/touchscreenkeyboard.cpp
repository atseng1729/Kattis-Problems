#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
string keyboard = "qwertyuiopasdfghjkl-zxcvbnm";
int distances[800];
unordered_map<char,int> keys;

void init()
{
    FOR(i,0,27) keys.insert({keyboard[i], i});
}

int distance(string s1, string s2)
{
    int length = s1.length();
    int dist = 0, pos1, pos2;
    FOR(i,0,length) {
         pos1 = keys[s1[i]];
         pos2 = keys[s2[i]];
         dist += abs(pos1 / 10 - pos2 / 10) + abs(pos1 % 10 - pos2 % 10);
    }
    return dist;
}

int main() {
    int cases;
    cin >> cases;
    init();
    FOR(i,0,cases) {
        string word, option_word;
        int num_options;
        cin >> word >> num_options;
        set<pair<int, string> > options_dist;
        FOR(j,0,num_options) {
            cin >> option_word;
            options_dist.insert(make_pair(distance(word, option_word), option_word));
        }
        for (const auto &i: options_dist)
            cout << i.second << ' ' << i.first << endl;
    }
}
