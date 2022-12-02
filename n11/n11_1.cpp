#include <bits/stdc++.h>
#include <iostream>
#include <vector>

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

bool isSqr(int n)
{
    float f(sqrt(n));

    return f == int(f);
}

int fact(int n)
{
    int a, s(ceil(sqrt(n))), x(s), l(x * x - n), k(0), y;

    if (n % 2 == 0)
    {
        printf("\nЧисло %d четное.\n\n", n);
        return -1;
    }

    if (s * s == n)
    {
        a = s;
        return a;
    }

    while (true)
    {
        if (isSqr(l))
        {
            y = sqrt(l);
            a = x + y;
            return a;
        }
        k++;
        x++;
        l = x * x - n;
    }
}

int main()
{
    setlocale(0, "");
    int n;

    printf("\nВведите число n:\n    ");
    n = validated_input();

    printf(fact(n) == -1 ? 
        "\nПрекращение работы\n\n" 
        : "\nМножители: [%4d] [%4d]\n\n", fact(n), n / fact(n));

        return 0;
}