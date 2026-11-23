// Задание.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <clocale>
#include <cstdlib>
using namespace std;
// Класс «СумматорМассива»
class ArraySum {
private:
    // Данные (поля)
    vector<int> data; // элементы массива
    int size;         // количество элементов

public:
    // Конструкторы
    ArraySum() : size(0) {}                 // Конструктор по умолчанию (пустой массив)
    ArraySum(int arr[], int n) : size(0) {  // Конструктор с параметрами
        setArray(arr, n);
    }

    // Установить массив
    void setArray(int arr[], int n) {
        data.clear();
        if (arr == nullptr || n <= 0) {
            size = 0;
            return;
        }
        size = n;
        for (int i = 0; i < n; i++) {
            data.push_back(arr[i]);
        }
    }

    // Вычислить сумму всех элементов
    long long calculateSum() const {
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }

    // Найти максимальный элемент
    int findMax() const {
        if (size == 0) {
            cout << "Массив пуст!" << endl;
            return 0;
        }
        int maxValue = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > maxValue) maxValue = data[i];
        }
        return maxValue;
    }

    // Найти минимальный элемент
    int findMin() const {
        if (size == 0) {
            cout << "Массив пуст!" << endl;
            return 0;
        }
        int minValue = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < minValue) minValue = data[i];
        }
        return minValue;
    }

    // Вывести массив на экран
    void showArray() const {
        cout << "Массив [" << size << " эл.]: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Геттер
    int getSize() const { return size; }
};

int main() {
    setlocale(0, "");

    cout << "=== Класс СумматорМассива (ArraySum) ===" << endl;

    // Объект 1: конструктор по умолчанию + setArray
    ArraySum first;
    int arr1[] = { 5, 12, -3, 8, 20, 1 };
    first.setArray(arr1, 6);

    cout << "\nОбъект 1" << endl;
    first.showArray();
    cout << "Сумма элементов: " << first.calculateSum() << endl;
    cout << "Максимальный элемент: " << first.findMax() << endl;
    cout << "Минимальный элемент: " << first.findMin() << endl;

    // Объект 2: конструктор с параметрами
    int arr2[] = { 100, 45, 7, 63, 29 };
    ArraySum second(arr2, 5);

    cout << "\nОбъект 2" << endl;
    second.showArray();
    cout << "Сумма элементов: " << second.calculateSum() << endl;
    cout << "Максимальный элемент: " << second.findMax() << endl;
    cout << "Минимальный элемент: " << second.findMin() << endl;

    // Объект 3: ввод массива пользователем
    cout << "\nОбъект 3 (ввод с клавиатуры)" << endl;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    if (n > 0) {
        vector<int> input(n);
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            cin >> input[i];
        }
        ArraySum third;
        third.setArray(input.data(), n);
        third.showArray();
        cout << "Сумма элементов: " << third.calculateSum() << endl;
        cout << "Максимальный элемент: " << third.findMax() << endl;
        cout << "Минимальный элемент: " << third.findMin() << endl;
    }
    else {
        cout << "Размер массива должен быть положительным!" << endl;
    }
    cout << endl;
    system("pause");
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
