// Практическая работа №4. Вариант 16
// 1. Сохранить и вывести любимую сказку.
// 2. Сохранить цвет текста в консоли при выводе сказки.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Функция для установки цвета текста (используется черный фон '0')
void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 04"); // Чёрный фон + Красный текст
    }
    else if (color == "blue") {
        system("color 01"); // Чёрный фон + Синий текст
    }
    else if (color == "green") {
        system("color 02"); // Чёрный фон + Зелёный текст
    }
    else if (color == "yellow") {
        system("color 06"); // Чёрный фон + Жёлтый текст
    }
    else if (color == "white") {
        system("color 07"); // Чёрный фон + Белый текст
    }
    else if (color == "black") {
        system("color 00"); // Чёрный фон + Синий текст
    }
    else if (color == "cyan") {
        system("color 03"); // Чёрный фон + Синий текст
    }
    else {
        system("color 0F"); // По умолчанию
    }
}
// Задание 16.1: Функция для ввода и сохранения названия сказки
void saveFairytale(string& fairytale, const string& color) {
    cout << "Введите вашу любимую сказку: ";
    cin >> fairytale;

    ofstream fout("settings.txt"); // Создаем файл для записи
    if (fout.is_open()) {
        fout << fairytale << " " << color; // Записываем сказку и текущий цвет
        fout.close();
        cout << "Название сказки сохранено!" << endl;
    }
}
// Задание 16.2: Функция для ввода и сохранения цвета текста
void saveColor(const string& fairytale, string& color) {
    cout << "Введите цвет текста (red, blue, green, yellow, white, cyan, black): ";
    cin >> color;
    ofstream fout("settings.txt"); // Перезаписываем файл с новым цветом
    if (fout.is_open()) { 
        setConsoleColor(color); // Применяем цвет сразу в консоли
        fout << fairytale << " " << color; // Сохраняем обновленные данные
        fout.close();
        cout << "Цвет текста обновлен!" << endl;
    }
}
void resetSettings(string& fairytale, string& color) {
    fairytale = "Неизвестно";
    color = "white";
    setConsoleColor(color); // Возвращаем стандартный цвет
    // Удаляем файл с диска, чтобы настройки не загрузились при следующем старте
    remove("settings.txt");

    cout << "Настройки успешно сброшены до первоначальных!" << endl;
}
int main() {
    setlocale(0, ""); // Настройка локализации
    string fairytale;
    string color = "white"; // Цвет по умолчанию
    ifstream fin("settings.txt"); // Попытка открыть файл для чтения
    if (fin.is_open()) {
        // Читаем сохраненные данные из файла
        fin >> fairytale >> color;
        fin.close();

        // Восстанавливаем цвет и выводим сохраненную сказку
        setConsoleColor(color);
        cout << "Сохраненные настройки:" << endl;
        cout << "Любимая сказка: " << fairytale << endl;
        cout << "Цвет текста: " << color << endl;

        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            // Вызов первой функции для изменения сказки
            saveFairytale(fairytale, color);
            // Вызов второй функции для изменения цвета
            saveColor(fairytale, color);
        }
        else {
            cout << "Не хотите как хотите. Наше дело предложить" << endl;
            resetSettings(fairytale, color);
        }
    }
    else {
        // Если файла нет — первоначальный ввод данных через функции
        cout << "Файл настроек не найден. Введите данные впервые.\n" << endl;
        saveFairytale(fairytale, color);
        saveColor(fairytale, color);
    }
    return 0;
}
