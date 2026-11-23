// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <cmath>

struct FractionOperations {
    // Вспомогательная функция для поиска наибольшего общего делителя (НОД)
    static int gcd(int a, int b) {
        return b == 0 ? std::abs(a) : gcd(b, a % b);
    }

    // Упрощение дроби (изменяет переданные значения числителя и знаменателя)
    static void simplifyFraction(int& num, int& denom) {
        if (denom == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        int commonDivisor = gcd(num, denom);
        num /= commonDivisor;
        denom /= commonDivisor;
        if (denom < 0) { // Переносим минус в числитель
            num = -num;
            denom = -denom;
        }
    }

    // Сложение двух дроби: num1/denom1 + num2/denom2 -> результат записывается в resNum/resDenom
    static void addFractions(int num1, int denom1, int num2, int denom2, int& resNum, int& resDenom) {
        if (denom1 == 0 || denom2 == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        resNum = num1 * denom2 + num2 * denom1;
        resDenom = denom1 * denom2;
        simplifyFraction(resNum, resDenom);
    }

    // Умножение двух дробей: (num1/denom1) * (num2/denom2) -> результат в resNum/resDenom
    static void multiplyFractions(int num1, int denom1, int num2, int denom2, int& resNum, int& resDenom) {
        if (denom1 == 0 || denom2 == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        resNum = num1 * num2;
        resDenom = denom1 * denom2;
        simplifyFraction(resNum, resDenom);
    }

    // Преобразование дроби в десятичное число
    static double toDecimal(int num, int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю.");
        }
        return static_cast<double>(num) / denom;
    }
};
int main() {
    // Настройка локализации для корректного вывода русского текста
    std::setlocale(LC_ALL, "Russian");

    std::cout << "=== Демонстрация работы FractionOperations ===" << std::endl;

    // 1. Проверка сложения: 1/3 + 1/6 (должно получиться 3/6 -> после упрощения 1/2)
    int n1 = 1, d1 = 3;
    int n2 = 1, d2 = 6;
    int rNum = 0, rDenom = 0;

    FractionOperations::addFractions(n1, d1, n2, d2, rNum, rDenom);
    std::cout << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " = "
        << rNum << "/" << rDenom << std::endl;

    // 2. Проверка умножения: 2/5 * 3/4 (должно получиться 6/20 -> после упрощения 3/10)
    n1 = 2; d1 = 5;
    n2 = 3; d2 = 4;
    FractionOperations::multiplyFractions(n1, d1, n2, d2, rNum, rDenom);
    std::cout << n1 << "/" << d1 << " * " << n2 << "/" << d2 << " = "
        << rNum << "/" << rDenom << std::endl;

    // 3. Проверка преобразования в десятичное число: 3/4 (должно быть 0.75)
    int n3 = 3, d3 = 4;
    double decimal = FractionOperations::toDecimal(n3, d3);
    std::cout << "Десятичный вид дроби " << n3 << "/" << d3 << " = " << decimal << std::endl;

    // 4. Демонстрация обработки ошибок (негативный сценарий)
    std::cout << "\nПроверка перехвата ошибок:" << std::endl;
    try {
        FractionOperations::toDecimal(5, 0); // Попытка деления на ноль
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Перехвачено ожидаемое исключение: " << e.what() << std::endl;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
