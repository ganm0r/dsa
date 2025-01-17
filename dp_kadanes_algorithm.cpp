// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int>& prices) {
    int min_price = prices[0], max_profit = 0;

    for (int i = 0; i < prices.size(); i++) {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
}

int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << max_profit(prices) << "\n";
    return 0;
}
