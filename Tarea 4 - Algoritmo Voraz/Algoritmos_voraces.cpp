#include <iostream>
#include <vector>
#include <cmath>

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

int main()
{

    double vuelto = 3.89;
    Monedas(vuelto);

    return 0;
}
