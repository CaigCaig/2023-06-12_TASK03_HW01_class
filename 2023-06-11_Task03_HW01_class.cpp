#include <iostream>
#include <Windows.h>
#include <string>

class Calculator
{
public:
    double num1, num2;
    double add() {
        return this->num1 + this->num2;
    }
    double multiply() {
        return this->num1 * this->num2;
    }
    double subtract_1_2() {
        return this->num1 - this->num2;
    }
    double subtract_2_1() {
        return this->num2 - this->num1;
    }
    double divide_1_2() {
        return this->num1 / this->num2;
    }
    double divide_2_1() {
        return this->num2 / this->num1;
    }
    bool set_num1(double num1) {
        if (num1) this->num1 = num1;
        else return FALSE;
        return TRUE;
    }
    bool set_num2(double num2) {
        if (num2) this->num2 = num2;
        else return FALSE;
        return TRUE;
    }
    void set_num(std::string str, double* num) {
        std::string s;
        do {
            std::cout << "Введите " << str << ": ";
            try {
                std::cin >> s;
                *num = static_cast<double>(std::stof(s));
            }
            catch (const std::invalid_argument&) {
                *num = 0;
            }
            if (!*num) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (!*num);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (1) {
        Calculator calc;
        calc.set_num("num1", &calc.num1);
        calc.set_num("num2", &calc.num2);
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }
}
