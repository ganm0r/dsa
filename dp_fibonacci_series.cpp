// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacci_series(int n) {
    vector<int> f(n + 1);
    if (n == 0) return { 0 };
    if (n == 1) return { 0, 1 };
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f;
}

int main() {
    vector<int> a = fibonacci_series(19);
    cout << "[ ";
    for (int i : a) {
        cout << i << " ";
    }
    cout << "]\n";
    return 0;
}
