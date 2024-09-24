#include <iostream>
#include <cmath>
#include <ctime>      // Для clock_gettime
using namespace std;

/*Функция для вычисления числа Пи с использованием ряда Лейбница*/
double calculatePi(int terms) {
    double pi = 0.0;
    for (int i = 0; i < terms; ++i) { // Чередование знаков (+) и (-) достигается через выражение pow(-1, i)
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }
    return pi * 4.0; // Умножаем результат на 4, чтобы получить приближение Пи
}

int main() {
    setlocale(LC_ALL, "ru");
    int terms;

    cout << "Введите количество членов ряда: ";
    cin >> terms;

    // Создание переменных для замера времени
    struct timespec start, end;
    struct timespec res;

    if (clock_getres(CLOCK_MONOTONIC_RAW, &res) == 0) {
        printf("Погрешность: %ld sec, %ld nsec\n", res.tv_sec, res.tv_nsec);
    }

    // Замер времени перед выполнением программы
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    // Вычисление числа Пи
    double pi = calculatePi(terms);

    // Замер времени после выполнения программы
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    // Вычисление прошедшего времени
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Вывод результатов
    cout << "Приближенное значение числа Пи: " << pi << endl;
    cout << "Время выполнения: " << time_taken << " секунд" << endl;

    return 0;
}
