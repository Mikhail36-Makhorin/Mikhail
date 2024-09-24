#include <iostream>
#include <cmath>
using namespace std;

/*������� ��� ���������� ����� �� � �������������� ���� ��������*/
double calculatePi(int terms) {
    double pi = 0.0;
    for (int i = 0; i < terms; ++i) { // ����������� ������ (+) � (-) ����������� ����� ��������� pow(-1, i)
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }
    return pi * 4.0; // �������� ��������� �� 4, ����� �������� ����������� ��
}

int main() {
    setlocale(LC_ALL, "ru");
    int terms;
    cout << "Enterterms: ";
    cin >> terms;

    double pi = calculatePi(terms);
    cout << "Pi: " << pi <<endl;

    return 0;
}
