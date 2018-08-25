#include <iostream>
#include <list>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
list<int> *map = new list<int>[26];

void addEdge(int v, int w)
{
    map[v].push_back(w);
}

int bfs(int start, int end)
{
    if (start == end) return 1;
    char visited[26];
    FOR(i,0,26) visited[i] = 0;
    list<int> queue;
    queue.push_back(start);
    visited[start] = 1;

    while (!queue.empty()) {
        start = queue.front();
        queue.pop_front();
        for (auto i: map[start]) {
            if (i == end) return 1;
            if (!visited[i]) { queue.push_back(i); visited[i] = 1; }
        }
    }
    return 0;
}

int main() {
    int M, N;
    char c1, c2;
    string word, trans_word;
    cin >> M >> N;
    FOR(i,0,M) { cin >> c1 >> c2; addEdge(c1 - 'a', c2 - 'a'); }
    FOR(i,0,N) {
        cin >> word >> trans_word;
        int length = word.length();
        if (length == trans_word.length()) {
            string possible = "yes";
            FOR(j,0,length)
                if (!bfs(word[j] - 'a', trans_word[j] - 'a')) { possible = "no"; break; }
            cout << possible << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
