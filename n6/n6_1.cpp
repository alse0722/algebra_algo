//#include <bits/stdc++.h>
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

int gcd(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = a;
        a = b;
        b = temp % b;
    }

    return a;
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

int jacobi(int a, int b)
{
    if (gcd(a, b) != 1)
        return 0;

    else
    {
        int r = 1;

        if (a < 0)
        {
            a = -a;

            if (b % 4 == 3)
                r = -r;
        }

        for (int i = 0; a != 0; i++)
        {
            int t = 0;

            while (a % 2 == 0)
            {
                t += 1;
                a /= 2;
            }

            if (t % 2 == 1 && (b % 8 == 3 || b % 8 == 5))
                r = -r;

            if (a % 4 == 3 && b % 4 == 3)
                r = -r;

            int c = a;

            a = b % c;
            b = c;
        }

        return r;
    }
}

int main()
{   
    srand(time(0));
    setlocale(0, "");
    int n, k, a;

    printf("\nВведите число n: ");
    n = validated_input();

    printf("\nПроверим число %d на простоту по тесту Соловей-Штрассена:", n);
    printf("\n  Если n нечетное, то оно простое <=> для всех a из Z*n выполняется a^((n-1)/2) = (a/n) (mod n)\n");

    printf("\nВведите количество проверок k: ");
    k = validated_input();

    for (int i = 0; i < k; i++)
    {
        a = (rand() % (n - 2)) + 2;

        printf("\n[a = %4d] - свидетель простоты числа %d", a, n);

        if (gcd(n, a) > 1)
        {
            printf("\n[gdc]Число %d - составное\n\n", n);
            return 0;
        }

        int aa(modexp(a, (n - 1) / 2, n)), bb((n + jacobi(a, n)) % n);

        if (aa != bb)
        {
            printf("\n[modexp]Число %d - составное\n\n", n);
            return 0;
        }
    }

    printf("\nЧисло %d - Вероятно простое\n\n", n);

    return 0;
}