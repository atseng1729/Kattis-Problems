#include <iostream>
#include <string>
#include <list>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {
    int cases;
    cin >> cases;
    FOR(i,0,cases) {
        string alien_number, source_lang, target_lang;
        int source_digits, target_digits, value = 0, temp;
        cin >> alien_number >> source_lang >> target_lang;
        source_digits = source_lang.length();
        target_digits = target_lang.length();
        list<char> output;


        FOR(i,0,alien_number.length()) value = source_digits * value + source_lang.find(alien_number[i]);

        while (value >= target_digits) {
            output.push_front(target_lang[value % target_digits]);
            value /= target_digits;
        }
        output.push_front(target_lang[value]);

        cout << "Case #" << (i + 1) << ": ";
        for (auto c: output) cout << c;
        cout << '\n';
    }
}
