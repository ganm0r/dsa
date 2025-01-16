// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int xor_all_nums_n2_time(vector<int>& n1, vector<int>& n2) {
    vector<int> n3;
    for (int i = 0; i < n1.size(); i++) {
        for (int j = 0; j < n2.size(); j++) {
            n3.push_back(n1[i] ^ n2[j]);
        }
    }

    int r = 0;

    for (int i = 0; i < n3.size(); i++) {
        r ^= n3[i];
    }

    return r;
}

int main() {
    vector<int> n1 = { 2,1,3 };
    vector<int> n2 = { 10,2,5,0 };
    cout << xor_all_nums_n2_time(n1, n2) << "\n";
    return 0;
}
