#include <iostream>
#include <stdexcept> // ��� ������� �������
using namespace std;

// ������� ��� �������� ������� �� ��������� �� ����������
bool inputValues(double& A, double& B, int& N1, int& N2, int& N3) {
    cout << "������ ����� A (���������): ";
    cin >> A;
    if (A == 0) {
        cerr << "�������: ����� A �� ���� ����������!" << endl;
        return false;
    }

    cout << "������ ����� B (���������): ";
    cin >> B;
    if (B == 0) {
        cerr << "�������: ����� B �� ���� ����������!" << endl;
        return false;
    }

    cout << "������ ���� ����� N1 (1-4): ";
    cin >> N1;

    cout << "������ ���� ����� N2 (1-4): ";
    cin >> N2;

    cout << "������ ���� ����� N3 (1-4): ";
    cin >> N3;

    return true;
}

// ������� ��������� ����������� ��������
double Calc(double A, double B, int Op) {
    switch (Op) {
    case 1: return A - B; // ³�������
    case 2: return A * B; // ��������
    case 3: return A / B; // ĳ�����
    default: return A + B; // ���������
    }
}

// ������� ��������� ����������
void outputResults(double A, double B, int N1, int N2, int N3) {
    try {
        double result1 = Calc(A, B, N1);
        double result2 = Calc(A, B, N2);
        double result3 = Calc(A, B, N3);

        cout << "���������� ���������:" << endl;
        cout << "�������� N1 (" << N1 << "): " << result1 << endl;
        cout << "�������� N2 (" << N2 << "): " << result2 << endl;
        cout << "�������� N3 (" << N3 << "): " << result3 << endl;
    }
    catch (const exception& e) {
        cerr << "������� ����������: " << e.what() << endl;
    }
}

// ������� �������
int main() {
    double A, B;
    int N1, N2, N3;

    if (!inputValues(A, B, N1, N2, N3)) {
        cerr << "���������� �� ������� ����� ����������� ���." << endl;
        return 1;
    }

    outputResults(A, B, N1, N2, N3);

    return 0;
}
