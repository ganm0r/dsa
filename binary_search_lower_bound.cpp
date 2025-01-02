// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int search (vector<int>& n, int t) {
    int l = 0, r = n.size() - 1;
    int a = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] > t) {
            a = n[m]; // or a = m if returning index
            r = m - 1;
        } else l = m + 1;
    }
    return a;
}

int main() {
    vector<int> n = { -1, 0, 3, 5, 7, 9, 12 };
    int t = -1;
    cout << search(n, t) << "\n";
    return 0;
}
