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
    return b ? gcd(b, a % b) : a;
}

float log_2(int n)
{
    return (log(n) / log(2));
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

bool wilson_crit(int n)
{
    int f(1), i(1);

    while (i < n)
    {
        f *= i;
        f %= n;
        i++;
    }

    return ((f + 1) % n == 0);
}

bool ch(int a)
{
    for (int i = 0; i < 15; i++)
    {
        float n = 0;
        n = sqrt(a);

        if (n == int(n))
            return true;

    }

    return false;
}

bool AKS(int n)
{
    int r(2);

    if (n == 2 || n == 3 || n == 5 || n == 7){
        //printf("\n[1] Число %d простое. Выход\n", n);
        return true;
    }

    if (n % 2 == 0){
        //printf("\n[1] Число %d четное - оно не простое. Выход\n", n);
        return false;
    }

    for (int i = 2; i < 10; i++)
    {

        int s(0), t(n);

        while (t != 0 && t % i == 0)
        {
            s++;
            t /= i;
        }

        if (t == 1){
            //printf("\n[1] Число %d вида a^b - оно составное. Выход\n", n);
            return false;
        }
    }

    //printf("\n[1] Число %d может быть простым. Продолжаем работу\n", n);
    //printf("\n+ [2] Положим значение r = %d", r);

    while (r < n)
    {   
        //printf("\n\n+ + [3] Выполним шаги 4-8, текущее значение r = %d\n", r);

        if (r < n && gcd(r, n) > 1){
            //printf("\n+ + + [4] НОД(%d, %d) >  1. Число %d составное. Выход", r, n, n);
            return false;
        } else //printf("\n+ + + [4] НОД(%d, %d) < 1. Продолжаем работу", r, n);

        if (wilson_crit(r))
        {   
            //printf("\n+ + + + [5] r = %d - простое. Выполним шаги 6-7", r);

            int q = 1;
            for (int i = r - 1; i >= 1; i--)
            {
                if (r - 1 % i == 0 && wilson_crit(i))
                {
                    q = i;
                    break;
                }
            }

            //printf("\n+ + + + + [6] Наибольший простой делитель q = %d", q);

            if (q >= 4 * sqrt(r) * log_2(n) && modexp(n, r, q) != 0)
            {   
                //printf("\n+ + + + + + [7] Условие выполнено. Переходим к шагу 9");
                if (n - 1 <= 2 * sqrt(r) * log_2(n))
                {   
                    //printf("\n+ + + + + + + + [9] Рассматривается 1й случай. Продолжаем работу");
                    for (int a = r + 1; a < n; a++)
                    {
                        if (gcd(a, n) > 1)
                        {   
                            //printf("\n+ + + + + + + + + [10] Условие не выполнено. Число %d составное. Выход", n);
                            return false;
                        }
                    }
                }
                //printf("\n+ + + + + + + + [9] Рассматривается 2й случай. Продолжаем работу");
                //printf("\n+ + + + + + + + + [10] Условие не выполнено. Число %d простое. Выход", n);
                return true;
            }
            //printf("\n+ + + + + + [7] Условие не выполнено. Переходим к шагу 8");
            r++;
            if (r >= n){
                //printf("\n+ + + + + + + [8] Условие выполнено. Число %d простое. Выход", n);
                return true;
            }
            else {
                printf(" ");
                //printf("\n+ + + + + + + [8] Условие не выполнено. Переходим к шагу 3")
                };
        }
        else
        {   
            //printf("\n+ + + + [5] r = %d - не простое. Переходим к шагу 8", r);
            r++;
            if (r >= n){
                //printf("\n+ + + + + + + [8] Условие выполнено. Число %d простое. Выход", n);
                return true;
            }
            else {
                printf(" ");
                //printf("\n+ + + + + + + [8] Условие не выполнено. Переходим к шагу 3")
                };
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    setlocale(0, "");
    int n;

    printf("\nВведите число n: ");
    n = validated_input();

    printf("\nПроверим число %d на простоту по полиномиальному тесту AKS\n  ", n);

    AKS(n) ? 
        printf("\n\n[Результат] Число %d простое\n\n", n):
        printf("\n\n[Результат] Число %d составное\n\n", n);

    return 0;
}