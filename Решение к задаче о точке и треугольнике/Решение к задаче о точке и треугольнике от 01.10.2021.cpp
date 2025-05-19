#include <iostream>
#include <cmath>
using namespace std;
float x1, yy, x2, y2, x3, y3, x, y, l1, l2, l3, l12, l13, l23;
int main()
{
    cin >> x1 >> yy >> x2 >> y2 >> x3 >> y3 >> x >> y;

    l1 = sqrt((fmax(x, x1) - fmin(x, x1)) * (fmax(x, x1) - fmin(x, x1)) + (fmax(y, yy) - fmin(y, yy)) * (fmax(y, yy) - fmin(y, yy)));
    l2 = sqrt((fmax(x, x2) - fmin(x, x2)) * (fmax(x, x2) - fmin(x, x2)) + (fmax(y, y2) - fmin(y, y2)) * (fmax(y, y2) - fmin(y, y2)));
    l3 = sqrt((fmax(x, x3) - fmin(x, x3)) * (fmax(x, x3) - fmin(x, x3)) + (fmax(y, y3) - fmin(y, y3)) * (fmax(y, y3) - fmin(y, y3)));
    l12 = sqrt((fmax(x2, x1) - fmin(x2, x1)) * (fmax(x2, x1) - fmin(x2, x1)) + (fmax(y2, yy) - fmin(y2, yy)) * (fmax(y2, yy) - fmin(y2, yy)));
    l13 = sqrt((fmax(x1, x3) - fmin(x1, x3)) * (fmax(x1, x3) - fmin(x1, x3)) + (fmax(yy, y3) - fmin(yy, y3)) * (fmax(yy, y3) - fmin(yy, y3)));
    l23 = sqrt((fmax(x2, x3) - fmin(x2, x3)) * (fmax(x2, x3) - fmin(x2, x3)) + (fmax(y2, y3) - fmin(y2, y3)) * (fmax(y2, y3) - fmin(y2, y3)));

    if (((l1 <= l12) && (l1 <= l13)) && ((l2 <= l12) && (l2 <= l23)) && ((l3 <= l13) && (l3 <= l23))) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}