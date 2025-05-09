#include <iostream>
#include <vector>
using namespace std;

/**
 * Uses counting sort to compute the number of students out of place.
 * heights: vector of current heights
 * returns: count of indices where heights[i] != sorted(i)
 */
int heightChecker(const vector<int>& heights) {
    if (heights.empty()) return 0;

    // Find min and max height to size the count array
    int minH = heights[0], maxH = heights[0];
    for (int h : heights) {
        if (h < minH) minH = h;
        if (h > maxH) maxH = h;
    }
    int range = maxH - minH + 1;

    // Counting array
    vector<int> count(range, 0);
    for (int h : heights) {
        count[h - minH]++;
    }

    int mismatches = 0;
    int idx = 0;
    // Reconstruct sorted heights via counting sort on the fly
    for (int offset = 0; offset < range; ++offset) {
        while (count[offset] > 0) {
            int expectedHeight = offset + minH;
            if (heights[idx] != expectedHeight) {
                ++mismatches;
            }
            ++idx;
            --count[offset];
        }
    }
    return mismatches;
}

int main() {
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = heightChecker(heights);
    cout << "Number of students out of place: " << result << endl;
    return 0;
}
