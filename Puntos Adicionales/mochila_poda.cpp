#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Nodo
{
    int nivel;
    int beneficio;
    int resto;
    double valor_acumulado;

    Nodo(int n, int b, int c, double v)
        : nivel(n), beneficio(b), resto(c), valor_acumulado(v) {}
};

int resolverMochila(int capacidad_maxima, const vector<int> &beneficios, const vector<int> &pesos)
{
    int size = beneficios.size();
    priority_queue<Nodo> LNV;
    int mejor_beneficio = 0;

    Nodo raiz(0, 0, capacidad_maxima, 0.0);
    LNV.push(raiz);

    while (!LNV.empty())
    {
        Nodo x = LNV.top();
        LNV.pop();

        if (x.nivel == size || x.resto == 0)
        {
            if (x.beneficio > mejor_beneficio)
            {
                mejor_beneficio = x.beneficio;
            }
        }
        else
        {
            int nivel_siguiente = x.nivel + 1;

            Nodo sin_elemento(nivel_siguiente, x.beneficio, x.resto, x.valor_acumulado);
            LNV.push(sin_elemento);

            if (pesos[x.nivel] <= x.resto)
            {
                int beneficio_nuevo = x.beneficio + beneficios[x.nivel];
                int resto_nueva = x.resto - pesos[x.nivel];
                double valor_acumulado_nuevo = static_cast<double>(beneficio_nuevo) / resto_nueva;
                Nodo con_elemento(nivel_siguiente, beneficio_nuevo, resto_nueva, valor_acumulado_nuevo);
                LNV.push(con_elemento);
            }
        }
    }
    return mejor_beneficio;
}

int main()
{
    int n = 4;
    int capacidad_maxima = 7;
    vector<int> beneficios = {2, 3, 4, 5};
    vector<int> pesos = {1, 2, 3, 4};

    int mejor_beneficio = resolverMochila(capacidad_maxima, beneficios, pesos);

    cout << "Mejor beneficio obtenido: " << mejor_beneficio << endl;

    return 0;
}
