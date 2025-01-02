// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test

#include <iostream>
#include <vector>

using namespace std;

int start(vector<int> n, int t) {
    int l = 0, r = n.size() - 1;
    int a = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] == t) a = m;
        if (n[m] >= t) r = m - 1; // >= makes it go left
        else l = m + 1;
    }
    return a;
}

int end(vector<int> n, int t) {
    int l = 0, r = n.size() - 1;
    int a = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n[m] == t) a = m;
        if (n[m] > t) r = m - 1; // > makes it go right
        else l = m + 1;
    }
    return a;
}

vector<int> search_range_in_sorted_array(vector<int>& n, int t) {
    return { start(n, t), end(n, t) };
}

int main() {
    vector<int> n = { 5, 7, 7, 8, 8, 10 };
    int t = 8;
    vector<int> a = search_range_in_sorted_array(n, t);
    cout << "[ ";
    for (int i : a) {
        cout << i << " ";
    }
    cout << "]\n";
    return 0;
}
