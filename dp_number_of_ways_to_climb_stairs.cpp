// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int climb_stairs(int n) {
    if (n < 2) return 1;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << climb_stairs(31) << "\n";
    return 0;
}
