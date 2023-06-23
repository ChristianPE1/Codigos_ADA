#include<iostream>
#include<vector>
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
}

*/


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


/* 3.6

class CMyComplexDataStructure{
    vector<float> m_container;
    public:
        void Insert(float fVal){
            m_container.push_back(fVal);
        }
        template <typename objclass>
        void sumone(objclass funobj){
            vector<float>::iterator iter = m_container.begin();
            for(;iter!= m_container.end() ; iter++)
                funobj(*iter);
        }
        template <typename objclass>
        void print(objclass funobj){
            vector<float>::iterator iter = m_container.begin();
            for(;iter!= m_container.end() ; iter++)
                cout<<*iter<<endl;
        }
};


template <typename objclass>
class funcobjclass{
    public:
        void operator ()(objclass& objinstance){
            objinstance++;
        }
};
int main(int argc, char* argv[]){

    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);
    funcobjclass<float> x;
    ds.sumone(x);
    ds.print(x);
    return 0;
}
*/

/* LinkedLIst & ABB
template <typename T>
class CLinkedList
{
    private:
        struct NODE{
            T m_data;
            struct NODE * m_pNext;
            NODE(T data){
                m_data = data;
            }
        };
        NODE<T> *head;

    NODE* m_pRoot;
    public:
        CLinkedList(){
            head->m_data=0;
        };
        void push_back(T d){
            if(!head)
                head->m_data=d;
            else{
                NODE<T> *aux=head;
                while(aux){
                    if(!aux->m_pNext){
                        NODE<T>* n = new NODE(d);
                        aux->m_pNext=n;
                        return;
                    }
                    aux=aux->m_pNext;
                }
            }
        }

};

template <typename T>
class CBinaryTree{
    private:
        struct NODE
        {
        T m_data;
        struct NODE * m_pLeft, m_pRight;
        NODE(T d){
            m_data=n;
        }
        };
        NODE* m_pRoot;
    public:
        CBinaryTree(){
            m_pRoot=0;
        }
        void add(T d){
            if(!m_pRoot){
                NODE n = new NODE(d);
                m_pRoot=n;
            } else {
                NODE<T> *head=m_pRoot;
                NODE<T> n= new NODE(d);
                while(head){
                    if(d < head->m_data;){
                        if(!head->m_pLeft){
                            head->m_pLeft = n;
                            break
                        } else { head = head->m_pLeft; }
                    }
                    if(d > head->m_data;){
                        if(!head->m_pRight){
                            head->m_pRight = n;
                            break
                        } else { head = head->m_pRight; }
                    } else { break; }
                }
            }
        }
};
*/


class CVector//sin terminar
{
    private:
        void **m_pVect;
        int m_nCount,
        m_nMax, //Controla el numero de elementos asignados
        m_nDelta, //Controla el crecimiento
        m_nElemSize; //Tamanio del elemento
        // Pointer to the function to compare
        int (*m_lpfnCompare)(void *, void*);
        void Init(int delta){
            m_nMax=m_nElemSize=m_nCount=0;
            m_nDelta=delta;
        }
        void Resize(); // Resize the vector when occurs an overflow
    public:
        CVector( int (lpfnCompare)(void *, void*),int nElemSize, int delta = 10); // Constructor
        void Insert(void * elem); // Insert a new element
        void* DupBlock(void *pElem){
            void *p = new char[m_nElemSize];
            return memcpy(p, pElem, m_nElemSize);
        }
};

CVector::CVector(int (*lpfnCompare)(void *, void*),int nElemSize, int delta){
    Init(delta);
    m_lpfnCompare = lpfnCompare;
    m_nElemSize = nElemSize;
}

void CVector::Insert(void *pElem){
    if( m_nCount == m_nMax ) // Verify the overflow
    Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = DupBlock(pElem); // Insert the element at the end
}



