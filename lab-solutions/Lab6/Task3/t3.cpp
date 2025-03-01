#include <iostream>

class Marks {
public:
    virtual double getPercentage() = 0; // Pure virtual function
};
 
class A : public Marks {
private:
    int subject1, subject2, subject3;
public:
    A(int m1, int m2, int m3) : subject1(m1), subject2(m2), subject3(m3) {}
    
    double getPercentage() override {
        // Calculate percentage for student A (3 subjects)
        double totalMarks = subject1 + subject2 + subject3;
        return (totalMarks / 300.0) * 100.0;
    }
};
 
class B : public Marks {
private:
    int subject1, subject2, subject3, subject4;
public:
    B(int m1, int m2, int m3, int m4) : subject1(m1), subject2(m2), subject3(m3), subject4(m4) {}
    
    double getPercentage() override {
        // Calculate percentage for student B (4 subjects)
        double totalMarks = subject1 + subject2 + subject3 + subject4;
        return (totalMarks / 400.0) * 100.0;
    }
};

int main() {
    // Create objects for Student A and Student B
    A studentA(90, 80, 70);
    B studentB(73, 70, 62, 95);
    
    // Display the percentages
    std::cout << "Percentage of Student A: " << studentA.getPercentage() << "%" << std::endl;
    std::cout << "Percentage of Student B: " << studentB.getPercentage() << "%" << std::endl;
    
    return 0;
}