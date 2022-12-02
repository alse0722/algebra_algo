#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vect;
typedef pair<vect, vect> vect_pair;

vect_pair v;

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

void pdf(vect a, vect b)
{

    int a_len(a.size() - 1), b_len(b.size() - 1);
    vect q(a_len - b_len + 1);

    for (int i = 0; i <= a_len - b_len; i++)
    {
        q[i] = a[i] / b[0];

        for (int j = i; j <= b_len + i; j++)
            a[j] = a[j] - q[i] * b[j - i];
    }

    v.first = q;
    v.second = a;
}

vect get()
{
    vect s;
    int n;

    printf("\nВведите степень многочлена:\n ");
    n = validated_input();

    printf("\nВведите коэффициенты многочлена:\n    ");
    for (int i = 0; i < n + 1; i++)
    {
        printf("\n  [X ^ %d] --> ", n - i);
        s.push_back(validated_input());
    }

    return s;
}

int main()
{
    setlocale(0, "");

    vect poly1, poly2;

    poly1 = get();
    poly2 = get();

    pdf(poly1, poly2);

    printf("\nЧастное:\n    ");
    for(auto e: v.first)
        printf("{%3d} ", e);
    
    printf("\nОстаток:\n    ");
    for(auto e: v.second)
        printf("{%3d} ", e);

    return 0;
}
