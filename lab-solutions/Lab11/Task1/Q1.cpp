#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Simple Student struct
struct Student {
    string name;
    double gpa;
};

// Comparator to sort students by name (alphabetical, case-insensitive)
struct NameComparator {
    bool operator()(const Student &a, const Student &b) const {
        // Convert both names to lowercase for case-insensitive comparison
        auto toLower = [](unsigned char c) { return static_cast<char>(tolower(c)); };
        string lowerA, lowerB;
        lowerA.resize(a.name.size());
        lowerB.resize(b.name.size());
        transform(a.name.begin(), a.name.end(), lowerA.begin(), toLower);
        transform(b.name.begin(), b.name.end(), lowerB.begin(), toLower);
        return lowerA < lowerB;
    }
};

// Comparator to sort students by GPA (descending)
struct GpaComparator {
    bool operator()(const Student &a, const Student &b) const {
        return a.gpa > b.gpa;
    }
};

// GenericSorter using insertion sort
template<typename T, typename Comparator>
class GenericSorter {
public:
    // Sorts 'list' in-place according to the order defined by 'cmp'
    void insertionSort(vector<T> &list, Comparator cmp) {
        for (size_t i = 1; i < list.size(); ++i) {
            T key = list[i];
            int j = static_cast<int>(i) - 1;
            // Shift elements that should come after 'key'
            while (j >= 0 && cmp(key, list[j])) {
                list[j + 1] = list[j];
                --j;
            }
            list[j + 1] = key;
        }
    }
};

int main() {
    vector<Student> students = {
        {"Alice", 3.5},
        {"bob", 3.8},
        {"Charlie", 3.2},
        {"david", 3.9}
    };

    GenericSorter<Student, NameComparator> sorterByName;
    auto byName = students;  // copy original
    sorterByName.insertionSort(byName, NameComparator());

    cout << "Sorted by name:" << endl;
    for (const auto &s : byName) {
        cout << s.name << " (" << s.gpa << ")" << endl;
    }
    cout << endl;

    GenericSorter<Student, GpaComparator> sorterByGpa;
    auto byGpa = students;  // copy original
    sorterByGpa.insertionSort(byGpa, GpaComparator());

    cout << "Sorted by GPA (descending):" << endl;
    for (const auto &s : byGpa) {
        cout << s.name << " (" << s.gpa << ")" << endl;
    }

    return 0;
}
