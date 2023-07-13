#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tupla
{
    int izq;
    int der;
    Tupla(int _izq,int _der){
        izq=_izq;
        der=_der;
    }
};

bool SortBytesMin(const Tupla &c1, const Tupla &c2)
{
    return c1.izq < c2.izq;
}

void Ejercicio4(vector<Tupla> tup,int m){
    sort(tup.begin(),tup.end(),SortBytesMin);
    int cont=0;
    vector<Tupla> resp;
    for(Tupla i : tup){
        if(i.izq >= 0 && i.der <=m){
            resp.push_back(i);
            cont++;
        }
    }
    cout<<cont<<endl;
    for(Tupla i : resp){
        cout<<i.izq<<" "<<i.der<<endl;
    }
}

int main(){

    int n;
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++){
        int m,x,y;
        cin>>m;
        vector<Tupla> pares;
        do{
            cin>>x>>y;
            if(x!=0 || y!=0){
                Tupla aux(x,y);
                pares.push_back(aux);
            }
        }while(x!=0 || y!=0);
        Ejercicio4(pares,m);
        cout<<endl;
    }


    return 0;
}