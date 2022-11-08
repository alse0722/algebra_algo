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

int factmod(int n, int p)
{   
    printf("\nПроверка теоремы Вильсона для нашего случая:\n    %d! + 1 (mod %d)\n    ", n, p);
    int res = 1;
    while (n > 1)
    {
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        for (int i = 2; i <= n % p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    printf("(p-1)! (mod p) = %d! (mod %d)\n", res % p, p);

    return res % p;
}

void test(int p){

    (factmod(p - 1, p) + 1) % p == 0 ? 
        printf("\nОтвет: p - простое число\n") :
        printf("\nОтвет: p - не простое число\n");

}

int main()
{
    setlocale(0, "");
    int p;

    printf("\nТеорема: Число p простое, если (p-1)! делится на p. Обратное тоже верно.\n");

    printf("\nВведите число p: ");
    p = validated_input();

    test(p);

    return 0;
}