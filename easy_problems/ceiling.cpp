#include <iostream>
#include <cstdlib>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

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

int equal_pat_nodes(node *node1, node *node2)
{
    if (node1 == NULL && node2 == NULL) return 1;
    if (node1 == NULL || node2 == NULL) return 0;
    return (equal_pat_nodes(node1 -> left, node2 -> left)
        && equal_pat_nodes(node1 -> right, node2 -> right));
}

int main()
{
    int n, k, temp, unique_trees = 0;
    cin >> n >> k;
    node *trees[n];
    FOR(i,0,n) {
        node *node = NULL;
        FOR(j,0,k) { cin >> temp; node = insert(node, temp); }
        trees[i] = node;
        temp = 1;
        FOR(j,0,i) if (equal_pat_nodes(trees[i], trees[j])) { temp = 0; break; }
        unique_trees += temp;
    }
    cout << unique_trees << endl;
}
