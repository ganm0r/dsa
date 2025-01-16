// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include <iostream>

using namespace std;

int needle_in_haystack(string haystack, string needle) {
    int haystack_size = haystack.size();
    int needle_size = needle.size();

    for (int i = 0; i <= haystack_size - needle_size; ++i) {
        if (haystack.substr(i, needle_size) == needle) return i;
    }

    return -1;
}

int main() {
    cout << needle_in_haystack("notsadbutsad", "sad") << "\n";
    return 0;
}
