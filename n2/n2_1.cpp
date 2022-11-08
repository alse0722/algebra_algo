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

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

int modexp(int x, int y, int N)
{
    if (y == 0)
        return 1;

    int z = modexp(x, y / 2, N);

    if (y % 2 == 0)
        return (z * z) % N;
    else
        return (x * z * z) % N;
}

int norm(int x, int m)
{

    while (x < 0)
        x += m;

    return x % m;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void program(int a, int b, int m)
{
    printf("\nИсходное уравнение:\n %d * x = %d (mod %d)\n", a, b, m);

    a = norm(a, m);
    b = norm(b, m);

    int d = gcd(a, m);
    printf("\nНОД(%d, %d) = %d\n", a, b, d);

    if (b % d == 0)
    {
        a /= d;
        b /= d;
        m /= d;
    }

    printf("\nСокращенное уравнение:\n %d * x = %d (mod %d)\n", a, b, m);

    printf("\nВычислим phi:\n   phi(%d) = %d\n", m, phi(m));

    int first = norm(b * modexp(a, phi(m) - 1, m), m);
    printf("\nРешение:\n    x0 = %d", first);

    for (int i = 1; i < d; i++)
        printf("\n    x%d = %d", i, first + m * i);

    printf("\nКонец работы программы\n");
}

int main()
{
    setlocale(0, "");

    int a, b, m;

    printf("\nРешение уравнения вида\n  ax = b (mod m)\n");
    printf("можно свести к нахождению функции Эйлера, вычисляющей количество взаимно простых чисел с заданным числом,");
    printf("\nа затем найти одно из решений искомого выражения по формуле\n x0 = b * a^(phi(m)-1) (mod m)\n");
    printf("\nОстальные решения можно найти по формуле\n x = x0 + mk,   k = 1..НОД(a,m)\n");

    printf("\nВведите коэффициент a: ");
    a = validated_input();

    printf("\nВведите коэффициент b: ");
    b = validated_input();

    printf("\nВведите коэффициент m: ");
    m = validated_input();

    printf("\nТаким образом уравнение примет вид:\n %dx = %d (mod %d)\n", a, b, m);
    printf("\nРешим его!\n");

    program(a, b, m);

    return 0;
}