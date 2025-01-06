// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int min_cost_to_climb_stairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
        if (dp[i - 1] > dp[i - 2]) dp[i] = cost[i] + dp[i - 2];
        else dp[i] = cost[i] + dp[i - 1];
    }
    if (dp[n - 1] > dp[n - 2]) return dp[n - 2];
    else return dp[n - 1];
}

int main() {
    vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };
    cout << min_cost_to_climb_stairs(cost) << "\n";
    return 0;
}
