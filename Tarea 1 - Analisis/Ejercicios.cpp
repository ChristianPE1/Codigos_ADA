#include <iostream>
#include <vector>
#include <list>

using namespace std;

/////////////////////////
// ABSTRACT DATA TYPES //
/////////////////////////

/*
template<class T>
class CVector{
    private:
        T *m_pVect;
        int m_nCount;
        int m_nMax;
        int m_nDelta;
        void init(int delta){
            m_nCount=m_nMax=0;
            m_nDelta=delta;
        }
        void Resize(){}
    public:
        CVector(int);
        void Insert(T element);

};

template<class T>
CVector<T>::CVector(int delta){
    init(delta);
}

template<class T>
void CVector::Insert(T element){
    if(m_nCount == m_nMax)//verifica si ya se sobrepaso
        Resize();
    m_pVect[m_nCount++] = elem;//inserta al final
}*/

////////////////////
// DESIGN PATERNS //
////////////////////

/* 3.5
template<class T>
void Write(T &ds, ostream &os){
    typename T::iterator iter = ds.begin();
    for(;iter!=ds.end();iter++ )
        os<<*iter<<"\n";
}

int main(int argc, char* argv[]){

    list<float> mylist;
    vector<float> myvector;
    for( int i = 0 ; i < 10 ; i++ ){
        mylist .push_back(i);
        myvector.push_back(i+50);
    }
    Write(mylist,cout);
    Write(myvector,cout);

    return 0;
}
*/

// 3.6
////////////////////
// LISTAS Y ARBOLES //
////////////////////

/*class CMyComplexDataStructure
{
    vector<float> m_container;

public:
    void Insert(float fVal)
    {
        m_container.push_back(fVal);
    }
    template <typename objclass>
    void sumone(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end(); iter++)
            funobj(*iter);
    }
    template <typename objclass>
    void print(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end(); iter++)
            cout << *iter << endl;
    }
};

template <typename objclass>
class funcobjclass
{
public:
    void operator()(objclass &objinstance)
    {
        objinstance++;
    }
};
int main()
{

    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);
    funcobjclass<float> x;
    ds.sumone(x);
    ds.print(x);
    return 0;
}*/

/// LinkedLIst & ABB

/*template <typename T>
class CLinkedList
{
private:
    struct NODE
    {
        T m_data;
        NODE *m_pNext;
        NODE(T data) : m_data(data), m_pNext(nullptr) {} // Constructor inicializado
    };

    NODE *head;

public:
    CLinkedList() : head(nullptr) {} // Inicializar head a nullptr en el constructor

    void push_back(T d)
    {
        if (!head)
        {
            head = new NODE(d);
        }
        else
        {
            NODE *aux = head;
            while (aux->m_pNext)
            {
                aux = aux->m_pNext;
            }
            aux->m_pNext = new NODE(d);
        }
    }

    void Print()
    {
        NODE *aux = head; // Utilizar head en lugar de m_pRoot
        while (aux)
        {
            cout << aux->m_data << " -> ";
            aux = aux->m_pNext;
        }
        cout << "nullptr" << endl; // Agregar nullptr al final de la lista
    }
};

int main()
{
    CLinkedList<int> lista;
    lista.push_back(15);
    lista.push_back(8);
    lista.push_back(19);
    lista.push_back(22);
    lista.push_back(36);
    lista.push_back(18);
    lista.Print();
    return 0;
}*/

/*
#include <iostream>
using namespace std;

template <typename T>
class CBinaryTree
{
private:
    struct NODE
    {
        T m_data;
        NODE *m_pLeft;
        NODE *m_pRight;

        NODE(T d) : m_data(d), m_pLeft(nullptr), m_pRight(nullptr) {}
    };

    NODE *m_pRoot;

public:
    CBinaryTree() : m_pRoot(nullptr) {}

    void add(T d)
    {
        if (!m_pRoot)
        {
            m_pRoot = new NODE(d);
        }
        else
        {
            NODE *head = m_pRoot;
            NODE *n = new NODE(d);

            while (head)
            {
                if (d < head->m_data)
                {
                    if (!head->m_pLeft)
                    {
                        head->m_pLeft = n;
                        break;
                    }
                    else
                    {
                        head = head->m_pLeft;
                    }
                }
                else if (d > head->m_data)
                {
                    if (!head->m_pRight)
                    {
                        head->m_pRight = n;
                        break;
                    }
                    else
                    {
                        head = head->m_pRight;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    void imprimir(NODE *node)
    {
        if (node)
        {
            imprimir(node->m_pLeft);
            cout << node->m_data << " ";
            imprimir(node->m_pRight);
        }
    }

    void imprimir()
    {
        imprimir(m_pRoot);
        cout << endl;
    }
};

int main()
{
    CBinaryTree<int> arbol;
    arbol.add(8);
    arbol.add(4);
    arbol.add(12);
    arbol.add(2);
    arbol.add(6);
    arbol.add(10);
    arbol.add(14);
    arbol.imprimir();

    return 0;
}*/

//////////////////
/// CALCULADORA //
//////////////////

/*
#include <iostream>
using namespace std;

float Addition(float a, float b) { return a + b; }
float Subtraction(float a, float b) { return a - b; }
float Multiplication(float a, float b) { return a * b; }
float Division(float a, float b) { return a / b; }

typedef float (*lpfnOperation)(float, float);

int main()
{
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};

    float a, b, c;
    int opt;

    cout << "1er Numero: ";
    cin >> a;
    cout << "2do Numero: ";
    cin >> b;

    cout << "Selecciona la operacion\n(0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    cin >> opt;

    c = (*vpf[opt])(a, b);

    cout << "Result: " << c << endl;

    return 0;
}
*/

////////////////////////
/// CALCULADORA CLASES//
///////////////////////

#include <iostream>
using namespace std;

// Class CArithmetic definition
class CArithmetic
{
public:
    static double Addition(double a, double b) { return a + b; }
    static double Substraction(double a, double b) { return a - b; }
    static double Multiplication(double a, double b) { return a * b; }
    static double Division(double a, double b)
    {
        if (b == 0.0)
            throw 0;
        return a / b;
    }
};

int main()
{
    double x, y, z;

    // Enter the operands
    cout << "1er Numero: ";
    cin >> x;
    cout << "2do Numero: ";
    cin >> y;

    z = CArithmetic::Division(x, y);
    cout << "Result: " << z << endl;

    return 0;
}
