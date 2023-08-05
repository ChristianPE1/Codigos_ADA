#include <iostream>
#include <vector>

using namespace std;

void mochila_comb_bt(vector<int> &beneficios, vector<int> &pesos, int capacidad, int level, vector<int> &respuesta, int &max, int peso_act, vector<int> &used_objects)
{
    int n = beneficios.size();

    if (level > n)
    {
        // Comprobamos si la solución actual es mejor que la mejor solución encontrada hasta ahora
        int current_value = 0;
        for (int i = 0; i < n; ++i)
        {
            if (respuesta[i] != 0)
            {
                current_value += beneficios[respuesta[i] - 1];
            }
        }
        if (current_value > max && peso_act <= capacidad)
        {
            max = current_value;
            used_objects = respuesta;
        }
        return;
    }

    // No incluir el objeto actual
    mochila_comb_bt(beneficios, pesos, capacidad, level + 1, respuesta, max, peso_act, used_objects);

    // Incluir el objeto actual si es posible
    if (respuesta[level - 1] == 0 && peso_act + pesos[level - 1] <= capacidad)
    {
        respuesta[level - 1] = level;
        mochila_comb_bt(beneficios, pesos, capacidad, level + 1, respuesta, max, peso_act + pesos[level - 1], used_objects);
        respuesta[level - 1] = 0;
    }
}

int main()
{
    vector<int> beneficios = {2, 3, 4, 5}; // Valores de los elementos
    vector<int> pesos = {1, 2, 3, 4};      // Pesos de los elementos
    vector<int> used_objects;
    int capacidad = 7; // Capacidad máxima de la mochila

    vector<int> respuesta(beneficios.size(), 0); // Arreglo inicializado con valores 0 (no escogido)
    int max = 0;

    mochila_comb_bt(beneficios, pesos, capacidad, 1, respuesta, max, 0, used_objects);

    cout << "\nValor maximo que se puede llevar en la mochila: " << max << endl;

    cout << "Objetos usados: ";
    for (int i = 0; i < used_objects.size(); ++i)
    {
        if (used_objects[i] != 0)
        {
            cout << used_objects[i] << " - ";
        }
    }
    cout << endl;
    return 0;
}
