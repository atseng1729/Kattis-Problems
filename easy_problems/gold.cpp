#include <iostream>
#include <list>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
int M, N, cur, gold, visited[2600];
char vals[2600];
list<int> queue;

int check_surrounding(int cur)
{
    return (vals[cur - 1] != 'T' && vals[cur + 1] != 'T'
        && vals[cur - M] != 'T' && vals[cur + M] != 'T');
}

int process_move(int cur)
{
    if (visited[cur] || vals[cur] == '#') return 0;
    if (vals[cur] == 'G') gold++;
    visited[cur] = 1;
    return 1;
}

int main() {
    cin >> M >> N;
    FOR(i,0,M*N) { cin >> vals[i]; if (vals[i] == 'P') cur = i; }
    queue.push_back(cur);
    visited[cur] = 1;

    while (!queue.empty()) {
        cur = queue.front();
        queue.pop_front();
        if (check_surrounding(cur)) {
            if (process_move(cur - 1)) queue.push_back(cur - 1);
            if (process_move(cur + 1)) queue.push_back(cur + 1);
            if (process_move(cur - M)) queue.push_back(cur - M);
            if (process_move(cur + M)) queue.push_back(cur + M);
        }
    }

    cout << gold << endl;
}
