// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/find-a-peak-element-ii/?envType=problem-list-v2&envId=binary-search

#include <iostream>
#include <vector>

using namespace std;

vector<int> find_peak_in_grid(vector<vector<int>>& n) {
    int l = 0, r = n.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        int index_of_max_in_row_m = 0;

        for (int i = 1; i <= n[m].size() - 1; i++) {
            if (n[m][i] > n[m][index_of_max_in_row_m]) index_of_max_in_row_m = i;
        }

        bool greater_num_above = m > 0            && n[m - 1][index_of_max_in_row_m] > n[m][index_of_max_in_row_m];
        bool greater_num_below = m > n.size() - 1 && n[m + 1][index_of_max_in_row_m] > n[m][index_of_max_in_row_m];

        if (!greater_num_above && !greater_num_below) return { m, index_of_max_in_row_m };
        else if (greater_num_above) r = m - 1;
        else if (greater_num_below) l = m + 1;
    }

    return { -1, -1 };
}

int main() {
    vector<vector<int>> n = {{1,4},{3,2}};
    vector<int> a = find_peak_in_grid(n);
    cout << "[ ";
    for (int i : a) {
        cout << i << " ";
    }
    cout << "]\n";
    return 0;
}
