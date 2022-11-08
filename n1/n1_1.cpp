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

int euclid_extended(int a, int b, int &x, int &y)
{
    int x1, y1;

    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int d = euclid_extended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return d;
}

bool task(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = euclid_extended(abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 *= -1;
    if (b < 0)
        y0 *= -1;
    return true;
}

int norm(int x, int m){
    
    while (x < 0)
        x+= m;
    
    return x % m;
}

int main()
{
    setlocale(0, "");

    int a, b, m, x, y, g, tmp;

    printf("\nРешение уравнения вида\n  ax = b (mod m)\n");
    printf("можно свести к решению Диофантового уравнения вида\n ax + km = b\n");
    printf("которое в свою очередь может быть решено с помощью расширенного алгоритма Евклида.\n");

    printf("\nВведите коэффициент a: ");
    a = validated_input();

    printf("\nВведите коэффициент b: ");
    b = validated_input();

    printf("\nВведите коэффициент m: ");
    m = validated_input();
    tmp = m;

    printf("\nТаким образом уравнение примет вид:\n %dx = %d (mod %d)\n", a, b, m);
    printf("\nРешим его!\n");

    task(a % tmp, m, b % tmp, x, y, g) ? printf("\nРешение:\n    x = %d\n", (norm(x,m))) : printf("\nРешения нет!\n");

    return 0;
}