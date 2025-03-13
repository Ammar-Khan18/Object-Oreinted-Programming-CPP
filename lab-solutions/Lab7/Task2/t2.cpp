#include <iostream>
using namespace std;

void testException(int x) {
    if (x == 1) throw 10;
    else if (x == 2) throw 2.5;
    else if (x == 3) throw 'A';
    else throw string("Unknown Error");
}

int main() {
    try {
        testException(4); // Change this value to test different cases
    }
    catch (int e) {
        cout << "Caught an int: " << e << endl;
    }
    catch (double e) {
        cout << "Caught a double: " << e << endl;
    }
    catch (char e) {
        cout << "Caught a char: " << e << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception!" << endl;
    }
    return 0;
}