#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Arista
{
    int destino;
    int origen;
    int peso;

    Arista(int org, int dest, int p)
    {
        origen = org;
        destino = dest;
        peso = p;
    }
};

class Grafo
{
private:
    int numVertices;
    vector<vector<Arista>> ady;

    void DFS(int nodo, vector<bool> &visitado)
    {
        visitado[nodo] = true;
        for (Arista arista : ady[nodo])
        {
            if (!visitado[arista.destino])
            {
                DFS(arista.destino, visitado);
            }
        }
    }

public:
    Grafo(int V)
    {
        numVertices = V;
        ady.resize(V);
    }

    void agregarArista(int origen, int destino, int peso)
    {
        Arista arista(origen - 1, destino - 1, peso);
        Arista arista_2(destino - 1, origen - 1, peso);
        ady[origen - 1].push_back(arista);
        ady[destino - 1].push_back(arista_2);
    }

    bool esConexo()
    {
        vector<bool> visitado(numVertices, false);

        DFS(0, visitado);

        for (bool visit : visitado)
        {
            if (!visit)
            {
                return false; // Si hay algún vértice no visitado, el grafo no es conexo
            }
        }
        return true;
    }
};

int main()
{
    Grafo grafo(5);

    grafo.agregarArista(1, 2, 10);
    grafo.agregarArista(1, 3, 55);
    grafo.agregarArista(1, 4, 25);
    grafo.agregarArista(1, 5, 45);
    grafo.agregarArista(2, 3, 20);
    grafo.agregarArista(2, 4, 25);
    grafo.agregarArista(2, 5, 40);
    grafo.agregarArista(3, 4, 15);
    grafo.agregarArista(3, 5, 30);
    grafo.agregarArista(4, 5, 50);

    if (grafo.esConexo())
    {
        cout << "El grafo es conexo." << endl;
    }
    else
    {
        cout << "El grafo no es conexo." << endl;
    }

    return 0;
}
