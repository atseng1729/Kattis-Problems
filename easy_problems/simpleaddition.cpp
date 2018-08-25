#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int LEN1, LEN2, i, carry, temp, mini, maxi;
string S1, S2, S3, S4;
list<int> answer;

int main() {
    cin >> S1 >> S2;
    reverse(S1.begin(), S1.end());
    reverse(S2.begin(), S2.end());
    LEN1 = S1.length();
    LEN2 = S2.length();
    if (LEN1 < LEN2) { S3 = S2; S4 = S1; swap(LEN1, LEN2); }
    else { S3 = S1; S4 = S2; }
    list<int> :: iterator it;

    for (i = 0; i < LEN2; i++) {
        temp = S3[i] + S4[i] + carry - 2 * '0';
        answer.push_front((temp % 10));
        carry = temp / 10;
    }
    for (;i < LEN1; i++) {
        temp = S3[i] + carry - '0';
        answer.push_front((temp % 10));
        carry = temp / 10;
    }
    if (carry) answer.push_front(carry);

    for (it = answer.begin(); it != answer.end(); it++) cout << *it;
}
