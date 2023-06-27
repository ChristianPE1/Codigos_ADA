#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

vector<double> monedas = {2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};

void Monedas(double vuelto)
{
    int temp;
    vector<int> res;
    for (auto i : monedas)
    {
        cout << "Moneda: " << i << endl;
        temp = floor(vuelto / i);
        cout << temp << endl;
        if (temp >= 1)
        {
            res.push_back(temp);
            vuelto -= temp * i;
            if (vuelto == 0)
                break;
            cout << "Vuelto: " << vuelto << endl;
        }
    }

    cout << "Se devuelve " << res[0] << " de 2 euros, " << res[1] << " de 1 euro, " << res[2] << " de 50 centimos, " << res[3] << " de 20 centimos, " << res[4] << " de 10 centimos, " << res[5] << " de 5 centimos, " << res[6] << " de 2 centimos y " << res[7] << " de 1 centimo." << endl;
}

void Mochila(vector<float> peso, vector<float> benef, int M)
{
    float base_g = 0;
    int i = 0, ini = 0, peso_total = 0, beneficio_total = 0;
    vector<float> resp;

    for (i; i < peso.size(); i++)
    {
        // cout << "I: " << i << endl;
        for (int j = i; j < peso.size(); j++)
        {
            float c = benef[j] / peso[j];
            // cout << "C: " << c << "  Base g: " << base_g << endl;
            if (c > base_g)
            {
                // cout << "Ocurre Swap" << endl;
                base_g = c;
                swap(peso[i], peso[j]);
                swap(benef[i], benef[j]);
            }
        }
        base_g = 0;
    }
    i = 0;
    while (peso_total < M)
    {
        // float c = benef[i] / peso[i];
        if (peso_total + peso[i] < M)
        {
            resp.push_back(1);
            beneficio_total += benef[i];
            peso_total += peso[i];
        }
        else
        {
            float fr = (M - peso_total) / peso[i];
            resp.push_back(fr);
            beneficio_total += benef[i] * fr;
            peso_total += (M - peso_total) * peso[i];
        }
        cout << "Peso momentaneo en I: " << peso_total << endl;
        i++;
    }

    for (auto i : resp)
    {
        cout << i << " - ";
    }
    cout << "Beneficio total: " << beneficio_total << endl;
}

bool siEsta(vector<int> v, int n)
{
    for (int i : v)
        if (i == n)
            return true;
    return false;
}

void Tareas(vector<int> benef, vector<int> tiempo, vector<int> num_tareas)
{
    int temp = tiempo[0], beneficio_total = 0, lim = benef.size() / 2, ben = 0, total = benef.size();
    vector<int> posiciones(total); // ESTE VECTOR SOLO ES PARA MOSTRAR LOS ID DE LAS TAREAS, SE PUEDE OMITIR

    // SOLO SE CREA CON EL FIN DE QUE SE ENTIENDA MEJOR LA SOLUCION

    iota(posiciones.begin(), posiciones.end(), 1); // RELLENAMOS LAS POSICIONES DE LAS TAREAS

    // ORDENAMOS LOS VECTORES DE TIEMPO Y BENEFICIO
    for (int i = 0; i < tiempo.size(); i++)
    {
        for (int j = i; j < tiempo.size(); j++)
        {
            if (tiempo[j] <= temp)
            {
                temp = tiempo[j];
                swap(benef[j], benef[i]);
                swap(tiempo[j], tiempo[i]);
                swap(posiciones[j], posiciones[i]);
            }
        }
    }

    // TABLAS ORDENADAS, SOLO LO MUESTRO PARA SABER COMO QUEDARON LAS TABLAS
    // POR LO QUE NO AFECTA EN SI AL ALGORITMO, SE PUEDE OMITIR
    cout << "VALORES YA ORDENADOS: " << endl;
    for (int i = 0; i < tiempo.size(); i++)
        cout << benef[i] << " - ";
    cout << endl;
    for (int i = 0; i < tiempo.size(); i++)
        cout << tiempo[i] << " - ";
    cout << endl;
    for (int i = 0; i < tiempo.size(); i++)
        cout << posiciones[i] << " - ";
    cout << endl;

    vector<int> resp(lim);
    cout << "LIM: " << lim << endl;
    int pk = 1;
    for (int i = 0; i < lim; i++)
    {
        int limite;
        if (i + 1 < lim)
            limite = lim * pk;
        else
            limite = total;
        for (int j = i; j < limite; j++)
        {
            int aux = benef[j];
            if (aux > ben && !siEsta(resp, aux))
            {
                ben = aux;
                resp[pk - 1] = aux;
                beneficio_total += aux;
            }
        }
        ben = 0;
        pk++;
    }
    cout << endl
         << "Tareas a completar para conseguir el mayor beneficio: " << endl;
    for (auto k : resp)
    {
        cout << k << " - ";
    }
    cout << endl
         << "Beneficio conseguido: " << accumulate(resp.begin(), resp.end(), 0) << endl;
}

int main()
{
    /////// MONEDAS ////////

    /*
    double vuelto = 3.89;
    Monedas(vuelto);
    */

    /////// MOCHILA ///////

    // INPUT 1

    /*
    vector<float> peso = {10, 3, 3, 4};
    vector<float> benef = {10, 9, 9, 9};
    Mochila(peso, benef, 10);
    */

    // INPUT 2
    /*
    vector<float> peso = {10, 3, 3, 4};
    vector<float> benef = {10, 1, 1, 1};
    Mochila(peso, benef, 10);
    */

    //////// TAREAS /////////

    // INPUT 1

    vector<int> benef = {100, 10, 15, 27};
    vector<int> tiempo = {2, 1, 2, 1};
    vector<int> tareas = {1, 2};
    Tareas(benef, tiempo, tareas);

    // INPUT 2

    /*
    vector<int> benef = {20, 15, 10, 7, 5, 3};
    vector<int> tiempo = {3, 1, 1, 3, 1, 3};
    vector<int> tareas = {1, 3};
    Tareas(benef, tiempo, tareas);
    */

    return 0;
}
