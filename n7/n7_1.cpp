#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int validated_input()
{
    int s = 0;
    while (!(cin >> s))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printf("! Неверный ввод. Повторите ввод, начиная с первого неверного элемента.\n");
    }

    return s;
}

int modexp(int x, int y, int N)
{
    int result(1);

    for (int i = 0; i < y; i++)
    {
        result *= x;
        result %= N;
    }

    return result;
}

void mr(int n, int k)
{
    int s(0), d(n - 1), a, x;
    bool fin(true);

    while (d != 0 && d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    for (int i = 0; i < k; i++)
    {
        a = (rand() % (n - 2)) + 2;
        x = modexp(a, d, n);

        if (x != 1 && x != n - 1)
            for (int r = 0; r < s; r++)
            {
                x = (x * x) % n;

                if (x == n - 1)
                {
                    printf("\n[a = %4d] - свидетель простоты числа %d", a, n);
                    break;
                }
            }

        if (x != n - 1) 
            fin = true;

    }

    fin ? printf("\nЧисло %d - составное\n\n", n) : printf("\nЧисло %d - вероятно простое\n\n", n);
}

int main()
{
    srand(time(0));
    setlocale(0, "");
    int n, k;

    printf("\nВведите число n: ");
    n = validated_input();

    printf("\nПроверим число %d на простоту по тесту Миллера-Рабина:\n  ", n);
    printf("Пусть n - простое, n - 1 = d * 2^s, d - нечетно.\n  ");
    printf("Тогда для всех a из Z*n выполнится хотя бы одно условие:");
    printf("\n      1 a^d = 1 (mod n)");
    printf("\n      2 Существует целое r<s : a^(d * 2^r) = -1 (mod n)\n");

    printf("\nВведите количество проверок k: ");
    k = validated_input();

    mr(n, k);

    return 0;
}