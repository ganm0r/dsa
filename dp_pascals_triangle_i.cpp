// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/pascals-triangle/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp_pascals_triangle(int n) {
    vector<vector<int>> r;

    for (int i = 0; i < n; i++) {
        vector<int> dp(i + 1, 1);

        for (int j = 1; j < i; j++) {
            dp[j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        r.push_back(dp);
    }

    return r;
}

int main() {
    vector<vector<int>> r = dp_pascals_triangle(5);
    for (vector<int> i : r) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
