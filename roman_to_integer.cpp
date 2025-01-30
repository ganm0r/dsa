// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/roman-to-integer/?envType=daily-question&envId=2025-01-30

#include <iostream>
#include <unordered_map>

using namespace std;

int roman_to_integer(string s) {
    unordered_map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int r = 0, n = s.size();

    for (int i = 0; i < n; i++) {
        int c = m[s[i]];
        if (i + 1 < n && c < m[s[i + 1]]) {
            r += m[s[i + 1]] - c;
            i++;
        }
        else {
            r += m[s[i]];
        }
    }

    return r;
}

int main() {
    cout << roman_to_integer("MCMXCIV") << "\n";
    return 0;
}
