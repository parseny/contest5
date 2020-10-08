#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double func(int a, int b, int c, int d, long double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    //cout << func(-1,1,1,1, 1.8393);
    int a, b, c, d;
    long double eps = 1e-15, y;
    cin >> a >> b >> c >> d;
    /*a = 1;
    b = -3;
    c = 3;
    d = -1;*/
    long double l = -1e9, r = 1e9, p;//= (l + r) / 2;
    do {
        p = (l + r) / 2;
        y = func(a, b, c, d, p);
        if (a > 0) {
            if (y > 0) {
                //l = l / 2;
                r = p;
            } else {
                l = p;
            }
        } else {
            if (y > 0) {
                l = p;
            } else {
                r = p;
            }

        }
    } while (abs(y) > eps);
    cout << setprecision(6) << p;
    return 0;
}
