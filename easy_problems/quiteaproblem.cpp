#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int i, j, OUTPUT, LEN;
string LINE, WORD = "roblem";

int main() {
    LEN = WORD.length();
    while(getline(cin, LINE)) {
        OUTPUT = 0;
        for (i = 0; i < LINE.length(); i++) {
            if ((char) tolower(LINE[i]) == 'p') {
                for (j = 0; j < LEN; j++) if ((char) tolower(LINE[i + j + 1]) == WORD[j]) OUTPUT++;
                if (OUTPUT == LEN) break;
                else OUTPUT = 0;
            }
        }
        cout << ((OUTPUT) ? "yes" : "no") << endl;
    }
}
