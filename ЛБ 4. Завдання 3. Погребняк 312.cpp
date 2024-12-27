#include <iostream>
#include <stdexcept> // Для обробки винятків
using namespace std;

// Функція для введення значень із перевіркою на коректність
bool inputValues(double& A, double& B, int& N1, int& N2, int& N3) {
    cout << "Введіть число A (ненульове): ";
    cin >> A;
    if (A == 0) {
        cerr << "Помилка: число A має бути ненульовим!" << endl;
        return false;
    }

    cout << "Введіть число B (ненульове): ";
    cin >> B;
    if (B == 0) {
        cerr << "Помилка: число B має бути ненульовим!" << endl;
        return false;
    }

    cout << "Введіть ціле число N1 (1-4): ";
    cin >> N1;

    cout << "Введіть ціле число N2 (1-4): ";
    cin >> N2;

    cout << "Введіть ціле число N3 (1-4): ";
    cin >> N3;

    return true;
}

// Функція виконання арифметичної операції
double Calc(double A, double B, int Op) {
    switch (Op) {
    case 1: return A - B; // Віднімання
    case 2: return A * B; // Множення
    case 3: return A / B; // Ділення
    default: return A + B; // Додавання
    }
}

// Функція виведення результатів
void outputResults(double A, double B, int N1, int N2, int N3) {
    try {
        double result1 = Calc(A, B, N1);
        double result2 = Calc(A, B, N2);
        double result3 = Calc(A, B, N3);

        cout << "Результати обчислень:" << endl;
        cout << "Операція N1 (" << N1 << "): " << result1 << endl;
        cout << "Операція N2 (" << N2 << "): " << result2 << endl;
        cout << "Операція N3 (" << N3 << "): " << result3 << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка обчислення: " << e.what() << endl;
    }
}

// Головна функція
int main() {
    double A, B;
    int N1, N2, N3;

    if (!inputValues(A, B, N1, N2, N3)) {
        cerr << "Розрахунки не виконані через некоректний ввід." << endl;
        return 1;
    }

    outputResults(A, B, N1, N2, N3);

    return 0;
}
