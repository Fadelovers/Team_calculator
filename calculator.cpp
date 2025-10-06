#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    // Бинарные операции

     // Маргарита +
    double add(double a, double b) {

}

     //Юля -
   double subtract(double a, double b{ 
      
}

    //  Иван *
   double multiply(double a, double b){ 
      
}

// Арсений :
    double divide(double a, double b) {
        
    }

//Алексей %
    int mod(int a, int b) {
       
    }

    // Унарные операции

      //Андрей |_|
    double absolute(double a) {

}

//Богдан sqr
    double square(double a) {

}

//Игорь sqrt 
    double squareRoot(double a) {
        
    }
// Максим А. log 
    
    }
//Илья !
    unsigned long long factorial(int n) {
        
    }
};


int main() {
    Calculator calc;
    char operation;
    double a, b;
    int intA, intB;

    cout << "Доступные операции: + - * / % (остаток) a (abs) s (square) r (sqrt) l (log) f (factorial)\n";
    cout << "Введите операцию: ";
    cin >> operation;

    try {
        switch (operation) {
            case '+':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << calc.add(a, b) << endl;
                break;
            case '-':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << calc.subtract(a, b) << endl;
                break;
            case '*':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << calc.multiply(a, b) << endl;
                break;
            case '/':
                cout << "Введите два числа: ";
                cin >> a >> b;
                cout << "Результат: " << calc.divide(a, b) << endl;
                break;
            case '%':
                cout << "Введите два целых числа: ";
                cin >> intA >> intB;
                cout << "Результат: " << calc.mod(intA, intB) << endl;
                break;
            case 'a':
                cout << "Введите число: ";
                cin >> a;
                cout << "Результат: " << calc.absolute(a) << endl;
                break;
            case 's':
                cout << "Введите число: ";
                cin >> a;
                cout << "Результат: " << calc.square(a) << endl;
                break;
            case 'r':
                cout << "Введите число: ";
                cin >> a;
                cout << "Результат: " << calc.squareRoot(a) << endl;
                break;
            case 'l':
                cout << "Введите число: ";
                cin >> a;
                cout << "Результат: " << calc.logarithm(a) << endl;
                break;
            case 'f':
                cout << "Введите целое число: ";
                cin >> intA;
                cout << "Результат: " << calc.factorial(intA) << endl;
                break;
            default:
                cout << "Неизвестная операция!" << endl;
        }
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
