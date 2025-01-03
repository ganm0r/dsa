// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int search_insert_position(vector<int> n, int t) {
    int l = 0, r = n.size() - 1;
    int a = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] == t) return m;
        if (n[m] > t) {
            r = m - 1;
            a = m;
        } else {
            l = m + 1;
            a = m + 1;
        }
    }
    return a;
}

int main() {
    vector<int> n = { 1, 3, 5, 6 };
    int t = 5;
    cout << search_insert_position(n, t) << "\n";
    return 0;
}
