// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <vector>

using namespace std;

string longest_common_prefix(vector<string>& s) {
    if (!(s.size())) return "";
    std::sort(s.begin(), s.end());
    string r = "";
    for (int i = 0; i < s[0].size(); i++) {
        if (s[0][i] == s[s.size() - 1][i]) r += s[0][i];
        else break;
    }
    return r;
}

int main() {
    vector<string> s = { "flower","flow","flight" };
    cout << longest_common_prefix(s) << "\n";
    return 0;
}
