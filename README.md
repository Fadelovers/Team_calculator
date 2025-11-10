# Team_calculator
Team calculator 21312 group
       
# Функции писать в файл calculator.cpp 
Для каждой функуии уже готовы свои Func с комментарием



# основной Класс
```c++
class MathOperation {
public:
    virtual ~MathOperation() = default;
    virtual double calculate(double a, double b = 0) const = 0;
    virtual string getName() const = 0;
    virtual bool isBinary() const = 0;
};
```
Пример
```c++

// функция "Ваша функция". ФИО

class YourFunc : public MathOperation {
public:
  double calculate(double a, double b (= or != 0)) const override { Yourcode }
  string getName() const override { return "YourFunc"; }
   bool isBinary() const override { return true OR False; } 
};

```

# Tusk for Team
<br> 1 Маргарита + <br>
<br> 2 Юля - <br>
<br> 3 Иван * <br> ✅
<br> 4 Андрей |_| <br>
<br> 5 Арсений : <br>
<br> 6 Богдан sqr <br>
<br> 7 Игорь sqrt <br>
<br> 8 Алексей  %  <br> 
<br> 9 Максим А. log <br>
<br> 10 Илья ! <br>
