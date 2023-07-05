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
        temp = floor(vuelto / i);
        if (temp >= 1)
        {
            res.push_back(temp);
            vuelto -= temp * i;
            if (vuelto == 0)
                break;
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
        for (int j = i; j < peso.size(); j++)
        {
            float c = benef[j] / peso[j];
            if (c > base_g)
            {
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
        i++;
    }
    for (auto i : resp)
    {
        cout << i << " - ";
    }
    cout << "Beneficio total: " << beneficio_total << endl;
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

    vector<float> peso = {10, 3, 3, 4};
    vector<float> benef = {10, 9, 9, 9};
    Mochila(peso, benef, 10);

    // INPUT 2
    /*
    vector<float> peso = {10, 3, 3, 4};
    vector<float> benef = {10, 1, 1, 1};
    Mochila(peso, benef, 10);
    */

    return 0;
}