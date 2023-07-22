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

void Solucion(vector<vector<int>> &tabla, vector<int> &pesos, int n, int m)
{
    vector<int> x(n);
    int cont = 0, cont2 = n, j = m;
    for (int i = n; i >= 1; i--)
    {
        if (tabla[i][j] == tabla[i - 1][j])
        {
            x[cont] = 0;
            cont++;
        }
        else
        {
            x[cont] = 1;
            cont++;
            j = j - pesos[cont2 - 1];
        }
    }
    cout << "Vector de respuesta:" << endl;
    for (int i : x)
        cout << i << " ";
    cout << endl;
    cout << "Se usa " << x[0] << " vez el obj1, " << x[1] << " el obj2 y " << x[2] << " el obj3" << endl;
}

void Mochila_PD(vector<int> &beneficios, vector<int> &pesos, int n, int m)
{
    vector<vector<int>> tabla(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; i++)
    {
        tabla[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        tabla[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - pesos[i - 1] >= 0)
                tabla[i][j] = max(tabla[i - 1][j], beneficios[i - 1] + tabla[i - 1][j - pesos[i - 1]]);
            else
            {
                tabla[i][j] = tabla[i - 1][j];
            }
        }
    }
    print(tabla);
    cout << "El beneficio maximo es " << tabla[n][m] << endl;
    Solucion(tabla, pesos, n, m);
}

int main()
{

    int n = 3;
    int m = 6;
    vector<int> beneficios = {1, 2, 5};
    vector<int> pesos = {2, 3, 4};
    Mochila_PD(beneficios, pesos, n, m);

    return 0;
}
