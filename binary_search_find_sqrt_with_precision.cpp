// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

long double find_sqrt_with_precision(int n) {
    long double l = 0, r = n, m = 0.0;
    while (r - l > 0.000000000000001) {
        m = l + (r - l) / 2.0;
        if (m * m < n) l = m;
        else r = m;
    }
    return m;
}

int main() {
    cout << find_sqrt_with_precision(11) << "\n";
    return 0;
}
