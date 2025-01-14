// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/sum-of-unique-elements/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sum_of_unique_numbers(vector<int>& n) {
    unordered_map<int, int> h;
    for (int i = 0; i < n.size(); i++) {
        h[n[i]]++;
    }
    int r = 0;
    for (const auto& [n, f] : h) {
        if (f == 1) r += n;
    }
    return r;
}

int main() {
    vector<int> n = { 1,2,3,2 };
    cout << sum_of_unique_numbers(n) << "\n";
    return 0;
}
