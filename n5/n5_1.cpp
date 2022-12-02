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

int factmod(int n, int p)
{
    // printf("\nПроверка теоремы Вильсона для нашего случая:\n    %d! + 1 (mod %d)\n    ", n, p);
    int res = 1;
    while (n > 1)
    {
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        for (int i = 2; i <= n % p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    // printf("(p-1)! (mod p) = %d! (mod %d)\n", res % p, p);

    return res % p;
}

bool test(int p)
{

    bool res = (factmod(p - 1, p) + 1) % p == 0;

    return res;
}

bool sv1(int n)
{   
    bool res(true);
    bool tst;

    printf("\nПроверка 1:\n Если n кратно p^2 где p - простое, то n - не число Кармайкла\n");

    for (int i = 2; i * i < n; i++){
        
        test(i) ? tst = true : tst = false;

        if (n % (i * i) == 0 && tst){
            res = false;
            printf("[%d]", i);
        }
    }
    

    printf(res ? "\nТест 1 пройден\n" : "\nТест 1 не пройден\n");

    return res;
}

bool sv2(int n)
{
    printf("\nПроверка 2:\n Если n = p1*p2*...*pk, pi != pj, i != j и при этом (n-1) кратно (pi - 1) <=> n - число Кармайкла\n");
    vector<int> v;
    bool res(true);
    int del(2);

    while (n > 1)
    {
        if (n % del == 0)
        {
            v.push_back(del);

            while (n % del == 0)
                n /= del;
        }

        del++;
    }

    for (auto e : v)
    {
        if ((n - 1) % (e - 1) != 0)
            res = false;
    }

    printf(res ? "\nТест 2 пройден\n" : "\nТест 2 не пройден\n");
    return res;
}

bool sv3(int n)
{
    printf("\nПроверка 2:\n Если n = p1*p2*...*pk, pi != pj, i != j и при этом k >= 3 <=> n - число Кармайкла\n");
    vector<int> v;
    int del(2);

    while (n > 1)
    {
        if (n % del == 0)
        {
            v.push_back(del);

            while (n % del == 0)
                n /= del;
        }

        del++;
    }

    printf(v.size() >= 3 ? "\nТест 3 пройден\n" : "\nТест 3 не пройден\n");
    return v.size() >= 3;
}

int main()
{
    setlocale(0, "");
    int n, ntmp;

    printf("\nВведите число n: ");
    n = validated_input();
    ntmp = n;

    printf("\nПроверим число %d на простоту по критерию Вильсона\n", n);

    (test(n)) ?
        printf("\nОтвет: %d - простое число\n", ntmp) :
        printf("\nОтвет: %d - не простое число\n", ntmp);

    printf("\nПроверим число на свойства числа Кармайкла\n");

    if (n % 2 == 0)
    {
        printf("\nЧисло четное - выполнить тест не удастся\n");
        return 0;
    }

    bool t1(sv1(n)), t2(sv2(n)), t3(sv3(n));

    (t1 && t2 && t3) ? printf("\n%d это число Кармайкла\n\n", n) : printf("\n%d это не число Кармайкла\n\n", n);

    return 0;
}