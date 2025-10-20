#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// Base operation class
class MathOperation {
public:
    virtual ~MathOperation() = default;
    virtual double calculate(double a, double b = 0) const = 0;
    virtual string getName() const = 0;
    virtual bool isBinary() const = 0;
};

// Concrete operation classes
class Add : public MathOperation {
public:
    double calculate(double a, double b) const override { return a + b; }
    string getName() const override { return "Addition"; }
    bool isBinary() const override { return true; }
};

class Subtract : public MathOperation {
public:
    double calculate(double a, double b) const override { return a - b; }
    string getName() const override { return "Subtraction"; }
    bool isBinary() const override { return true; }
};

class Multiply : public MathOperation {
public:
    double calculate(double a, double b) const override { return a * b; }
    string getName() const override { return "Multiplication"; }
    bool isBinary() const override { return true; }
};

class Divide : public MathOperation {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
    string getName() const override { return "Division"; }
    bool isBinary() const override { return true; }
};

class Modulus : public MathOperation {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw runtime_error("Modulus by zero!");
        return fmod(a, b);
    }
    string getName() const override { return "Modulus"; }
    bool isBinary() const override { return true; }
};


class Absolute : public MathOperation {
public:
    double calculate(double a, double b = 0) const override { return abs(a); }
    string getName() const override { return "Absolute value"; }
    bool isBinary() const override { return false; }
};

class Square : public MathOperation {
public:
    double calculate(double a, double b = 0) const override { return a * a; }
    string getName() const override { return "Square"; }
    bool isBinary() const override { return false; }
};

class SquareRoot : public MathOperation {
public:
    double calculate(double a, double b = 0) const override {
        if (a < 0) throw runtime_error("Square root of negative number!");
        return sqrt(a);
    }
    string getName() const override { return "Square root"; }
    bool isBinary() const override { return false; }
};

class Logarithm : public MathOperation {
public:
    double calculate(double a, double b = 0) const override {
        if (a <= 0) throw runtime_error("Logarithm of non-positive number!");
        return log(a);
    }
    string getName() const override { return "Natural logarithm"; }
    bool isBinary() const override { return false; }
};

class Factorial : public MathOperation {
public:
    double calculate(double a, double b = 0) const override {
        if (a < 0) throw runtime_error("Factorial of negative number!");
        if (floor(a) != a) throw runtime_error("Factorial of non-integer number!");
        
        unsigned long long result = 1;
        for (int i = 2; i <= static_cast<int>(a); ++i) {
            result *= i;
        }
        return static_cast<double>(result);
    }
    string getName() const override { return "Factorial"; }
    bool isBinary() const override { return false; }
};

class LogarithmBase10 : public MathOperation {
public:
    double calculate(double a, double b = 0) const override {
        if (a <= 0) throw runtime_error("Logarithm of non-positive number!");
        return log10(a);
    }
    string getName() const override { return "Logarithm base 10"; }
    bool isBinary() const override { return false; }
};
// Function to clear screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    char op;
    
    while (true) {
        clearScreen();
        cout << "=== Simple OOP Calculator ===\n";
        cout << "Available operations:\n";
        cout << "+ - addition\n- - subtraction\n* - multiplication\n/ - division\n";
        cout << "% - modulus\n^ - power\na - absolute value\ns - square\nr - square root\n";
        cout << "l - natural logarithm\nL - logarithm base 10\nf - factorial\nq - quit\n";
        
        cout << "Enter operation: ";
        cin >> op;
        
        // Check if user wants to quit
        if (op == 'q' || op == 'Q') {
            cout << "Goodbye!\n";
            break;
        }
        
        MathOperation* operation = nullptr;
        
        // Create operation object
        switch(op) {
            case '+': operation = new Add(); break;
            case '-': operation = new Subtract(); break;
            case '*': operation = new Multiply(); break;
            case '/': operation = new Divide(); break;
            case '%': operation = new Modulus(); break;
            case 'a': operation = new Absolute(); break;
            case 's': operation = new Square(); break;
            case 'r': operation = new SquareRoot(); break;
            case 'l': operation = new Logarithm(); break;
            case 'f': operation = new Factorial(); break;
            default:
                cout << "Unknown operation! Please try again.\n";
                cout << "Press Enter to continue...";
                cin.ignore();
                cin.get();
                continue; // Skip the rest and show menu again
        }
        
        try {
            clearScreen();
            if (operation->isBinary()) {
                double a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                clearScreen();
                cout << "Result: " << operation->calculate(a, b) << endl;
            } else {
                double a;
                cout << "Enter a number: ";
                cin >> a;
                clearScreen();
                cout << "Result: " << operation->calculate(a) << endl;
            }
        } catch (const exception& e) {
            clearScreen();
            cout << "Error: " << e.what() << endl;
        }
        
        delete operation;
        
        // Wait for user to continue
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}
