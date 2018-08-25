#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define pi 3.1415926535

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int cases, radius, coordinates;
    int first_x, first_y, prev_x, prev_y, cur_x, cur_y;
    double perimeter, ratio;
    cin >> cases;
    cout << setprecision(10);
    
    FOR(i,0,cases) {
        cin >> radius >> coordinates;
        cin >> prev_x >> prev_y;
        first_x = prev_x;
        first_y = prev_y;
        perimeter = 0;
        FOR(i,1,coordinates) {
            cin >> cur_x >> cur_y;
            perimeter += distance(prev_x, prev_y, cur_x, cur_y);
            prev_x = cur_x;
            prev_y = cur_y;
        }
        perimeter += distance(prev_x, prev_y, first_x, first_y);
        ratio = 1 - 2 * pi * radius / perimeter;
        if (ratio > 0) cout << ratio << endl;
        else cout << "Not possible" << endl;
    }
}
