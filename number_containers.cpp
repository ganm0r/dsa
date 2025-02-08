// g++ -std=c++11 -O2 -Wall test.cpp -o test && ./test
// https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08

#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
    
    void change(int index, int number) {
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }

        indexToNumber[index] = number;

        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();
        }
        return -1;
    }
};

int main() {
    return 0;
}
