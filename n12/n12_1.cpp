#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vect;
typedef vector<pair<int, int>> vect_pair;

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
    return b == 0 ? a : gcd(b, a % b);
}

bool test(int x, int y, int n)
{
    return (x * x - y * y) % n == 0 && (x + y) % n != 0 && (x - y) % n != 0;
}

int dix(int n)
{
    vect base({2, 3, 5, 7});
    vect_pair result;
    int init(sqrt(n)), len(base.size()), left, right;

    for (int i = init; i < n; i++)
        for (int j = 0; j < len; j++)
        {
            left = (i * i) % n;
            right = (base[j] * base[j]) % n;

            if (left == right)
                result.push_back(make_pair(i, base[j]));
        }

    len = result.size();

    for (int i = 0; i < len; i++)
        if (test(result[i].first, result[i].second, n))
            if (result[i].first != 1)
            {
                return n / result[i].first;
                break;
            }
    return -1;
}

int main()
{
    setlocale(0, "");
    int n;

    printf("\nВведите число n:\n    ");
    n = validated_input();

    printf(dix(n) == -1 ? 
        "\nПрекращение работы\n\n" 
        : "\nМножители: [%4d] [%4d]\n\n", dix(n), n / dix(n));

        return 0;
}