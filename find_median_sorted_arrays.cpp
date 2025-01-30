// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/median-of-two-sorted-arrays/?envType=daily-question&envId=2025-01-27

#include <iostream>
#include <vector>

using namespace std;

double find_median_sorted_arrays_with_binary_search(vector<int>& n1, vector<int>& n2) { // O(min(n1, n2)) time
    if (n1.size() > n2.size()) {
        return find_median_sorted_arrays_with_binary_search(n2, n1);
    }

    int s1 = n1.size();
    int s2 = n2.size();
    int l = 0, r = s1;

    while (l <= r) {
        int p1 = (l + r) / 2; 
        int p2 = (s1 + s2 + 1) / 2 - p1;

        int maxL1 = (p1 == 0) ? INT_MIN : n1[p1 - 1];
        int minR1 = (p1 == s1) ? INT_MAX : n1[p1];

        int maxL2 = (p2 == 0) ? INT_MIN : n2[p2 - 1];
        int minR2 = (p2 == s2) ? INT_MAX : n2[p2];

        if (maxL1 <= minR2 && maxL2 <= minR1) {
            if ((s1 + s2) % 2 == 0) {
                return (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
            } else {
                return max(maxL1, maxL2);
            }
        } else if (maxL1 > minR2) {
            r = p1 - 1;
        } else {
            l = p1 + 1;
        }
    }

    throw invalid_argument("mate, the input arrays are not sorted!");
}

double find_median_sorted_arrays(vector<int>& n1, vector<int>& n2) { // O(n1 + n2) time
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
    cout << find_median_sorted_arrays_with_binary_search(n1, n2) << "\n";
    return 0;
}
