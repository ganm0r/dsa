// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09

#include <iostream>
#include <vector>

using namespace std;

int count_prefixes(vector<string>& w, string p) {
    int c = 0;
    for (int i = 0; i < w.size(); i++) {
        int c1 = 0;
        for (int j = 0; j < p.size(); j++) {
            if (j < w[i].size() && w[i][j] == p[j]) c1++;
            else break;
        }
        if (c1 == p.size()) c++;
    }
    return c;
}

int main() {
    vector<string> w = { "lewsmb","lewrydnve","lewqqm","lewec","lewn","lewb","lewedb" };
    string p = "lew";
    cout << count_prefixes(w, p) << "\n";
    return 0;
}
