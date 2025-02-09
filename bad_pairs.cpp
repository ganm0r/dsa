// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

long long count_bad_pairs_linear_time(vector<int>& nums) {
    long long n = nums.size();
    long long t = n * (n - 1) / 2;

    unordered_map<int, long long> m;

    for (int i = 0; i < n; i++) {
        m[nums[i] - i]++;
    }

    long long g = 0;

    for (const auto& [k, v] : m) {
        g += v * (v - 1) / 2;
    }

    return t - g;
}

long long count_bad_pairs_brute_force(vector<int>& nums) {
    int c = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (j - i != nums[j] - nums[i]) c++;
        }
    }

    return c;
}

int main() {
    vector<int> n = { 4,1,3,3 };
    cout << count_bad_pairs_linear_time(n) << "\n";
    return 0;
}
