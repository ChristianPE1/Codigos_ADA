#include <iostream>
#include <vector>
#include <utility>
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

bool siEsta(vector<int> v, int a)
{
    for (int i : v)
    {
        if (i == a)
            return true;
    }
    return false;
}

class Grafo
{
private:
    int numVertices;
    vector<vector<Arista>> ady;

    int encontrarSubconjunto(int nodo, vector<int> &padres)
    {
        if (padres[nodo] != nodo)
            padres[nodo] = encontrarSubconjunto(padres[nodo], padres);
        return padres[nodo];
    }
    static bool compararAristas(const Arista &a, const Arista &b)
    {
        return a.peso < b.peso;
    }

public:
    Grafo(int V)
    {
        numVertices = V;
        ady.resize(V);
    }

    void agregarArista(int origen, int destino, int peso)
    {
        Arista arista(origen, destino, peso);
        Arista arista_2(destino, origen, peso);
        ady[origen - 1].push_back(arista);
        ady[destino - 1].push_back(arista_2);
    }

    void imprimirGrafo()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (Arista arista : ady[i])
            {
                cout << "Vértice " << i + 1 << " -> " << arista.destino << " (" << arista.peso << ")" << endl;
            }
        }
    }

    void Sort()
    {
        for (int x = 0; x < numVertices; x++)
        {
            for (int i = 0; i < numVertices - 1; i++)
            {
                int peso = ady[x][i].peso;
                for (int j = i; j < numVertices - 1; j++)
                {
                    if (ady[x][j].peso < peso)
                    {
                        peso = ady[x][j].peso;
                        swap(ady[x][j], ady[x][i]);
                    }
                }
            }
        }
    }

    void Heuristica1(int _vertice)
    {
        vector<int> caminos;
        caminos.push_back(_vertice);

        int vertex = _vertice - 1;
        while (vertex > -1)
        {
            int arista_aux, vertex_aux, min = 100000;
            for (int i = 0; i < numVertices - 1; i++)
            {
                if (ady[vertex][i].peso < min && !siEsta(caminos, ady[vertex][i].destino))
                {
                    min = ady[vertex][i].peso;
                    arista_aux = ady[vertex][i].destino;
                }
            }
            vertex = arista_aux - 1;
            min = 0;
            caminos.push_back(arista_aux);
            if (caminos.size() == numVertices)
                break;
        }
        for (int i : caminos)
        {
            cout << i << " - ";
        }
    }

    void Heuristica2()
    {
        vector<Arista> resp;
        vector<int> vertices(numVertices);
        vector<Arista> aristas;

        for (int i = 0; i < numVertices; i++)
            vertices[i] = i;

        for (int i = 0; i < numVertices; i++)
        {
            for (Arista arista : ady[i])
            {
                aristas.push_back(arista);
            }
        }

        sort(aristas.begin(), aristas.end(), compararAristas);

        for (Arista aux : aristas)
        {
            int org = vertices[aux.origen - 1], dest = vertices[aux.destino - 1];
            if (org != dest)
            {
                resp.push_back(aux);
                for (int i = 0; i < numVertices; i++)
                {
                    if (vertices[i] == dest)
                        vertices[i] = org;
                }
            }
        }

        cout << "Camino a seguir: " << endl;
        for (Arista arista : resp)
        {
            cout << "Arista " << arista.origen << " - " << arista.destino << ": " << arista.peso << endl;
        }
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

    // grafo.Sort();
    // grafo.imprimirGrafo();
    cout << "Ruta mas corta: " << endl;
    grafo.Heuristica1(2);
    // grafo.Heuristica2();

    return 0;
}
