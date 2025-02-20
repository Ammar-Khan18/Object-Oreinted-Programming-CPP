#include <iostream>
#include <vector>
#include <string>

/*
Operation	        Complexity	Explanation
Insert/Delete Text	O(1)        for pushing to undo stack, O(n) for modifying text	Storing the current state in the stack is O(1), but modifying text (like erase()) can be O(n).
Undo	            O(1)	    Restoring previous text state is an O(1) operation.
Redo	            O(1)	    Moving from redo stack back to text is O(1).
Clearing Redo Stack	O(n)	    If redo is invalidated, clearing redo history takes O(n) in the worst case.
*/

class TextEditor {
private:
    std::vector<std::string> undoStack; // Stack for undo operations
    std::vector<std::string> redoStack; // Stack for redo operations
    std::string text;                   // Current text content

public:
    // Insert or delete text (push changes onto the undo stack)
    void insertText(const std::string& newText) {
        undoStack.push_back(text); // Save current state before modification (O(1))
        text += newText;           // Append new text (O(1))
        redoStack.clear();         // Clear redo stack since new action invalidates redo history (O(n))
    }

    void deleteText(size_t length) {
        if (length > text.size()) length = text.size();
        undoStack.push_back(text); // Save current state before modification (O(1))
        text.erase(text.size() - length, length); // Remove last `length` characters (O(n))
        redoStack.clear();         // Clear redo stack (O(n))
    }

    // Undo last operation
    void undo() {
        if (!undoStack.empty()) {
            redoStack.push_back(text); // Save current state before undo (O(1))
            text = undoStack.back();   // Restore last state (O(1))
            undoStack.pop_back();      // Remove last state from undo stack (O(1))
        } else {
            std::cout << "Nothing to undo!\n";
        }
    }

    // Redo last undone operation
    void redo() {
        if (!redoStack.empty()) {
            undoStack.push_back(text); // Save current state before redo (O(1))
            text = redoStack.back();   // Restore last undone state (O(1))
            redoStack.pop_back();      // Remove from redo stack (O(1))
        } else {
            std::cout << "Nothing to redo!\n";
        }
    }

    // Display current text
    void displayText() {
        std::cout << "Current Text: \"" << text << "\"\n";
    }
};

// Driver Code
int main() {
    TextEditor editor;

    editor.insertText("Hello");
    editor.displayText(); // Hello

    editor.insertText(", World!");
    editor.displayText(); // Hello, World!

    editor.undo();
    editor.displayText(); // Hello

    editor.redo();
    editor.displayText(); // Hello, World!

    editor.deleteText(6);
    editor.displayText(); // Hello

    editor.undo();
    editor.displayText(); // Hello, World!

    return 0;
}