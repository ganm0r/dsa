// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/median-of-two-sorted-arrays/?envType=daily-question&envId=2025-01-27

#include <iostream>
#include <vector>

using namespace std;

double find_median_sorted_arrays(vector<int>& n1, vector<int>& n2) {
    vector<int> t;

    int s1 = n1.size();
    int s2 = n2.size();

    int i = 0, j = 0;

    while (i < s1 && j < s2) {
        if (n1[i] > n2[j]) {
            t.push_back(n2[j]);
            j++;
        } else {
            t.push_back(n1[i]);
            i++;
        }
    }

    while (i < s1) {
        t.push_back(n1[i]);
        i++;
    }

    while (j < s2) {
        t.push_back(n2[j]);
        j++;
    }

    int s = t.size();

    return s % 2 == 0 ? (t[s / 2 - 1] + t[s / 2]) / 2.0 : t[s / 2];
}

int main() {
    vector<int> n1 = { 1,2 };
    vector<int> n2 = { 3,4 };
    cout << find_median_sorted_arrays(n1, n2) << "\n";
    return 0;
}
