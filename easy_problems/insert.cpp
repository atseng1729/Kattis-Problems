#include <iostream>
#include <cstdlib>
using namespace std;

int N, i, val, CARRY;
unsigned long long DP[100][100], ANSWER;

typedef struct node node;

struct node
{
    int val;
    node *left, *right;
};

node *newNode(int val)
{
    node *temp = (node *) malloc(sizeof(node));
    temp -> val = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

node *insert(node *node, int val)
{
    if (node == NULL) return newNode(val);
    if (val < node -> val) node -> left = insert(node -> left, val);
    else node -> right = insert(node -> right, val);
    return node;
}

int count(node *node)
{
    if (node == NULL) return 0;
    if (node -> left == NULL && node -> right == NULL) return 1;
    return (1 + count(node -> left) + count(node -> right));
}

unsigned long long ncr(int n, int r)
{
    if (n == r || r == 0) return 1;
    if (r == 1) return n;
    if (DP[n][r]) return DP[n][r];
    return DP[n][r] = ncr(n - 1, r) + ncr(n - 1, r - 1);
}

void permutations(node *node)
{
    if (node == NULL) return;
    if ((node -> left != NULL) && (node -> right != NULL)) {
        int left = count(node -> left);
        int right = count(node -> right);
        int mini = min(left, right);
        ANSWER *= ncr(left + right, mini);
        while (ANSWER % 10 == 0) { ANSWER /= 10; CARRY++; }
    }
    permutations(node -> left);
    permutations(node -> right);
}

int main() {
    while (cin >> N && N != 0) {
        node *bst = NULL;
        ANSWER = 1;
        CARRY = 0;
        for (i = 0; i < N; i++) { cin >> val; bst = insert(bst, val); }
        permutations(bst);
        cout << ANSWER;
        for (i = 0; i < CARRY; i++) cout << '0';
        cout << '\n';
    }
}
