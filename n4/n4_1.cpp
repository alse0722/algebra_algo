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

int mul(int a, int b, int m)
{

    if (b == 1)
        return a;

    if (b % 2 == 0)
    {
        int t = mul(a, b / 2, m);
        return (2 * t) % m;
    }

    return (mul(a, b - 1, m) + a) % m;
}

int pows(int a, int b, int m)
{

    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        int t = pows(a, b / 2, m);
        return mul(t, t, m) % m;
    }

    return (mul(pows(a, b - 1, m), a, m)) % m;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool test(int p, int n)
{

    if (p == 2)
        return true;

    for (int i = 1; i <= n; i++)
    {
        int a = (rand() % (p - 2)) + 2;
        printf(i % 10 == 1 ? "\n [a = %4d]" : " [a = %4d]", a);

        if (gcd(a, p) != 1)
            return false;
        
        if (pows(a, p - 1, p) != 1)
            return false;
        
    }

    return true;
}

int main()
{
    setlocale(0, "");
    int p, n;

    printf("\nТеорема Ферма: Если p - прсотое и a - целое число, не кратное p, то:\n    ");
    printf("a^(p-1) - 1\nделится на p\n");

    printf("\nВведите число p: ");
    p = validated_input();

    printf("\nВведите количество проверок n: ");
    n = validated_input();

    bool t = test(p, n);

    t ? printf("\nЧисло %d - является простым\n", p) : printf("\nЧисло %d - не является простым\n", p);

    return 0;
}