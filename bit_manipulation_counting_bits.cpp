// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/counting-bits/?envType=problem-list-v2&envId=dynamic-programming

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> bit_manipulation_counting_bits_n2_time(int n) {
    vector<int> r(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 31; j >= 0; j--) {
            if (i & (1 << j)) r[i]++;
        }
    }

    return r;
}

int main() {
    cout << "[ ";
    for (int i : bit_manipulation_counting_bits_n2_time(21)) {
        cout << i << " ";
    }
    cout << "]" << "\n";
    return 0;
}
