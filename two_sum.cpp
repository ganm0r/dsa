// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum_n_time(vector<int>& n, int t) {
    unordered_map<int, int> m;
    for (int i = 0; i < n.size(); i++) {
        if (m.count(t - n[i])) return { m[t - n[i]], i };
        m[n[i]] = i;
    }

    return { -1, - 1};
}

vector<int> two_sum_n2_time(vector<int>& n, int t) {
    for (int i = 0; i < n.size(); i++) {
        for (int j = i + 1; j < n.size(); j++) {
            if (n[i] + n[j] == t) return { i, j };
        }
    }

    return { -1, -1 };
}

int main() {
    vector<int> n = { 2,7,11,15 };
    cout << "[ ";
    for (int i : two_sum_n_time(n, 9)) {
        cout << i << " ";
    }
    cout << "]" << "\n";
    return 0;
}
