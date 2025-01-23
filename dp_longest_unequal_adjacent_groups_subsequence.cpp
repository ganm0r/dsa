// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>

using namespace std;

vector<string> get_longest_unequal_adjacent_group_subsequence(vector<string>& w, vector<int>& g) {
    vector<string> dp;
    dp.push_back(w[0]);

    for (int i = 1; i < g.size(); i++) {
        if (g[i] != g[i - 1]) dp.push_back(w[i]);
    }

    return dp;
}

int main() {
    vector<string> w = { "a","b","c","d" };
    vector<int> g = { 1,0,1,1 };
    cout << "[ ";
    for (string s : get_longest_unequal_adjacent_group_subsequence(w, g)) {
        cout << s << " ";
    }
    cout << "]" << "\n";
    return 0;
}
