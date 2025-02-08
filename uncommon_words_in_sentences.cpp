// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2025-02-08

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

void split(string s, unordered_map<string, int>& m) {
    stringstream ss(s);
    string w;
    
    while (ss >> w) m[w]++;
}

vector<string> find_uncommon_words_in_sentences(string s1, string s2) {
    unordered_map<string, int> m;

    split(s1, m);
    split(s2, m);

    vector<string> r;

    for (const auto& [k, v] : m) {
        if (v == 1) r.push_back(k);
    }

    return r;
}

int main() {
    vector<string> r = find_uncommon_words_in_sentences("this apple is sweet", "this apple is sour");
    cout << "[ ";
    for (string s : r) {
        cout << s << " ";
    }
    cout << "]\n";
    return 0;
}
