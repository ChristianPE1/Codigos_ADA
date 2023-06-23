#include <iostream>
#include <cmath>

using namespace std;

void ejercicio1(int n)
{
    int cont = 0;

    for (int i = 0; i <= n; i++)
    {
        cont++;
        if (i % 2 == 0)
        {
            cont++;
            // cout<<i<<endl;
        }
    }
    cont++;
    cout << "Cont 1: " << cont << endl;
}

void ejercicio2(int n)
{
    int cont = 0;

    for (int i = 0; i <= n; i++)
    {
        cont++;
        for (int j = i; j <= n; j++)
        {
            // cont++;
            //  cout<<i<<" - "<<j<<endl;
            cont++;
        }
    }
    cont++;
    cout << "Cont 2: " << cont << endl;
}

void ejercicio3(int n)
{
    int cont = 0;

    for (int i = 0; i <= n; i++)
    {
        cont++;
        if (i % 2 == 0)
        {
            cont++;
            // cout << i << endl;
        }
    }
    cont++;
    for (int i = 0; i <= n; i++)
    {
        cont++;
        if (i % 2 != 0)
        {
            cont++;
            // cout << i << endl;
        }
    }
    cont++;
    cout << "Cont 3: " << cont << endl;
}

void ejercicio4(int n)
{
    int cont = 1, i = 1;
    while (i < n)
    {
        // cout<<i<<endl;
        cont++;
        i = i * 2;
    }
    cout << "Cont 4: " << cont << endl;
}

void ejercicio5(string a, string b)
{
    int cont = 0;
    for (int i = 0; i <= a.length(); i++)
    {
        cont++;
        for (int j = 0; j <= b.length(); j++)
        {
            // cout << i << " - " << j << endl;
            cont++;
        }
    }
    cont++;
    cout << "Cont 5: " << cont << endl;
}

void ejercicio6(int n)
{
    int cont = 0;
    for (int i = 0; i <= n; i++)
    {
        cont++;
        int j = 1;
        while (j < n)
        {
            // cout<<j<<endl;
            j = j * 2;
            cont++;
        }
    }
    cont++;
    cout << "Cont 6: " << cont << endl;
}

void ejercicio7()
{
    int n = 1000, cont = 0;
    cont++;
    if (n % 2 == 0)
    {
        // cout << "Par";
        cont++;
    }
    else
    {
        // cout << "Impar";
        cont++;
    }
    cout << "Cont 7: " << cont << endl;
}

int main()
{
    int n = 10;
    string a = "Gato", b = "Buho";

    ejercicio1(n);
    ejercicio2(n);
    ejercicio3(n);
    ejercicio4(n);
    ejercicio5(a, b);
    ejercicio6(n);
    ejercicio7();

    return 0;
}
