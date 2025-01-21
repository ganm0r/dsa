// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/is-subsequence/

#include <iostream>

using namespace std;

bool is_subsequence(string s, string t) {
    int j = 0;
    for (int i = 0; i < t.size() && j < s.size(); i++) {
        if (s[j] == t[i]) j++;
    }

    return j == s.size();
}

int main() {
    cout << is_subsequence("abc", "ahbgdc") << "\n";
    return 0;
}
