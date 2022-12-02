#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_dividers;

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

void fact(int n)
{
    prime_dividers = {};

    int tmp(n);

    for (auto cnt = 2; cnt * cnt <= tmp; cnt++)
    {
        if (tmp % cnt == 0)
            prime_dividers.push_back(cnt);

        while (tmp % cnt == 0)
            tmp = tmp / cnt;
    }

    if (tmp > 1)
        prime_dividers.push_back(tmp);

    // printf("\nДелители n - 1 = %d", n - 1);
    // for(auto e: prime_dividers)
    //     printf(" [%d]", e);
}

int fastPow(int num, int deg)
{
    int result = 1;

    while (deg)
    {
        if (deg % 2 == 0)
        {
            deg /= 2;
            num *= num;
        }
        else
        {
            deg--;
            result *= num;
        }
    }

    return result;
}

bool lucasTest(int a, int n)
{

    if (fastPow(a, n - 1) % n != 1)
        return false;

    for (auto e : prime_dividers)
        if (fastPow(a, (n - 1) / e) % n == 1)
            return false;

    return true;
}

pair<int, int> genPrime(int n)
{
    int a = n - 1;

    n = fastPow(2, n) - 1;

    // printf("\nNew n = %d\n", n);
    fact(n - 1);

    while (!lucasTest(a, n) && a > 1)
        a--;

    return make_pair(a, n);
}

int main()
{
    setlocale(0, "");

    int n;
    pair<int, int> res;

    // printf("\nВведите число n:\n    ");
    // n = validated_input();
    
    n = 3;
    res = genPrime(n);
    printf("\n\nПростое число для n = %3d: %7d | Свидетель: %4d\n\n",
           n, res.second, res.first);

    n = 5;
    res = genPrime(n);
    printf("\n\nПростое число для n = %3d: %7d | Свидетель: %4d\n\n",
           n, res.second, res.first);

    n = 7;
    res = genPrime(n);
    printf("\n\nПростое число для n = %3d: %7d | Свидетель: %4d\n\n",
           n, res.second, res.first);

    n = 13;
    res = genPrime(n);
    printf("\n\nПростое число для n = %3d: %7d | Свидетель: %4d\n\n",
           n, res.second, res.first);

    n = 17;
    res = genPrime(n);
    printf("\n\nПростое число для n = %3d: %7d | Свидетель: %4d\n\n",
           n, res.second, res.first);

    return 0;
}