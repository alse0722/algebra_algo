#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vect;
typedef pair<vect, vect> vect_pair;

vect_pair v;
vect_pair qr;

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

vect_pair pdf(vect a, vect b)
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

    return v;
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

vect diff(vect a, vect b, vect c)
{
    int len(a.size());
    vect res(2 * len, 0),
        aa(len - a.size(), 0),
        bb(len - b.size(), 0),
        cc(len - c.size(), 0),
        temp;

    for (auto e : a)
        aa.push_back(e);

    printf("\na:");
    for (auto e : aa)
        printf(" [%d]", e);

    for (auto e : b)
        bb.push_back(e);

    printf("\nb:");
    for (auto e : bb)
        printf(" [%d]", e);

    for (auto e : c)
        cc.push_back(e);

    printf("\nc:");
    for (auto e : cc)
        printf(" [%d]", e);

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            res[i + j - 1] = bb[i] * cc[j];

    printf("\nres:");
    for (auto e : res)
        printf(" [%d]", e);

    res.erase(res.begin(), res.begin() + len);

    for (int i = 0; i < len; i++)
        aa[i] -= res[i];

    return aa;
}

bool check_properties(vect a, vect b)
{

    int a_len(a.size()), b_len(b.size());

    return a_len < b_len || b_len == 0 ? false : true;
}

vect_pair xea_p_field(vect a, vect b)
{
    vect p0(a), p1(b);
    vect g0({1}), g1({0});
    vect f0({0}), f1({1});
    vect qx, zero({0});

    while (p1 != zero)
    {
        qx = pdf(p0, p1).second;
    }
}

int main()
{
    setlocale(0, "");

    vect poly1, poly2;

    // poly1 = get();
    // poly2 = get();
    vect fin(diff({1, 0, 3, 0, 7}, {1, 0, 2}, {1, -4}));

    printf("\nfin:");
    for (auto e : fin)
        printf(" [%d]", e);

    return 0;
}