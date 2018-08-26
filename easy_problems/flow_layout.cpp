#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)


int main() {
    int m;
    while (cin >> m && m != 0) {
        int max_width = 0, max_height = 0, cur_width = 0, cur_height = 0, dim1, dim2;

        while (cin >> dim1 >> dim2 && dim1 != -1 && dim2 != -1) {
            if (dim1 + cur_width <= m) {
                cur_width += dim1;
                if (cur_width > max_width) max_width = cur_width;
                cur_height = max(cur_height, dim2);
            } else {
                cur_width = dim1;
                max_height += cur_height;
                cur_height = dim2;
            }
        }
        max_height += cur_height;

        cout << max_width << " x " << max_height << endl;
    }
}
