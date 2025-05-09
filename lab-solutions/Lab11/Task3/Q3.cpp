#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstddef>
#include <cctype>
using namespace std;

// RadixStringSorter: lexicographically sorts strings using LSD Radix Sort (stable)
class RadixStringSorter {
private:
    // Perform a single pass counting sort on character at 'pos'
    static void countingSortByPosition(vector<string>& arr, size_t pos) {
        const int R = 256;  // extended ASCII alphabet size
        vector<int> count(R + 2, 0);
        // Frequency counts: map missing char -> 0, others -> (unsigned char)+1
        for (const auto& s : arr) {
            int c = (pos < s.size()) ? (static_cast<unsigned char>(s[pos]) + 1) : 0;
            count[c]++;
        }
        // Transform counts to indices (cumulative)
        for (int r = 0; r < R + 1; ++r) {
            count[r + 1] += count[r];
        }
        // Build output array (stable)
        vector<string> output(arr.size());
        for (const auto& s : arr) {
            int c = (pos < s.size()) ? (static_cast<unsigned char>(s[pos]) + 1) : 0;
            output[count[c]++] = s;
        }
        arr = move(output);
    }

public:
    // Sort entire array ascending lexicographically
    static void sortAsc(vector<string>& arr) {
        if (arr.empty()) return;
        // Find maximum string length
        size_t maxLen = 0;
        for (const auto& s : arr) {
            if (s.size() > maxLen) {
                maxLen = s.size();
            }
        }
        // LSD radix: from least significant (end) to most (start)
        for (size_t pos = maxLen; pos-- > 0; ) {
            countingSortByPosition(arr, pos);
        }
    }

    // Sort entire array descending lexicographically
    static void sortDesc(vector<string>& arr) {
        sortAsc(arr);
        reverse(arr.begin(), arr.end());
    }

    // Sort by a specific character position only
    // ascending: true for A→Z, false for Z→A
    static void sortByPosition(vector<string>& arr,
                               size_t pos,
                               bool ascending = true) {
        countingSortByPosition(arr, pos);
        if (!ascending) {
            reverse(arr.begin(), arr.end());
        }
    }
};

int main() {
    vector<string> data = {"apple", "Banana", "app", "banana", "Apricot"};

    auto arr1 = data;
    RadixStringSorter::sortAsc(arr1);
    cout << "Ascending lexicographic:" << endl;
    for (auto& s : arr1) cout << s << endl;
    cout << endl;

    auto arr2 = data;
    RadixStringSorter::sortDesc(arr2);
    cout << "Descending lexicographic:" << endl;
    for (auto& s : arr2) cout << s << endl;
    cout << endl;

    auto arr3 = data;
    size_t pos = 2; // 3rd character (0-based index 2)
    RadixStringSorter::sortByPosition(arr3, pos, true);
    cout << "Sorted by 3rd character ascending:" << endl;
    for (auto& s : arr3) cout << s << endl;

    return 0;
}