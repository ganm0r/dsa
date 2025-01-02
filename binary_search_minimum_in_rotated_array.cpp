// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int minimum_in_rotated_sorted_array (vector<int>& n) {
    int l = 0, r = n.size() - 1;
    int a = n[0];
    if (r == 1) {
        if (n[l] > n[r]) return n[r];
        return n[l];
    }
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] > a) {
            l = m + 1;
        } else {
            a = n[m];
            r = m - 1;
        };
    }
    return a;
}

int main() {
    vector<int> n = { 2, 1 };
    cout << minimum_in_rotated_sorted_array(n) << "\n";
    return 0;
}
