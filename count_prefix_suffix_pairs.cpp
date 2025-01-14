// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-10

#include <iostream>
#include <vector>

using namespace std;

bool is_prefix(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

bool is_suffix(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[(s2.size() - s1.size()) + i]) return false;
    }
    return true;
}

bool is_prefix_and_suffix(string s1, string s2) {
    if (s2.size() < s1.size()) return false;
    return is_prefix(s1, s2) && is_prefix(s1, s2);
}

int count_prefix_suffix_pairs(vector<string>& w) {
    int c = 0;
    for (int j = 0; j < w.size(); j++) {
        for (int i = 0; i < j; i++) {
            if (is_prefix_and_suffix(w[i], w[j])) c++;
        }
    }

    return c;
}

int main() {
    vector<string> w = { "pa","papa","ma","mama" };
    cout << count_prefix_suffix_pairs(w) << "\n";
    return 0;
}
