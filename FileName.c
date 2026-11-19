#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int year(int yeas);
double calc(double x);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double x;
    int yeas;
    int N, choice;

    printf("--- Задание 1: Год ---\n");
    printf("Введите год: ");
    scanf("%d", &yeas);

    int is_leap = year(yeas);
    if (is_leap) {
        printf("%d Високосный год\n\n", yeas);
    }
    else {
        printf("%d Не високосный год\n\n", yeas);
    }

    printf("--- Задание 2: Функция ---\n");
    printf("Введите значение x: ");
    scanf("%lf", &x);
    double res_calc = calc(x);
    printf("F(x) = %.2f\n\n", res_calc);
    printf("--- Задание 3: Цифры числа ---\n");
    printf("Введите целое число N (меньше 1000): ");
    scanf("%d", &N);
    if (N >= 1000 || N <= -1000) {
        printf("Ошибка: Вы ввели число, которое не меньше 1000!\n");
        return 1;
    }

    if (N < 0) {
        N = -N;
    }

    printf("Что вывести?\n");
    printf("1 - первую цифру\n");
    printf("2 - последнюю цифру\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    if (choice == 1) {
        int temp = N;
        while (temp >= 10) {
            temp = temp / 10;
        }
        printf("Первая цифра числа: %d\n", temp);
    }
    else if (choice == 2) {
        int last_digit = N % 10;
        printf("Последняя цифра числа: %d\n", last_digit);
    }
    else {
        printf("Ошибка: выбран неверный пункт меню.\n");
    }

    return 0;
}

int year(int yeas)
{
    if ((yeas % 4 == 0 && yeas % 100 != 0) || (yeas % 400 == 0)) {
        return 1;
    }
    return 0;
}

double calc(double x)
{
    return x * x;
}