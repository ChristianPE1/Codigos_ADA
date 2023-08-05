#include <iostream>
#include <vector>

using namespace std;

void mochila_bt(vector<int> &beneficios, vector<int> &pesos, int capacidad, int level, vector<int> &respuesta, int &max, int current_weight)
{
    if (level == beneficios.size())
    {
        int current_value = 0;
        for (int i = 0; i < beneficios.size(); ++i)
        {
            if (respuesta[i] == 1)
            {
                current_value += beneficios[i];
            }
        }

        if (current_value > max)
        {
            max = current_value;
        }
        return;
    }

    // Se escoge el objeto
    if (respuesta[level] == -1 && current_weight + pesos[level] <= capacidad)
    {
        respuesta[level] = 1;
        mochila_bt(beneficios, pesos, capacidad, level + 1, respuesta, max, current_weight + pesos[level]);
        respuesta[level] = -1;
    }

    // No se incluye
    if (respuesta[level] == -1)
    {
        respuesta[level] = 0;
        mochila_bt(beneficios, pesos, capacidad, level + 1, respuesta, max, current_weight);
        respuesta[level] = -1;
    }
}

int main()
{
    vector<int> beneficios = {2, 3, 4, 5};
    vector<int> pesos = {1, 2, 3, 4};
    int capacidad = 7;

    vector<int> respuesta(beneficios.size(), -1);
    int max = 0;

    mochila_bt(beneficios, pesos, capacidad, 0, respuesta, max, 0);

    cout << "Valor maximo que se puede llevar en la mochila: " << max << endl;

    return 0;
}
