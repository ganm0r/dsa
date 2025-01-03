// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/peak-index-in-a-mountain-array/?envType=problem-list-v2&envId=binary-search

#include <iostream>
#include <vector>

using namespace std;

int find_peak_index(vector<int>& n) {
    int k = n.size() - 1;
    int l = 1, r = k - 1;
    if (k == 0) return 0;
    if (n[k] > n[k - 1]) return k;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m - 1] < n[m] && n[m] > n[m + 1]) return m;
        if (n[m] < n[m - 1]) r = m - 1;
        else if (n[m] < n[m + 1]) l = m + 1;
    }
    return -1;
}

int main() {
    vector<int> n = { 0,10,5,2 };
    cout << find_peak_index(n) << "\n";
    return 0;
}
