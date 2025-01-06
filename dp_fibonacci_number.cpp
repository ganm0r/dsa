// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int fibonacci_number(int n) {
    if (n < 2) return n;
    vector<int> f(n + 1);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    cout << fibonacci_number(31) << "\n";
    return 0;
}
