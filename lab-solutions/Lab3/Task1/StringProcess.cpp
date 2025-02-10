#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class StringProcessor {
public:
    // Reverse a string
    string process(const string& input) {
        string result = input;
        reverse(result.begin(), result.end());
        return result;
    }

    // Concatenate two strings with a space
    string process(const string& str1, const string& str2) {
        return str1 + " " + str2;
    }

    // Repeat a string N times
    string process(const string& input, int repeat) {
        string result;
        for (int i = 0; i < repeat; i++) {
            result += input;
        }
        return result;
    }
};

int main() {
    StringProcessor sp;

    // Test reversing
    cout << sp.process("hello") << endl;          // "olleh"

    // Test concatenation
    cout << sp.process("Hello", "World") << endl; // "Hello World"

    // Test repeating
    cout << sp.process("ha", 3) << endl;          // "hahaha"       

    return 0;
}