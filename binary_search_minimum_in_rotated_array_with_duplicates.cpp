// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?envType=problem-list-v2&envId=binary-search

#include <iostream>
#include <vector>

using namespace std;

int minimum_in_rotated_array_with_duplicates(vector<int>& n) {
    int l = 0, r = n.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (n[m] == n[r]) r--; 
        if (n[m] > n[r]) l = m + 1;
        else if (n[m] < n[r]) r = m;
    }
    return n[l];
}

int main() {
    vector<int> n = { 2,2,2,0,1 };
    cout << minimum_in_rotated_array_with_duplicates(n) << "\n";
    return 0;
}
