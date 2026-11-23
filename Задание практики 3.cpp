#include <iostream>
using namespace std;
// Правило 2: Имена параметров понятные и лаконичные (width, height).Имена функций в camelCase, отражают суть (calculateArea).
void calculateRectangleArea(double width, double height) {
    // Правило 1 & 4: Отступ 4 пробела внутри блока. Фигурная скобка на той же строке.
    // Правило 3: Пробелы вокруг операторов (>, &&).
    if (width > 0.0 && height > 0.0) {
        // Правило 3: Пробелы вокруг операторов (=, *).
        double area = width * height;

        // Правило 5: std:: убрано из глобальной видимости и используется явно.
       cout << "Площадь прямоугольника со сторонами " << width
            << " и " << height << ": " << area << endl;
    }
    else {
       cout << "Ошибка: Такого прямоугольника не существует!" << endl;
    }
}

int main() {
    // Правило 2: Переменные названы понятно, тип изменен на double для соответствия функции.
    double rectWidth = 0.0;
    double rectHeight = 0.0;

    cout << "Введите стороны прямоугольника: " << endl;

    // Правило 3: Пробелы вокруг операторов ввода (>>).
    cin >> rectWidth >> rectHeight;

    // Вызов функции с понятными аргументами
    calculateRectangleArea(rectWidth, rectHeight);

    return 0;
}
