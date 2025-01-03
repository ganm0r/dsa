// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int search_in_rotated_array(vector<int>& n, int t) {
    int l = 0, r = n.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] == t) return m;
        if (n[l] <= n[m]) {
            if (n[l] <= t && t < n[m]) r = m - 1;
            else l = m + 1;
        } else {
            if (n[m] < t && t <= n[r]) l = m + 1;
            else r = m - 1;
        };
    }
    return -1;
}

int main() {
    vector<int> n = { 4,5,6,7,0,1,2 };
    int t = 0;
    cout << search_in_rotated_array(n, t) << "\n";
    return 0;
}
