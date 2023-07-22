#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &tabla)
{
    for (int i = 0; i < tabla.size(); i++)
    {
        for (int j : tabla[i])
            cout << j << " - ";
        cout << endl;
    }
}

void Solucion(vector<vector<int>> &tabla, vector<int> &monedas, int n, int m)
{
    vector<int> x(n, 0);
    int i = n - 1, j = m, cont = 0;
    while (i > 0)
    {
        if (tabla[i][j] == tabla[i - 1][j])
        {
            i = i - 1;
            cont++;
        }
        else
        {
            x[cont] = x[cont] + 1;
            j = j - monedas[i];
        }
    }
    cout << "Vector de respuestas: " << endl;
    for (int i : x)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Se necesitaran " << x[0] << " monedas de 1, " << x[1] << " de 4 y " << x[2] << " de 6" << endl;
}

void Monedas_PD(vector<int> &monedas, int n, int m)
{
    vector<vector<int>> tabla(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        tabla[i][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - 1 >= 0)
                tabla[i][j] = min(tabla[i - 1][j], 1 + tabla[i][j - monedas[i]]);
            else
                tabla[i][j] = 1 + tabla[i][j - monedas[i]];
        }
    }
    print(tabla);
    Solucion(tabla, monedas, n, m);
}

int main()
{

    int n = 3, m = 8;
    vector<int> monedas = {1, 4, 6};
    Monedas_PD(monedas, n, m);

    return 0;
}
