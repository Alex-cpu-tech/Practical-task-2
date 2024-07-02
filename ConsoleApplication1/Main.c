#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Функція для обчислення найбільшого спільного дільника (НСД) використовуючи алгоритм Евкліда
int y(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функція для обчислення найменшого спільного кратного (НСК) двох чисел
int c(int a, int b) {
    return (a * b) / y(a, b);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x;
    printf("Введіть кількість чисел: ");
    scanf("%d", &x);

    // Динамічне виділення пам'яті для масиву numbers
    int* numbers = (int*)malloc(x * sizeof(int));
    if (numbers == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    printf("Введіть числа: ");
    for (int i = 0; i < x; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = numbers[0];
    for (int i = 1; i < x; i++) {
        result = c(result, numbers[i]);
    }

    printf("Найменше спільне кратне: %d\n", result);

    // Звільнення виділеної пам'яті
    free(numbers);

    return 0;
}
