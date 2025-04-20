#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Functor to check for balanced braces
class BalancedBraces {
public:
    bool operator()(const std::string& expression) const {
        int braceCount = 0;

        for (char ch : expression) {
            if (ch == '{') {
                ++braceCount;
            } else if (ch == '}') {
                if (braceCount == 0) {
                    return false; // Unmatched closing brace
                }
                --braceCount;
            }
        }

        return braceCount == 0; // All braces matched
    }
};

int main() {
    // Test expressions
    std::vector<std::string> expressions = {
        "int main() { return 0; }",
        "if (a > b) { doSomething(); }",
        "{{{}}}",
        "{ unbalanced",
        "no braces here",
        "}{", // invalid: closing comes first
        "{ { } } }", // unbalanced
        "{}{}{}"
    };

    BalancedBraces checker;

    std::cout << "Balanced Braces Check:\n\n";
    for (const auto& expr : expressions) {
        std::cout << "\"" << expr << "\" -> "
                  << (checker(expr) ? "Balanced" : "Unbalanced") << '\n';
    }

    return 0;
}
